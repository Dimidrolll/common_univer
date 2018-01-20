#include <iostream>
#include <fstream>
#include <list>
#include <conio.h>

using namespace std;

bool compare (int x){
   return x >= 5 && x <= 10;
}

void print_list(list <int> &l){
  for (list <int>::const_iterator it = l.begin(); it != l.end(); ++it)
    cout << *it << ' ';
  cout << endl;
}

void read_list(string s, list <int> &l){
  ifstream f1(s);
  while (!f1.eof()){
    int temp;
    f1 >> temp;
    l.push_back(temp);
  }
  f1.close();
}

void main()
{
  list <int> l1;
  list <int> l2;
  read_list("input1.txt",l1);
  read_list("input2.txt",l2);
  print_list(l1);
  print_list(l2);
  l1.remove_if(compare);
  l1.sort();
  l2.sort();
  print_list(l1);
  print_list(l2);
  l1.merge(l2);
  print_list(l1);
  getch();
}