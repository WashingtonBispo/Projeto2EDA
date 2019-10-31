#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utilidades.h"


char * recebe_palavra(){
	char * aux = (char *) malloc(sizeof(char)*100);
	scanf(" %[^\n]s", aux);
	aux = realloc(aux, sizeof(char)*strlen(aux));
	return aux;
}

void invalido(){
	RED;
	printf("Entrada Invalida\n");
	WHITE;	
	system("sleep 1");
	
}

int exist_in_array(int * vetor, int size, int desejo){
	for(int i=0;i<size;i++)
		if(*(vetor+i)==desejo) return 1;
	return 0;
}

void sucesso(){
	GREEN;
	printf("Operacao realizada com sucesso\n");
	WHITE;
}

void gotoxy(int x, int y){
	printf("%c[%d;%df", 0x1B, y, x);
}

void faz_retangulo(int base, int altura, int x_inicial, int y_inicial){
	gotoxy(x_inicial, y_inicial);

	//Faz o topo do meu retângulo
	printf("\u2554");
	for(int i=2;i<base;i++){
		printf("\u2550");
	}
	printf("\u2557\n");

	//Faz o Meio
	for(int i=1;i<altura+1;i++){
		gotoxy(x_inicial,y_inicial+i);
		printf("\u2551");
		gotoxy(x_inicial+base-1,y_inicial+i);
		printf("\u2551");
	}

	//Faz o meio
	gotoxy(x_inicial,x_inicial+altura+1);
	printf("\u255A");
	for(int i=2;i<base;i++){
		printf("\u2550");
	}
	printf("\u255D\n");

}

void Enter(){
	printf("\nDigite ENTER para sair");
	getchar();
	getchar();
}
