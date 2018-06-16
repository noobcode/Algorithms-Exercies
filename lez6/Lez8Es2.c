#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101
typedef char* String;

int compare_string(const void* a, const void* b){
	String* s1 = (String*)a;
	String* s2 = (String*)b;
	return ( - strcmp(*s1,*s2));
}


int main(){
	int n,i;
	String* a;
	scanf("%d",&n);
	a = malloc(n * sizeof(String));
	for(i = 0; i < n; i++){
		a[i] = malloc(MAXLEN * sizeof(char));
		scanf("%s",a[i]);
	}
	qsort(a,n,sizeof(String),compare_string);
	for(i = 0; i < n; i++)
		printf("%s\n",a[i]);
	
	return 0;
}
