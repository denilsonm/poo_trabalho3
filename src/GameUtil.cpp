#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
#include <map>

#include "GameUtil.hpp"

using namespace std;

map<string, vector<string> > GameUtil::namebase = map<string, vector<string> >();

/*
 * Nome: pushName
 * Descricao: (static) Adiciona um nome a algum campo de namebase
 * Entrada: (string) tipo do nome, (string) nome a ser adicionado
 * Saida: (void)
*/
void GameUtil::pushName(string type, string element){
  if(namebase.find(type)==namebase.end()){
    namebase.insert(make_pair(type, vector<string>()));
  }

  namebase[type].push_back(element);
}

/*
  * Nome: makeName
  * Descricao: Gera um nome aleatorio pela composicao de elementos aleatorios de nomes de tipo nameType1 e nameType2
  Os nomes sao extraidos do respectivo vector no map namebase.
  * Entrada: (string) tipo do primeiro nome, (string) tipo do segundo nome
  * Saida: Nome aleatorio gerado
*/
string GameUtil::makeName(const string nameType1, const string nameType2){
  if(namebase.find(nameType1)==namebase.end() || namebase.find(nameType2)==namebase.end())
    return "";

  ostringstream buffer;

  buffer << namebase[nameType1][ GameUtil::generateRandom(0, namebase[nameType1].size()-1) ]
      << " " << namebase[nameType2][ GameUtil::generateRandom(0, namebase[nameType2].size()-1) ];

  return buffer.str();
}

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

/*
 * Nome: generateDouble
 * Descricao: Gera um numero aleatorio entre 'a' e 'b'
 * Entrada: (double) menor valor, (double) maior valor
 * Saida: Numero aleatorio gerado (double)
*/
double GameUtil::generateDouble(double a, double b){
    return ((double)rand())/(b-a)+a;
}
