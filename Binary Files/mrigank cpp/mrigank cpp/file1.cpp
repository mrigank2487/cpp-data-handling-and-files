#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
int main()
{
	int i;
	system("cls");
	ofstream fout;
	fout.open("g:\\mrigank\\Aschars.txt",ios::app);
	if(!fout)
	{
		cout<<"The file cannot be opened. \n";
		return 1;
	}
	char ch;
	int line=0;
	for(int i=33;i<128;i++)
	{
		fout.put((char)i);
	}
	fout.close();
	ifstream fin;
	fin.open("Aschars",ios::in);
	fin.seekg(0);
	for (i=33;i<128;i++)
	{
		fin.get(ch);
		cout<<" "<<i<<"=";
		cout.put((char)(i));
		if(!(i%8))
		{
			cout<<endl;
			line++;
		}
		if (line>22)
		{
	//		System("PAUSE");
			line=0;
		}
	}
	return(0);
}