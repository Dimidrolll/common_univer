#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void Input(int *s,int n,int a,int b)
{ 
	srand(time(NULL));
	for (int i=0;i<n;i++) s[i]=a+rand()%(b-a+1);
	for (int i=0;i<n;i++) cout<<s[i]<<' ';
	cout<<endl;
}
int summa(int s)
{
	int summ=0;
	while(s>0)
	{
		summ+=s%10;
		s=s/10;
	}
	return summ;
}
int Array_sum_chet(int *C,int *D,int n)
{ 
	int j=0;
	for(int i=0;i<n;i++)
	{
		if((summa(C[i]))%2==0)
		{
			D[j]=C[i];
			j++;
		}
	}
	for (int i=0;i<j;i++) cout<<D[i]<<' ';
	cout<<endl;
	return j;
}
int Array_up(int *D,int n)
{ 
	int i;
	for( i=0;i<n-1;i++)
		if (D[i]>=D[i+1]) break;
	if ( i==n-1)
	{
			cout<<"yes";
			return 1;
	}
	else
	{
		cout<<"no";
		return 0;
	}

	
}
void Sort(int *D,int n)//простой выбор
{
	int k,m;
	for (int i=n-1;i>=0;i--)
	{
		k=i;
		m=D[i];
		for (int j=0;j<i;j++)
			if(D[j]>m)
			{
				k=j;
				m=D[k];
			}
		if(k!=i)
		{
			D[k]=D[i];
			D[i]=m;
		}
	}
	for (int i=0;i<n;i++)cout<<D[i]<<' ';
}
void main()
{
	int C[9999],a,b,n,t,Truth;
	cout<<"nab"<<endl;
	cin>>n>>a>>b;
	Input(C,n,a,b);
	int D[9999];
	t=Array_sum_chet(C,D,n);
	Truth=Array_up(D,t);
	cout<<endl;
	if(Truth==0) Sort(D,t);
	else cout<<"Array has been sorted";
	cout<<endl;
}