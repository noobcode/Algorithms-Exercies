#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* next;
}nodo;

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

void stampa(nodo* head){
	nodo* curr = head;
	while(curr){
			printf("%d ",curr->info);
			curr = curr->next;
	}
}

int ricerca(nodo** head, nodo** prev, nodo** curr, int el, int i){
	if(*curr == NULL){
		printf("-1\n");
		return 0;
	}
	if((*curr)->info == el){
		printf("%d\n", i);
		(*prev)->next = (*curr)->next;
		(*curr)->next = *head;
		*head = *curr;
		return 1;
	}
	else	return ricerca(head, curr, &((*curr)->next), el, i+1);
}

int ricerca2(nodo** head, int el){
	int i = 0;
	nodo* curr = *head;
	nodo* prev = curr;
	
	while(curr){
		if((*head)->info == el){
			printf("%d\n",i);
			return 1;
		}
		else if(curr->info == el){	//move to front
			printf("%d\n",i);
			prev->next = curr->next;
			curr->next = *head;
			*head = curr;
			return 1;
		}else{
			prev = curr;
			curr = curr->next;
			i++;
		}
	}
	printf("-1\n");
	return 0;
}

int main(){
	int n, i, el,trovato = 1;
	nodo* head = NULL;
	nodo* tail = NULL;
	nodo* curr;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		insert_coda(&head,&tail,el);
	}
	
	while(trovato){
		i = 0;
		scanf("%d",&el);
		//trovato = ricerca(&head,&head,&head,el,i);
		trovato = ricerca2(&head,el);
		//stampa(head);		
	}
	
	
		
	return 0;
}
