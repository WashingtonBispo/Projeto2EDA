#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utilidades.h"
#include "Materia.h"

Materia * cria_materia(){
	Materia * aux = (Materia*) malloc(sizeof(Materia));
	return aux;
}

Lista_Materia * cria_lista_materia(){
	Lista_Materia * lista = (Lista_Materia*) malloc(sizeof(Lista_Materia));
	lista -> head = NULL;
	lista -> size = 0;
	return lista;
}

void push_materia(Lista_Materia * lista, Materia * materia){
	materia-> next = lista -> head;
	lista->head = materia;
	lista->size++;
}

int is_empty_materia(Lista_Materia * lista){
	if(lista->size==0) return 1;
	else return 0;
}

Materia * recebe_materia(){
	Materia * materia = cria_materia();
	printf("Digite o nome da matéria: ");
	materia->nome = recebe_palavra();

	do{
		printf("Digite a mencao:\n0 - TR\n1 - SR\n2 - II\n3 - MI\n4 - MM\n5 - MS\n6 - SS\n->");
		scanf("%d", &materia->mencao);
	if(materia->mencao > 6 || materia->mencao < 0){
		RED;
		printf("Entrada Inválida\n");
		WHITE;
	}

}while(materia->mencao > 6 || materia->mencao < 0);


return materia;

}

void qual_mencao(Materia * materia){
	if(materia->mencao == 0) printf("TR\n");
	if(materia->mencao == 1) printf("SR\n");
	if(materia->mencao == 2) printf("II\n");
	if(materia->mencao == 3) printf("MI\n");
	if(materia->mencao == 4) printf("MM\n");
	if(materia->mencao == 5) printf("MS\n");
	if(materia->mencao == 6) printf("SS\n");
}

void relatorio(Lista_Materia * lista){
	int cont_AP=0,cont_REP=0,cont_TR=0;

	Materia * aux = lista->head;
	while(aux!=NULL){
		if(aux->mencao==0) cont_TR++;
		else if(aux->mencao==1 || aux->mencao==2 || aux->mencao==3) cont_REP++;
		else cont_AP++;
		aux = aux->next;
	}

	printf("Numero total de disciplinas: %d\n",lista->size);
	GREEN;
	printf("Aprovacoes: %d\n", cont_AP);
	
	RED;
	printf("Reprovacoes: %d\n", cont_REP);

	GRAY;
	printf("Trancamentos: %d\n", cont_TR);

	WHITE;

	printf("Aperte enter para sair");
	getchar();
	getchar();

}

int pesquisar_materia(Lista_Materia * lista){

	if(is_empty_materia(lista)) return -1;
	int opc, n;
	char * palavra = (char *) malloc(sizeof(char)*50);
	printf("Deseja pesquisar por:\n1 - Nome da materia\n2 - Indice\n->");
	scanf("%d", &opc);
	while(opc!=1 && opc!=2){
		printf("Invalido\n");
		scanf("%d", &opc);
	}
	Materia * aux = lista->head;
	if(opc==1){
		printf("Digite o nome da materia: ");
		scanf(" %[^\n]s", palavra);
		int cont=1;
		while(aux!=NULL){ 	
			if(strcmp(aux->nome,palavra)==0){
				return cont;
			}
			aux = aux->next;
			cont++;
		}
	}
	else{

		printf("Digite o indice que deseja:");
		scanf("%d", &n);
		while(n>lista->size && n<1){
			printf("Fora do intervalo!\nDigite novamente:");
			scanf("%d", &n);
		}
		return n;
	}

	return 0;
}

int apagar_materia(Lista_Materia * lista, int indice){
	Materia * aux = lista->head;
	Materia * aux2;
	if(indice == 1){
		aux2 = lista->head->next;
		free(lista->head);
		lista->head = aux2;
		lista->size--;

		return 1;
	}
	else{
		for(int i=2;i<indice;i++){
			aux = aux->next;
		}
		aux2 = aux->next;
		aux->next = aux2->next;
		free(aux2);
		lista->size--;
		return 1;
	}

}

int editar_materia(Lista_Materia * lista, int indice){
	Materia * aux = lista->head;
	for(int i=1;i<indice;i++){
			aux = aux->next;
		}

	printf("Digite o novo nome: ");
	aux->nome = recebe_palavra();
	printf("Digite a nova mencao ");
	printf("\n0 - TR\n1 - SR\n2 - II\n3 - MI\n4 - MM\n5 - MS\n6 - SS\n->");
	scanf("%d", &aux->mencao);

	return 1;
}

void print_materias(Lista_Materia * lista){

	if(is_empty_materia(lista)) printf("Sem materia\n");
	else{
		Materia * aux = lista->head;
		while(aux!=NULL){
			printf("Disciplina: %s\nMencao: ", aux->nome);
			qual_mencao(aux);
			aux = aux->next;
			printf("-------------------------------------\n");
		}

	}
	printf("Aperte ENTER para sair.");
	getchar();
	getchar();	
}

void print_por_mencao(Lista_Materia * lista,int filtro){
	Materia * aux = lista->head;
	int cont=0;
	printf("O(a) aluno(a) possui essa mencao nessas disciplinas:\n");
	while(aux!=NULL){
		if(aux->mencao==filtro) cont++, printf("->%s\n", aux->nome);
		aux = aux -> next;
	}
	if(cont==0) printf("->NENHUMA\n");
	printf("Aperte ENTER para sair");
	getchar();
	getchar();
}