#include "agenda.h"
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  int opcaoGeral;

  do {
    opcaoGeral = menuPrincipal();

    switch (opcaoGeral) {
    case 1: // adicionar evento
      gravandoDados();
      break;

    case 2:            // listar eventos
      system("clear"); // limpar o terminal
      int opcaoListagens;
      Data data;

      opcaoListagens = menuListagens();

      system("clear"); // limpar o terminal

      switch (opcaoListagens) {

      case 1:
        listagemTodosEventos();
        break;

      case 2: // listar por nome
        char nome[20];
        cout << "\nEvento: ";
        cin >> nome;
        listagemEventosNome(nome);
        break;

      case 3: // listar por dia
        cout << "Informe o dia do evento (dia mês ano): \n";
        cin >> data.dia >> data.mes >> data.ano;
        listagemEventosDia(data);
        break;

      case 4: // listar por mes
        cout << "Informe o mes do evento (mês ano): \n";
        cin >> data.mes >> data.ano;
        listagemEventosMes(data);
        break;

      case 5: // listar por local
        char local[100];
        cout << "\nLocal: ";
        cin >> local;
        listagemEventosLocal(local);
        break;

      case 6: // listar hoje
        listagemEventosHoje();
        break;

      case 7: // listar futuro
        listagemEventosFuturos();
        break;
      }
      break;

    case 3:            // apagar logicamente
      system("clear"); // limpar o terminal
      listagemTodosEventos();
      remocaoLogica();
      break;

    case 4: // apagar fisicamente
      remocaoFisica();
      break;

    case 5:
      cout << "\nFinalizando..." << endl;
      exit(0);
      break;

    default:
      cout << "\nOpcao inexistente" << endl;
    }
  } while (opcaoGeral != 5);
}