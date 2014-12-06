#ifndef GAME_H
#define GAME_H

class GameUtil{

    public:

        /*
           * Nome: checkInterval
           * Descricao: (static) Checa se determinado valor 'n' esta no intervalo entre 'a' e 'b'
           * Entrada: (int) menor valor, (int) valor, (int) maior valor
         * Saida: (int) valor corrigido
        */
        static int checkInterval(int a, int n, int b);

        /*    Funcao generateRandom(int a, int b)

            Retorna um numero aleatorio entre a e b

        */

        /*
         * Nome: generateRandom
         * Descricao: Gera um numero aleatorio entre 'a' e 'b'
         * Entrada: (int) menor valor, (int) maior valor
         * Saida: Numero aleatorio gerado
        */
        static int generateRandom(int a, int b);
};

#endif
