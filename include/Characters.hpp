#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>

#include "Character.hpp"

using namespace std;

/*
 * Classe Knight
 *  Representa um personagem do jogo
*/
class Knight : public Character{

    protected:
        int power;

    public:

        /*
               * Nome: Knight (Construtor)
               * Descricao: Construtor que define os valores iniciais para os atributos da classe
               * Entrada: (string) nome do personagem, (int) vida, (int) mp, (int) poder
            */
        Knight(const string name, int hp, int mp, int newpower);

        /*
               * Nome: addPower
               * Descricao: Adiciona poder
               * Entrada: (int) poder
            */
        void addPower(int add);

        /*
               * Nome: getPower
               * Descricao: retorna o poder
               * Saida: (int) poder
            */
        int getPower() const;

    protected:

        /*
               * Nome: getAttackPts
               * Descricao: retorna a quantidade de pontos de ataque
               * Saida: (int) pontos de ataque
            */
        int getAttackPts() const;

        /*
               * Nome: getDefensePts
               * Descricao: retorna a quantidade de pontos de defesa
               * Saida: (int) pontos de defesa
            */
        int getDefensePoints() const;
};

/*
 * Classe Wizard
 *  Representa um personagem do jogo
*/
class Wizard : public Character{

    protected:
        int wisdom;

    public:

        /*
               * Nome: Wizard (Construtor)
               * Descricao: Construtor que define os valores iniciais para os atributos da classe
               * Entrada: (string) nome do personagem, (int) vida, (int) mp, (int) sabedoria
            */
        Wizard(const string name, int hp, int mp, int newwisdom);

        /*
               * Nome: addWisdom
               * Descricao: Adiciona sabedoria
               * Entrada: (int) sabedoria
            */
        void addWisdom(int add);

        /*
               * Nome: getWisdom
               * Descricao: retorna a sabedoria
               * Saida: (int) sabedoria
            */
        int getWisdom() const;

    protected:

        /*
               * Nome: getAttackPts
               * Descricao: retorna a quantidade de pontos de ataque
               * Saida: (int) pontos de ataque
            */
        int getAttackPoints() const;

        /*
               * Nome: getDefensePts
               * Descricao: retorna a quantidade de pontos de defesa
               * Saida: (int) pontos de defesa
            */
        int getDefensePoints() const;
};

/*
 * Classe Archer
 *  Representa um personagem do jogo
*/
class Archer : public Character{

    protected:
        int luck;

    public:

        /*
               * Nome: Archer (Construtor)
               * Descricao: Construtor que define os valores iniciais para os atributos da classe
               * Entrada: (string) nome do personagem, (int) vida, (int) mp, (int) sorte
            */
        Archer(const string name, int hp, int mp, int newluck);

        /*
               * Nome: addLuck
               * Descricao: Adiciona sorte
               * Entrada: (int) sorte
            */
        void addLuck(int add);

        /*
               * Nome: getLuck
               * Descricao: retorna a sorte -> "We're up all night to get lucky"
               * Saida: (int) sorte
            */
        int getLuck() const;

    protected:

        /*
               * Nome: getAttackPts
               * Descricao: retorna a quantidade de pontos de ataque
               * Saida: (int) pontos de ataque
            */
        int getAttackPoints() const;

        /*
               * Nome: getDefensePts
               * Descricao: retorna a quantidade de pontos de defesa
               * Saida: (int) pontos de defesa
            */
        int getDefensePoints() const;
};

#endif
