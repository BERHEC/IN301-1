#include "stdio.h"
#define e 0.0001

int diff(double a, double b){

	if(a - b < 0) if(b - a < e) return 1;
	if(a - b > 0) if(a - b < e) return 1;	
	
	return 0;	
}



int main(){
	
	int i;
	double S, Sm;
	S = 0;
	Sm = -100*e;
	i = 1;
	
	while(!diff(Sm, S)){
	Sm = S;
	S += 1.0/(float)(i*i);
	i++;}
	
	printf("%f\n", S);

  return 0;

}

