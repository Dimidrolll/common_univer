#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

void main()
{
  fstream f;
  f.open("a_bin2.dat",ios::out|ios::in|ios::trunc|ios::binary);
  int N; double t;
  cin >> N;
  for (int i = 0; i < N; ++i){
    cin >> t;
    f.write((char *)& t, sizeof(t));
  }
  f.seekp(0,0);
  f.seekg(0,0);
  for (int i = 0; i < N; ++i){
    //f.seekp(0,0);
    //f.seekg(0,0);
    f.read((char *)& t, sizeof(t));
    cout << double(t) << ' ';
    
  }
  cout << endl;
  for (int i = 0; i < N; ++i){
    f.seekg(8 * i,0);
    f.read((char *)& t, sizeof(t));
    //cout << t << ' ';
    f.seekg(8 * i,0);
    if (t >= 0) f.write((char *)& t, sizeof(t));
    else {
      t = 0;
      f.write((char *)& t, sizeof(t)); 
    }
  }
  cout << endl;
  f.seekp(0,0);
  f.seekg(0,0);
  for (int i = 0; i < N; ++i){
    f.read((char *)& t, sizeof(t));
    cout << double(t) << ' ';
  }
  cout << endl;
  getch();
}