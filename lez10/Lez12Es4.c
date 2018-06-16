#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* next;
}nodo;


void insert_coda(nodo** head, nodo** tail, int el){
	nodo* new = malloc(sizeof(nodo));
	new->info = el;
	new->next = NULL;
	
	if(*head == NULL){
		*head = new;
		*tail = new;
	}else{
		(*tail)->next = new;
		*tail = new;
	}
}

void stampa(nodo* head){
	while(head){
		printf("%d ",head->info);
		head = head->next;	
	}
}

void somme(nodo* head,int* somma){
	if(head->next == NULL){
		*somma = head->info;
		head->info = 0;	
		return;
	}
	else{
		int temp;
		somme(head->next, somma);
		temp = *somma;
		*somma += head->info;
		head->info = temp;
		
	}
}

int main(){
	int i,n, el;
	nodo* head = NULL;
	nodo* tail = NULL;
	nodo* curr;
	int somma = 0;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		insert_coda(&head,&tail,el);
	}
	stampa(head);
	printf("\n");
	somme(head,&somma);
	stampa(head);		
	
	return 0;	
}
