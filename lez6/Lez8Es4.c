#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101

typedef char* String;
typedef struct Str{
	String s;
	int len;
}Str;

int compare(const void* s1, const void* s2){
	Str* S1 = (Str*) s1;
	Str* S2 = (Str*) s2;
	if(S1->len < S2->len)	return -1;
	if(S1->len > S2->len)	return 1;
	else
		return (strcmp(S1->s,S2->s)); 
}

int main(){
	int i,n;
	Str* stringhe;
	scanf("%d",&n);
	stringhe = malloc(n * sizeof(Str));
	for(i = 0; i < n; i++){
		stringhe[i].s = malloc(MAXLEN * sizeof(String));
		scanf("%s",stringhe[i].s);
		stringhe[i].len = strlen(stringhe[i].s);	
	}
	qsort(stringhe,n,sizeof(Str),compare);
	for(i = 0; i < n; i++)
		printf("%s\n",stringhe[i].s);
	return 0;	 
}
