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

cout<<" ------------------------------------------------------"<<endl<<" � � � � � � � � � �   � � � � � � � � �   � � � � � � �   � �   � � � � .  "<<endl<<" � � � � � � �   � � � � � � � �   � � � � � � :  "<<endl<<" � � � � � � � � � �   � �   � � � �   �   � � � �   � � � � � � �   ( � � )   � >   ";
cin>>s;
cout<<" � � � � � �   � � � � � � �   ( �   � �   1 0 0   � � )   � >  ";
cin>>rashod;
cout<<" � � � �   � � � � �   � � � � � � �   ( � � � . )   � >   ";
cin>>tzena;
cout<<" ------------------------------------------------------"<<endl;
sum=2*s/100*rashod*tzena;
cout<<" � � � � � � �   � �   � � � �   � � � � � � � � � "<<endl;
cout<<fixed<<setprecision(2)<<sum<<setprecision(2)<<" ���."<<endl;
//system("pause");
}