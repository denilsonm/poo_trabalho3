#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "Inventory.hpp"

#define MAX_XP 100
#define MAX_HP 100

#define MAX_ATTR_SUM 100

using namespace std;

class Character{

	/*	Atributos da classe	*/

	private:
		string alias;
		Inventory myitems;

		int HP;
		int MP;

	protected:
		int XP;

		int strength;
		int speed;
		int dexterity;
		int constitution;

		bool dead;		// Diz se o personagem esta morto. Se esta,
						// chamadas a funcao takeDamage sao ignoradas.
	public:

	/*	Metodos da classe	*/

		/*	Construtor	*/

		Character(const string name);

		/*
			Para a classe Character, nao ha necessidade de um destrutor, ja que
			o proprio programa se encarrega de destruir tipos primitivos e a string
			alias, e quanto ao atributo myitems, seu destrutor eh chamado
			automaticamente quando Character eh destruido.
		*/

		/*	Metodos getters	*/

		string getName() const;

			// Foi necessario implementar o metodo getHP para que a classe
			// Team conseguisse acessar o HP de cada personagem.

		int getHP() const;

		bool isAlive() const;

		int getAttributeSum() const;

		int getSpeed() const;

		/*	Metodos setters	*/

		void setStrength(int newStr);

		void setSpeed(int newSpd);

		void setDexterity(int newDex);

		void setConstitution(int newConst);

		void addHP(int amount);

		void addMP(int amount);

		void addXP(int amount);

		void resurrect();

		/*	Outros metodos	*/

		void attack(Character * victim);

		// Ja que myitems eh um atributo private de Character, eh necessario
		// um metodo para que funcoes externas a classe consigam fazer com que
		// itens sejam adicionados ao inventario do personagem

		bool takeItem(Item * item);

		bool hasItem(Item * item);

		void equipItem(Item * item);

		void removeItem(Item * item);

		void equipAll();

	protected:

		virtual int getAttackPoints() const = 0;

		virtual int getDefensePoints() const = 0;

		int getBaseAttackPoints() const;

		int getBaseDefensePoints() const;

};

#endif