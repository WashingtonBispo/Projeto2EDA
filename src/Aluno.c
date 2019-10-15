#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void edita_aluno(Lista_Aluno * lista, int indice){
	
	Aluno * aux = lista->head;
	int opc;
	printf("Digite o que deseja mudar:\n1 - Nome\n2 - Matricula\n3 - Email\n4 - Todos\n->");
	
	do{
		scanf("%d", &opc);
		if(opc>4 || opc<1) printf("ENTRADA INVALIDA\n->");
	}while(opc>4 || opc<1);

	for(int i=1;i<indice;i++){
		aux = aux->next;
		}
	
	if(opc==1 || opc==4) printf("Digite o novo nome: "), aux-> nome = recebe_palavra();
	if(opc==2 || opc==4) printf("Digite a nova matricula: "), aux-> matricula = recebe_palavra();
	if(opc==3 || opc==4) printf("Digite o novo email: "), aux-> email = recebe_palavra();


}

void apaga_aluno(Lista_Aluno * lista, int indice){
	Aluno * aux = lista->head;
	if(indice==1){
		lista->head = aux->next;
		free(aux);
	}

	else{
	for(int i=2;i<indice;i++){//Como eu já começo na posição "1" e eu quero chegar até a posição "indice -1" eu preciso começar meu contador como 2.
		aux = aux->next;
		}
	aux->next = aux->next->next;
	}
	lista->size--;
}

int procura(Lista_Aluno * lista, int opc){
	Aluno * aux;
	aux=lista->head;
	char pal[100];
	printf("Digite o dado que deseja busca: ");
	scanf(" %s", pal);

	if(opc==2){
		for(int i=1;i<=lista->size;i++){
			if(strcmp(pal,aux->matricula)==0) return i;
			aux = aux->next;
		}
	}
	if(opc==3){
		for(int i=1;i<=lista->size;i++){
			if(strcmp(pal,aux->email)==0) return i;
			aux = aux->next;
		}
	}	

	return -1;
	}