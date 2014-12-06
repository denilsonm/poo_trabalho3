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
        Tournament(vector<Party *> partyList);

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

    /*
     * Nome: getWinner
     * Descricao: Se o torneio terminou, havera um vencedor e ele sera retornado.
     Caso contrario, um ponteiro NULL sera retornado. Essa funcao pode ser usada
     para determinar se o torneio acabou.
     * Saida: (Character *) party vencedora
    */
        Party * getWinner();

};

#endif
