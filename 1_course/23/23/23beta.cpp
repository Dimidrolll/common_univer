#include <iostream>
using namespace std;

void main()
{  
	int i;
	double x,a,sum,e;
	cin>>x>>e;
	sum=x;               
	a=x;
	i=1;
	while(abs(a)>e){
			i+=1;
			a=(a*((-1)*x*x))/((2*i-1)*(2*i-2));
			
			sum+=a;
	}
	
	
	cout<<sum<<endl;
}