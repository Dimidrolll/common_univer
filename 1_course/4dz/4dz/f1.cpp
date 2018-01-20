#include "fff.h"
int sokr1(int a,int b){
	for(int i3=2;i3<=sqrt(float(a));i3++){
		if((a%i3==0)&&(b%i3==0)){b=b/i3;a=a/i3;}
	
	}
	return a;
}