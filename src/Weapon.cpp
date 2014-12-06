#include <iostream>

#include "Weapon.hpp"

/*
 * Nome: Weapon (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome da arma, (double) preço, (int) pontos de ataque, (double) alcance
*/
Weapon::Weapon(const string name, double price, int attackpts, double range) : Item(name, price){
    // Certifica que os pontos de ataque estão dentro do intervalo permitido
    this->attackpts = GameUtil::checkInterval(1, attackpts, 20);

    this->range = range;
}

/*
 * Nome: Weapon (Construtor de cópia)
 * Descricao: Construtor que copia os atributos de um objeto Weapon
 * Entrada: (Weapon&) Referencia para um objeto Weapon
*/
Weapon::Weapon(Weapon & weapon) : Item(weapon){
    attackpts = weapon.attackpts;
    range = weapon.range;
}

/*
 * Nome: describe
 * Descricao: retorna uma string descrevendo o item
 * Saida: (string) descricao do item
*/
virtual string describe() const{
    ostringstream buffer;

    buffer << this->getName << " ( " << price << " G / " << getAttackPts() << " attack / range: " << range << " m )";

    return buffer.str();  
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
 * Nome: getRange
 * Descricao: retorna o alcance da arma
 * Saida: (double) range
*/
double Weapon::getRange() const{
    return range;
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
int Armor::MaximumEquipped() const{
    return 2;
};

/*
 * Nome: use
 * Descricao: Equipa o item
 * Entrada: (Character&) Personagem em qual o item será equipado
 * Saida: void
*/
void Armor::use(Character & character){
    target.equipItem(this);
}
