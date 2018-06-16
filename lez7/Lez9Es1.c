#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

typedef struct nodo{
	char* str;
	int occorrenze;
}nodo;


int compare_string(const void* a, const void* b){
	char** s1 = (char**)a;
	char** s2 = (char**)b;
	return strcmp(*s1,*s2);
}

int compare_occorrenze(const void* a,  const void* b){
	nodo* aa = (nodo*)a;
	nodo* bb = (nodo*)b;
	return ((bb)->occorrenze - (aa)->occorrenze);
}

void kstringhe(nodo* stringhe,int len, int k){

}

int main(){
	int n, k, i, j, count;
	char **s, *temp;
	nodo* stringhe;       
	
	scanf("%d%d",&n,&k);
	
	// leggo le n stringhe
	s = malloc(n * sizeof(char*));
	for(i = 0; i < n; i++){
		s[i] = malloc(MAXLEN * sizeof(char));
		scanf("%s",s[i]);
	}
	
	// alloco un array di nodi (stringa, occorrenze) e le inizializzo a 0
	stringhe = malloc(n * sizeof(nodo));
	for(i  = 0; i < n; i++)
		stringhe[i].occorrenze = 0;
	// ordino le n stringhe
	qsort(s,n,sizeof(char*),compare_string);
	// riempio array dei nodi contenente le occorrenze
	j = -1;
	temp = malloc(MAXLEN * sizeof(char*));
	for(i = 0; i < n; i++){ 
		if(strcmp(temp,s[i]) != 0){	// se la stringa è diversa da temp 
			temp = s[i];	
			count = 0;		// contatore per ogni stringa
			j++;			// posizione dell'array di nodi
			stringhe[j].str = s[i];
			//printf("ok\n"); 
		}
		if(strcmp(temp,s[i]) == 0){
			count++;
			stringhe[j].occorrenze++;
		}
	}
	
	qsort(stringhe, n, sizeof(nodo),compare_occorrenze);
	qsort(stringhe,k,sizeof(nodo),compare_string);
	for(i = 0; i < k; i++)
		printf("%s\n",stringhe[i].str);
	
	
	return 0;	
}
