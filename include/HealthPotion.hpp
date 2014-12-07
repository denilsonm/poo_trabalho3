#ifndef _HEALTHPOTION_HPP_
#define _HEALTHPOTION_HPP_

#include <string>

#include "Potion.hpp"

/*
 * Classe HealthPotion
 *  Representa uma poção de vida no jogo
*/
class HealthPotion : public Potion{
    public:
    /*
     * Nome: HealthPotion (Construtor)
     * Descricao: Construtor que define os valores iniciais para os atributos da classe
     * Entrada: (string) nome da pocao, (double) preço, (int) poder de restauracao de vida
    */
    HealthPotion(string name, double price, int restorepts);

    /*
     * Nome: use
     * Descricao: usa a pocao
     * Entrada: (Character&) personagem usando a pocao
     * Saida: (void)
    */
    void use(Character & character);

    // Retorna uma descricao do item
    operator string() const;

    // Retorna um clone da classe
    virtual Item * clone();
};

#endif
