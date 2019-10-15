#include <stdio.h>
#include <stdlib.h>
#include "Materia.h"
#include "Aluno.h"
#include "Utilidades.h"

Aluno * cria_aluno(){
	Aluno * aux = (Aluno *) malloc(sizeof(Aluno));
	aux->historico = (Lista_Materia *) malloc(sizeof(Lista_Materia));
	return aux;
}

Lista_Aluno * cria_lista_aluno(){
	Lista_Aluno * aux = (Lista_Aluno *) malloc(sizeof(Lista_Aluno));
	aux->head = NULL;
	aux->size = 0;
	return aux;
}

Aluno * recebe_aluno(){
	Aluno * aux = cria_aluno(); 

	printf("Digite o nome: ");
	aux-> nome = recebe_palavra();
	
	printf("Digite a matricula: ");
	aux-> matricula = recebe_palavra();

	printf("Digite o email: ");
	aux-> email = recebe_palavra(); 

	return aux;
}

void push_aluno(Lista_Aluno * lista, Aluno * aluno){
	aluno->next = lista->head;
	lista->head = aluno;
	lista->size++;
}

int is_empty_aluno(Lista_Aluno * lista){
	if(lista->size == 0) return 0;
	else return 1;
}

void print_aluno(Lista_Aluno * lista){
	Aluno * aux;
	aux = lista->head;
	printf("LISTA DE ALUNOS\n");
	while(aux!= NULL){
		printf("------------------------------------------------------------\n");
		printf("Nome: %s\n", aux->nome);
		printf("Matricula: %s\n", aux->matricula);
		printf("Email: %s\n", aux->email);
		
		aux=aux->next;
	}
}

void apaga_aluno(Lista_Aluno * lista, int indice){
	Aluno * aux = lista->head;
	if(indice==1){
		lista->head = aux->next;
		free(aux);
	}
	else{
	for(int i=2;i<indice-1;i++){//Como eu já começo na posição "1" e eu quero chegar até a posição "indice -1" eu preciso começar meu contador como 2.
		aux = aux->next;
		}
	aux->next = aux->next->next;
	}
	lista->size--;
}