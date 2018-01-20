#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include <iomanip>
using namespace std;
bool simple(int n)
{
  int i, j = 0;
  for (i = 2; i * i <= n; ++i)
      if (n % i == 0) ++j;
  if (j == 0) return 1;
  else return 0;
  
}
void main()
{ 
  setlocale(0,"");
  cout << "Бинарные файлы, задача 1" << endl;
 
  int n, q;
  fstream f1_bin, f2_bin;
  cout << "Введи n" << endl;
  cin >> n;
  f1_bin.open("daniy_bin.dat",ios::binary|ios::trunc|ios::out);
  f2_bin.open("copy_bin.dat",ios::binary|ios::out);
  int razm = 0;
  for (int i = 2; i <= n; ++i)
    if (simple(i)){
    f1_bin.write((char*) &i, sizeof(i));
    ++razm;
    }

  int k;
  cout << "Введи k" << endl;
  cin >> k;
  f1_bin.close();
  //f1_bin.seekg(0,0);f1_bin.seekp(0,0);
  f2_bin.seekg(0,0);f2_bin.seekp(0,0);
  f1_bin.open("daniy_bin.dat",ios::binary|ios::in);
  while (f1_bin.peek() != EOF){
    f1_bin.read((char*) &q, sizeof(q));
    if (q % 10 == k) f2_bin.write((char*) &q, sizeof(q));
    
  }
  f1_bin.close();
  f2_bin.close();
  f1_bin.open("daniy_bin.dat",ios::binary|ios::in);
  //f1_bin.seekg(0,0);f1_bin.seekp(0,0);
  //for (int i = 2; i <= n; ++i)
    //if (simple(i)) f1_bin.write((char*) &i, sizeof(i));
  f1_bin.seekg(0,0);f1_bin.seekp(0,0);
  while (f1_bin.peek() != EOF){
    f1_bin.read((char*) &q, sizeof(q)); 
    cout << q << ' ';
  }
  f1_bin.close();
  f2_bin.open("copy_bin.dat",ios::binary|ios::in);
  f1_bin.open("daniy_bin.dat",ios::binary|ios::in);
  cout << endl;
  f2_bin.seekg(0,0);
  while (f2_bin.peek() != EOF){
    f2_bin.read((char*) &q, sizeof(q));
    cout << q << ' ';
  }
  cout << endl;
  f1_bin.seekp(16, 0);f1_bin.seekg(16, 0);
  f1_bin.read((char*) &q, sizeof(q)); 
  if (razm >= 5) cout << q << endl;
  else cout << "Нет 5-го элемента." << endl;
  f1_bin.close();
  f2_bin.close();
  getch();
}