#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

int main(){
	int opc=1,n;
	Lista_Aluno * alunos;
	alunos = cria_lista_aluno();
	system("clear");

	while(opc!=0){
		printf("--------------------MENU--------------------\n");
		printf("1 - Cadastro\n");
		printf("2 - Listar Alunos\n");
		printf("5 - Apagar Aluno\n");
		printf("0 - SAIR\n->");
		scanf("%d", &opc);
		system("clear");
		n=-1;

		if(opc == 1){
			printf("Quantos alunos deseja cadastrar ?\n");

			while(n<1){
				scanf("%d",&n);
			}

			system("clear");

			for(int i=0;i<n;i++){
				push_aluno(alunos, recebe_aluno());
				system("clear");
			}
		}
		else if(opc == 2){
			if(is_empty_aluno(alunos)){
				print_aluno(alunos);
				printf("\nDigite algo pra sair:");
				scanf("%d", &n);
			}
			else
				printf("Lista vazia :(\n");
		}
		else if(opc == 5){
			
			while(n<1 || n>alunos->size){
				scanf("%d", &n);
			}
			apaga_aluno(alunos, n);
		}

		system("clear");
	}
	printf("Todos sucumbirao ao tempo\n");

	return 0;
}
