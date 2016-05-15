class BFVM;
typedef BFVM*	PBFVM;
class BFVM
{
private:
	char *program;
	long long program_len;
public:
	BFVM(char *&_data, long long &_data_len);
	~BFVM();
	void Execute();
};
#ifndef IN_BFVM
extern PBFVM CreateBFVM(STRING file_name);
#endif