#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <cstdlib>

#include "Equipment.hpp"
#include "Item.hpp"

#define STARTING_SPACE 10
#define STARTING_GOLD 0.0

using namespace std;

/*
 * Classe Inventory
 *  Representa um inventario de um personagem
*/
class Inventory{

    private:
        int spaces;
        double gold;

        vector<Item *> items;
        vector<Equipment*> equipments;

    public:

    /*
     * Nome: Inventory (Construtor)
     * Descricao: Construtor que define os valores iniciais para os atributos da classe
    */
        Inventory();

    /*
     * Nome: Inventory (Construtor)
     * Descricao: Construtor que define os valores iniciais para os atributos da classe
     * Entrada: (int) espaco/slots, (double) ouro
    */
        Inventory(int space, double gld);

    /*
     * Nome: ~Inventory (Destrutor)
     * Descricao: Destrutor que libera a memoria do vetor de itens
    */
        ~Inventory();

    /*
     * Nome: getGold
     * Descricao: Retorna o ouro do personagem
     * Saida: Ouro
    */
        double getGold() const;

    /*
     * Nome: addGold
     * Descricao: aumenta ou diminui o ouro do personagem
     * Entrada: quantidade
    */
        void addGold(double amount);

    /*
     * Nome: getAvailableSpace
     * Descricao: Retorna o espaco livre no inventario
     * Saida: espacos livres
    */
        int getAvailableSpace() const;

    /*
     * Nome: getItemAmount
     * Descricao: Retorna quantos itens existem
     * Saida: (int) quantidade de itens
    */
        int getItemAmount() const;

    /*
     * Nome: setSpaces
     * Descricao: Atribui uma quantidade de espacos para o inventario
     * Entrada: (int) Espacos
    */
        void setSpaces(int n);

    /*
     * Nome: searchItem
     * Descricao: Retorna um item do inventario
     * Entrada: (string) nome do item
     * Saida: (Item*) item
    */
        Item * searchItem(string itemName) const;
    /*
     * Nome: searchItem
     * Descricao: Retorna um item do inventario
     * Entrada: (int) id do item
     * Saida: (Item*) item
    */
        Item * searchItem(int id) const;

    /*
     * Nome: isInInventory
     * Descricao: Verifica se o item esta no inventario
     * Entrada: (string) nome do item
     * Saida: (bool) esta no inventario?
    */
        bool isInInventory(const string itemName) const;

    /*
     * Nome: isInInventory
     * Descricao: Verifica se o item esta no inventario
     * Entrada: (Item *) ponteiro para o item
     * Saida: (bool) esta no inventario?
    */
        bool isInInventory(const Item * ptr) const;

    /*
     * Nome: insertItem
     * Descricao: Insere um item no inventario
     * Entrada: (Item*) item
     * Saida: (bool) o item foi adicionado?
    */
        bool insertItem(Item * newItem);


    /*
     * Nome: removeItem
     * Descricao: Remove um item do inventario
     * Entrada: (string) nome do item
    */
        void removeItem(string itemName);

    /*
     * Nome: removeItem
     * Descricao: Remove um item do inventario
     * Entrada: (int) id do item
    */
        void removeItem(int id);

    /*
     * Nome: removeItem
     * Descricao: Remove um item do inventario
     * Entrada: (Item*) item
    */
        void removeItem(Item * item);

    /*
     * Nome: searchEquipment
     * Descricao: Retorna um equipamento do inventario
     * Entrada: (int) id do equipamento
     * Saida: (Equipment *) ponteiro para o equipamento
    */
        Equipment * searchEquipment(int id) const;

    /*
     * Nome: getEquipmentAmount
     * Descricao: Retorna o numero de itens equipados
     * Saida: (int) numero de itens equipados
    */
        int getEquipmentAmount() const;

    /*
       * Nome: equip
       * Descricao: Adiciona um equipamento que estava no inventario
       * Entrada: (Equipment*) Equipamento
       * Saida: (bool) obteve sucesso?
    */
        bool equip(Equipment * equipment);

    /*
       * Nome: unequip
       * Descricao: remove um equipamento que estava equipado
       * Entrada: (Equipment*) Equipamento
       * Saida: (bool) obteve sucesso?
    */
        bool unequip(Equipment * equipment);

    /*
       * Nome: isEquipped
       * Descricao: checa se o item ja esta equipado
       * Entrada: (Equipment*) Equipamento
       * Saida: (bool) retorna o resultado
    */
        bool isEquipped(Equipment * equipment) const;

    /*
     * Nome: getWeight
     * Descricao: Retorna a soma do peso de todos os itens do inventario
     * Entrada: (int) soma dos pesos
    */
        int getWeight() const;
};

#endif
