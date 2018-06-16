#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 101

typedef struct esame{
	char* sigla;
	int crediti;
	int diff;
}esame;

esame* crea_esame(){
	esame* new = malloc(sizeof(esame)); 
	new->sigla = malloc(LEN * sizeof(char));
	scanf("%s%d%d", new->sigla, &(new->crediti), &(new->diff));
	return new;
}

void stampa(esame** e, int n){
	int i;
	for(i = 0; i < n; i++)
		printf("sigla %s crediti %d diff %d\n", e[i]->sigla, e[i]->crediti, e[i]->diff);
}

int comparestring(const void* a, const void* b){
	char** aa = (char**)a;
	char** bb = (char**)b;
	return strcmp(*aa,*bb);
}

void stampa_esami(char** a, int n){
	int i;
	for(i = 0; i < n; i++)
		printf("%s\n",a[i]);
}


int compare(const void* a, const void* b){
	esame** aa = (esame**)a;
	esame** bb = (esame**)b;
	
	if((*aa)->crediti > (*bb)->crediti){
		return -1;
	}else if((*aa)->crediti == (*bb)->crediti){
		if((*aa)->diff < (*bb)->diff)
			return -1;
		else if((*aa)->diff == (*bb)->diff)
			return strcmp((*aa)->sigla, (*bb)->sigla);
		else
			return 1;
	}else
		return 1;		
}

void scegli_esami(esame** e, char** scelti, int n, int k){
	int i;
	int j = 0;
	int somma = 0;
	scelti[j] = e[0]->sigla;
	somma += e[0]->crediti;
	
	for(i = 1; i < n; i++){
		if(somma + e[i]->crediti <= k){
			j++;
			scelti = realloc(scelti, (j+1) * sizeof(char*));
			scelti[j] = e[i]->sigla;
			somma += e[i]->crediti;
		}
		if(somma == k)
			break;
	}
	//stampa_esami(scelti, j+1);
	qsort(scelti, j+1, sizeof(char*), comparestring);
	stampa_esami(scelti, j+1);
}

void ordina(esame** e, int n){
	qsort(e,n, sizeof(esame*),compare);
}

int main(){
	int n, k,i;
	esame** e;
	char** scelti = malloc(sizeof(char*));
		
	scanf("%d%d", &k, &n);
	e = malloc(n * sizeof(esame*));
	for(i = 0; i < n; i++){
		e[i] = crea_esame();
	}
	//stampa(e, n);
	ordina(e,n);
	//stampa(e,n);
	scegli_esami(e, scelti, n, k);
	return 0;
}
