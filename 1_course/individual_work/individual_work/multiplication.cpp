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
int str_p;
char str[999];
gets(str);
cin >> str;
//cin >> str_p;
int ar[100], ar1[100]; //массив для хранения полученного результата операции возведения в степень
int i, j, l, len, p, t, count = 0;
//string str1; //строка, в которую будет записываться изменяющееся значение от операции возведения в степень
int len1 = 0;
for (i = 0; str[i] !='\0'; i++) len1++;

//reverse(str.begin(), str.end()); //переворачиваем входную строку
int buf1;
for (i = 0; i <= len1 / 2 - 1; i++)
{
buf1 = str[i];
str[i] = str[len1 - i - 1];
str[len1 - i - 1] = buf1;
}

len = str_p * len1 + 1; //максимально вычисляем размер результирующего массива/строки
for (i = 0; i < len; i++) //зануляем строку и массив
{
ar1[i] = 0;
ar[i] = 0;
}
for (i = 0; i < len1; i++) //представляем строку в виде str[(n-1)..0]00..000
ar1[i] += str[i] - '0';

for (l = 1; l < str_p; l++) //производим операцию возведения в степень
{
for (i = 0; i < len1; i++) //производим перемножения чисел, хранящихся в str1,
{ //сначала на разряд единиц, потом сотен и т.д. строки str
for (j = 0; j < len; j++)
{
ar[j + i] += ar1[j]*(str[i] - '0');
p = j + i;
if (ar[p] > 9) //проверяем, является полученное число цифрой. если не является, то
{ //в переменную t заносим количество десятков, результуруищему массиву
t = ar[p] / 10; //оставляем остаток от деления на 10 и добавляем к уже имеющемся
ar[p] %= 10; //количеству десятков полученное t
ar[p + 1] += t;
}
}
}
for (i = 0; i < len; i++) //перезаписываем в str1 полученное число
ar1[i] = ar[i];
for (i = 0; i < len; i++) //зануляем результирующий массив
ar[i] = 0;
}



int final_count = len;
i = len - 1;
while (ar1[i] == 0){
    i--;
    final_count--;
}
int buf;
for (i = 0; i <= final_count / 2 - 1; i++)
{
buf = ar1[i];
ar1[i] = ar1[final_count - i - 1];
ar1[final_count - i - 1] = buf;
}
for (i = 0; i < final_count; i++) //выводим полученный результат
cout << (int)ar1[i];
getch();
}