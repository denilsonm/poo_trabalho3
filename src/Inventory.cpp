#include <string>
#include <vector>
#include <cstdlib>
#include <typeinfo>
#include <iostream>

#include "Inventory.hpp"

#define STARTING_SPACE 10
#define STARTING_GOLD 0.0

using namespace std;

/*	Construtores	*/

Inventory::Inventory(){
	spaces = STARTING_SPACE;
	gold = STARTING_GOLD;
}

Inventory::Inventory(int space, double gld){
	spaces = space;
	gold = gld;
}

/*	Destrutor	*/

Inventory::~Inventory(){
	int i;

	for(i=0; i<items.size(); i++){
		delete items[i].first;
	}
}

/*	Metodos relativos ao gold do character	*/

double Inventory::getTotalGold() const{
	return gold;
}

void Inventory::spendGold(double amount){

	if(amount < 0){
		earnGold(-amount);
		return;
	}else{
		gold = gold-amount;

		if(gold < 0)
			gold = 0;
	}

}

void Inventory::earnGold(double amount){

	if(amount < 0){
		spendGold(-amount);
		return;
	}else{
		gold += amount;
	}

}

/*	Metodos relativos ao espaco no inventario	*/

int Inventory::getAvailableSpace() const{
	return spaces - items.size();
}

int Inventory::getItemAmount() const{
	return items.size();
}

void Inventory::setSpaces(int n){

	if( n < items.size() ){

		// Se o novo espaco maximo do inventario nao consegue conter todos
		// os items, os items do fim do vetor de items serao deletados ate
		// que o numero de items fique igual a spaces. Oops :)
		items.erase(items.end()-(items.size() - n), items.end());

	}

	spaces = n;

}

/*	Metodos relativos aos items contidos no inventario	*/

Item * Inventory::searchItem(string itemName) const{

	int i;

	// Faz uma simples busca sequencial pelo item do nome procurado. Se encontra,
	// o retorna, caso contrario, retorna NULL.
	for(i=0; i<items.size(); i++){
		if(items[i].first->getName() == itemName){
			return items[i].first;
		}
	}

	return NULL;

}

Item * Inventory::searchItem(int id) const{	// Retorna o id-esimo item no inventario.

	if(id < 0 || id >= items.size())
		return NULL;

	return items[id].first;

}

bool Inventory::isInInventory(Item * item) const{

	int i;

	for(i=0; i<items.size(); i++){
		if(items[i].first == item)
			return true;
	}

	return false;

}

bool Inventory::insertItem(Item * newItem){

	if(items.size() < spaces){
		items.push_back(make_pair(newItem, false));
		return true;
	}
	return false;

}

void Inventory::removeItem(string itemName){

	int i;

	for(i=0; i<items.size(); i++){
		if(items[i].first->getName() == itemName){
			delete items[i].first;

			items.erase(items.begin()+i);
			return;
		}
	}

}

void Inventory::removeItem(Item * item){

	int i;

	for(i=0; i<items.size(); i++){
		if(items[i].first == item){
			delete items[i].first;

			items.erase(items.begin()+i);
			return;
		}
	}

}

void Inventory::removeItem(int id){

	if(0 <= id && id < items.size()){
		delete items[id].first;

		items.erase(items.begin()+id);
	}

}

void Inventory::equipItem(int id){

	if(id >= items.size() || id < 0)
		return;

	if(items[id].first->MaximumEquipped() == 0){
		return;
	}

	if(items[id].second){
		items[id].second = false;
	}else{
		if(getEquippedAmount(items[id].first) >= items[id].first->MaximumEquipped())
			return;

		items[id].second = true;
	}

}

void Inventory::equipItem(Item * item){
	int i;

	for(i=0; i<items.size(); i++){
		if(items[i].first == item){
			equipItem(i);
			return;
		}
	}
}

bool Inventory::isEquipped(Item * item) const{
	int i;

	for(i=0; i<items.size(); i++){
		if(items[i].first == item)
			return items[i].second;
	}

	return false;
}

int Inventory::getEquippedAmount(string itemType) const{

	int i, equipped = 0;

	for(i=0; i<items.size(); i++){
		if(itemType == typeid(*items[i].first).name() && items[i].second)
			equipped++;
	}

	return equipped;

}

int Inventory::getEquippedAmount(Item * item) const{

	return getEquippedAmount(typeid(*item).name());

}

int Inventory::getWeight() const{

	int i, w = 0;

	for(i=0; i<items.size(); i++){
		if(items[i].second)
			w += items[i].first->getWeight();
	}

	return w;

}