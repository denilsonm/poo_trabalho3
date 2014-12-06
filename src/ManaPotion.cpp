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
    character.addMP(getDefensePts());

    character.removeItem(getName());
}

/*
 * Nome: describe
 * Descricao: retorna uma string descrevendo o item
 * Saida: (string) descricao do item
*/
virtual string describe() const{
	ostringstream buffer;

	buffer << this->getName << " ( " << price << " G / Restores " << restorepts << " MP )";

	return buffer.str();  
}