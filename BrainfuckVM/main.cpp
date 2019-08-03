#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Runtime.h"

using namespace std;
using namespace BrainfuckVM;

/// <summary>
/// Main entry point
/// </summary>
/// <param name="argc">Argument count</param>
/// <param name="argv">Arguments</param>
/// <returns>Exit code</returns>
int main(int argc, const char *argv[])
{
	int ret(0);
	if (argc > 1)
	{
		try
		{
			ifstream file_stream(argv[1]);
			if (file_stream.is_open())
			{
				string source;
				file_stream.seekg(0, ios::end);
				source.reserve(file_stream.tellg());
				file_stream.seekg(0, ios::beg);
				source.assign((istreambuf_iterator<char>(file_stream)), istreambuf_iterator<char>());
				Runtime runtime;
				ERuntimeState runtime_state(ERuntimeState_NoOperation);
				ret = runtime.Interpret(source, &runtime_state);
				switch (runtime_state)
				{
				case ERuntimeState_OK:
					cerr << "OK state?" << endl;
					break;
				case ERuntimeState_Finished:
					break;
				case ERuntimeState_NoOperation:
					cerr << "No operation?" << endl;
					break;
				case ERuntimeState_PointerUnderflow:
					cerr << "Pointer underflow" << endl;
					break;
				case ERuntimeState_StackUnderflow:
					cerr << "Stack underflow" << endl;
					break;
				case ERuntimeState_StackOverflow:
					cerr << "Stack overflow" << endl;
					break;
				case ERuntimeState_OutOfMemory:
					cerr << "Out of memory" << endl;
					break;
				default:
					cerr << "Unknown error " << runtime_state << endl;
					break;
				}
			}
		}
		catch (exception & e)
		{
			cerr << e.what() << endl;
		}
	}
	return ret;
}
