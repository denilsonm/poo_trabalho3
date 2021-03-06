#include <sstream>

#include "HealthPotion.hpp"
#include "Character.hpp"

using namespace std;

/*
 * Nome: HealthPotion (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome da pocao, (double) preço, (int) poder de restauracao de vida
*/
HealthPotion::HealthPotion(const string name, double price, int restorepts) : Potion(name, price, restorepts){
}

/*
 * Nome: use
 * Descricao: usa a pocao
 * Entrada: (Character&) personagem usando a pocao
 * Saida: (void)
*/
void HealthPotion::use(Character & character){
    character.addHP(restorepts);

    character.getInventory().removeItem(getName());
}

// Retorna um clone da classe
Item * HealthPotion::clone(){
    return new HealthPotion(*this);
}

// Retorna uma descricao do item
HealthPotion::operator string() const{
    ostringstream buffer;

    buffer << this->getName() << " ( " << this->getPrice() << " G / Restores " << restorepts << " HP )";

    return buffer.str();  
}
