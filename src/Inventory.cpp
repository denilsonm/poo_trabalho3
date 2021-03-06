#include <string>
#include <vector>
#include <cstdlib>
#include <typeinfo>
#include <iostream>
#include <sstream>

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
        if(items[i]->getName().compare(itemName) == 0){
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
 * Entrada: (string) nome do item
 * Saida: (bool) esta no inventario?
*/
bool Inventory::isInInventory(const string itemName) const{

    return searchItem(itemName) != NULL;
}

/*
 * Nome: isInInventory
 * Descricao: Verifica se o item esta no inventario
 * Entrada: (Item *) ponteiro para o item
 * Saida: (bool) esta no inventario?
*/
bool Inventory::isInInventory(const Item * ptr) const{

    for(int i=0; i<items.size(); i++){
        if(items[i]==ptr)
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
    if(newItem == NULL)
        return false;

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
        if(items[i]->getName() == itemName){
            unequip(dynamic_cast<Equipment*>(items[i]));

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

        unequip(dynamic_cast<Equipment*>(items[id]));

        delete items[id];

        items.erase(items.begin()+id);
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

            unequip(dynamic_cast<Equipment*>(item));

            delete item;
    
            items.erase(items.begin()+i);
            return;
        }
    }

}

/*
 * Nome: searchEquipment
 * Descricao: Retorna um equipamento do inventario
 * Entrada: (int) id do equipamento
 * Saida: (Equipment *) ponteiro para o equipamento
*/
Equipment * Inventory::searchEquipment(int id) const{
    if(id < equipments.size() && id >= 0)
        return equipments[id];
    else
        return NULL;
}

/*
 * Nome: getEquipmentAmount
 * Descricao: Retorna o numero de itens equipados
 * Saida: (int) numero de itens equipados
*/
int Inventory::getEquipmentAmount() const{
    return equipments.size();
}

/*
   * Nome: equip
   * Descricao: Adiciona um equipamento que estava no inventario
   * Entrada: (Equipment*) Equipamento
   * Saida: (bool) obteve sucesso?
*/
bool Inventory::equip(Equipment * equipment){
    if(equipment == NULL)
        return false;

    if(!isEquipped(equipment) && isInInventory(equipment->getName()))
    {
        if(getEquippedAmount(equipment) < equipment->MaximumEquipped())
            equipments.push_back(equipment);
    }
}

/*
   * Nome: unequip
   * Descricao: remove um equipamento que estava equipado
   * Entrada: (Equipment*) Equipamento
   * Saida: (bool) obteve sucesso?
*/
bool Inventory::unequip(Equipment * equipment){
    for(int i=0; i<equipments.size(); i++){
        if(equipments[i]==equipment){
            equipments.erase(equipments.begin()+i);
            return true;
        }
    }

    return false;
}

int Inventory::getEquippedAmount(string equipmentType) const{

        int i, equipped = 0;

            for(i=0; i<equipments.size(); i++){
                        if(equipmentType == typeid(*equipments[i]).name())
                                        equipped++;
                            }

                return equipped;

}

int Inventory::getEquippedAmount(Equipment * equipment) const{

        return getEquippedAmount(typeid(*equipment).name());

}

/*
   * Nome: isEquipped
   * Descricao: checa se o item ja esta equipado
   * Entrada: (Equipment*) Equipamento
   * Saida: (bool) retorna o resultado
*/
bool Inventory::isEquipped(const Equipment * equipment) const{
    for(int i=0; i<equipments.size(); i++){
        if(equipments[i]==equipment){
            return true;
        }
    }

    return false;
}

/*
   * Nome: isEquipped
   * Descricao: checa se o item ja esta equipado
   * Entrada: (string) nome do equipamento
   * Saida: (bool) retorna o resultado
*/
bool Inventory::isEquipped(const string name) const{
    for(int i=0; i<equipments.size(); i++){
        if(equipments[i]->getName()==name){
            return true;
        }
    }

    return false;
}

/*
 * Nome: getWeight
 * Descricao: Retorna a soma do peso de todos os itens do inventario
 * Entrada: (int) soma dos pesos
*/
int Inventory::getWeight() const{

    int w = 0;

    for(int i=0; i<items.size(); i++){
        w += items[i]->getWeight();
    }

    return w;

}

Inventory::operator string() const{
    ostringstream buffer;

    buffer << "Gold: " << gold << "\nSpace: " << items.size() << " / " << spaces << "\n\n";

    if(items.size()==0)
        buffer << "\tInventory is empty!";
    else{
        int i;

        for(i=0; i<items.size(); i++){
            if(i!=0)
                buffer << "\n";

            buffer << "\t" << i << " - ";

            if(isEquipped(items[i]->getName()))
                buffer << "(EQUIPPED) ";

            buffer << (string)*(items[i]);
        }
    }

    return buffer.str();
}
