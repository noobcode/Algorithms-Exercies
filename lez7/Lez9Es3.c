#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 20

typedef struct Struttura{
	char* stringa;
	char* aPrincipale;
}Struttura;

int comparechar(const void* a, const void* b){
	char* aa = (char*)a;
	char* bb = (char*)b;
	return ((*aa)-(*bb));
}

char* ana_princ(char** a,int len){
	int i;
	char* b = malloc(LEN * sizeof(char));
	strcpy(b,*a);
	for(i = 0; i < len; i++){
		qsort(b,strlen(b), sizeof(char),comparechar);
	}
	return b;
}


int compare_ana(const void* a, const void* b){
	Struttura* aa = (Struttura*)a;
	Struttura* bb = (Struttura*)b;
	return strcmp((aa)->aPrincipale,(bb)->aPrincipale);
}

int compare_string(const void* a, const void* b){
	Struttura* aa = (Struttura*)a;
	Struttura* bb = (Struttura*)b;
	if(strcmp((aa)->aPrincipale,(bb)->aPrincipale) == 0)
		return strcmp((aa)->stringa,(bb)->stringa);
	if(strcmp((aa)->aPrincipale,(bb)->aPrincipale) < 0)
		return -1;
	else return 1;
}

int main(){
	int n, i;
	char** s;
	char* prova;
	Struttura* str;
	
	scanf("%d",&n);
	str = malloc(n * sizeof(Struttura));
	for(i = 0; i < n; i++){
		str[i].stringa = malloc(LEN * sizeof(char*));
		scanf("%s",str[i].stringa);
		str[i].aPrincipale = malloc(LEN * sizeof(char*));
		str[i].aPrincipale = ana_princ(&(str[i].stringa),LEN);
	}
	qsort(str,n,sizeof(Struttura),compare_ana);
	qsort(str,n,sizeof(Struttura),compare_string);
	//for(i = 0; i < n; i++) printf("\n%s %s",str[i].stringa, str[i].aPrincipale);
	for(i = 0; i < n-1; i++){
		printf("%s",str[i].stringa);
		if(strcmp(str[i].aPrincipale,str[i+1].aPrincipale) == 0)
			printf(" ");
		else	printf("\n");	
	}
	printf("%s",str[i].stringa);
	
	return 0;
}
