#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Utilidades.h"
#include "Aluno.h"
#include "Materia.h"

void menu_2(Aluno * aluno){
	int opc, index;
	system("clear");

	do{
		system("clear");
		printf("\n Aluno(a): %s\n Matricula: %s\n",aluno->nome, aluno->matricula);
		faz_retangulo(40,2,1,1);
		gotoxy(1,5);
		printf("O que deseja fazer:\n1 - Cadastrar Matéria\n2 - Listar Disciplinas Do Aluno\n3 - Editar Uma Disciplina\n");
		printf("4 - Excluir Uma Disciplina\n5 - Filtrar Disciplinas por mencao\n6 - Apresentar Relatório Geral\n0 - Retornar\n->");
		scanf("%d", &opc);

		system("clear");

		printf("Aluno: %s\nMatricula: %s\n",aluno->nome, aluno->matricula);
		system("clear");
		printf("\n Aluno(a): %s\n Matricula: %s\n",aluno->nome, aluno->matricula);
		faz_retangulo(40,2,1,1);
		
		if(opc == 1) push_materia(aluno->historico, recebe_materia());
		else if(opc == 2) print_materias(aluno->historico);
		else if(opc == 3){
			index = pesquisar_materia(aluno->historico);
			if(index)
				editar_materia(aluno->historico, index);
			else{
				RED;
				printf("Materia nao encontrada\n");
				WHITE;
				system("sleep 2");
			}
		}
		else if(opc == 4){
		
			index = pesquisar_materia(aluno->historico);
			
			if(index==1)
				apagar_materia(aluno->historico, index);
			else if(index==0)
				printf("Materia nao encontrado\n");
			else
				printf("Lista Vazia :(\n");
		
		}
		else if(opc == 5){
			int mencao;
			if(!is_empty_materia(aluno->historico)){
			do{
				printf("Digite a mencao:\n0 - TR\n1 - SR\n2 - II\n3 - MI\n4 - MM\n5 - MS\n6 - SS\n->");
				scanf("%d", &mencao);
			}while(mencao>6 || mencao <0);

			system("clear");
			printf("Aluno: %s\nMatricula: %s\n--------------------------------------------\n",aluno->nome, aluno->matricula);
			print_por_mencao(aluno->historico, mencao);
		}
			else printf("Lista Vazia :(\n");
		}
		else if(opc == 6){
			if(!is_empty_materia(aluno->historico))	
				relatorio(aluno->historico);	
			else
				printf("Lista Vazia :(\n");
		}
		else if(opc!=0) invalido();
	}while(opc!=0);
}
