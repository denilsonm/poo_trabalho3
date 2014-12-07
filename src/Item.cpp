#include "Item.hpp"
#include "Character.hpp"

/*
 * Nome: Item (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome do item, (double) preço
*/
Item::Item(const string name, double price){
    this->name = name;
    this->price = price;
}

/*
 * Nome: Item (Construtor de copia)
 * Descricao: Construtor que copia os atributos de um objeto Item
 * Entrada: (Item&) referencia ao objeto Item
*/
Item::Item(Item & item){
    name = item.name;
    price = item.price;
}

Item::~Item(){}

/*
 * Nome: getName
 * Descricao: Retorna o nome do item
 * Saida: (string) nome
*/
string Item::getName() const{
    return name;
}

/*
 * Nome: getPrice
 * Descricao: Retorna o preço do item
 * Saida: (double) preço
*/
double Item::getPrice() const{
    return price;
}

/*
 * Nome: getWeight
 * Descricao: Metodo virutal, retorna o peso do item
 * Saida: (double) peso
*/
double Item::getWeight() const{
    return 0;
}
