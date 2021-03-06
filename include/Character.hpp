#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "Inventory.hpp"
#include "Equipment.hpp"

#define MAX_XP 100

#define MAX_HP 100

#define MAX_ATTR_SUM 100

using namespace std;

/*
 * Classe Character
 *  Representa um personagem do jogo
*/
class Character{

    private:
        string name;

        Inventory inventory;

        int HP;
        int MP;
        int MAXHP;

        int XP;

        int strength;
        int speed;
        int dexterity;
        int constitution;
    public:

        /*
               * Nome: Character (Construtor)
               * Descricao: Construtor que define os valores iniciais para os atributos da classe
               * Entrada: (string) nome do personagem, (int) vida, (int) mp
            */
        Character(const string name, int hp, int mp);

        virtual ~Character();

        /*
               * Nome: getName
               * Descricao: Retorna o nome do personagem
               * Saida: (string) nome
            */
        string getName() const;

        /*
               * Nome: getHP
               * Descricao: Retorna os pontos de vida
               * Saída: (int) hp
            */
        int getHP() const;

        /*
               * Nome: getMP
               * Descricao: Retorna os pontos de magia
               * Saída: (int) mp
            */
        int getMP() const;

        /*
               * Nome: isAlive
               * Descricao: Retorna se o personagem esta vivo
               * Saída: (bool) esta vivo?
            */
        bool isAlive() const;

        /*
               * Nome: getAttributeSum
               * Descricao: Retorna a soma dos atributos
               * Saída: (int) soma dos atributos
            */
        int getAttributeSum() const;

        /*
               * Nome: getSpeed
               * Descricao: Retorna a velocidade, baseado na soma dos pesos de todos os
                itens no inventario
               * Saída: (int) velocidade
            */
        int getSpeed() const;

        /*
               * Nome: setStrength
               * Descricao: Atribui uma forca
               * Entrada: (int) forca
            */
        void setStrength(int newStr);

        /*
               * Nome: setSpeed
               * Descricao: Atribui uma velocidade
               * Entrada: (int) velocidade
            */
        void setSpeed(int newSpd);

        /*
               * Nome: setDexterity
               * Descricao: Atribui uma Destreza
               * Entrada: (int) destreza
            */
        void setDexterity(int newDex);

        /*
               * Nome: setConstitution
               * Descricao: Atribui uma constituicao
               * Entrada: (int) constituicao
            */
        void setConstitution(int newConst);

        /*
               * Nome: addHP
               * Descricao: Aumenta ou diminui o HP
               * Entrada: (int) Quantidade
            */
        void addHP(int amount);

        /*
               * Nome: addMP
               * Descricao: Aumenta ou diminui o MP
               * Entrada: (int) Quantidade
            */
        void addMP(int amount);

        /*
               * Nome: addXP
               * Descricao: Aumenta o XP
               * Entrada: (int) Quantidade
            */
        void addXP(int amount);

        /*
               * Nome: attack
               * Descricao: ataca outro personagem
               * Entrada: (Character*) vitima
            */
        void attack(Character * victim);

            /*
               * Nome: getInventory
               * Descricao: retorna o inventario do character, por referencia
               * Entrada: (Inventory &) inventario do character
            */
        Inventory & getInventory();

            /*
               * Nome: resurrect
               * Descricao: Retorna os pontos de vida do personagem para o valor máximo
               * Saida: void
            */
        void resurrect();

    protected:

        /*
               * Nome: getAttackPts
               * Descricao: (Puramente virtual) retorna a quantidade de pontos de ataque
               * Saida: (int) pontos de ataque
            */
        virtual int getAttackPoints() const = 0;

        /*
               * Nome: getDefensePts
               * Descricao: (Puramente virtual) retorna a quantidade de pontos de defesa
               * Saida: (int) pontos de defesa
            */
        virtual int getDefensePoints() const = 0;

        /*
               * Nome: getBaseAttackPts
               * Descricao: retorna os pontos de ataque base
               * Saida: (int) pontos de ataque base
            */
        int getBaseAttackPoints() const;

        /*
               * Nome: getBaseDefesePts
               * Descricao: retorna os pontos de defesa base
               * Saida: (int) pontos de defesa base
            */
        int getBaseDefensePoints() const;
};

#endif
