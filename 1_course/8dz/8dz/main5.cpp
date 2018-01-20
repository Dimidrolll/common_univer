#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

void func(double a[10][10], int n)
{
  int i,j,ma = -999,k,l;double t;
  for (i = 0; i < n; i++)
    {
        if (a[i][i] > ma)
        {
            ma = a[i][i];
            k = i;
            l = i;
        }
        if ( a[i][n - i - 1] > ma )
        {
            ma = a[i][n - i - 1];
            k = i;
            l = n - i - 1;
        }
	}
	i = j = n / 2;
	t = a[i][j];
	a[i][j] = a[k][l];
	a[k][l] = t;
}

void main()
{ 
	int n, k, l, t, ma = 0, i, j;double a[10][10];
	ifstream f;
	f.open("dat.txt");
	f >> n; //סעמכבצû
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			f >> a[i][j];
	}
	f.close();

  func(a,n);
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw(2) << a[i][j];
		cout << endl;
	}
}