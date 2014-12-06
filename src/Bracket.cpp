#include <vector>
#include <thread>
#include <chrono>
#include <queue>

#include "Bracket.hpp"

using namespace std;

    /*
     * Nome: Bracket (Construtor)
     * Descricao: Construtor que recebe uma lista de grupos
     * Entrada: (vector<Party*>) lista de grupos de personagens
    */
Bracket::Bracket(vector<Party *> partyList){
    if(partyList.size()==1){
        winner = partyList[0];

        leftBracket = NULL;
        rightBracket = NULL;
    }else{
        winner = NULL;

        vector<Party *> left(partyList.begin(), partyList.begin() + partyList.size()/2);
        vector<Party *> right(partyList.begin() + partyList.size()/2, partyList.end());

        leftBracket = new Bracket(left);
        rightBracket = new Bracket(right);
    }
}

    /*
     * Nome: ~Bracket (Destrutor)
     * Descricao: Destrutor para liberar memoria
    */
Bracket::~Bracket(){

    // Se a chave esquerda nao for nula, chamar seu destrutor

    if(leftBracket != NULL)
        delete leftBracket;

    // Se a chave direita nao for nula, chamar seu destrutor

    if(rightBracket != NULL);
        delete rightBracket;

}

    /*
     * Nome: solveTree
     * Descricao: Resolve a arvore de chaves de forma recursiva
     * Entrada: (vector<thread>) vetor de threads
    */
void Bracket::solveTree(vector<thread> & battles){
    if(winner == NULL && leftBracket->winner != NULL && rightBracket->winner != NULL){
        battles.push_back(thread(solveBattle));
    }else{
        leftBracket->solveTree(battles);
        rightBracket->solveTree(battles);
    }
}

    /*
     * Nome: solveBattle
     * Descricao: Faz uma batalha entre times
     * Saida: (void)
    */
void Bracket::solveBattle(){

    // Executando uma batalha ate a morte! >:D

    // Enquanto os dois times estiverem vivos...

    while(leftBracket->winner->isAlive() && rightBracket->winner->isAlive()){

        // Para cada time, criar uma fila com os characters embaralhados,
        // que corresponde a ordem em que estes vao atacar.

        queue<Character *> T1Queue = leftBracket->winner->shuffleCharacters();
        queue<Character *> T2Queue = rightBracket->winner->shuffleCharacters();

        // Enquanto ainda houver elementos em pelo menos uma das filas

        while(!T1Queue.empty() || !T2Queue.empty()){

            // Eliminar todos os characters mortos da fila do time 1,
            // caso haja algum.

            while(!T1Queue.empty() && !T1Queue.front()->isAlive())
                T1Queue.pop();

            // Se houver um character vivo do time 1 em T1Queue, entao atacar
            // um personagem vivo aleatorio do time 2.

            if(!T1Queue.empty()){
                Character * Attacker = T1Queue.front();
                Character * Victim = rightBracket->winner->getRandomAliveCharacter();

                Attacker->attack(Victim);

                T1Queue.pop();
            }

            // Se um dos times estiver morto, parar execucao...

            if(!(leftBracket->winner->isAlive() && rightBracket->winner->isAlive()))
                break;

            // Eliminar personagens mortos da fila de ataque do time 2.

            while(!T2Queue.empty() && !T2Queue.front()->isAlive())
                T2Queue.pop();

            // Fazer o primeiro personagem vivo da fila de ataque do time 2
            // atacar um personagem vivo aleatorio do time 1.

            if(!T2Queue.empty()){
                Character * Attacker = T2Queue.front();
                Character * Victim = leftBracket->winner->getRandomAliveCharacter();

                Attacker->attack(Victim);

                T2Queue.pop();
            }
        }
    }

    // O time que nao estver morto sobe na chave

    winner = leftBracket->winner->isAlive() ? leftBracket->winner : rightBracket->winner;

    // Restaurando o HP ds personagens do time vencedor,
    // para que eles possam batalhar novamente

    winner->resurrectCharacter();
}
