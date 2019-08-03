#include <iostream>
#include <stack>
#include "Runtime.h"

using namespace std;
using namespace BrainfuckVM;

/// <summary>
/// Default constructor
/// </summary>
Runtime::Runtime() : pointer(0UL)
{
	// ...
}

/// <summary>
/// Destructor
/// </summary>
Runtime::~Runtime()
{
	// ...
}

/// <summary>
/// Load program
/// </summary>
/// <param name="source">Source</param>
void Runtime::Load(const string & source)
{
	memory.clear();
	while (!(programCounterStack.empty()))
	{
		programCounterStack.pop();
	}
	this->source = source;
	memory.resize(source.length() + 1024UL);
	for (string::const_iterator begin(source.begin()), it(source.begin()), end(source.end()); it != end; ++it)
	{
		memory[it - begin] = static_cast<int8_t>(*it);
	}
	programCounterStack.push(0UL);
	pointer = source.length();
}

/// <summary>
/// Interpret program
/// </summary>
/// <param name="source">Source</param>
/// <param name="optRuntimeState">Runtime state (optional)</param>
/// <returns>Exit code</returns>
int8_t Runtime::Interpret(const string & source, ERuntimeState *optRuntimeState)
{
	Load(source);
	return Execute(optRuntimeState);
}

/// <summary>
/// Execute loaded program
/// </summary>
/// <param name="optRuntimeState">Runtime state (optional)</param>
/// <returns>Exit code</returns>
int8_t Runtime::Execute(ERuntimeState *optRuntimeState)
{
	ERuntimeState runtime_state;
	while ((runtime_state = Step()) == ERuntimeState_OK)
	{
		// ...
	}
	if (optRuntimeState)
	{
		*optRuntimeState = runtime_state;
	}
	return ReadValue();
}

/// <summary>
/// Do execution step
/// </summary>
/// <returns>Runtime state</returns>
ERuntimeState Runtime::Step()
{
	ERuntimeState ret(ERuntimeState_NoOperation);
	if (programCounterStack.empty())
	{
		ret = ERuntimeState_StackUnderflow;
	}
	else
	{
		size_t program_counter;
		while (ret == ERuntimeState_NoOperation)
		{
			program_counter = programCounterStack.top();
			if (program_counter < source.length())
			{
				ret = ERuntimeState_OK;
				switch (memory[program_counter])
				{
				case '>':
					++pointer;
					try
					{
						if (memory.size() == pointer)
						{
							memory.push_back(static_cast<int8_t>(0));
						}
						else if (memory.size() < pointer)
						{
							memory.resize(pointer, static_cast<int8_t>(0));
						}
					}
					catch (exception & e)
					{
						ret = ERuntimeState_OutOfMemory;
						cerr << e.what() << endl;
					}
					++(programCounterStack.top());
					break;
				case '<':
					if (pointer)
					{
						--pointer;
					}
					else
					{
						ret = ERuntimeState_PointerUnderflow;
					}
					++(programCounterStack.top());
					break;
				case '+':
					++(memory[pointer]);
					++(programCounterStack.top());
					break;
				case '-':
					--(memory[pointer]);
					++(programCounterStack.top());
					break;
				case '.':
					putchar(static_cast<int>(memory[pointer]));
					++(programCounterStack.top());
					break;
				case ',':
					memory[pointer] = static_cast<int8_t>(getchar());
					++(programCounterStack.top());
					break;
				case '[':
					if (memory[pointer])
					{
						try
						{
							programCounterStack.push(program_counter + 1UL);
						}
						catch (exception & e)
						{
							ret = ERuntimeState_StackOverflow;
							cerr << e.what() << endl;
						}
					}
					else
					{
						size_t brackets(1UL);
						for (size_t i(program_counter + 1UL); i != source.size(); i++)
						{
							switch (memory[i])
							{
							case '[':
								++brackets;
								break;
							case ']':
								--brackets;
								break;
							}
							if (brackets == 0UL)
							{
								programCounterStack.top() = i + 1UL;
								break;
							}
						}
					}
					break;
				case ']':
					programCounterStack.pop();
					if (programCounterStack.empty())
					{
						ret = ERuntimeState_StackUnderflow;
					}
					break;
				default:
					++(programCounterStack.top());
					ret = ERuntimeState_NoOperation;
				}
			}
			else
			{
				ret = ERuntimeState_Finished;
			}
		}
	}
	return ret;
}

/// <summary>
/// Reset runtime
/// </summary>
void Runtime::Reset()
{
	Load(source);
}

/// <summary>
/// Get program counter
/// </summary>
/// <returns>Program counter</returns>
size_t Runtime::GetProgramCounter()
{
	return programCounterStack.top();
}

/// <summary>
/// Read value from memory
/// </summary>
/// <returns>Value from memory</returns>
int8_t Runtime::ReadValue()
{
	return memory[pointer];
}

/// <summary>
/// Read value from memory
/// </summary>
/// <param name="position">Position</param>
/// <returns>Read value from memory</returns>
int8_t Runtime::ReadValue(size_t position)
{
	return memory[position];
}
