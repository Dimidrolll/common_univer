#include <iostream>
//#include <cctype>
#include <string>
#include <conio.h>
//#include <algorithm>
//#include <windows.h>
//#include <stdio.h>
using namespace std;


void main()
{
int str_p,len1 = 0,buf;
char str[999];
gets(str);

cin >> str_p;
char ar[999], ar1[999]; //������ ��� �������� ����������� ���������� �������� ���������� � �������
int i, j, l, len = 0, p, t, count = 0;
//string str1; //������, � ������� ����� ������������ ������������ �������� �� �������� ���������� � �������
for (i = 0; str[i] != '\0'; i++)
  len1++;
//reverse(str.begin(), str.end()); //�������������� ������� ������
for (i = 0; i <= len1 / 2 - 1; i++)
{
buf = ar1[i];
ar1[i] = ar1[len1 - i - 1];
ar1[len1 - i - 1] = buf;
}

len = str_p * len1 + 1;
for (i = 0; i < len; i++) //�������� ������ � ������
{
ar1[i] = 0;
ar[i] = 0;
}
for (i = 0; i < len; i++) //������������ ������ � ���� str[(n-1)..0]00..000
ar1[i] += str[i] - '0';

for (l = 1; l < str_p; l++) //���������� �������� ���������� � �������
{
for (i = 0; i < len; i++) //���������� ������������ �����, ���������� � str1,
{ //������� �� ������ ������, ����� ����� � �.�. ������ str
for (j = 0; j < len; j++)
{
ar[j + i] += ar1[j]*(str[i] - '0');
p = j + i;
if (ar[p] > 9) //���������, �������� ���������� ����� ������. ���� �� ��������, ��
{ //� ���������� t ������� ���������� ��������, ��������������� �������
t = ar[p] / 10; //��������� ������� �� ������� �� 10 � ��������� � ��� ���������
ar[p] %= 10; //���������� �������� ���������� t
ar[p + 1] += t;
}
}
}
for (i = 0; i < len; i++) //�������������� � str1 ���������� �����
ar1[i] = ar[i];
for (i = 0; i < len; i++) //�������� �������������� ������
ar[i] = 0;
}

int final_count = len;
i = len - 1;

while (ar1[i] == 0){
    i--;
    final_count--;
}
//int buf;


for (i = 0; i <= final_count / 2 - 1; i++)
{
buf = ar1[i];
ar1[i] = ar1[final_count - i - 1];
ar1[final_count - i - 1] = buf;
}
for (i = 0; i < final_count; i++) //������� ���������� ���������
cout << ar1[i];
getch();
}