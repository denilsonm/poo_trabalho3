#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <vector>

#include "Bracket.hpp"
#include "Party.hpp"

using namespace std;

/*
 * Classe Tournament
 *  Representa um torneio
*/
class Tournament{

    private:
        Bracket * mainBracket;

    public:

    /*
     * Nome: Tournament (Construtor)
     * Descricao: Construtor que recebe uma lista de grupos
     * Entrada: (vector<Party*>) lista de grupos de personagens
    */
        Tournament(vector<Party *> characterList);

    /*
     * Nome: ~Tournament (Destrutor)
     * Descricao: Libera a memoria usada por mainBracket
    */
        ~Tournament();

    /*
     * Nome: startRound
     * Descricao: Inicia um round do torneio
     * Saida: (void)
    */
        void startRound();

};

#endif
