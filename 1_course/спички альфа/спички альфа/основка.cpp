
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void main(){
SetConsoleCP(1252);
SetConsoleOutputCP(1251);
	cout<<"� ���� ������� � ����� � ���� ����... ������..."<<endl;
	cout<<"���� �� ����������... ����� ���� �� �����, ��� �����..."<<endl<<"����� ����������� ����� �������� ���������� �� ������ �����."<<endl;
	cout<<"���� 21 ������. ����� ����� ������ 1,2 ��� 3 ������ �� ���. ��������� ���, ��� ������� ���������..."<<endl<<"�����, ��� ��� ��� �����."<<endl<<"��� � ����, ����� ������� ���� ����..."<<endl<<"�.�. ���� ����� ������ ���-�� ������, �� ����� ���������, � � ����������"<<endl<<"� ���� ����� �� ��������..."<<endl;
	int i,a;
	i=21;
	while(i>1){
		cout<<"���� ���"<<endl;
		cin>>a;
		if ((a!=1)&&(a!=2)&&(a!=3)) {cout<<"�� ����������! � � ������������! �� ��� ���� ����������� ���������!"<<endl;break;}
		if (a==1){i-=1;cout<<"�������� "<<i<<endl<<"��� ������ ����� "<<3<<endl;i-=3;cout<<"�������� "<<i<<endl;}
		if (a==2){i-=2;cout<<"�������� "<<i<<endl<<"��� ������ ����� "<<2<<endl;i-=2;cout<<"�������� "<<i<<endl;}
		if (a==3){i-=3;cout<<"�������� "<<i<<endl<<"��� ������ ����� "<<1<<endl;i-=1;cout<<"�������� "<<i<<endl;}
	}
	cout<<"���� �������� ����� ��������� ������."<<endl;
	cout<<"GG WP ������."<<endl;
	cout<<"�� �����, ��� �� ��������� ���..."<<endl;
	getch();
}