#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * recebe_palavra(){
	char * aux = (char *) malloc(sizeof(char)*100);
	scanf(" %[^\n]s", aux);
	aux = realloc(aux, sizeof(char)*strlen(aux));
	return aux;
}