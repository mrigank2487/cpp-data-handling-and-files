
#include<iostream>
#include<fstream>
using namespace std;
class student
{
    char name[10],grade;
    int rollno,marks;
public:
    void getdata()
    {
        cout<<"\n\nENTER YOUR NAME\n";
        cin>>name;
        cout<<"ENTER YOUR ROLLNO.\n";
        cin>>rollno;
        cout<<"ENTER YOUR MARKS\n";
        cin>>marks;
        assigngrade();
    }
    void assigngrade()
    {
        if(marks>=75)
            grade='A';
        else if((marks<75)&&(marks>=60))
            grade='B';
        else if((marks<60)&&(marks>=45))
            grade='C';
        else if((marks<45)&&(marks>=30))
            grade='D';
        else
            grade='F';
    }
    void display()
    {
        cout<<"\nNAME: "<<name;
        cout<<"\nROLLNO.: "<<rollno;
        cout<<"\nMARKS: "<<marks;
        cout<<"\nGRADE: "<<grade<<"\n";
    }
    int getrn()
    {
        return(rollno);
    }
};
main()
{
    student s;
    int a,r;char ch;

    ofstream fout("student.txt",ios::binary);
    do
    {
        s.getdata();
        fout.write((char*)&s,sizeof(s));
        cout<<"DO YOU WANT TO ADD MORE DATA (Y/N) ";
        cin>>ch;
    }while(ch!='n'&&ch!='N');
    cout<<"\nENTER THE ROLLNO. OF DATA TO BE DELETED\n";
    cin>>r;
    fout.close();

    ofstream fout1("temp.txt",ios::binary);
    ifstream fin("student.txt",ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)&s,sizeof(s));
        if(r!=s.getrn())
       {
         fout1.write((char*)&s,sizeof(s));
       }
    }
    fin.close();
    fout1.close();
    remove("student.txt");
    rename("temp.txt","student.txt");

    ifstream fin1("student.txt",ios::binary);
    while(!fin1.eof())
    {
        fin1.read((char*)&s,sizeof(s));
        s.display();
    }
    fin1.close();
}


