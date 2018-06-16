#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 101

typedef struct nodo{
	char* nome;
	struct nodo* next;
}nodo;

nodo* enqueue(nodo* q, nodo** tail){
	nodo* new = malloc(sizeof(nodo));
	new->nome = (char *)malloc(LEN * sizeof(char));
	scanf("%s", new->nome);
	new->next = NULL;

	if(q == NULL){
		q = new;
		*tail = new;
	}else{
		(*tail)->next = new;
		*tail = new;
	}	
	return q;
}

nodo* dequeue(nodo* q){
	nodo* temp = q;
	q = q->next;
	free(temp);
	return q; 
}

int compare(const void* s1, const void* s2){
	char** a = (char**)s1;
	char** b = (char**)s2;
	return strcmp(*a,*b);
}

void stampa(char** rimasti, int lencoda){
	int i;
	for(i = 0; i < lencoda; i++){
		printf("%s\n",rimasti[i]);	
	}
	printf("$\n");
}

void cleanup(nodo *q){
	nodo* curr = q;
	while(q){
		curr = q;	
		q = q->next;
		free(curr);
	}
}

cleanup2(char** rimasti, int lencoda){
	int i;
	for(i = 0; i< lencoda; i++)
		free(rimasti[i]);
	free(rimasti);
}

void riempi(char** rimasti, nodo* q){
	int i = 0;
	while(q){
		rimasti[i] = q->nome;
		q = q->next;
		i++;
	}
}

int main(){
	nodo* q = NULL;
	nodo* tail = NULL;
	int e,lencoda = 0;
	char** rimasti;

	scanf("%d",&e);
	while(e != 0){
		if(e == 1){
			lencoda++;
			q = enqueue(q, &tail);
		}else if(e == 2){
			q = dequeue(q);
			lencoda--;	
		}
		scanf("%d",&e);
	}

	rimasti = malloc(lencoda * sizeof(char*));
	riempi(rimasti, q);
	cleanup(q);

	qsort(rimasti,lencoda,sizeof(char*),compare);
	stampa(rimasti,lencoda);
	cleanup2(rimasti,lencoda);
	return 0;
}
