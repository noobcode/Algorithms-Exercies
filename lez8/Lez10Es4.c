#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	int count;
	struct nodo* next;
	struct nodo* prev;
}nodo;

void insertcoda(nodo** head, nodo** tail, int el){
	nodo* new = malloc(sizeof(nodo));
	new->info = el;
	new->count = 0;
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

nodo* ricerca(nodo* head, int el){
	int i = 0;
	while(head){
		if(head->info == el){
			(head->count)++;
			printf("%d\n",i);
			return head;
		}
		i++;
		head = head->next;
	}
	return NULL;
}

void stampa(nodo* head){
	while(head){
		printf("%d conteggio : %d\n",head->info, head->count);
		head = head->next;
	}
}

void movetofront(nodo** head, nodo* aus){
	nodo* curr,*succ;
	if(aus == *head) return;
	if(aus->count <= aus->prev->count)	return;
	else{
		curr = aus->prev;
		while(curr != NULL && curr->count < aus->count)
			curr = curr->prev;
			
		if(curr == NULL){		
			if(aus->next){
				aus->prev->next = aus->next;
				aus->next->prev = aus->prev;
				aus->next = *head;
				aus->prev = NULL;
				(*head)->prev = aus;
				*head = aus;
			}else{	//aus->next == NULL
				aus->prev->next = NULL;
				aus->prev = NULL;
				aus->next = *head;
				(*head)->prev = aus;
				*head = aus;
			}
		}else{
			if(aus->next){
				aus->prev->next = aus->next;
				aus->next->prev = aus->prev;
				aus->next = curr->next;
				curr->next = aus;
				aus->prev = curr;
				aus->next->prev = aus;
			}else{
				aus->prev->next = aus->next;
				aus->next = curr->next;
				curr->next = aus;
				aus->prev = curr;
				aus->next->prev = aus;
			}
		}	
	}
	
		
}

int main(){
	int i,n,el, trovato = 1;
	nodo* head,*tail,*temp;
	head = tail = NULL;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		insertcoda(&head,&tail,el);
	}
	
	while(trovato){
		scanf("%d",&el);
		temp = ricerca(head, el);
		if(temp){
			movetofront(&head, temp);
			//stampa(head);
		}else{
			printf("-1\n");
			trovato = 0;
		}				
	}	
	return 0;
}
