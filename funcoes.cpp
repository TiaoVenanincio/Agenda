#include "agenda.h"
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

int gera_codigo() {
  ifstream fin;
  fin.open("dados", ios::in | ios::binary);

  if (!fin)
    return 1;
  else {
    int codigo;
    evento evento;
    while (fin.read((char *)&evento, sizeof(struct Evento))) {
      codigo = evento.codigo; // pega o ultimo codigo dentro do registro
    }
    return codigo + 1;
  }
  fin.close();
}

void gravandoDados() {
  evento evento, novo;

  if (verifica_marcado() == 0) { // caso nao tenha arquivos marcados como
                                 // apagado
    ofstream fout;
    fout.open("dados", ios::out | ios::app | ios::binary);

    /* define para um novo evento a condicao de apagado = 0, ou seja, quando for
    ler, vai verificar se nao foi apagado, se foi (apagado = 1), nao lê. */
    evento.apagado = 0;
    evento.codigo = gera_codigo();
    cout << "Nome do evento: ";
    cin >> evento.nome;
    cout << "Data: ";
    cin >> evento.data.dia >> evento.data.mes >> evento.data.ano >>
        evento.data.hora >> evento.data.minuto;
    cout << "Local: ";
    cin >> evento.local;
    fout.write((char *)&evento, sizeof(struct Evento));
    fout.close();
  }

  else { // caso tenha arquivos marcados como apagado
    ifstream fin;
    fin.open("dados", ios::in | ios::binary);
    int posicao;
    while (fin.read((char *)&evento, sizeof(struct Evento)) &&
           evento.apagado != 1)
      posicao = (evento.codigo) * sizeof(Evento);

    fstream finout;
    finout.open("dados");

    // posiciona o cursor nessa posicao recebida acima
    finout.seekp(posicao, ios::cur);

    // preparando as variaveis para reescrever no registro
    novo.codigo = evento.codigo; // mantem o codigo do registro anterior
    novo.apagado = 0;            // coloca como nao apagado
    cout << "Nome do evento: ";
    cin >> novo.nome; // Recebe o novo nome
    cout << "Data: ";
    cin >> novo.data.dia >> novo.data.mes >> novo.data.ano >> novo.data.hora >>
        novo.data.minuto; // nova data
    cout << "Local: ";
    cin >> novo.local; // novo local

    finout.write((char *)&novo, sizeof(Evento)); // grava o registro todo
    finout.close();
  }
  cout << "\nDados gravados com sucesso!" << endl;
}

void listagemTodosEventos() {
  ifstream fin;
  fin.open("dados", ios::in | ios::binary);

  if (!fin) {
    cout << "Erro ao abrir o arquivo\n";
  }

  evento evento;

  cout << "\n[EVENTOS]\n";

  // le cada registro e imprime até o fim do arquivo
  while (fin.read((char *)&evento, sizeof(struct Evento))) {
    if (evento.apagado == 0) {
      cout << "\nCodigo: " << evento.codigo;
      cout << "\nEvento: " << evento.nome;
      cout << "\nData: " << evento.data.dia << "/" << evento.data.mes << "/"
           << evento.data.ano;
      cout << "\nHorário: " << evento.data.hora << "h" << evento.data.minuto
           << "min";
      cout << "\nLocal: " << evento.local;
      cout << "\n";
    }
  }
  fin.close();
}

void listagemEventosNome(char nome[]) {
  // abre o arquvio em modo leitura e verifica
  ifstream fin;
  fin.open("dados", ios::in | ios::binary);

  if (!fin) {
    cout << "Erro ao abrir o arquivo\n";
  }

  evento evento;

  while (fin.read((char *)&evento, sizeof(struct Evento))) {
    if (strcmp(nome, evento.nome) == 0 && evento.apagado == 0) {
      cout << "\nCodigo: " << evento.codigo;
      cout << "\nEvento: " << evento.nome;
      cout << "\nData: " << evento.data.dia << "/" << evento.data.mes << "/"
           << evento.data.ano;
      cout << "\nHorário: " << evento.data.hora << "h" << evento.data.minuto
           << "min";
      cout << "\nLocal: " << evento.local;
      cout << "\n";
    }
  }

  fin.close();
}

void listagemEventosDia(Data data) {
  ifstream fin;
  fin.open("dados", ios::in | ios::binary);

  if (!fin) {
    cout << "Erro ao abrir o arquivo\n";
  }

  evento evento;
  cout << "\n[EVENTOS]\n";

  while (fin.read((char *)&evento, sizeof(struct Evento))) {
    if (evento.data.dia == data.dia && evento.data.mes == data.mes &&
        evento.data.ano == data.ano && evento.apagado == 0) {
      cout << "\nCodigo: " << evento.codigo;
      cout << "\nEvento: " << evento.nome;
      cout << "\nData: " << evento.data.dia << "/" << evento.data.mes << "/"
           << evento.data.ano;
      cout << "\nHorário: " << evento.data.hora << "h" << evento.data.minuto
           << "min";
      cout << "\nLocal: " << evento.local;
      cout << "\n";
    }
  }
  fin.close();
}

void listagemEventosMes(Data data) {
  ifstream fin;
  fin.open("dados", ios::in | ios::binary);

  if (!fin) {
    cout << "Erro ao abrir o arquivo\n";
  }

  evento evento;
  cout << "\n[EVENTOS]\n";

  while (fin.read((char *)&evento, sizeof(struct Evento))) {
    if (evento.data.mes == data.mes && evento.data.ano == data.ano &&
        evento.apagado == 0) {
      cout << "\nCodigo: " << evento.codigo;
      cout << "\nEvento: " << evento.nome;
      cout << "\nData: " << evento.data.dia << "/" << evento.data.mes << "/"
           << evento.data.ano;
      cout << "\nHorário: " << evento.data.hora << "h" << evento.data.minuto
           << "min";
      cout << "\nLocal: " << evento.local;
      cout << "\n";
    }
  }
  fin.close();
}

void listagemEventosLocal(char local[]) {
  ifstream fin;
  fin.open("dados", ios::in | ios::binary);

  if (!fin) {
    cout << "Erro ao abrir o arquivo\n";
  }

  evento evento;

  while (fin.read((char *)&evento, sizeof(struct Evento))) {
    if (strcmp(local, evento.local) == 0 && evento.apagado == 0) {
      cout << "\nCodigo: " << evento.codigo;
      cout << "\nEvento: " << evento.nome;
      cout << "\nData: " << evento.data.dia << "/" << evento.data.mes << "/"
           << evento.data.ano;
      cout << "\nHorário: " << evento.data.hora << "h" << evento.data.minuto
           << "min";
      cout << "\nLocal: " << evento.local;
      cout << "\n";
    }
  }

  fin.close();
}

void listagemEventosFuturos() {
  // current date/time based on current system
  time_t now = time(0);

  // estrutura de data e hora
  struct tm *dh = localtime(&now);

  dh->tm_hour = dh->tm_hour - 3; // Descontado fuso-horário
  dh->tm_mon =
      dh->tm_mon + 1; // somando 1 ao mês (contagem dele inicia loucamente no 0)
  dh->tm_year =
      dh->tm_year +
      1900; // compensando o ano (a biblioteca tem domínio a partir de 1900)

  ifstream fin;
  fin.open("dados", ios::in | ios::binary);

  if (!fin) {
    cout << "Erro ao abrir o arquivo\n";
  }

  evento evento;
  cout << "\n[PRÓXIMOS EVENTOS]\n";

  while (fin.read((char *)&evento, sizeof(struct Evento))) {
    if ((evento.data.minuto > dh->tm_min && evento.data.hora == dh->tm_hour &&
         evento.data.dia == dh->tm_mday && evento.data.mes == dh->tm_mon &&
         evento.data.ano == dh->tm_year && evento.apagado == 0) ||
        (evento.data.hora > dh->tm_hour && evento.data.dia == dh->tm_mday &&
         evento.data.mes == dh->tm_mon && evento.data.ano == dh->tm_year &&
         evento.apagado == 0) ||
        (evento.data.dia > dh->tm_mday && evento.data.mes == dh->tm_mon &&
         evento.data.ano == dh->tm_year && evento.apagado == 0) ||
        (evento.data.mes > dh->tm_mon && evento.data.ano == dh->tm_year &&
         evento.apagado == 0) ||
        (evento.data.ano > dh->tm_year && evento.apagado == 0)) {

      cout << "\nCodigo: " << evento.codigo;
      cout << "\nEvento: " << evento.nome;
      cout << "\nData: " << evento.data.dia << "/" << evento.data.mes << "/"
           << evento.data.ano;
      cout << "\nHorário: " << evento.data.hora << "h" << evento.data.minuto
           << "min";
      cout << "\nLocal: " << evento.local;
      cout << "\n";
    }
  }

  fin.close();
}

void listagemEventosHoje() {

  // current date/time based on current system
  time_t now = time(0);

  // estrutura de data e hora
  struct tm *dh = localtime(&now);

  dh->tm_hour = dh->tm_hour - 3; // Descontado fuso-horário
  dh->tm_mon =
      dh->tm_mon + 1; // somando 1 ao mês (contagem dele inicia loucamente no 0)
  dh->tm_year =
      dh->tm_year +
      1900; // compensando o ano (a biblioteca tem domínio a partir de 1900)

  ifstream fin;
  fin.open("dados", ios::in | ios::binary);

  if (!fin) {
    cout << "Erro ao abrir o arquivo\n";
  }

  evento evento;
  cout << "\n[EVENTOS MARCADOS PARA HOJE]\n";

  while (fin.read((char *)&evento, sizeof(struct Evento))) {
    if (evento.data.dia == dh->tm_mday && evento.data.mes == dh->tm_mon &&
        evento.data.ano == dh->tm_year && evento.apagado == 0) {
      cout << "\nCodigo: " << evento.codigo;
      cout << "\nEvento: " << evento.nome;
      cout << "\nData: " << evento.data.dia << "/" << evento.data.mes << "/"
           << evento.data.ano;
      cout << "\nHorário: " << evento.data.hora << "h" << evento.data.minuto
           << "min";
      cout << "\nLocal: " << evento.local;
      cout << "\n";
    }
  }

  fin.close();
}

void remocaoLogica() {
  fstream finout; // abre para leitura e gravacao
  finout.open("dados");

  int apagado = 1; // para marcar como excluido
  int codigo, posicao;
  cout << "\nInsira o codigo do evento que deseja apagar: ";
  cin >> codigo; // pega o id do registro que sera marcado como eliminado

  // direciona o cursor para a posicao da variavel 'apagado'
  // rrn*sizeof(evento)+(4 bytes depois de id) = posicao da variavel 'apagado'
  posicao = (codigo - 1) * sizeof(evento) + 4;

  finout.seekp(posicao); // coloca o cursor na posicao
  finout.write((char *)&apagado,
               sizeof(int)); // sobrescreve int apagado de 0 para 1

  cout << "\n[Exclusao bem sucedida]\n\n";
}

void remocaoFisica() {
  // abre o arquvio em modo leitura e verifica
  ifstream fin;
  fin.open("dados", ios::in | ios::binary);
  if (!fin) {
    cout << "Erro ao abrir o arquivo\n";
  }

  // cria o arquivo temporario p/ gravar e verifica
  ofstream fout;
  fout.open("dadosTemp", ios::out | ios::app | ios::binary);
  if (!fout) {
    cout << "Erro ao abrir o arquivo\n";
  }

  evento evento;
  int i = 0; // para os novos codigos
  while (fin.read((char *)&evento, sizeof(struct Evento))) {
    if (evento.apagado == 0) {
      i++;
      evento.codigo = i; // reescreve os codigos
      fout.write((char *)&evento, sizeof(struct Evento));
    }
  }

  fin.close();
  fout.close();

  if (rename("dados", "trash") != 0)
    cout << ("\nErro na renomeação 1");

  if (rename("dadosTemp", "dados") != 0)
    cout << ("\nErro na renomeação 1");

  if (remove("trash") != 0)
    return;
  else
    cout << "\nApagado com sucesso\n";
}

int verifica_marcado() {
  ifstream fin;
  fin.open("dados", ios::in | ios::binary);
  if (!fin) {
    cout << "Erro ao abrir o arquivo\n";
  }

  evento evento;
  while (fin.read((char *)&evento, sizeof(struct Evento))) {
    if (evento.apagado == 1) {
      return 1;
    }
  }
  return 0;
}

int menuPrincipal() {
  int opcaoGeral;

  cout << "\nMENU" << endl;
  cout << "1. Adicionar evento" << endl;
  cout << "2. Listagem de eventos" << endl;
  cout << "3. Apagar evento\n";
  cout << "4. Remocao Fisica\n";
  cout << "5. Sair" << endl;
  cout << "\nOpção: ";
  cin >> opcaoGeral;

  return opcaoGeral;
}

int menuListagens() {
  int opcaoListagens;

  cout << "\nMENU" << endl;
  cout << "1. Listar todos eventos" << endl;
  cout << "2. Listar eventos por nome" << endl;
  cout << "3. Listar eventos por data" << endl;
  cout << "4. Listar eventos por mes" << endl;
  cout << "5. Listar eventos por local" << endl;
  cout << "6. Listar eventos hoje" << endl;
  cout << "7. Listar proximos eventos" << endl;
  cout << "8. Voltar" << endl;
  cout << "\nOpção: ";
  cin >> opcaoListagens;

  return opcaoListagens;
}