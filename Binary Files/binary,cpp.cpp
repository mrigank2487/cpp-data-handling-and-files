#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct costumer
{
	char name[51];
	float balance;
};

int main()
{
	system("cls");
	costumer savac;
	strcpy(savac.name,"Tina Marshall");
	savac.balance=21310.75;
	ofstream fout;
	fout.open("g:\\mrigank\\saving",ios::out|ios::binary);
	if(!fout)
	{
		cout<<"File cannot be opened";
		return (1);
	}
	fout.write((char*)&savac,sizeof(costumer));
	fout.close();
	ifstream fin;
	fin.open("g:\\mrigank\\saving",ios::in|ios::binary);
	fin.read((char*)&savac,sizeof(costumer));
	cout<<savac.name;
	cout<<" has balance amount of Rs. "<<savac.balance;
	fin.close();
	system(" pause ");
	return (0);
	
}

