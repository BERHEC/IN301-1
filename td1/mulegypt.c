#include "stdio.h"

int main(){
	
	int X = 23;
	int Y = 87;
	int Z = 0;
	
	printf("  %d * %d\n", X, Y);
	
	while(X != 1){
	
	if(X%2){
		X = (X - 1);
		Y = Y;
		Z += Y;}
	else{
		X = X/2;
		Y = Y*2;}
		
	printf("= %d * %d + %d\n", X, Y, Z);}
	
	X = Y + Z;
	printf("= %d\n", X);
	

	return 0;

}

