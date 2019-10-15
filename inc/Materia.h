#ifndef MATERIA_H
#define MATERIA_H

#include <stdlib.h>

typedef struct materia{
	char * nome;
	int mencao;
	struct materia * next;
}Materia;

typedef struct lista_materia{
	Materia * head;
	int size;
}Lista_Materia;

Materia * cria_materia();
Lista_Materia * cria_lista_materia();
void push_materia(Lista_Materia * lista, Materia * materia);
int  is_empty_materia(Lista_Materia * lista);

#endif