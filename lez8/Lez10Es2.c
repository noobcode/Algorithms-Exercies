#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* next;
	struct nodo* prev;
}nodo;

void insertcoda(nodo** head, nodo** tail, int el){
	nodo* curr;
	nodo* new = malloc(sizeof(nodo));
	new->info = el;
	new->next = NULL;
	
	if(!*head){
		*head = new;
		*tail = new;
		new->prev = NULL;
	}else{
		new->prev = *tail;
		(*tail)->next = new;
		*tail = new;
	}
}

int main(){
	int i,n,el;
	nodo* head,*tail,*curr;
	head = tail = NULL;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		insertcoda(&head,&tail,el);
	}
	/*
	curr = head;
	while(curr){
		printf("%d ",curr->info);
		curr = curr->next;
	}
	*/
	curr = tail;
	while(curr){
		printf("%d\n",curr->info);
		curr = curr->prev;
	}
}
