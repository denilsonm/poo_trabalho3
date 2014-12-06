#include <iostream>

#include "Armor.hpp"
#include "GameUtil.hpp"

/*
 * Nome: Armor (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (std::string) nome da armadura, (double) preço, (int) pontos de defesa, (double) peso
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
 * Nome: describe
 * Descricao: retorna uma string descrevendo o item
 * Saida: (string) descricao do item
*/
virtual string describe() const{
    ostringstream buffer;

    buffer << this->getName << " ( " << price << " G / " << getDefensePts() << " defense / weights " << weight << " )";

    return buffer.str();  
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
    character.equipItem(this);
}
