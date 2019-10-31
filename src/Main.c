#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Segundo_Menu.h"
#include "Utilidades.h"

int main(){
	int opc=1,opc2,n;
	Lista_Aluno * alunos;
	alunos = cria_lista_aluno();
	system("clear");
	//system("setterm -cursor off");
	while(opc!=0){

		//Criar o menu principal
		WHITE;
		printf("\n 1 - Cadastro\n");
		printf(" 2 - Listar Alunos\n");
		printf(" 3 - Visualizar Aluno\n");
		printf(" 4 - Editar Aluno\n");
		printf(" 5 - Apagar Aluno\n");
		printf(" 0 - SAIR");
		SLOW_BLINK;
		printf("\n ->");
		BLINK_OFF;
		faz_retangulo(30,7,1,1);
		gotoxy(4,8);
		scanf("%d", &opc);


		system("clear");
		n=-1;

		//Confere se a lista está vazia e a opção precisa que a lista esteja com algum elemento 
		if(!is_empty_aluno(alunos) && (opc==2 || opc==3 || opc==4 || opc==5)){
			RED;
			printf("Lista Vazia :(\n");
			WHITE;
			system("sleep 1");
		}
		else if(opc == 1){

			do{
				printf("Quantos alunos deseja cadastrar ?\n");
				scanf("%d",&n);
				if(n<1) invalido();
			}while(n<1);

			system("clear");
			for(int i=0;i<n;i++){
				push_aluno(alunos, recebe_aluno());
				GREEN;
				printf("Cadastrado com sucesso!\n\n");
				WHITE;
			}
		}
		else if(opc == 2){
				print_aluno(alunos);
				Enter();
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

			if (n!=-1 && opc==3) menu_2(mandar_aluno(alunos, n));
			else if(n!=-1 && opc==4) edita_aluno(alunos, n), sucesso();
			else if(n!=-1 && opc==5) apaga_aluno(alunos, n), sucesso();
			else {
				printf("Não encontrado\n");
			}
			
			if(opc!=3)
				Enter();
		}
		else if(opc!=0) invalido();

		system("clear");
	}
	printf("Todos sucumbirao ao tempo\n");

	RESET;
	return 0;
}
