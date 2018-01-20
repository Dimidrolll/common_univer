#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;

void main ()
{
  cout << "1 and 0" << endl;
  bool queue = 1, clossse[3][3];
  int i,j,i1,j1, a[3][3];
  for (int inp1 = 1; inp1 <= 3; ++inp1)
      for (int inp2 = 1; inp2 <= 3; ++inp2) 
        clossse[inp1][inp2] = 0;
  for (int inp1 = 1; inp1 <= 3; ++inp1)
      for (int inp2 = 1; inp2 <= 3; ++inp2) 
        a[inp1][inp2] = -1;
  for (i = 1; i <= 9; ++i){
    
    for (int drow1 = 1; drow1 <= 3; ++drow1){
      for (int drow2 = 1; drow2 <= 3; ++drow2) 
        cout << setw(2) << a[drow1][drow2];

      cout << endl;
    }
    cout << "vvod coordinat (stroka potom stolbez)" << endl;
    cin >> i1 >> j1;
    if (clossse[i1][j1] == 0)
      if (queue){ 
        a[i1][j1] = 1;
        queue = 0;
        clossse[i1][j1] = 1;
      } else { 
        a[i1][j1] = 0;
        queue = 1;
        clossse[i1][j1] = 1;
      }
    else {
      cout << "eshe raz invalid vvod" << endl;
      --i;
    }
  
    if (a[1][1] == 1 && a[1][2] == 1 && a[1][3] == 1) {cout << "first" << endl; break;};
    if (a[2][1] == 1 && a[2][2] == 1 && a[2][3] == 1) {cout << "first" << endl; break;};
    if (a[3][1] == 1 && a[3][2] == 1 && a[3][3] == 1) {cout << "first" << endl; break;};
    if (a[1][1] == 1 && a[2][1] == 1 && a[3][1] == 1) {cout << "first" << endl; break;};
    if (a[1][2] == 1 && a[2][2] == 1 && a[3][2] == 1) {cout << "first" << endl; break;};
    if (a[1][3] == 1 && a[2][3] == 1 && a[3][3] == 1) {cout << "first" << endl; break;};
    if (a[1][1] == 1 && a[2][2] == 1 && a[3][3] == 1) {cout << "first" << endl; break;};
    if (a[3][1] == 1 && a[2][2] == 1 && a[1][3] == 1) {cout << "first" << endl; break;};

    if (a[1][1] == 0 && a[1][2] == 0 && a[1][3] == 0) {cout << "second" << endl; break;};
    if (a[2][1] == 0 && a[2][2] == 0 && a[2][3] == 0) {cout << "second" << endl; break;};
    if (a[3][1] == 0 && a[3][2] == 0 && a[3][3] == 0) {cout << "second" << endl; break;};
    if (a[1][1] == 0 && a[2][1] == 0 && a[3][1] == 0) {cout << "second" << endl; break;};
    if (a[1][2] == 0 && a[2][2] == 0 && a[3][2] == 0) {cout << "second" << endl; break;};
    if (a[1][3] == 0 && a[2][3] == 0 && a[3][3] == 0) {cout << "second" << endl; break;};
    if (a[1][1] == 0 && a[2][2] == 0 && a[3][3] == 0) {cout << "second" << endl; break;};
    if (a[3][1] == 0 && a[2][2] == 0 && a[1][3] == 0) {cout << "second" << endl; break;};
  
  }
  
  getch();
}