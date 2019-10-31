#ifndef UTILIADES_H
#define UTILIDADES_H

#define UNDERLINE printf("%s", "\x1B[4m");
#define SLOW_BLINK printf("%s", "\x1B[5m");
#define RAPID_BLINK printf("%s", "\x1B[6m");
#define BLINK_OFF printf("%s", "\x1B[25m");
#define RED printf("%s","\x1B[31m");
#define RESET printf("%s", "\x1B[0m");
#define WHITE printf("%s", "\x1B[37m");
#define GREEN printf("%s", "\x1B[32m");
#define GRAY printf("%s", "\x1B[90m");

#include <stdlib.h>

char * recebe_palavra();
void invalido();
int exist_in_array(int * vetor, int size, int desejo);
void sucesso();
void gotoxy(int x, int y);
void faz_retangulo(int base, int altura, int x_inicial, int y_inicial);
void Enter();

#endif