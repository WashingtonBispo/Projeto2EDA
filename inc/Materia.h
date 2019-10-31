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
Materia * recebe_materia();
void qual_mencao(Materia * materia);
void relatorio(Lista_Materia * lista);
int pesquisar_materia(Lista_Materia * lista);
int apagar_materia(Lista_Materia * lista, int indice);
int editar_materia(Lista_Materia * lista, int indice);
void print_materias(Lista_Materia * lista);
void print_por_mencao(Lista_Materia * lista,int filtro);		

#endif