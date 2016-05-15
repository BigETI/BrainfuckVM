#include <iostream>
#include <stack>
#include "string.h"
#define IN_BFVM
#include "bfvm.h"
#define MEM_STEP	(1048576LL)

BFVM::BFVM(char *&_program, long long &_program_len)
{
	program = _program;
	program_len = _program_len;
}

PBFVM CreateBFVM(STRING file_name)
{
	PBFVM ret = NULL;
	FILE *file = NULL;
	long long file_size;
	char *buf;
	unsigned int bracket = 0;
	_wfopen_s(&file, file_name.c_str(), L"rb");
	if (file)
	{
		fseek(file, 0, SEEK_END);
		file_size = _ftelli64(file);
		fseek(file, 0, SEEK_SET);
		try
		{
			buf = new char[file_size];
		}
		catch (...)
		{
			buf = NULL;
		}
		if (buf)
		{
			memset(buf, 0, sizeof(char)*file_size);
			fread_s(buf, file_size, sizeof(char), file_size, file);
			for (char *c = buf; (*c) != '\0'; c++)
			{
				switch (*c)
				{
				case '[':
					bracket++;
					break;
				case ']':
					if (bracket) bracket--;
					else
					{
						std::wcout << L"\nClosing bracket too early!\n";
						fclose(file);
						delete[] buf;
						return ret;
					}
					break;
				}
			}
			if (bracket == 0)
			{
				try
				{
					ret = new BFVM(buf, file_size);
				}
				catch (...)
				{
					ret = NULL;
				}
				if (ret == NULL) delete[] buf;
			}
			else std::wcout << L"\nMissing brackets!\n";
		}
		fclose(file);
	}
	return ret;
}

BFVM::~BFVM()
{
	delete program;
}

void BFVM::Execute()
{
	std::stack<long long> bracket_stack;
	long long i, mem_len = MEM_STEP + program_len, ptr_pos = program_len, brackets;
	char *mem = NULL, *temp;
	bool out_check;
	try
	{
		mem = new char[mem_len];
	}
	catch (...)
	{
		mem = NULL;
	}
	if (mem)
	{
		memcpy(mem, program, sizeof(char)*program_len);
		memset(&(mem[program_len]), 0, sizeof(char)*MEM_STEP);
		for (i = 0LL; i < program_len; i++)
		{
		inner_loop:
			switch (mem[i])
			{
			case '>':
				ptr_pos++;
				while (ptr_pos >= mem_len)
				{
					try
					{
						temp = new char[mem_len + MEM_STEP];
					}
					catch (...)
					{
						temp = NULL;
					}
					if (temp)
					{
						memcpy(temp, mem, sizeof(char)*mem_len);
						memset(&(temp[mem_len]), 0, sizeof(char)*MEM_STEP);
						delete[] mem;
						mem = temp;
						mem_len += MEM_STEP;
					}
					else
					{
						delete[] mem;
						return;
					}
				}
				break;
			case '<':
				if (ptr_pos) ptr_pos--;
				else
				{
					delete[] mem;
					return;
				}
				break;
			case '+':
				mem[ptr_pos]++;
				break;
			case '-':
				mem[ptr_pos]--;
				break;
			case '.':
				putchar(mem[ptr_pos]);
				break;
			case ',':
				mem[ptr_pos] = getchar();
				break;
			case '[':
				if (mem[ptr_pos]) bracket_stack.push(i);
				else
				{
					brackets = 0;
					out_check = false;
					while (true)
					{
						switch (program[i])
						{
						case '[':
							brackets++;
							break;
						case ']':
							brackets--;
							if (brackets == 0) out_check = true;
							break;
						}
						if (out_check) break;
						i++;
					}
				}
				break;
			case ']':
				i = bracket_stack.top();
				bracket_stack.pop();
				goto inner_loop;
				break;
			}
		}
		delete[] mem;
	}
}