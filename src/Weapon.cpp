#include <iostream>
#include <sstream>

#include "Weapon.hpp"
#include "GameUtil.hpp"

/*
 * Nome: Weapon (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome da arma, (double) preço, (int) pontos de ataque
*/
Weapon::Weapon(const string name, double price, int attackpts) : Item(name, price){
    // Certifica que os pontos de ataque estão dentro do intervalo permitido
    this->attackpts = GameUtil::checkInterval(1, attackpts, 20);
}

/*
 * Nome: Weapon (Construtor de cópia)
 * Descricao: Construtor que copia os atributos de um objeto Weapon
 * Entrada: (Weapon&) Referencia para um objeto Weapon
*/
Weapon::Weapon(Weapon & weapon) : Item(weapon){
    attackpts = weapon.attackpts;
}

/*
 * Nome: getDefensePts
 * Descricao: retorna os pontos de defesa, nao usado nessa classe
 * Saida: (int) 0
*/
int Weapon::getDefensePts() const{
    return 0;
}

/*
 * Nome: getAttackPts
 * Descricao: retorna os pontos de ataque da arma
 * Saida: (int) pontos de ataque
*/
int Weapon::getAttackPts() const{
    return attackpts;
}

/*
 * Nome: MaximumEquipped
 * Descricao: retorna a quantidade máxima desse item que podem ser equipados
 * Saida: (int) quantidade máxima
*/
int Weapon::MaximumEquipped() const{
    return 2;
};

/*
 * Nome: use
 * Descricao: Equipa o item
 * Entrada: (Character&) Personagem em qual o item será equipado
 * Saida: void
*/
void Weapon::use(Character & character){
    character.getInventory().equip(this);
}

string Weapon::getName() const{
    return Item::getName();
}

// Retorna uma descricao do item
Weapon::operator string() const{
    ostringstream buffer;

    buffer << this->getName() << " ( " << this->getPrice() << " G / " << this->getAttackPts() << " attack )";

    return buffer.str();  
}

// Retorna um clone da classe
Item * Weapon::clone(){
    return new Weapon(*this);
}