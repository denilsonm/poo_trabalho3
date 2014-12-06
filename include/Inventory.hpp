#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <cstdlib>

#include "Item.hpp"

#define STARTING_SPACE 10
#define STARTING_GOLD 0.0

using namespace std;

class Inventory{

	/*	Atributos da classe	*/

	private:
		int spaces;
		double gold;

		vector<pair<Item *, bool> > items;

	public:

	/*	Metodos da classe	*/

		/*	Construtores	*/

		Inventory();

		Inventory(int space, double gld);

		/*	Destrutor	*/

		~Inventory();

		/*	Metodos relativos ao gold do character	*/

		double getTotalGold() const;

		void spendGold(double amount);

		void earnGold(double amount);

		/*	Metodos relativos ao espaco no inventario	*/

		int getAvailableSpace() const;

		int getItemAmount() const;

		void setSpaces(int n);

		/*	Metodos relativos aos items contidos no inventario	*/

		Item * searchItem(string itemName) const;
		Item * searchItem(int id) const;

		bool isInInventory(Item * item) const;

		bool insertItem(Item * newItem);

		void removeItem(string itemName);
		void removeItem(int id);
		void removeItem(Item * item);

		void equipItem(int id);
		void equipItem(Item * item);

		bool isEquipped(Item * item) const;

		int getEquippedAmount(string) const;
		int getEquippedAmount(Item *) const;

		int getWeight() const;

};

#endif