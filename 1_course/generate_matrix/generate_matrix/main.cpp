#include <fstream>

using namespace std;

void main()
{
  fstream f("C:\\Users\\acer\\Documents\\Visual Studio 2010\\Projects\\polinom_Bobrov\\polinom_Bobrov\\input.txt", ios::out);
  int a[100][100];
  for (int i = 0; i < 10; ++i)
    for(int j = 0; j < 10; ++j)
      if (i == j) a[i][j] = 0;
      else a[i][j] = a[j][i] = rand() % 2;
  for (int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
      f << a[i][j];
      if (j != 9) f << ' ';
    
    }
    f << endl;
  }
  f.close();
}