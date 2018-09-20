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
		student arts;
		//fstream fillin;
		ofstream fillin;
		fillin.open("g:\\mrigank\\StudentSearch.dat",ios::out|ios::binary);
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
		fillinn.open("g:\\mrigank\\StudentSearch.dat",ios::in|ios::binary);
		cout<<" \n Enter the roll number to be searched: ";
		int r;
		cin>>r;
		int count=0;
		while(!fillinn.eof ())
		{
			
			fillinn.read((char*)&arts,sizeof(arts));
			if (arts.getrollno()==r)
			{
             arts.display();
			 count++;
			}
        }
		if (count==0)
			cout<<"Roll number not found: ";
		fillinn.close();
		system("pause");
		return (0);
	}

	