#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
class student
{
	char name[40];
	char grade;
	float marks;
	int rollno;
public:
	void getdata()
	{
		cout<<"Enter name: ";
		//cin.getline(name,40);
		cin>>name;
		cout<<"Enter grade: ";
		cin>>grade;
		cout<<"Enter marks: ";
		cin>>marks;
		cout<<"Enter Roll number: ";
		cin>>rollno;
	}
	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Grade: "<<grade<<endl;
		cout<<"Marks: "<<marks<<endl;
		cout<<"Roll no: "<<rollno<<endl;
	}
	int getrollno()
	{
		return(rollno);
	}
};
	int main()
	{
		int i,ch;
		system (" cls ");
		student arts,arts2;
		//fstream fillin;
		ofstream fillin,fillin2;
		fillin.open("g:\\mrigank\\StudentSearch.dat",ios::out|ios::binary);
		fillin2.open("g:\\mrigank\\temp.dat",ios::out|ios::binary);
		if (!fillin)
		{
			cout<<"Cannot open file!!";
				return(1);
		}
		do
		{
		cout<<"Enter details for students: \n"<<endl;
		
			arts.getdata();
			fillin.write((char*)&arts,sizeof (arts));
			cout<<"Press 1 to continue or any other key to discontinue: ";
			cin>>ch;
		}while(ch==1);

		fillin.close();
	

		ifstream fillinn;
		fillinn.open("g:\\mrigank\\StudentSearch.dat",ios::in|ios::binary);
		cout<<" \n Enter details to be inserted: ";
		arts2.getdata();
		
		while(!fillinn.eof ())
		{
			
			fillinn.read((char*)&arts,sizeof(arts));
			if (arts.getrollno()<arts2.getrollno())
			{
				fillin2.write((char*)&arts,sizeof(arts));
			}
			else
		    {
				cout<<"record inserted";
				fillin2.write((char*)&arts2,sizeof(arts2));
				break;
			}
		}

		while(!fillinn.eof())
		{
			fillinn.read((char*)&arts,sizeof(arts));
			fillin2.write((char*)&arts,sizeof(arts));
		}
		remove("g:\\mrigank\\StudentSearch.dat");
		rename("g:\\mrigank\\temp.dat","g:\\mrigank\\StudentSearch.dat");
		
		fillinn.close();
		fillin2.close();
//		ifstream fillinn;
		fillinn.open("g:\\mrigank\\StudentSearch.dat",ios::in|ios::binary);
		while(!fillinn.eof ())
		  {
			fillinn.read((char*)&arts,sizeof(arts));
			arts.display();
		  }
		system("pause");
	}
	

	