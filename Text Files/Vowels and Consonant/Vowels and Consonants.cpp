#include<iostream>
#include<fstream>
using namespace std;
void main()
{
	int v=0, i=0;
	instream inf ("g:\\mrigank\\vowels and consonants.txt",ios::in);
	while(!inf)
	{
	//inf.get();
	if(inf.get()=='A'||inf.get()=='E'||inf.get()=='I'||inf.get()=='O'||inf.get()=='U'||inf.get()=='a'||inf.get()=='e'||inf.get()=='i'||inf.get()=='o'||inf.get()=='u')
	{
		v++;
	}
	i++;
	}
	cout<<"Number of Vowels: "<<v;
	cout<<"Number of Consonants: "<<i-v;
}
	
