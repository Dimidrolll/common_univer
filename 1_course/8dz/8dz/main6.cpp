#include <iomanip>
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

void func(double a[10][10], int n)
{
  int sum = 0;
  double b[10];
  for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) 
			{
				b[i] = a[i][j];
			}
    }
  }
  for (int i = 0; i < n; i++)
    sum += b[i];
   for (int i = 0; i < n; i++)
	 {
     if (i % 2 == 1)
		for (int j = 0; j < n; j++)
		{
		  a[i][j] /= sum;
    }
  }
   cout << sum << endl;
}

void main()
{ 
	int n, m, k , l , o , p, t, i, j;
  double a[10][10];
	ifstream f("input6.txt");
	f >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			f >> a[i][j] ;
	}

  func(a,n);


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw(5) << a[i][j] << " ";
		  cout << endl;
	}
  getch();
}