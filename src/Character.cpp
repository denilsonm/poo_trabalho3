#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "Game.hpp"
#include "Character.hpp"

using namespace std;

/* Construtores */

Character::Character(const string name){
	alias = name;

	strength = rand() % 10;
	speed = rand() % 10;
	dexterity = rand() % 10;
	constitution = rand() % 10;

	HP = MAX_HP;
	XP = 1;

	dead = false;
}

/* Metodos */

string Character::getName() const{
	return alias;
}

bool Character::isAlive() const{
	return !dead;
}

int Character::getAttributeSum() const{
	return strength + speed + dexterity + constitution;
}

int Character::getHP() const{
	return HP;
}

int Character::getSpeed() const{
	return (double)speed*exp(-pow((double)myitems.getWeight()/20.0, 2.0));
}

/*	Metodos setters	*/

void Character::setStrength(int newStr){
	strength = Game::checkInterval(1, newStr, 100);

	if(getAttributeSum() > MAX_ATTR_SUM){
		strength -= getAttributeSum() - MAX_ATTR_SUM;
	}
}

void Character::setSpeed(int newSpd){
	speed = Game::checkInterval(1, newSpd, 100);

	if(getAttributeSum() > MAX_ATTR_SUM){
		speed -= getAttributeSum() - MAX_ATTR_SUM;
	}
}

void Character::setDexterity(int newDex){
	dexterity = Game::checkInterval(1, newDex, 100);

	if(getAttributeSum() > MAX_ATTR_SUM){
		dexterity -= getAttributeSum() - MAX_ATTR_SUM;
	}
}

void Character::setConstitution(int newConst){
	constitution = Game::checkInterval(1, newConst, 100);

	if(getAttributeSum() > MAX_ATTR_SUM){
		constitution -= getAttributeSum() - MAX_ATTR_SUM;
	}
}

void Character::addHP(int amount){
	HP += amount;

	if(HP < 0){
		HP = 0;
		dead = true;

		cout << getName() << " has died!\n";
	}
}

void Character::addMP(int amount){
	MP += amount;

	if(MP < 0)
		MP = 0;
}

void Character::addXP(int amount){
	XP = Game::checkInterval(1, XP + amount, MAX_XP);
}

void Character::resurrect(){
	HP = MAX_HP;
	dead = false;
}

/*	Outros metodos	*/

// Attack sempre eh embasada numa comparacao entre os attack points
// do atacante e os defense points da vitima, independente da classe
// daquele, portanto nao ha necessidade de implementar attack mais
// de uma vez.

void Character::attack(Character * victim){

	if(victim == NULL)
		return;

	// Se o personagem atacado ja esta morto, a chamada a 
	// esta funcao eh ignorada.

	if(!victim->isAlive())
		return;

	// Calculando as chances de acontecer um miss ou ataque critico

	double misschance = 0.1 / (double)XP;
	double critchance = 0.02 * (double)XP / 2;

	double chance = (double)(rand()%10000)/10000;

	// Calculando o dano dado

	int damage = (getAttackPoints() - victim->getDefensePoints()) + Game::generateRandom(-5, 5);
	int multiplier = 1;

	// Dano 1 eh o minimo

	if(damage < 1)
		damage = 1;

	if(misschance > chance){
		// Miss: multiplicador 0 de dano

		multiplier = 0;
		cout << alias << " tries to attack " << victim->getName() << " and misses.\n";
	}else if(critchance + misschance > chance){
		// Critical strike: multiplicador 2 de dano

		multiplier = 2;
		cout << alias << " hits " << victim->getName() << "'s weakest spot and does " << damage*2 << " damage.\n";
	}else{
		// Ataque normal

		cout << alias << " attacks " << victim->getName() << " and does " << damage << " damage.\n";
	}

	victim->HP -= Game::checkInterval(1, damage*multiplier, victim->HP);
	if(victim->HP==0)
		victim->dead = true;
	
	if(!victim->isAlive()){
		cout << victim->getName() << " died!\n";
	}
}


// Ja que myitems deve ser privado, a fim de evitar que o usuario
// cause problemas, sao necessarios metodos para acessar o conteudo
// de myitems

bool Character::takeItem(Item * item){
	return myitems.insertItem(item);
}

bool Character::hasItem(Item * item){
	return myitems.isInInventory(item);
}

void Character::equipItem(Item * item){

	// Se o item estiver no inventorio do character, tenta equipa-lo

	if(myitems.isInInventory(item)){
		myitems.equipItem(item);
	}

}

void Character::removeItem(Item * item){

	myitems.removeItem(item);

}

// Tenta equipar todos os itens equipaveis que o Character tem.
// Serve apenas para simplificar a main

void Character::equipAll(){
	int i;

	for(i=0; i<myitems.getItemAmount(); i++)
		myitems.equipItem(i);
}

// Nas classes filho de Character, a funcao getAttackPoints e
// getDefensePoints sempre sao a soma de algum atributo especifico
// da classe filho com pontos base que podem ser calculados apenas com
// os dados da classe Character. Portanto eh conveniente ter as
// funcoes getBaseDefensePoints() e getBaseAttackPoints() para
// evitar a reimplementacao dessa rotina que eh comum a
// todas as classes filho

int Character::getBaseDefensePoints() const{
	int i;
	double def = 0.5*(double)constitution + 0.3*(double)dexterity + 0.2*(double)speed;

	for(i=0; i<myitems.getItemAmount(); i++){
		Item * currentItem = myitems.searchItem(i);

		if(myitems.isEquipped(currentItem))
			def += (double)currentItem->getDefensePoints();
	}

	def = def*(double)XP/2.0;
	return def;
}

int Character::getBaseAttackPoints() const{
	int i;
	int atk = 0.5*(double)strength + 0.3*(double)dexterity + 0.2*(double)speed;

	for(i=0; i<myitems.getItemAmount(); i++){
		Item * currentItem = myitems.searchItem(i);

		if(myitems.isEquipped(currentItem))
			atk += (double)currentItem->getAttackPoints();
	}

	atk = atk*(double)XP/3.0;
	return atk;
}