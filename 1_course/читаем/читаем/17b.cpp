#include <iostream>
#include <cmath>
using namespace std;


void main(){
	long sokr1(long,long);
	long sokr2(long,long);
	long rashet1(long );
	long rashet2(long );
	int n;
	cout<<"N"<<endl;
	cin>>n;
	cout<<sokr1(rashet1(n),rashet2(n))<<endl<<"-----"<<endl<<sokr2(rashet1(n),rashet2(n))<<endl;
}

long sokr1(long a,long b){
	for(long i3=2;i3<=sqrt(float(a));i3++){
		while((a%i3==0)&&(b%i3==0)){b=b/i3;a=a/i3;}
	
	}
	return a;
}
long sokr2(long a,long b){
	for(long i4=2;i4<=sqrt(float(a));i4++){
		while((a%i4==0)&&(b%i4==0)){b=b/i4;a=a/i4;}
	
	}
	return b;

}
long rashet1(long q){
	long s1=1,sum=0;
	for(int i1=1;i1<=q;i1++) {s1=1;
				for(long j1=1;j1<=q;j1++) s1*=j1;
				s1=s1/i1;
				sum=sum+s1;
	}
	return sum;

}
long rashet2(long q){
	long s2=1;
	for(long i2=1;i2<=q;i2++) s2*=i2;
	return s2;

}
