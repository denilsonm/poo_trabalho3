#include "HealthPotion.hpp"
#include "Character.hpp"

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
    character.addHP(getDefensePts());

    character.removeItem(getName());
}

// Retorna uma descricao do item
HealthPotion::operator string() const{
    ostringstream buffer;

    buffer << this->getName << " ( " << this->getPrice() << " G / Restores " << restorepts << " HP )";

    return buffer.str();  
}
