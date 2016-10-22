#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct Tableau{
	int tab[2000]; //important pour pouvoir faire varier la taille des tableaux jusqu'à 1500
	int taille;	
	
};

typedef struct Tableau TB;

int alea(int n)
{
	return rand()%n;		
}

TB remplinit(TB t, int taille, int n){
	int i;
	t.taille = taille;
	for (i=0; i<t.taille; i++)
		t.tab[i] = alea(n);	
	return t;
}

void affichtab(TB t){
	int i;
	for (i=0; i<t.taille; i++)
		printf("(%d)", t.tab[i]);
	printf("\n");
}

int mintab(TB t, int d){
	int i;
	int m = d; //  sinon problème avec la dernière valeur;
	for (i=d; i<t.taille; i++)
		if (t.tab[m] > t.tab[i]) m = i;
	return m;
}


int maxtab(TB t, int d){
	int i;
	int m = d;
	for (i=d; i<t.taille; i++)
		if (t.tab[m] < t.tab[i]) m = i;
	return m;
}

TB swap (TB t, int i, int j){
	int temp;
	temp = t.tab[i];
	t.tab[i] = t.tab[j];
	t.tab[j] = temp;
	return t;	
}

TB tinverse(TB t){
	int i;
	for(i=0; i<t.taille/2; i++){
	t = swap(t,i, t.taille-i-1);
	}
	return t;
}

TB triinsertion(TB t){
	int TC,i,temp,p;
	for(TC = 0; TC < t.taille; TC++)
	{
		temp = t.tab[TC+1]; //voir TC+1
		p = 0;
		while(t.tab[p]<temp) p++;
		for(i=TC; i >= p; i--)
			t.tab[i+1] = t.tab[i];
		t.tab[p] = temp;
	}
	return t;
}


TB triselection(TB t){
	int i,m;
	for(i = 0; i < t.taille; i++)
		{m = mintab(t,i);
		t = swap(t,i,m);}	
	return t;
}

TB tribulles(TB t){ //permutation
	int TC,i,ech;
	for(TC = 1; TC <= t.taille - 1; TC++)
	{
		ech = t.taille; //**
		for(i = t.taille - 1; i >= TC; i--)
			if(t.tab[i- 1] > t.tab[i])
			{
				t = swap(t,i,i-1);
				ech = i;} //**
		i = ech;} //** améliorations vues en IN303
	return t;
}

int cpinsertion(TB t){
	int comp = 0;
	int TC,i,temp,p;
	for(TC = 0; TC < t.taille - 1; TC++)
	{
		temp = t.tab[TC+1];
		comp ++;
		p = 0;
		while(t.tab[p]<temp) {p++; comp++;}
		for(i=TC; i >= p; i--)
			{
				t.tab[i+1] = t.tab[i];
				comp++;
			}
		t.tab[p] = temp;
	}
	return comp;
}


int cpselection(TB t){
	int comp = 0;
	int i,m;
	for(i = 0; i < t.taille; i++)
		{m = mintab(t,i);
		t = swap(t,i,m);
		comp += (2*(t.taille - i + 1));}	
	return comp;
}

int cpbulles(TB t){ //permutation
	int comp = 0;
	int TC,i,ech;
	for(TC = 1; TC <= t.taille - 1; TC++)
	{
		ech = t.taille;
		for(i = t.taille - 1; i >= TC; i--)
			{
			if(t.tab[i- 1] > t.tab[i])
			{
				t = swap(t,i,i-1);
				ech = i;
			}
			comp+=2;}
		TC = ech;
		comp++;}
	return comp;
}

TB insertri(TB t, int e){
	int TC,i,k;
	if(t.taille == 0){
		t.taille = 1;
		t.tab[0] = e;}
		
	else {
		i = 0;
		while(i < t.taille && t.tab[i] < e) i++;
		if(i == t.taille && t.tab[i] < e) k = t.taille + 1;
		else k = i;
		for(i = t.taille; i >= k; i--)
			t.tab[i] = t.tab[i-1];
		t.tab[k] = e;
		t.taille ++;
	}
	
	return t;
}

int main(){
	
	int i,j;
	srand(time(NULL));
	TB t[15];
	
	TB T = remplinit(T,35,80); //ne marche pas avec gnuplot
	T = triinsertion(T);
	T = tinverse(T); //Le but est d'en faire un tableau dur à trier.
	
	printf("Tableau:");
	affichtab(T);
	printf("Insertion: %d\nSéléction: %d\nPermutation: %d\n", cpinsertion(T), cpselection(T), cpbulles(T));
	
	printf("\n15 tableaux:\n");
	
	for(i = 0; i < 15; i++)
	{
		t[i] = remplinit(t[i], (i+1)*100, 80); 
	}
	printf("Taille Insertion Séléction Permutation \n");
	for (i = 0; i < 15; i++) //pour gnuplot
	{
		printf("%d %d %d %d\n", t[i].taille, cpinsertion(t[i]), cpselection(t[i]), cpbulles(t[i]));
	}
	//~ printf("\nSéléction:\n");
	//~ for (i = 0; i < 15; i++)
	//~ {
		//~ printf("%d\n", cpselection(t[i]));
	//~ }
	//~ printf("\nPermutation:\n");
	//~ for (i = 0; i < 15; i++)
	//~ {
		//~ printf("%d\n", );
	//~ }
		
	


  return 0;

}


