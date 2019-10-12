typedef struct materia{
	char * nome;
	int mencao;
	struct materia * next;
}Materia;

typedef struct lista_materia{
	Materia * head;
	int size;
}Lista_Materia;

Materia * Cria_Materia();
Lista_Materia * Cria_Lista_Materia();
void push_materia(Lista_Materia * lista, Materia * materia);
int  is_empty_Materia(Lista_Materia * lista);

