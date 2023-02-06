# Agenda
Trabalho feito em grupo com Ricardo Araújo e Alex Cardoso para a disciplina Organização e Recuperação da Informação.


O programa consiste em uma agenda, onde, quando se inicia a execução, é apresentado um menu, no qual é possivel adicionar um evento, listar os eventos, apagá-los
(remoção lógica, onde o evento é marcado como apagado) e a funçaõo de remoção física, onde os eventos são de fato apagados do arquivo de dados.

Na opção de adicionar um evento, é necessário inserir o nome, em seguida a data no seguinte formato (dd mm aa hh mm) e o local.
Ao adicionar um arquivo, o programa verifica se há um arquivo de dados, senão há, um novo é criado.

Há também diferentes tipos de listagens, feitas pelos diferentes atributos dos arquivos, como data, local e listar todos os eventos.

A remoção física é feita da seguinte forma: os eventos marcados como "não apagados" são copiados para um novo arquivo de dados, o antigo é excluido e o novo é
renomeado como "dados" para que o programa o reconheça como o atual arquivo de dados.
