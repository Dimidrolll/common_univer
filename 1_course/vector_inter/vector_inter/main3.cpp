#include <iostream>
#include <map>
#include <conio.h>
#include <fstream>
#include <string>


using namespace std;

void main()
{
  setlocale(0,"");
  multimap <string,string> m;
  multimap <string,string> ::iterator p;
  fstream f;
  f.open("input3.txt",ios::in);
  string book, author;
  //pair <string,string> p;
  while (!f.eof()){
    f >> author >> book;
    p = m.insert(pair <string,string> (author,book));
  }

  for (p = m.begin(); p != m.end(); ++p){
    cout << (*p).first << ' ' << (*p).second << endl;
  }
  cout << "¬веди фамилию автора" << endl;
  string s;
  cin >> s;
  for (p = m.begin(); p != m.end(); ++p){
    if ((*p).first == s)
      cout << (*p).second << endl;
  }
  //int i = 1;
  fstream f1;
  f1.open("output.txt",ios::out);
  //int j;
  for (p = m.begin(); p != m.end(); ++p){
    int i = 1;
    multimap <string,string> ::iterator p1;
    p1 = p;
    ++p1;
    while ((p1 !=m.end()) && ((*p).first == (*(p1)).first)){
      ++i;
      ++p;
      p1 = p;
      ++p1;
    }
    //++p;
    f1 << (*p).first << ' ' << i << endl;
      
  }
  getch();
}