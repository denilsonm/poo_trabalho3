#ifndef _ITEM_HPP
#define _ITEM_HPP

#include <string>

using namespace std;

/*
 * Classe Character
 *  Utilizada apenas como referencia para o metodo use
*/
class Character;

/*
 * Classe Item
 *  Representa um item no jogo
*/
class Item{
    private:

    string name; // Nome do item
    double price; // Preço do item

    public:

    /*  
     * Nome: Item (Construtor)
     * Descricao: Construtor que define os valores iniciais para os atributos da classe
     * Entrada: (string) nome do item, (double) preço
    */
    Item(string name, double price);

    /*
     * Nome: Item (Construtor de copia)
     * Descricao: Construtor que copia os atributos de um objeto Item
     * Entrada: (Item&) referencia ao objeto Item
    */
    Item(Item & item);

    /*
     * Nome: getName
     * Descricao: Retorna o nome do item
     * Saida: (std::string) nome
    */
    std::string getName() const;

    /*
     * Nome: getPrice
     * Descricao: Retorna o preço do item
     * Saida: (double) preço
    */
    double getPrice() const;

    /*
     * Nome: getWeight
     * Descricao: Metodo virtual, retorna o peso do item
     * Saida: (double) peso
    */
    double Item::getWeight() const;

    /*
     * Nome: use
     * Descricao: metodo virtual, utiliza um item
     * Entrada: (Character&) personagem usando o item
     * Saida: (void)
    */
    virtual void use(Character & character) = 0;
};

#endif
