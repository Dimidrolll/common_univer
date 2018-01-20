#include <iostream>
#include <list>
#include <conio.h>
#include <iterator>
#include <fstream>
using namespace std;

void main()
{
  setlocale(0,"");
  fstream f;
  list <int> l;
  list <int> ::iterator it;
  //it = l.begin();
  f.open("input.txt",ios::in);
  int a, k;
  cout << "k = ?" << endl;
  cin >> k;
  while (!f.eof()){
    f >> a;
    l.push_back(a);
  }
  it = l.begin();
  for (int i = 0; i < l.size() ; ++i){
    cout << *it << ' ';
    it++;
  }
  cout << endl;
  it = l.begin();
  
  int razm = l.size();
  for (int i = 0; i < razm ; ++i){
    
    int t = *it;
    if (t > k) {
      ++it;
      int q1 = l.size();
      l.remove(t);
      int q2 = l.size();
      i = i + q1 - q2 - 1;
    }
     else it++;
  }
  it = l.begin();
  for (int i = 0; i < l.size() ; ++i){
    cout << *it << ' ';
    it++;
  }
  cout << endl << "M =?  L = ?" << endl;
  int M, L, m = 0, p = 0;
  cin >> M >> L;
  it = l.begin();
  for (int i = 0; i < l.size() ; ++i){
    if (*it == M) ++m;
    if (*it == L) ++p;
    it++;
  }
  cout << "M - " << m << "  L - " << p << endl; 
  l.sort();
  it = l.begin();
  for (int i = 0; i < l.size() ; ++i){
    cout << *it << ' ';
    it++;
  }
  getch();
}