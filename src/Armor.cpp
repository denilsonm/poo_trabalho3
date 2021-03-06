#include <iostream>
#include <sstream>

#include "Armor.hpp"
#include "GameUtil.hpp"

/*
 * Nome: Armor (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome da armadura, (double) preço, (int) pontos de defesa, (double) peso
*/
Armor::Armor(const string name, double price, int defensepts, double weight) : Item(name, price){
    // Certifica que os pontos de defesa estão dentro do intervalo permitido
    this->defensepts = GameUtil::checkInterval(1, defensepts, 20);

    // Certifica que o peso esta dentro do intervalo permitido
    this->weight = GameUtil::checkInterval(1, weight, 20);
}

/*
 * Nome: Armor (Construtor de cópia)
 * Descricao: Construtor que copia os atributos de um objeto Armor
 * Entrada: (Armor&) Referencia para um objeto Armor
*/
Armor::Armor(Armor & armor) : Item(armor){
    defensepts = armor.defensepts;
    weight = armor.weight;
}

/*
 * Nome: getDefensePts
 * Descricao: retorna os pontos de defesa da armadura
 * Saida: (int) pontos de defesa
*/
int Armor::getDefensePts() const{
    return defensepts;
}

/*
 * Nome: getAttackPts
 * Descricao: retorna os pontos de ataque da armadura, nao usado nessa classe
 * Saida: (int) 0
*/
int Armor::getAttackPts() const{
    return 0;
}

/*
 * Nome: getWeight
 * Descricao: retorna o peso da armadura
 * Saida: (double) peso
*/
double Armor::getWeight() const{
    return weight;
}

/*
 * Nome: MaximumEquipped
 * Descricao: retorna a quantidade máxima desse item que podem ser equipados
 * Saida: (int) quantidade máxima
*/
int Armor::MaximumEquipped() const{
    return 1;
};

/*
 * Nome: use
 * Descricao: Equipa o item
 * Entrada: (Character&) Personagem em qual o item será equipado
 * Saida: void
*/
void Armor::use(Character & character){
    character.getInventory().equip(this);
}

string Armor::getName() const{
    return Item::getName();
}

// Retorna um clone da classe
Item * Armor::clone(){
    return new Armor(*this);
}

// Retorna uma descricao do item
Armor::operator string() const{
    ostringstream buffer;

    buffer << this->getName() << " ( " << this->getPrice() << " G / " << this->getDefensePts() << " defense / weights " << this->weight << " )";

    return buffer.str();  
}
