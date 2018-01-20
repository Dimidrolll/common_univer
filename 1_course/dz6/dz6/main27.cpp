#include <iostream>
#include <fstream>
using namespace std;
int input(int *a)
{
	fstream f;
	int i=0;
	f.open("rez.txt",ios::in);
	while(!f.eof())
	{
		i++;
		f>>a[i];
		
		cout<<a[i]<<' ';
	}
	f.close();
	return i;
}
int Search(int *a,int n, int x)
{
	int L=0, R=n,sred;
	for(int i=0;i<n;i++) 
	{
			if(a[i]==x)break;
			if((i==n-1)&&(a[i]!=x))return -3;
	}
	while(L<R-1)
	{
		sred=(L+R)/2;
		if(x<=a[sred]) L=sred;
		else R=sred;
	}
	return L;
}
void main()
{
	int a[9999],n,x;
	cout<<"X"<<endl;
	cin>>x;
	n=input(a);
	cout<<endl;
	int t=Search(a,n,x);
	if (t==-3) cout<<"not found";
	else cout<<t-1;


	cout<<endl;

}