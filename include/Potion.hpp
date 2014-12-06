#ifndef _POTION_HPP_
#define _POTION_HPP_

#include <string>

#include "Item.hpp"

using namespace std;

/*
 * Classe Potion
 *  Representa uma poção no jogo
*/
class Potion : public Item
{
    private:
    int restorepts;

    public:
    /*
     * Nome: Potion (Construtor)
     * Descricao: Construtor que define os valores iniciais para os atributos da classe
     * Entrada: (std::string) nome da pocao, (double) preço, (int) poder de restauracao
    */
    Potion(std::string name, double price, int restorepts);

    /*
     * Nome: Potion (Construtor de cópia)
     * Descricao: Construtor que copia os atributos de um objeto Potion
     * Entrada: (Potion&) Referencia para um objeto Potion
    */
    Potion(Potion & potion);
};

#endif