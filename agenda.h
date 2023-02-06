#ifndef AGENDA_H
#define AGENDA_H

#include <string.h>

typedef struct Data {
  int dia, mes, ano;
  int hora, minuto;
} Data;

typedef struct Evento {
  int codigo;      // 4bytes
  int apagado;     // 4bytes
  char nome[50];   // 50bytes
  Data data;       //
  char local[100]; // 100 bytes
} evento;

int menuPrincipal();
int menuListagens();
int gera_codigo();
void gravandoDados();
void listagemTodosEventos();
void listagemTodosEventos();
void listagemEventosNome(char nome[]);
void listagemEventosDia(Data data);
void listagemEventosMes(Data data);
void listagemEventosLocal(char local[]);
void listagemEventosFuturos();
void listagemEventosHoje();
void remocaoLogica();
void remocaoFisica();
int verifica_marcado();

#endif