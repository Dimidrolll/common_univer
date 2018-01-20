#include <iomanip>
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

void func(int a[10][10], int n, int m)
{
  int i,j;
  for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < n - 1; j++)
			if (a[i][j] * a[i][j + 1] >= 0) 
				break;
		if (j == n - 1)
			cout << i + 1 << endl;
    }
}
void main()
{ 
	int n, m, i, j, k = 0, a[10][10];
	ifstream f("input14.txt");
	f >> n; f >> m;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			f >> a[i][j] ;
	}


  func(a,n,m);
	
	getch();
}