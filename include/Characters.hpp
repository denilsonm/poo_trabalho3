#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>

#include "Character.hpp"

using namespace std;

class Knight : public Character{

	protected:
		int power;

	public:

		Knight(string name, int newpower);

		void addPower(int add);

	protected:

		virtual int getAttackPoints() const;

		virtual int getDefensePoints() const;
};

class Wizard : public Character{

	protected:
		int wisdom;

	public:

		Wizard(string name, int newwisdom);

		void addWisdom(int add);

	protected:

		virtual int getAttackPoints() const;

		virtual int getDefensePoints() const;
};

class Thief : public Character{

	protected:
		int stealth;

	public:

		Thief(string name, int newstealth);

		void addStealth(int add);

	protected:

		virtual int getAttackPoints() const;

		virtual int getDefensePoints() const;
};

#endif