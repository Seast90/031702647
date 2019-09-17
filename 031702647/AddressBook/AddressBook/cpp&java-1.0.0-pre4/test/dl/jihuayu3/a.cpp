#include <fstream>
#include <iostream>
using namespace std;

int main(int argv,char** argc)
{
	if (argv<3)
	{
		return 0;
	}
	char data[100];
	ifstream infile;
	infile.open(argc[1]);
	// 以写模式打开文件
	ofstream outfile;
	outfile.open(argc[2]);
	std::string str((std::istreambuf_iterator<char>(infile)),
		std::istreambuf_iterator<char>());
	// 关闭打开的文件
	outfile << str;
	infile.close();
	outfile.close();

	return 0;
}