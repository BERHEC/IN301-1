#include "stdio.h"
#define e 0.0001

void ech(int *a, int *b){

	int c;
	c = *a;
	*a = *b;
	*b = c;	
	
}

void reinitPointeur(int *p){
	*p = NULL;	
}



int main(){
	
	int i = 0;
	int j = 4;
	char tab[10];
	char (*p)[10] = *tab;
	int *q;
	
	i = sizeof(char);	
	printf("Taille char: %d\n", i);
	i = sizeof(int);	
	printf("Taille int: %d\n", i);
	i = sizeof(double);	
	printf("Taille double: %d\n", i);
	i = sizeof(char*);	
	printf("Taille char*: %d\n", i);
	i = sizeof(void*);	
	printf("Taille void*: %d\n", i);
	i = sizeof(int*);
	printf("Taille int*: %d\n", i);
	i = sizeof(long int);	
	printf("Taille lg int: %d\n", i);
	i = sizeof(long long int);	
	printf("Taille lg lg int: %d\n", i);
	i = sizeof(short int);	
	printf("Taille st int: %d\n", i);
	i = sizeof(int**);	
	printf("Taille int**: %d\n", i);
	i = sizeof(double*);	
	printf("Taille double*: %d\n", i);
	i = sizeof(int[10]);	
	printf("Taille int[10]: %d\n", i);
	i = sizeof(char[7][3]);	
	printf("Taille char[7][3]: %d\n\n", i);
	i = sizeof(tab);	
	printf("Taille tab: %d\n", i);
	i = sizeof(tab[0]);	
	printf("Taille tab[0]: %d\n", i);
	i = sizeof(&tab[0]);	
	printf("Taille &tab[0]: %d\n", i);
	i = sizeof(*&tab);	
	printf("Taille *&tab: %d\n", i);
	i = sizeof(*&tab[0]);	
	printf("Taille *&tab[0]: %d\n\n", i);
	i = sizeof(p);
	printf("Taille p: %d\n", i);
	i = sizeof(*p);
	printf("Taille *p: %d\n", i);
	i = sizeof(*p[2]);
	printf("Taille *p[2]: %d\n", i);
	i = sizeof(&(*p)[2]);
	
	printf("Taille &(*p)[2]: %d\n\n", i);
	printf("Echange: \n(i=%d,j=%d)\n", i,j);
	ech(&i,&j);
	printf("(i=%d,j=%d)\n", i,j);
	
	q = &j;
	reinitPointeur(q);
	printf("(ReinitPointeur: j=%d)\n", j);
	
	

  return 0;

}

