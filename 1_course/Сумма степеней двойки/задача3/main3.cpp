#include <iostream>
using namespace std;
void main()
{
	long long int a,n,sum,i;
	a=2;
	sum=2;
	cin>>n;
	for(i=2;i<=n;i++){
		a=a*a;
		sum+=a;
	}
	cout<<sum<<endl;

}