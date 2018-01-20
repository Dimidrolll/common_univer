#include <iostream>
#include <cmath>
using namespace std;


void main(){
	int sokr1(int,int);
	int sokr2(int,int);
	int rashet1(int );
	int rashet2(int );
	int n;
	cout<<"N"<<endl;
	cin>>n;
	cout<<sokr1(rashet1(n),rashet2(n))<<endl<<"_"<<endl<<sokr2(rashet1(n),rashet2(n));
}

int sokr1(int a,int b){
	for(int i3=2;i3<=sqrt(float(b));i3++){
		if((a%i3==0)&&(b%i3==0)){b=b/i3;a=a/i3;}
	
	}
	return a;
}
int sokr2(int a,int b){
	for(int i4=2;i4<=sqrt(float(b));i4++){
		if((a%i4==0)&&(b%i4==0)){b=b/i4;a=a/i4;}
	
	}
	return b;

}
int rashet1(int q){
	int s1=1,sum=0;
	for(int i1=1;i1<=q;i1++) {s1=1;
				for(int j1=1;j1<=i1;j1++) s1*=j1;
				sum=sum+s1;
	}
	return sum;

}
int rashet2(int q){
	int s2=1;
	for(int i2=1;i2<=q;i2++) s2*=i2;
	return s2;

}
