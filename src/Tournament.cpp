#include <vector>
#include <thread>
#include <mutex>

#include "Tournament.hpp"
#include "Bracket.hpp"
#include "Party.hpp"

using namespace std;

    /*
     * Nome: Tournament (Construtor)
     * Descricao: Construtor que recebe uma lista de grupos
     * Entrada: (vector<Party*>) lista de grupos de personagens
    */
Tournament::Tournament(vector<Party *> partyList){
    mainBracket = new Bracket(partyList);
}

    /*
     * Nome: ~Tournament (Destrutor)
     * Descricao: Libera a memoria usada por mainBracket
    */
Tournament::~Tournament(){
    delete mainBracket;
}

    /*
     * Nome: startRound
     * Descricao: Inicia um round do torneio
     * Saida: (void)
    */
void Tournament::startRound(){
    // Vetor de batalhas acontecendo

    vector<thread> battles;
    mutex barrier;

    // Executa um round, sendo cada batalha executada em
    // uma thread.

    mainBracket->solveTree(battles, barrier);

    int i;

    // Esperar a execucao de todas as batalhas ocorrendo em
    // paralelo terminar

    for(i=0; i<battles.size(); i++)
        if(battles[i].joinable())
            battles[i].join();
}

Party * Tournament::getWinner(){
    if(mainBracket != NULL)
        return mainBracket->getWinner();
    else
        return NULL;
}
