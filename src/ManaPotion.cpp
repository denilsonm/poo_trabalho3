#include "ManaPotion.hpp"
#include "Character.hpp"

/*
 * Nome: ManaPotion (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (std::string) nome da pocao, (double) preço, (int) poder de restauracao de mana
*/
ManaPotion::ManaPotion(std::string name, double price, int restorepts) : Potion(name, price, restorepts){
}

/*
 * Nome: use
 * Descricao: usa a pocao
 * Entrada: (Character&) personagem usando a pocao
 * Saida: (void)
*/
void ManaPotion::use(Character & character){
    character.addMP(getDefensePts());

    character.removeItem(getName());
}
