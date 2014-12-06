#ifndef _MANAPOTION_HPP_
#define _MANAPOTION_HPP_

#include <string>

#include "Potion.hpp"

/*
 * Classe ManaPotion
 *  Representa uma poção de magia no jogo
*/
class ManaPotion : public Potion{
    public:
    /*
     * Nome: ManaPotion (Construtor)
     * Descricao: Construtor que define os valores iniciais para os atributos da classe
     * Entrada: (std::string) nome da pocao, (double) preço, (int) poder de restauracao de mana
    */
    ManaPotion(std::string name, double price, int restorepts);

    /*
     * Nome: use
     * Descricao: usa a pocao
     * Entrada: (Character&) personagem usando a pocao
     * Saida: (void)
    */
    void use(Character & character);
};

#endif
