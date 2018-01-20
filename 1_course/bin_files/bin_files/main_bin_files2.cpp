#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <iomanip>
using namespace std;

long int binar(int x)
{
  long int a = 0;
  int arr[20], i = 0;
  while (x){
    arr[i] = x % 2;
    ++i;
    x = x / 2;
  }
  for (int j = i - 1; j >= 0; --j)
    a = a * 10 + arr[j];

  return a;
}

void main()
{ 
  setlocale(0,"");
  cout << "Бинарные файлы, задача 2" << endl;
  srand(time(0));
  int n, q;
  fstream f1_bin;
  cout << "Введи n" << endl;
  cin >> n;
  f1_bin.open("daniy_bin2.dat",ios::binary|ios::out|ios::trunc|ios::in);
  for (int i = 0; i < n; ++i){
    q = rand() % 101; 
    cout << q << ' ';
    f1_bin.write((char*) &q, sizeof(q));
  }
  cout << endl;
  bool Continue = 1;
  int number;
  //f1_bin.seekp(0,0);f1_bin.seekg(0,0);
  while (Continue){
    cout << "Введи номер." << endl;
    cin >> number;
    f1_bin.seekp((number - 1) * 4, 0);
    f1_bin.read((char*) &q, sizeof(q));
    cout << q << "   " << binar(q) << "   " << bitset <7>(q) << endl;
    cout << "Хотите продолжить? Да - 1, нет - 0." << endl;
    cin >> Continue;
  }

  f1_bin.close();
  
  getch();
}