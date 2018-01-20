#include "fff.h"
int sokr2(int a,int b){
	for(int i4=2;i4<=sqrt(float(a));i4++){
		if((a%i4==0)&&(b%i4==0)){b=b/i4;a=a/i4;}
	
	}
	return b;

}