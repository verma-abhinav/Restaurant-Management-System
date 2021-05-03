#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class restaurant
{
public:
int cost;
char nm[50];
char cno[50];
int noper;
void input();
void output();
};
void restaurant ::input()
{
cout<<"enter your name :                 ";
gets(nm);
cout<<"enter your contact no. :          ";
gets(cno);
cout<<"enter number of persons:          ";
cin>>noper;
}
void restaurant::output()
{
cout<<"name of the customer is:          "<<nm<<endl;
cout<<"contact number is:                "<<cno<<endl;
cout<<"no of persons are:                "<<noper<<endl;
cout<<"\n";
}
class menu
{
public:
int beverages();
int chinese();
int maincourse();
int desserts();
int menu1();
};
int menu::beverages()
{
int ch,a;
cout<<"       \n         ";
cout<<"                   Beverages     "<<endl;
cout<<"      Item                    cost(Rs)"<<endl;
cout<<"1- Cold Drink                  15 "<<endl;
cout<<"2- Cold Coffee                 50 "<<endl;
cout<<"3- Latte                       40 "<<endl;
cout<<"4- Capachinno                  80 "<<endl;
cout<<"5- Espresso                    90 "<<endl;
cout<<"\n\n Enter choice -> ";
cin>>ch;
if(ch==1)
a=15;

else if(ch==2)
a=50;

else if(ch==3)
a=40;

else if(ch==4)
a=80;

else if(ch==5)
a=90;

return a;
}
int menu::chinese()
{
int ch,b;
cout<<" ";
cout<<"                    Chinese          "<<endl;
cout<<"     Item                                    cost(Rs)"<<endl;
cout<<"1- veg noodles                                100"<<endl;
cout<<"2- Hakka noodles                              120 "<<endl;
cout<<"3- Fried rice                                 90 "<<endl;
cout<<"4- Manchurian                                 350 "<<endl;
cout<<"5- Shushi                                     270 "<<endl;
cout<<"\n\n Enter choice -> ";
cin>>ch;
if(ch==1)
b=100;

else if(ch==2)
b=120;

else if(ch==3)
b=90;

else if(ch==4)
b=350;

else if(ch==5)
b=270;

return b;
}

int menu::maincourse()
{
int ch,c;
cout<<"            ";
cout<<"                 Main Course    "<<endl;
cout<<"        Item                                 cost(Rs)"<<endl;
cout<<"1- Shahi Paneer                               160"<<endl;
cout<<"2- Dal makhani                                100  "<<endl;
cout<<"3- Malai kofta                                120  "<<endl;
cout<<"4- Dum aaloo                                  180   "<<endl;
cout<<"5- Cholle                                     80"<<endl;
cout<<"\n\n Enter choice -> ";
cin>>ch;
if(ch==1)
c=160;

else if(ch==2)
c=100;

else if(ch==3)
c=120;

else if(ch==4)
c=180;

else if(ch==5)
c=80;

return c;
}
int menu::desserts()
{
int ch,d;
cout<<"                 ";
cout<<"             Desserts      "<<endl;
cout<<"        Item                                cost(Rs)"<<endl;
cout<<"1- gulab jamun                                   20 "<<endl;
cout<<"2- rasugulla                                     30   "<<endl;
cout<<"3- ice cream                                     90   "<<endl;
cout<<"4- rasmalai                                      60    "<<endl;
cout<<"5- brownies                                      80    "<<endl;
cout<<"\n\n Enter choice -> ";
cin>>ch;
if(ch==1)
d=20;

else if(ch==2)
d=30;

else if(ch==3)
d=90;

else if(ch==4)
d=60;

else if(ch==5)
d=80;

return d;
}

int menu::menu1()
{
int i,bill=0;
do
{
clrscr();
cout<<"\n1- Beverages ";
cout<<"\n2- Chinese ";
cout<<"\n3- Main Course ";
cout<<"\n4- Deserts ";
cout<<"\n5- Return to previous menu";
cout<<"\n\nEnter your choice-> ";
cin>>i;
switch(i)
{
case 1:
bill=bill+beverages();
break;

case 2:
bill=bill+chinese();
break;

case 3:
bill=bill+maincourse();
break;

case 4:
bill=bill+desserts();
break;
}
}
while(i!=5);
cout<<"\n\nYour bill is              Rs ";
return bill;
}


void main()
{
restaurant r;
menu m;
int ch1,b;
do
{
clrscr();
cout<<"\n---------------------------- WELCOME TO PARK GRAND -------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"\t1- To Book Your Seats"<<endl;
cout<<"\t2- To see the Menu"<<endl;
cout<<"\t3- To Display Details"<<endl;
cout<<"\t4- To Cancel Your Booking"<<endl;
cout<<"\t5- To exit\n"<<endl;
cout<<"\n Enter Your Choice-> ";
cin>>ch1;
switch(ch1)
{
      case 1:
      fstream f1;
      f1.open("restaurant.dat",ios::app|ios:: binary);
      r.input();
      f1.write((char*)&r,sizeof(r));
      f1.close();
      break;

      case 2:
      fstream f4;
      f4.open("menu.dat",ios::app|ios::binary);
      b=m.menu1();
      f4.write((char*)&m,sizeof(m));
      f4.close();
      cout<<b;
      break;

      case 3:
      fstream f6;
      f6.open("restaurant.dat",ios::in|ios::binary);
      f6.read((char*)&r,sizeof(r));
      while(!f6.eof())
      {
      r.output();
      f6.read((char*)&r,sizeof(r));
      }
      f6.close();
      break;

      case 4:
      fstream f7,f8;
      f7.open("restaurant.dat",ios::in|ios::binary);
      f8.open("temp1.dat",ios::out|ios::binary);
      char str[50];
      cout<<"\n Enter Name -> ";
      gets(str);
      f7.read((char*)&r,sizeof(r));
      while(!f7.eof())
      {
      if(strcmpi(r.nm,str)!=0)
      f8.write((char*)&r,sizeof(r));
      f7.read((char *)&r,sizeof(r));
      }
      f7.close();
      f8.close();
      remove("restaurant.dat");
      rename("temp1.dat","restaurant.dat");
      cout<<"\n Deleted \n";
      break;

}
getch();
}
while(ch1!=5);
}