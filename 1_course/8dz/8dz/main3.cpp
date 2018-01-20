#include <iomanip>
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

void maxim(int a[10][10], int n, int m,int &k, int &l)
{
  int max = -9999;
  for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > max) 
			{
				max = a[i][j];
				k = i;
				l = j;
			}
    }
  }
}
void minim(int a[10][10], int n, int m,int &k, int &l)
{
  int min = 9999;
  for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] < min) 
			{
				min = a[i][j];
				k = i;
				l = j;
			}
      
    }
  }
}

void main()
{ 
	int n, m, k , l , o , p, t, i, j, a[10][10];
	ifstream f("input3.txt");
	f >> n;
	f >> m; 
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			f >> a[i][j] ;
	}

  maxim(a,n,m,k,l);
  minim(a,n,m,p,o);

	t = a[k][l];
	a[k][l] = a[p][o];
	a[p][o] = t;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << setw(2) << a[i][j] << " ";
		  cout << endl;
	}
  //cout << 1;
  getch();
}