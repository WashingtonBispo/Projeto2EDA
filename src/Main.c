#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Utilidades.h"

int main(){
	int opc=1,opc2,n;
	Lista_Aluno * alunos;
	alunos = cria_lista_aluno();
	system("clear");

	while(opc!=0){
		printf("--------------------MENU--------------------\n");
		printf("1 - Cadastro\n");
		printf("2 - Listar Alunos\n");
		printf("4 - Editar Aluno\n");
		printf("5 - Apagar Aluno\n");
		printf("0 - SAIR\n->");
		scanf("%d", &opc);
		system("clear");
		n=-1;



		if(opc == 1){

			do{
				printf("Quantos alunos deseja cadastrar ?\n");
				scanf("%d",&n);
				if(n<1) printf("Entrada Invalida\n");
			}while(n<1);

			for(int i=0;i<n;i++){
				system("clear");
				push_aluno(alunos, recebe_aluno());
			}
		}
		else if(opc == 2){
			if(is_empty_aluno(alunos)){
				print_aluno(alunos);
				printf("\nDigite algo pra sair:");
				scanf("%d", &n);
			}
			else
				printf("Lista vazia :(\n"), system("sleep 2");
		}
		else if(opc>2 && opc<6){

			do{
				system("clear");
				printf("Como deseja pesquisar ?\n1 - Nome\n2 - Matricula\n3 - Email\n4 - Indice\n->");
				scanf("%d", &opc2);
				if(opc2>4 || opc2<1) invalido();
			}while(opc2>4 || opc2<1);
			
			if(opc2!=4){
				n = procura(alunos,opc2);
			}
			else{
			do{
				printf("Digite o indice do aluno: ");
				scanf("%d", &n);
				if(n<1 || n>alunos->size) invalido();
				}while(n<1 || n>alunos->size);
			
			}
			
			if(n!=-1 && opc==4) edita_aluno(alunos, n);
			else if(n!=-1 && opc==5) apaga_aluno(alunos, n);
			else printf("Não encontrado\n");

		}
		else invalido();

		system("clear");
	}
	printf("Todos sucumbirao ao tempo\n");

	return 0;
}
