#include <iostream>
using namespace std;

void main()
{
    
	int N,i;
	double a,sum,b;
	cin>>N>>a;
	b=1.0/(a*a);
	sum=b;
	cout<<b<<endl;
	for(i=2;i<=N;i++){
				b=b*(2*i-1)*(2*i-2)/(a*a);
				sum+=b;
				cout<<b<<endl;
						
	}
	cout<<sum<<endl;
}