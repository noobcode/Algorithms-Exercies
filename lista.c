#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* next;
} nodo_t;

nodo_t* creaNodo(int x){
	nodo_t* new = malloc(sizeof(nodo_t));
	new->info = x;
	new->next = NULL;
	return new;
}

void inserisciCoda(int x, nodo_t** head, nodo_t** tail){
	nodo_t* new = creaNodo(x);
	if(*head == NULL){
		*head = new;
		*tail = *head;
	} else {
		(*tail)->next = new;
		(*tail) = new; 
	}
}

void stampa(nodo_t* head){
	nodo_t* i = head;
	while(i != NULL){
		printf("%d ", i->info);
		i = i->next;
	}
	printf("\n");
}

int main() {
	int n, i, x;
	nodo_t* head = NULL;
	nodo_t* tail = NULL;
	
	printf("numero elementi?\n");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &x);
		inserisciCoda(x, &head, &tail);
	}
	stampa(head);
	
	return 0;
}
