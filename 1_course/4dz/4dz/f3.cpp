#include "fff.h"
int rashet1(int q){
	int s1=1,sum=0;
	for(int i1=1;i1<=q;i1++) {s1=rashet2(q)/i1;
		
				sum=sum+s1;
	}
	return sum;

}