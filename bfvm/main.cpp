//#include <Windows.h>
#include <iostream>
#include "string.h"
#include "bfvm.h"

int main(int argc, const char *argv[])
{
	PBFVM vm = NULL;
	if (argc > 1)
	{
		try
		{
			vm = CreateBFVM(argv[1]);
		}
		catch (...)
		{
			vm = NULL;
		}
		if (vm)
		{
			vm->Execute();
			delete vm;
		}
		else std::wcout << L"\n\nCan't allocate virtual machine!";
	}
	return 0;
}