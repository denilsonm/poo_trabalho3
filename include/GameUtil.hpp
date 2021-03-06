#ifndef GAME_H
#define GAME_H

#include <map>
#include <vector>
#include <string>
#include <mutex>

using namespace std;

class GameUtil{

    private:

        /*
            namebase contem vetores de nomes para serem usados na geracao de
            nomes aleatorios. Mapeia do tipo do nome para o vetor de nomes.
            Por exemplo, pode-se mapear de "sobrenomes" para as possibilidades
            de sobrenomes, ou de "adjetivos" para possibilidades de adjetivos
            para equipamentos.
        */

        static map<string, vector<string> > namebase;

    public:

        /*
            Comandos que potencialmente possam ser acessados ao mesmo tempo
            podem usar esse mutex global para evitar problemas. Assume-se que
            o usuario nao sera estupido, e portanto nao havera problemas
            em deixar print_mutex public.
        */

        static mutex print_mutex;

        /*
           * Nome: pushName
           * Descricao: (static) Adiciona um nome a algum campo de namebase
           * Entrada: (string) tipo do nome, (string) nome a ser adicionado
         * Saida: (void)
        */
        static void pushName(string type, string element);

        /*
          * Nome: makeName
          * Descricao: Gera um nome aleatorio pela composicao de elementos aleatorios de nomes de tipo nameType1 e nameType2
          Os nomes sao extraidos do respectivo vector no map namebase.
          * Entrada: (string) tipo do primeiro nome, (string) tipo do segundo nome
          * Saida: Nome aleatorio gerado
        */
        static string makeName(const string nameType1, const string nameType2);

        /*
           * Nome: checkInterval
           * Descricao: (static) Checa se determinado valor 'n' esta no intervalo entre 'a' e 'b'
           * Entrada: (int) menor valor, (int) valor, (int) maior valor
         * Saida: (int) valor corrigido
        */
        static int checkInterval(int a, int n, int b);

        /*
         * Nome: generateRandom
         * Descricao: Gera um numero aleatorio entre 'a' e 'b'
         * Entrada: (int) menor valor, (int) maior valor
         * Saida: Numero aleatorio gerado
        */
        static int generateRandom(int a, int b);

        /*
         * Nome: generateDouble
         * Descricao: Gera um numero aleatorio entre 'a' e 'b'
         * Entrada: (double) menor valor, (double) maior valor
         * Saida: Numero aleatorio gerado (double)
        */
        static double generateDouble(double a, double b);
};

#endif
