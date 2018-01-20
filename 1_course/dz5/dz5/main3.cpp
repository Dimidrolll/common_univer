#include <iostream>
using namespace std;
void main()

{
	int a,b,n,max=-9999,s[100],j=0,q=0;
	cout<<"n,[a,b]"<<endl;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		s[i]=a+rand()%(b-a+1);
		if(s[i]>max) max=s[i];
	}
	cout<<"bilo:"<<endl;
	for(int i=0;i<n;i++)cout<<s[i]<<' ';
	cout<<endl;
	for( j=0;j<n;j++)
	{
		
		while(s[j]==max){ for(int i=j;i<n;i++) s[i]=s[i+1];
											q++;
											//for(int i=0;i<(n-q);i++)cout<<s[i]<<' ';
											//cout<<endl;
											}
	
	}
	cout<<endl<<"max="<<max<<endl;
	cout<<"stalo:"<<endl;
	for(int i=0;i<(n-q);i++)cout<<s[i]<<' ';
	cout<<endl;
	
}