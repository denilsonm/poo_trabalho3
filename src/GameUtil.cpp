#include <cstdlib>

#include "GameUtil.hpp"

/*
  * Nome: checkInterval
  * Descricao: (static) Checa se determinado valor 'n' esta no intervalo entre 'a' e 'b'
  * Entrada: (int) menor valor, (int) valor, (int) maior valor
  * Saida: (int) valor corrigido
*/
int GameUtil::checkInterval(int a, int n, int b){
    if(n < a)
        return a;
    else if(n > b)
        return b;
    else
        return n;
}

/*
  * Nome: generateRandom
  * Descricao: Gera um numero aleatorio entre 'a' e 'b'
  * Entrada: (int) menor valor, (int) maior valor
  * Saida: Numero aleatorio gerado
*/
int GameUtil::generateRandom(int a, int b){
    return rand()%(b-a+1)+a;
}
