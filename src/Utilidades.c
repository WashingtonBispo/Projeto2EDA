#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * recebe_palavra(){
	char * aux = (char *) malloc(sizeof(char)*100);
	scanf(" %[^\n]s", aux);
	aux = realloc(aux, sizeof(char)*strlen(aux));
	return aux;
}

void invalido(){
	printf("Entrada Invalida\n");
	system("sleep 2");
}

int exist_in_array(int * vetor, int size, int desejo){
	for(int i=0;i<size;i++)
		if(*(vetor+i)==desejo) return 1;
	return 0;
}

void sucesso(){
	system("clear");
	printf("operacao realizada com sucesso\n");
	system("sleep 2");
}