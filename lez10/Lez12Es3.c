#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo* next;
}nodo;
typedef struct nodo* lista;

lista insert(lista head, int el){
	lista curr;
	lista new = malloc(sizeof(nodo));
	new->info = el;
	new->next = NULL;
	
	if(head == NULL)	
		return new;
	else{
		curr = head;
		while(curr->next)	curr = curr->next;
		curr->next = new;
		return head;
	}
}

void stampa(lista head){
	while(head){
		printf("%d ", head->info);
		head = head->next;
	}
}

int avg(lista head, int n){
	int somma = 0;
	while(head){
		somma += head->info;
		head = head->next;
	}
	return somma / n;	
}


lista cancellazione(lista head, int media){
	lista curr = head;
	lista prec = NULL;
	while(curr && curr->info <= media){
		free(curr);
		head = curr->next;
		curr = curr->next;
	}
	
	while(curr){
		if(curr->info <= media){
			prec->next = curr->next;
			free(curr);
			curr = prec->next;
		}else{
			prec = curr;
			curr = curr->next;
		}	
	}
	return head;
}

int main(){
	int i,n, el, media;
	nodo* head = NULL;
	
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&el);
		head = insert(head, el);	
	}
	media = avg(head,n);
	printf("%d\n",media);
	stampa(head);
	printf("\n");	
	head = cancellazione(head, media);
	stampa(head);
	return 0;	
}
