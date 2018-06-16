#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* next;
}nodo;

void aggiungi(nodo** head, int el){
	nodo* curr = *head;
	nodo* new = malloc(sizeof(nodo));
	new->info = el;
	new->next = NULL;

	if(*head == NULL){
		*head = new;
	}else{  
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = new;
	}		
}
insert_coda(nodo** head, nodo** tail, int el){
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

void print_reverse(nodo* head){
	if(head != NULL){
		print_reverse(head->next);
		printf("%d\n", head->info);
	}
}

int main(){
	int i,n, el;
	nodo* head = NULL;
	nodo* tail = NULL;
	nodo* curr;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		//aggiungi(&head,el);
		insert_coda(&head,&tail,el);
	}
	print_reverse(head);	
	
	return 0;	
}
