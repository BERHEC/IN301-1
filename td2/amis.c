#include "stdio.h"
#define e 0.00001

int echanger(int n, int m){
	int t;
	
	t = m;
	m = n;
	n = t;	
}

int somme_div(int a){
	int s = 0;
	int i;
	
	for(i = 1; i <= a/2; i++)
	    if (a%i == 0) s+=i;
	    
	return s;	
}


int Amis(int n, int m){

		int s1 = 0;
		int s2 = 0;	
		int i;	
		
		if(n > m) echanger(n,m);		
		
		for (i = 1; i <= n/2; i++)
		{
			if(n%i == 0) s1+=i;
			if(m%i == 0) s2+=i; 		
		}
		for (i = n/2 + 1; i <= m/2; i++)
		{
			if(m%i == 0) s2+=i;
		}
		
		if((s1 == m) && (s2 == n)) return 1;
		else return 0;	
	
}

int couples(int NMAX){
	int m,n;
		
	for(m = 1; (m < NMAX - 1); m++)
		{n = somme_div(m);
		if(m > n)	
		if (somme_div(n) == m)
		printf("(%d,%d)\n", n,m);}
	
}


int main(){
	
	int i,n,m, NMAX;
	
	do{	scanf("%d\n", &n);
	scanf("%d", &m);} while((n < 0) || (m < 0));
	
	

	printf("Les nombres sont ");
	if(!Amis(n,m))printf("pas ");
	printf("amis.\n");
	
	do scanf("%d", &NMAX); while((n < 0) || (m < 0));
	couples(NMAX);

    return 0;

}

