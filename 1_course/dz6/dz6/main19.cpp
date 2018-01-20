#include <iostream>
#include <fstream>
using namespace std;
void Sort_bin_insert(int *a,int n)
{
	int x,left,right,sred;
	for(int i=0;i<n;i++)
	{
		if(a[i-1]<a[i])
		{
			x=a[i];
			left=0;
			right=i-1;
			do
			{
				sred=(left+right)/2;
				if(a[sred]>x)left=sred+1;
				else right=sred-1;
			}
			while(left<=right);
			for(int j=i-1;j>=left;j--)a[j+1]=a[j];
			a[left]=x;
		}
	}
}
void input(int *a,int n)
{
	fstream f;
	f.open("input.txt",ios::in);
	for(int i=0;i<n;i++)
	{
		f>>a[i];
		cout<<a[i]<<' ';
	}
	f.close();
}
void rezult(int *a,int n)
{
	fstream f;
	f.open("rez.txt",ios::out);
	for(int i=0;i<n;i++)
	{
		f<<' '<<a[i];
		cout<<a[i]<<' ';
	}
	f.close();
}
void main()
{
	int a[9999],n;

	cout<<"vvedi n<50"<<endl;
	cin>>n;
	input(a,n);
	cout<<endl;
	Sort_bin_insert(a,n);
	rezult(a,n);

	cout<<endl;

}