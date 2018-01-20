#include <iostream>
#include <fstream>
#include <set>
#include <conio.h>
#include <string>

using namespace std;


void sum (set <string> &a, set <string> b){
  set <string> :: iterator it;
  for (it = b.begin(); it != b.end(); ++it)
    a.insert(*it);
}

void intersection (set <string> a, set <string> b, set <string> &c){
  pair <set <string> :: iterator, bool> p;
  set <string> :: iterator it;
  for (it = b.begin(); it != b.end(); ++it){
    p = a.insert(*it);
    if (!p.second) c.insert(*p.first);
  }
}

void diff (set <string> a, set <string> b, set <string> &c){
  pair <set <string> :: iterator, bool> p;
  set <string> :: iterator it;
  for (it = a.begin(); it != a.end(); ++it)
    c.insert(*it);
  for (it = b.begin(); it != b.end(); ++it){
    p = a.insert(*it);
    /*if (p.second)
      c.insert(*p.first);
    else
      c.erase(*p.first); */
    c.erase(*p.first);
  }
}

void main()
{
  ifstream f1("input_str1.txt");
  ifstream f2("input_str2.txt");
  ifstream f3("input_str3.txt");
  
  
  set <string> a;
  set <string> b;
  set <string> c;
  set <string> t2;
  set <string> t1;

  string temp;
  while (!f1.eof()){
    getline(f1,temp);
    a.insert(temp);
  }
  while (!f2.eof()){
    getline(f2,temp);
    b.insert(temp);
  }
  while (!f3.eof()){
    getline(f3,temp);
    c.insert(temp);
  }
  set <string> :: iterator it;
  for (it = a.begin(); it != a.end(); ++it)
    cout << *it << ' ';
  cout << endl;
  for (it = b.begin(); it != b.end(); ++it)
    cout << *it << ' ';
  cout << endl;
  for (it = c.begin(); it != c.end(); ++it)
    cout << *it << ' ';
  cout << endl;
  
  diff(a, b , t2);
  
  intersection(t2,c,t1);
  sum(a,b);
  sum(a,c);

  cout << "A + B + C = ";
  for (it = a.begin(); it != a.end(); ++it)
    cout << *it << ' ';
  cout << endl;
  
  cout << "(A - B) * C = ";
  for (it = t1.begin(); it != t1.end(); ++it)
    cout << *it << ' ';
  cout << endl;
  

  f1.close();
  f2.close();
  f3.close();
  getch();
}