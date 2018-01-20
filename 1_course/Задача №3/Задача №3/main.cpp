#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;
//#include <cstdlib>
void main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);

double tzena,rashod,s,sum;

cout<<" ------------------------------------------------------"<<endl<<" В ы ч и с л е н и е   с т о и м о с т и   п о е з д к и   н а   д а ч у .  "<<endl<<" В в е д и т е   и с х о д н ы е   д а н н ы е :  "<<endl<<" Р а с с т о я н и е   д о   д а ч и   в   о д н у   с т о р о н у   ( к м )   ­ >   ";
cin>>s;
cout<<" Р а с х о д   б е н з и н а   ( л   н а   1 0 0   к м )   ­ >  ";
cin>>rashod;
cout<<" Ц е н а   л и т р а   б е н з и н а   ( р у б . )   ­ >   ";
cin>>tzena;
cout<<" ------------------------------------------------------"<<endl;
sum=2*s/100*rashod*tzena;
cout<<" П о е з д к а   н а   д а ч у   о б о й д е т с я "<<endl;
cout<<fixed<<setprecision(2)<<sum<<setprecision(2)<<" руб."<<endl;
//system("pause");
}