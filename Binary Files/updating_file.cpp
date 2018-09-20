#include<iostream>
#include<fstream>
using namespace std;
class student
{
    char name[10],grade,ch;
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
    void update()
    {
        cout<<"\nDO YOU WANT TO RETAIN NAME (Y/N) ";
        cin>>ch;
        if(ch!='Y')
        {
            cout<<"ENTER NEW NAME\n";
            cin>>name;
        }
        cout<<"\nDO YOU WANT TO RETAIN ROLLNO. (Y/N) ";
        cin>>ch;
        if(ch!='Y')
        {
            cout<<"ENTER NEW ROLLNO.\n";
            cin>>rollno;
        }
        cout<<"\nDO YOU WANT TO RETAIN MARKS (Y/N) ";
        cin>>ch;
        if(ch!='Y')
        {
            cout<<"ENTER NEW MARKS\n";
            cin>>marks;
            assigngrade();
        }
    }
};
main()
{
    student s;
    char ch;int r;
    ofstream fout;
    fout.open("student.txt",ios::binary);
    do
    {
        s.getdata();
        fout.write((char*)&s,sizeof(s));
        cout<<"DO YOU WANT TO ADD MORE DATA (Y/N) ";
        cin>>ch;
    }while(ch!='n'&&ch!='N');
    cout<<"\nENTER ROLLNO. OF DATA TO BE UPDATED\n";
    cin>>r;
    ifstream fin;
    fin.open("student.txt",ios::binary);
    fout.seekp(0);
    while(!fin.eof())
    {
        int p=fin.tellg();
        fin.read((char*)&s,sizeof(s));
       if(r==s.getrn())
       {
           s.update();
           fout.seekp(p);
           fout.write((char*)&s,sizeof(s));
           break;
       }
    }
    fin.close();
    fout.close();
    fin.open("student.txt",ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)&s,sizeof(s));
        s.display();

    }
    fin.close();
}


