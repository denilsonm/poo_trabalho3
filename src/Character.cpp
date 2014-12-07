#include <iostream>
#include <string>
#include <cmath>

#include "GameUtil.hpp"
#include "Character.hpp"

using namespace std;

/*
  * Nome: Character (Construtor)
  * Descricao: Construtor que define os valores iniciais para os atributos da classe
  * Entrada: (string) nome do personagem, (int) vida, (int) mp
*/
Character::Character(const string name, int hp, int mp){
    this->name = name;

    strength = GameUtil::generateRandom(0, 9);
    speed = GameUtil::generateRandom(0, 9);
    dexterity = GameUtil::generateRandom(0, 9);
    constitution = GameUtil::generateRandom(0, 9);

    MAXHP = hp;
    HP = hp;
    MP = mp;
    XP = 1;
}

/*
 * Nome: getName
 * Descricao: Retorna o nome do personagem
 * Saida: (string) nome
*/
string Character::getName() const{
    return name;
}

/*
 * Nome: isAlive
 * Descricao: Retorna se o personagem esta vivo
 * Saída: (bool) esta vivo?
*/
bool Character::isAlive() const{
    return HP <= 0;
}

/*
 * Nome: getAttributeSum
 * Descricao: Retorna a soma dos atributos
 * Saída: (int) soma dos atributos
*/
int Character::getAttributeSum() const{
    return strength + speed + dexterity + constitution;
}

/*
 * Nome: getHP
 * Descricao: Retorna os pontos de vida
 * Saída: (int) hp
*/
int Character::getHP() const{
    return HP;
}

/*
 * Nome: getSpeed
 * Descricao: Retorna a velocidade, baseado na soma dos pesos de todos os
    itens no inventario
 * Saída: (int) velocidade
*/
int Character::getSpeed() const{
    return (double)speed*exp(-pow((double)inventory.getWeight()/20.0, 2.0));
}

/*
 * Nome: setStrength
 * Descricao: Atribui uma forca
 * Entrada: (int) forca
*/
void Character::setStrength(int newStr){
    strength = GameUtil::checkInterval(1, newStr, 100);

    if(getAttributeSum() > MAX_ATTR_SUM){
        strength -= getAttributeSum() - MAX_ATTR_SUM;
    }
}

/*
 * Nome: setSpeed
 * Descricao: Atribui uma velocidade
 * Entrada: (int) velocidade
*/
void Character::setSpeed(int newSpd){
    speed = GameUtil::checkInterval(1, newSpd, 100);

    if(getAttributeSum() > MAX_ATTR_SUM){
        speed -= getAttributeSum() - MAX_ATTR_SUM;
    }
}

/*
 * Nome: setDexterity
 * Descricao: Atribui uma Destreza
 * Entrada: (int) destreza
*/
void Character::setDexterity(int newDex){
    dexterity = GameUtil::checkInterval(1, newDex, 100);

    if(getAttributeSum() > MAX_ATTR_SUM){
        dexterity -= getAttributeSum() - MAX_ATTR_SUM;
    }
}

/*
 * Nome: setConstitution
 * Descricao: Atribui uma constituicao
 * Entrada: (int) constituicao
*/
void Character::setConstitution(int newConst){
    constitution = GameUtil::checkInterval(1, newConst, 100);

    if(getAttributeSum() > MAX_ATTR_SUM){
        constitution -= getAttributeSum() - MAX_ATTR_SUM;
    }
}

/*
 * Nome: addHP
 * Descricao: Aumenta ou diminui o HP
 * Entrada: (int) Quantidade
*/
void Character::addHP(int amount){
    HP += amount;

    if(HP < 0)
        HP = 0;
}

/*
 * Nome: addMP
 * Descricao: Aumenta ou diminui o MP
 * Entrada: (int) Quantidade
*/
void Character::addMP(int amount){
    MP += amount;

    if(MP < 0)
        MP = 0;
}

/*
 * Nome: addXP
 * Descricao: Aumenta o XP
 * Entrada: (int) Quantidade
*/
void Character::addXP(int amount){
    XP = GameUtil::checkInterval(1, XP + amount, MAX_XP);
}

/*
 * Nome: attack
 * Descricao: ataca outro personagem
 * Entrada: (Character*) vitima
*/
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

    int damage = (getAttackPoints() - victim->getDefensePoints()) + GameUtil::generateRandom(-5, 5);
    int multiplier = 1;

    // Dano 1 eh o minimo

    if(damage < 1)
        damage = 1;

    if(misschance > chance){
        // Miss: multiplicador 0 de dano

        multiplier = 0;
        cout << getName() << " tries to attack " << victim->getName() << " and misses.\n";
    }else if(critchance + misschance > chance){
        // Critical strike: multiplicador 2 de dano

        multiplier = 2;
        cout << getName() << " hits " << victim->getName() << "'s weakest spot and does " << damage*2 << " damage.\n";
    }else{
        // Ataque normal

        cout << getName() << " attacks " << victim->getName() << " and does " << damage << " damage.\n";
    }

    victim->HP -= GameUtil::checkInterval(1, damage*multiplier, victim->HP);
    
    if(!victim->isAlive()){
        cout << victim->getName() << " died!\n";
    }
}

Inventory & Character::getInventory(){
    return inventory;
}

/*
 * Nome: resurrect
 * Descricao: Retorna os pontos de vida do personagem para o valor máximo
 * Saida: void
*/
void resurrect()
{
    HP = MAXHP;
    //TODO
}

// Nas classes filho de Character, a funcao getAttackPoints e
// getDefensePoints sempre sao a soma de algum atributo especifico
// da classe filho com pontos base que podem ser calculados apenas com
// os dados da classe Character. Portanto eh conveniente ter as
// funcoes getBaseDefensePoints() e getBaseAttackPoints() para
// evitar a reimplementacao dessa rotina que eh comum a
// todas as classes filho

/*
 * Nome: getBaseDefesePts
 * Descricao: retorna os pontos de defesa base
 * Saida: (int) pontos de defesa base
*/
int Character::getBaseDefensePoints() const{
    int i;
    double def = 0.5*(double)constitution + 0.3*(double)dexterity + 0.2*(double)speed;

    for(i=0; i<inventory.getItemAmount(); i++){
        Equipment * currentEquip = inventory.searchEquipment(i);

        if(inventory.isEquipped(currentEquip))
            def += (double)currentEquip->getDefensePts();
    }

    def = def*(double)XP/2.0;
    return def;
}

/*
 * Nome: getBaseAttackPts
 * Descricao: retorna os pontos de ataque base
 * Saida: (int) pontos de ataque base
*/
int Character::getBaseAttackPoints() const{
    int i;
    int atk = 0.5*(double)strength + 0.3*(double)dexterity + 0.2*(double)speed;

    for(i=0; i<inventory.getEquipmentAmount(); i++){
        Equipment * currentEquip = inventory.searchEquipment(i);

        if(inventory.isEquipped(currentEquip))
            atk += (double)currentEquip->getAttackPts();
    }

    atk = atk*(double)XP/3.0;
    return atk;
}
