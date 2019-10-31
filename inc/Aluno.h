#ifndef ALUNO_H
#define ALUNO_H

#include <stdlib.h>
#include "Materia.h"

typedef struct aluno{
	char * nome;
	char * matricula;
	char * email;
	Lista_Materia * historico;
	struct aluno * next;
}Aluno;

typedef struct lista_aluno{
	Aluno * head;
	int size;
}Lista_Aluno;

Aluno * cria_aluno();
Lista_Aluno * cria_lista_aluno();
Aluno * recebe_aluno();
Aluno * mandar_aluno(Lista_Aluno * lista,int  indice);

void push_aluno(Lista_Aluno * lista, Aluno * aluno);
int  is_empty_aluno(Lista_Aluno * lista); 

void print_aluno(Lista_Aluno * lista);

void edita_aluno(Lista_Aluno * lista, int indice);
void apaga_aluno(Lista_Aluno * lista, int indice);

int procura(Lista_Aluno * lista,int opc);


#endif