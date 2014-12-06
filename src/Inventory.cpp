#include <string>
#include <vector>
#include <cstdlib>
#include <typeinfo>
#include <iostream>

#include "Inventory.hpp"

#define STARTING_SPACE 10
#define STARTING_GOLD 0.0

using namespace std;

/*
 * Nome: Inventory (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
*/
Inventory::Inventory(){
    spaces = STARTING_SPACE;
    gold = STARTING_GOLD;
}

/*
 * Nome: Inventory (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (int) espaco/slots, (double) ouro
*/
Inventory::Inventory(int space, double gld){
    spaces = space;
    gold = gld;
}

/*
 * Nome: ~Inventory (Destrutor)
 * Descricao: Destrutor que libera a memoria do vetor de itens
*/
Inventory::~Inventory(){
    int i;

    for(i=0; i<items.size(); i++){
        delete items[i];
    }
}

/*
 * Nome: getGold
 * Descricao: Retorna o ouro do personagem
 * Saida: Ouro
*/
double Inventory::getGold() const{
    return gold;
}

/*
 * Nome: addGold
 * Descricao: aumenta ou diminui o ouro do personagem
 * Entrada: quantidade
*/
void Inventory::addGold(double amount){
    gold += amount;

    if(gold < 0){
        gold = 0;
}

/*
 * Nome: getAvailableSpace
 * Descricao: Retorna o espaco livre no inventario
 * Saida: espacos livres
*/
int Inventory::getAvailableSpace() const{
    return spaces - items.size();
}

/*
 * Nome: getItemAmount
 * Descricao: Retorna quantos itens existem
 * Saida: (int) quantidade de itens
*/
int Inventory::getItemAmount() const{
    return items.size();
}

/*
 * Nome: setSpaces
 * Descricao: Atribui uma quantidade de espacos para o inventario
 * Entrada: (int) Espacos
*/
void Inventory::setSpaces(int n){

    if( n < items.size() ){

        // Se o novo espaco maximo do inventario nao consegue conter todos
        // os items, os items do fim do vetor de items serao deletados ate
        // que o numero de items fique igual a spaces. Oops :)
        items.erase(items.end()-(items.size() - n), items.end());

    }

    spaces = n;

}

/*
 * Nome: searchItem
 * Descricao: Retorna um item do inventario
 * Entrada: (string) nome do item
 * Saida: (Item*) item
    */
Item * Inventory::searchItem(string itemName) const{

    int i;

    // Faz uma simples busca sequencial pelo item do nome procurado. Se encontra,
    // o retorna, caso contrario, retorna NULL.
    for(i=0; i<items.size(); i++){
        if(items[i]->getName() == itemName){
            return items[i];
        }
    }

    return NULL;

}

/*
 * Nome: searchItem
 * Descricao: Retorna um item do inventario
 * Entrada: (int) id do item
 * Saida: (Item*) item
*/
Item * Inventory::searchItem(int id) const{    // Retorna o id-esimo item no inventario.

    if(id < 0 || id >= items.size())
        return NULL;

    return items[id];

}

/*
 * Nome: isInInventory
 * Descricao: Verifica se o item esta no inventario
 * Entrada: (Item*) item
 * Saida: (bool) esta no inventario?
*/
bool Inventory::isInInventory(Item * item) const{

    int i;

    for(i=0; i<items.size(); i++){
        if(items[i] == item)
            return true;
    }

    return false;

}

/*
 * Nome: insertItem
 * Descricao: Insere um item no inventario
 * Entrada: (Item*) item
 * Saida: (bool) o item foi adicionado?
*/
bool Inventory::insertItem(Item * newItem){

    if(items.size() < spaces){
        items.push_back(newItem);
        return true;
    }
    return false;

}

/*
 * Nome: removeItem
 * Descricao: Remove um item do inventario
 * Entrada: (string) nome do item
*/
void Inventory::removeItem(string itemName){

    int i;

    for(i=0; i<items.size(); i++){
        if(items[i].first->getName() == itemName){
            delete items[i];

            items.erase(items.begin()+i);
            return;
        }
    }

}

/*
 * Nome: removeItem
 * Descricao: Remove um item do inventario
 * Entrada: (Item*) item
*/
void Inventory::removeItem(Item * item){

    int i;

    for(i=0; i<items.size(); i++){
        if(items[i] == item){
            delete items[i];

            items.erase(items.begin()+i);
            return;
        }
    }

}

/*
 * Nome: removeItem
 * Descricao: Remove um item do inventario
 * Entrada: (int) id do item
*/
void Inventory::removeItem(int id){

    if(0 <= id && id < items.size()){
        delete items[id];

        items.erase(items.begin()+id);
    }

}
