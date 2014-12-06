#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <cstdlib>

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
     * Entrada: (Item*) item
     * Saida: (bool) esta no inventario?
    */
        bool isInInventory(Item * item) const;

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
};

#endif
