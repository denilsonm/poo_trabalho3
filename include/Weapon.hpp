#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <string>

#include "Item.hpp"
#include "Equipment.hpp"

/*
 * Classe Weapon
 *  Representa uma arma no jogo
*/
class Weapon : public Item, public Equipment{
    protected:
    int attackpts;

    double range;

    public:
    /*
     * Nome: Weapon (Construtor)
     * Descricao: Construtor que define os valores iniciais para os atributos da classe
     * Entrada: (std::string) nome da arma, (double) preço, (int) pontos de ataque, (double) alcance
    */
    Weapon(const string name, double price, int attackpts, double range);

    /*
     * Nome: Weapon (Construtor de cópia)
     * Descricao: Construtor que copia os atributos de um objeto Weapon
     * Entrada: (Weapon&) Referencia para um objeto Weapon
    */
    Weapon(Weapon & weapon);

    /*
     * Nome: describe
     * Descricao: retorna uma string descrevendo o item
     * Saida: (string) descricao do item
    */
    virtual string describe() const = 0;

    /*
     * Nome: getDefensePts
     * Descricao: retorna os pontos de defesa, nao usado nessa classe
     * Saida: (int) 0
    */
    int getDefensePts()const ;

    /*
     * Nome: getRange
     * Descricao: retorna o alcance da arma
     * Saida: (double) range
    */
    double getRange() const;

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
};

#endif
