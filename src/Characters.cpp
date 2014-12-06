#include <string>

#include "Characters.hpp"

using namespace std;

/* ============== CLASSE KNIGHT ============== */

	Knight::Knight(string name, int newpower) : Character(name){
		power = newpower;
	}

	void Knight::addPower(int add){
		power += add;
	}

	int Knight::getAttackPoints() const{
		return Character::getBaseAttackPoints();
	}

	int Knight::getDefensePoints() const{
		return Character::getBaseDefensePoints() + power;
	}

/* ============== CLASSE WIZARD ============== */

	Wizard::Wizard(string name, int newwisdom) : Character(name){
		wisdom = newwisdom;
	}

	void Wizard::addWisdom(int add){
		wisdom += add;
	}

	int Wizard::getAttackPoints() const{
		return Character::getBaseAttackPoints();
	}

	int Wizard::getDefensePoints() const{
		return Character::getBaseDefensePoints() + wisdom/2;
	}

/* ============== CLASSE THIEF ============== */

	Thief::Thief(string name, int newstealth) : Character(name){
		stealth = newstealth;
	}

	void Thief::addStealth(int add){
		stealth += add;
	}

	int Thief::getAttackPoints() const{
		return Character::getBaseAttackPoints() + stealth;
	}

	int Thief::getDefensePoints() const{
		return Character::getBaseDefensePoints();
	}