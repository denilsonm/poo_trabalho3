#ifndef _ARMOR_HPP_
#define _ARMOR_HPP_

#include <string>

#include "Item.hpp"
#include "Equipment.hpp"
#include "Character.hpp"

/*
 * Classe Armor
 *  Representa uma armadura no jogo
*/
class Armor : public Item, public Equipment{
    protected:
    int defensepts;

    double weight;

    public:
    /*
     * Nome: Armor (Construtor)
     * Descricao: Construtor que define os valores iniciais para os atributos da classe
     * Entrada: (string) nome da armadura, (double) preço, (int) pontos de defesa, (double) peso
    */
    Armor(const string name, double price, int defensepts, double weight);

    /*
     * Nome: Armor (Construtor de cópia)
     * Descricao: Construtor que copia os atributos de um objeto Armor
     * Entrada: (Armor&) Referencia para um objeto Armor
    */
    Armor(Armor & armor);

    /*
     * Nome: getDefensePts
     * Descricao: retorna os pontos de defesa da armadura
     * Saida: (int) pontos de defesa
    */
    virtual int getDefensePts() const;
    
    /*
     * Nome: getAttackPts
     * Descricao: retorna os pontos de ataque da armadura, nao usado nessa classe
     * Saida: (int) 0
    */
    virtual int getAttackPts() const;

    /*
     * Nome: getWeight
     * Descricao: retorna o peso da armadura
     * Saida: (double) peso
    */
    double getWeight() const;

    /*
     * Nome: MaximumEquipped
     * Descricao: retorna a quantidade máxima desse item que podem ser equipados
     * Saida: (int) quantidade máxima
    */
    virtual int MaximumEquipped() const;

    /*
     * Nome: use
     * Descricao: Equipa o item
     * Entrada: (Character&) Personagem em qual o item será equipado
     * Saida: void
    */
    void use(Character & character);

    string getName() const;

    // Retorna uma descricao do item
    operator string() const;
};

#endif
