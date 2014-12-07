#include <sstream>
#include <string>

#include "ManaPotion.hpp"
#include "Character.hpp"

using namespace std;

/*
 * Nome: ManaPotion (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome da pocao, (double) preço, (int) poder de restauracao de mana
*/
ManaPotion::ManaPotion(const string name, double price, int restorepts) : Potion(name, price, restorepts){
}

/*
 * Nome: use
 * Descricao: usa a pocao
 * Entrada: (Character&) personagem usando a pocao
 * Saida: (void)
*/
void ManaPotion::use(Character & character){
    character.addMP(restorepts);

    character.getInventory().removeItem(getName());
}

// Retorna uma descricao do item
ManaPotion::operator string() const{
    ostringstream buffer;

    buffer << this->getName() << " ( " << this->getPrice() << " G / Restores " << restorepts << " MP )";

    return buffer.str();  
}
