#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <string>

#include "Item.hpp"
#include "Equipment.hpp"
#include "Character.hpp"

/*
 * Classe Weapon
 *  Representa uma arma no jogo
*/
class Weapon : public Item, public Equipment{
    protected:
    int attackpts;

    public:
    /*
     * Nome: Weapon (Construtor)
     * Descricao: Construtor que define os valores iniciais para os atributos da classe
     * Entrada: (string) nome da arma, (double) preço, (int) pontos de ataque
    */
    Weapon(const string name, double price, int attackpts);

    /*
     * Nome: Weapon (Construtor de cópia)
     * Descricao: Construtor que copia os atributos de um objeto Weapon
     * Entrada: (Weapon&) Referencia para um objeto Weapon
    */
    Weapon(Weapon & weapon);

    /*
     * Nome: getDefensePts
     * Descricao: retorna os pontos de defesa, nao usado nessa classe
     * Saida: (int) 0
    */
    int getDefensePts() const;

    /*
     * Nome: getAttackPts
     * Descricao: retorna os pontos de ataque da arma
     * Saida: (int) pontos de ataque
    */
    int getAttackPts() const;

    /*
     * Nome: MaximumEquipped
     * Descricao: retorna a quantidade máxima desse item que podem ser equipados
     * Saida: (int) quantidade máxima
    */
    int MaximumEquipped() const;

    /*
     * Nome: use
     * Descricao: Equipa o item
     * Entrada: (Character&) Personagem em qual o item será equipado
     * Saida: void
    */
    void use(Character & character);

    /*
     * Nome: use
     * Descricao: Equipa o item
     * Entrada: (Character&) Personagem em qual o item será equipado
     * Saida: void
    */
    string getName() const;

    // Retorna uma descricao do item
    operator string() const;

    // Retorna um clone da classe
    virtual Item * clone();
};

#endif
