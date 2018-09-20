#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
class student
{
	char name[40];
	char grade;
	float marks;
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
	}
	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Grade: "<<grade<<endl;
		cout<<"Marks: "<<marks<<endl;
	}
};
	int main()
	{
		int i,ch;
		system (" cls ");
		student arts;
		//fstream fillin;
		ofstream fillin;
		fillin.open("g:\\mrigank\\Stu.dat",ios::app|ios::binary);
		if (!fillin)
		{
			cout<<"Cannot open file!!";
				return(1);
		}
		do
		{
		cout<<"Enter details for students: "<<endl;
		
			arts.getdata();
			fillin.write((char*)&arts,sizeof (arts));
			cout<<"Press 1 to continue or any other key to discontinue: ";
			cin>>ch;
		}while(ch==1);
		fillin.close();
	

		ifstream fillinn;
		fillinn.open("g:\\mrigank\\Stu.dat",ios::in|ios::binary);
		cout<<" \n The Contents of Stu.dat are shown below: \n \n";
		while(!fillinn.eof ())
		{
			
			fillinn.read((char*)&arts,sizeof(arts));
			arts.display();
		}
		fillinn.close();
		system("pause");
		return (0);
	}
	