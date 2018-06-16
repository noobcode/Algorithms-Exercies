#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN_N 101
#define LEN_T 21

typedef struct persona{
	char* nome;
	char* tele;
	struct persona* next;
}persona;

persona* crea(){
	persona* new = malloc(sizeof(persona));
	new->nome = malloc(LEN_N * sizeof(char));
	new->tele = malloc(LEN_T * sizeof(char));
	scanf("%s%s",new->nome, new->tele);
	new->next = NULL;
	return new;
}

int hash(char* nome, int n){
	int i = 0;
	int somma = 0;
	while(nome[i] != '\0'){
		somma += (unsigned int)nome[i];
		i++;
	}
	return somma % (2*n);
}

persona* inserisci_lista(persona* l, persona* new){
	persona* prec;
	persona* curr;
	if(l == NULL){
		l = new;
		return l;
	}else{
		curr = l;
		while(curr != NULL && strcmp(curr->nome,new->nome) <= 0){
			prec = curr;
			curr = curr->next;
		}
		if(curr == l){
			new->next = l;
			l = new;
		}else{
			new->next = prec->next;
			prec->next = new;
		}
		return l;
	}
}

persona** inserisci(persona** t, int n){
	int h;
	persona* new = crea();
	h = hash(new->nome, n);
	t[h] = inserisci_lista(t[h], new);
	return t;
}

void stampa(persona* l){
	while(l != NULL){
		printf("%s %s\n",l->nome,l->tele);
		l = l->next;
	}
}

int main(){
	int n, i, k;
	persona** t;
	
	scanf("%d",&n);
	t = malloc(2*n * sizeof(persona*));
	
	for(i = 0; i < n; i++){
		t = inserisci(t, n);
	}
	scanf("%d",&k);
	stampa(t[k]);
	
	return 0;
}
