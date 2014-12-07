#include <string>

#include "Characters.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"

using namespace std;

/* ============== CLASSE KNIGHT ============== */

/*
 * Nome: Knight (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome do personagem, (int) vida, (int) mp, (int) poder
*/
Knight::Knight(string name, int hp, int mp, int newpower) : Character(name, hp, mp){
    power = newpower;

    Weapon *sword = new Weapon("Simple Short Sword", 5.0, 1);
    Armor *cloth = new Armor("Leather Loincloth", 5.0, 1, 2.0);

    getInventory().insertItem(sword);
    getInventory().insertItem(cloth);

    getInventory().equip(sword);
    getInventory().equip(cloth);
}

/*
 * Nome: addPower
 * Descricao: Adiciona poder
 * Entrada: (int) poder
*/
void Knight::addPower(int add){
    power += add;
}

/*
 * Nome: getPower
 * Descricao: retorna o poder
 * Saida: (int) poder
*/
int Knight::getPower() const{
    return power;
}

/*
 * Nome: getAttackPts
 * Descricao: retorna a quantidade de pontos de ataque
 * Saida: (int) pontos de ataque
*/
int Knight::getAttackPoints() const{
    return Character::getBaseAttackPoints();
}

/*
 * Nome: getDefensePts
 * Descricao: retorna a quantidade de pontos de defesa
 * Saida: (int) pontos de defesa
*/
int Knight::getDefensePoints() const{
    return Character::getBaseDefensePoints() + power;
}

/* ============== CLASSE WIZARD ============== */

/*
 * Nome: Wizard (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome do personagem, (int) vida, (int) mp, (int) sabedoria
*/
Wizard::Wizard(string name, int hp, int mp, int newwisdom) : Character(name, hp, mp){
    wisdom = newwisdom;
 
    Weapon *staff = new Weapon("Simple Glittery Staff", 5.0, 1);
    Armor *cloak = new Armor("Leather Cloak", 5.0, 1, 1.0);

    getInventory().insertItem(staff);
    getInventory().insertItem(cloak);

    getInventory().equip(staff);
    getInventory().equip(cloak);
}

/*
 * Nome: addWisdom
 * Descricao: Adiciona sabedoria
 * Entrada: (int) sabedoria
*/
void Wizard::addWisdom(int add){
    wisdom += add;
}

/*
 * Nome: getWisdom
 * Descricao: retorna a sabedoria
 * Saida: (int) sabedoria
*/
int Wizard::getWisdom() const{
    return wisdom;
}

/*
 * Nome: getAttackPts
 * Descricao: retorna a quantidade de pontos de ataque
 * Saida: (int) pontos de ataque
*/
int Wizard::getAttackPoints() const{
    return Character::getBaseAttackPoints();
}

/*
 * Nome: getDefensePts
 * Descricao: retorna a quantidade de pontos de defesa
 * Saida: (int) pontos de defesa
*/
int Wizard::getDefensePoints() const{
    return Character::getBaseDefensePoints() + wisdom/2;
}

/* ============== CLASSE ARHCER ============== */

/*
 * Nome: Archer (Construtor)
 * Descricao: Construtor que define os valores iniciais para os atributos da classe
 * Entrada: (string) nome do personagem, (int) vida, (int) mp, (int) sorte
*/
Archer::Archer(string name, int hp, int mp, int newluck) : Character(name, hp, mp){
    luck = newluck;
    
    Weapon *bow = new Weapon("Wooden Short Bow", 5.0, 1);
    Armor *coat = new Armor("Leather Coat", 5.0, 1, 2.0);

    getInventory().insertItem(bow);
    getInventory().insertItem(coat);

    getInventory().equip(bow);
    getInventory().equip(coat);
}

/*
 * Nome: addLuck
 * Descricao: Adiciona sorte
 * Entrada: (int) sorte
*/
void Archer::addLuck(int add){
    luck += add;
}

/*
 * Nome: getLuck
 * Descricao: retorna a sorte -> "We're up all night to get lucky"
 * Saida: (int) sorte
*/
int Archer::getLuck() const{
    return luck;
}

/*
 * Nome: getAttackPts
 * Descricao: retorna a quantidade de pontos de ataque
 * Saida: (int) pontos de ataque
*/
int Archer::getAttackPoints() const{
    return Character::getBaseAttackPoints() + luck;
}

/*
 * Nome: getDefensePts
 * Descricao: retorna a quantidade de pontos de defesa
 * Saida: (int) pontos de defesa
*/
int Archer::getDefensePoints() const{
    return Character::getBaseDefensePoints();
}
