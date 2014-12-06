#ifndef BRACKET_H
#define BRACKET_H

#include <vector>
#include <thread>

#include "Character.hpp"
#include "GameUtil.hpp"

using namespace std;

/*
 * Classe Bracket
 *  Representa uma chave do torneio
*/
class Bracket{

    private:
        Party * winner;

        Bracket * leftBracket;
        Bracket * rightBracket;

    public:

    /*
     * Nome: Bracket (Construtor)
     * Descricao: Construtor que recebe uma lista de grupos
     * Entrada: (vector<Party*>) lista de grupos de personagens
    */
        Bracket(vector<Party *> characterList);

    /*
     * Nome: ~Bracket (Destrutor)
     * Descricao: Destrutor para liberar memoria
    */
        ~Bracket();

    /*
     * Nome: solveTree
     * Descricao: Resolve a arvore de chaves de forma recursiva
     * Entrada: (vector<thread>) vetor de threads
    */
        void solveTree(vector<thread> battles);

    /*
     * Nome: solveBattle
     * Descricao: Faz uma batalha entre times
     * Saida: (void)
    */
        void solveBattle();

};

#endif
