#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
fstream f1,f2;
class customer;
class customer
{
	public:
	int cno,total;
	string name;
	string adress;
	string cname;
	int a,b,c,n,x;
	float i;
	public:
		void give_details()
		{
			system("cls");
			fflush(stdin);
			cout<<"Enter Your Name :";
			getline(cin,name);
			cout<<"Enter your address:";
			getline(cin,adress);
			cout<<"Enter the name of your laptop:";
			getline(cin,cname);
			cout<<"Enter Your Id number -"<<endl;
			cin>>cno;
			
		}
		void display()
		{
			
			cout<<"Name:"<<name;
			cout<<endl<<"Address:"<<adress<<endl;
			cout<<"Name of your laptop:"<<cname<<endl;
			cout<<"Unique-Id:"<<cno;
			cout<<endl<<"Plz remember this Id for further details!!";
			
		}
		void damage()
		{
			 total=0;
			cout<<"Enter the number of components which you want to get repaired :";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<endl<<"Choose from the list:";
				cout<<endl<<"1)display  2)Hard disk 3)Usb ports:";
				cout<<endl<<"4)Graphic card  5)Mother board  6)Windows:";
				cout<<endl<<"7)Keypad  8)Ram  9)Anti-Virus:"<<endl;		
				cin>>x;	
				switch(x)
				{
					case 1:
						cout<<endl<<"Cost of display is 3000 Rs"<<endl;
						total+=3000;
						break;
					case 2:
						cout<<endl<<"cost of Hard disk is 4000 Rs"<<endl;
						total+=4000;
						break;
					case 3:
						cout<<endl<<"cost of Usb port is 500 Rs"<<endl;
						total+=500;
						break;
					case 4:
						cout<<endl<<"cost of Graphic card is 10000 Rs"<<endl;
						total+=10000;
						break;
					case 5:
						cout<<endl<<"cost of Mother board is 8000 Rs"<<endl;
						total+=8000;
						break;
					case 6:
						cout<<endl<<"cost of Windows is 3000 Rs"<<endl;
						total+=3000;
						break;
					case 7:
						cout<<endl<<"cost of key pad is 1200 Rs"<<endl;
						total+=1200;
						break;
					case 8:
						cout<<endl<<"cost of Ram is 1000 Rs"<<endl;
						total+=1000;
						break;	
					case 9:
						cout<<endl<<"cost of Anti-virus is 800 Rs"<<endl;
						total+=800;
						break;
				}
			}	
		}
		void bill()
		{
			cout<<endl<<"Your total bill to be paid  is:"<<total<<endl;
		}
};
void pay()
{
	system("cls");
	int i=0;
	for(i=1;i<101;i++)
	{
		cout<<"Your payment is processing....."<<system("cls")<<i<<"%";
		Sleep(100);
	}
	cout<<endl<<"Your bill is paid. Have a nice day!!!";
	getch();
}	
main()
{
	while(1)
	{
		system("cls");
		customer c1,c2,c,c3,c4;
		char found='f';
		char confirm='n';
		int d;
			cout<<"  \t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
			cout<<"\n\n\t\t\t*     1.NEW CUSTOMER              *";
			cout<<"\n\n\t\t\t*     2.pay the bill              *";
			cout<<"\n\n\t\t\t*     3.DELETE A RECORD           *";
			cout<<"\n\n\t\t\t*     4.MODIFY A RECORD           *";
			cout<<"\n\n\t\t\t*     5.DISPLAY RECORDS           *";
			cout<<"\n\n\t\t\t*     0.EXIT                      *\n";
			cout<<"\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
			cout<<"\n\n\n\n\t Enter your choice :\t";
			cin>>d;
			switch(d)
			{
			case 0 :
					exit(0);
			case 1:
					c1.give_details();
					c1.damage();
					char ch;
					f1.open("Laptop_shop.txt",ios::binary | ios::out);
					cout<<"\n\nDO you want to save the record(y/n)\t";
					cin>>ch;
					if(ch=='y')
					{
						f1.write((char*)&c1,sizeof(c1));
					}
					f1.close();
					c1.bill();
					cout<<"Do you want to pay now (y/n) :";
					char ifelse;
					cin>>ifelse;
					if(ifelse='y')
					{
						pay();
					}
					else
					{
						break;
					}
					break;
			case 2:
				cout<<"Enter the amount to be paid:";
				int temp;
				cin>>temp;
					pay();
					break;
			case 3:
						f1.open("Laptop_shop.txt",ios::in);
						f2.open("temp.txt",ios::out);
						int rno;
//						char found='f',confirm='n';
						cout<<"\n\n Enter Customer ID you want to DELETE :";
						cin>>rno;
					while(!f1.eof())
					{
						f1.read((char*)&c3,sizeof(c3));
						if(c3.cno==rno)
							{
								c3.display();
								found='t';
								cout<<"\n\n Are you sure want to DELETE this record ? (y/n)";
								cin>>confirm;
								if(confirm=='n')
								f2.write((char*)&c,sizeof(c));
							}
					else
						f2.write((char*)&c3,sizeof(c3));
					}
					if(found=='f')
					cout<<"\n\n\tRECORD NOT FOUND\n";
					f1.close();
					f2.close();
					remove("Laptop_shop.txt");
					rename("temp.txt","Laptop_shop.txt");
					f1.open("Laptop_shop.txt",ios::in);
					cout<<"\n\n\n Now the file contains\n\n\n";
					while(!f1.eof())
					{
						f1.read((char*)&c,sizeof(c));
						if(f1.eof())
						c.display();
					}
					f1.close();
					
					break;
			case 4:
					
					f1.open("Laptop_shop.txt",ios::in | ios::out );
//					int rno;
					long pos;
					
					cout<<"\n\n Enter the Customer ID you want to MODIFY :\t";
					cin>>rno;
					while(!f1.eof())
						{
							pos=f1.tellg();
							f1.read((char*)&c,sizeof(c));
							if(c.cno==rno)
								{
									c.give_details();
									f1.seekg(pos);
									f1.write((char*)&c,sizeof(c));
									found='t';
							break;
						}
					}
					break;
			case 5:
					f1.open("Laptop_shop.txt",ios::binary|ios::in);
					while(!f1.eof())
					{
						f1.read((char*)&c2,sizeof(c2));
						c2.display();
						if(f1.eof())
						{
							cout<<"\n\nEnd of the file reached\n\n";
						}
					}
						f1.close();
						getch();
					}
				}
}

