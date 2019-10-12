#include <stdio.h>
#include <stdlib.h>

#include "Materia.h"

Materia * Cria_Materia(){
	Materia * aux = (Materia*) malloc(sizeof(Materia));
	return aux;
}

Lista_Materia * Cria_Lista_Materia(){
	Lista_Materia * lista = (Lista_Materia*) malloc(sizeof(Lista_Materia));
	lista -> head = NULL;
	lista -> size =0;
	return lista;
}

void push_materia(Lista_Materia * lista, Materia * materia){
	materia->next = lista->	head;
	lista->head = materia;
	lista->size++;
}

int is_empty_Materia(Lista_Materia * lista){
	if(lista->size==0) return 0;
	else return 1;
}
