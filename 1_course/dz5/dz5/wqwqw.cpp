#include <iostream>
using namespace std;
void sort_bubble_mod_up(int *m,int *b,int n)
{
	int i=n,t;
	bool f;
	do 
	{
		f=true;
		for (int k=0;k<i-1;k++)
			if (m[b[k]]>m[b[k+1]])
			{
				t=m[b[k]];
				m[b[k]]=m[b[k+1]];
				f=false;
				m[b[k+1]]=t;
			}
		i--;
	}
	while(!f && i>1);
}
void sort_bubble_mod_down(int *m,int *b,int n)
{
	int i=n,t;
	bool f;
	do 
	{
		f=true;
		for (int k=0;k<i-1;k++)
			if (m[b[k]]<m[b[k+1]])
			{
				t=m[b[k]];
				m[b[k]]=m[b[k+1]];
				f=false;
				m[b[k+1]]=t;
			}
		i--;
	}
	while(!f && i>1);
}
void main()

{
	int a,b,n,s[1000],m[1000],j=0,q=0;
	cout<<"n,[a,b]"<<endl;
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		s[i]=a+rand()%(b-a+1);
		if(s[i]%2==0)
		{
			m[j]=i;
			j++;
		}
	}

	for(int i=0;i<n;i++)cout<<s[i]<<' ';
	cout<<endl;

	sort_bubble_mod_up(s,m,j);

	j=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]%2!=0)
		{
			m[j]=i;
			j++;
		}
	}

	sort_bubble_mod_down(s,m,j);

	for(int i=0;i<n;i++)cout<<s[i]<<' ';
	cout<<endl;

}