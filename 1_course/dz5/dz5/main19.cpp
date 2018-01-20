#include <iostream>
#include <limits.h>
using namespace std;
void main()

{
	int a,b,n,s[100],j,q=0;
	cout<<"n,[a,b]"<<endl;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		s[i]=a+rand()%(b-a+1);
	}
	cout<<"bilo:"<<endl;
	for(int i=0;i<n;i++)cout<<s[i]<<' ';
	cout<<endl;
	for(j=0;j<n;j++)
		if(s[j]<0) {
			for(int i=n;j+1<i;i--) s[i]=s[i-1];
			s[j+1]=INT_MAX;	
			n++;
		}



	cout<<"stalo:"<<endl;
	for(int i=0;i<(n);i++)cout<<s[i]<<' ';
	cout<<endl;
	
}