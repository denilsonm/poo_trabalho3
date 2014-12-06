#include <vector>
#include <string>

#include "GameUtil.hpp"
#include "Tournament.hpp"

using namespace std;

int main(){

	// Dando dados para o gerador de nomes

	vector<string> adjectives();

	adjectives.push_back("Powerful");
	adjectives.push_back("Chaotic");
	adjectives.push_back("Elven");
	adjectives.push_back("Dwarven");
	adjectives.push_back("Mighty");

	vector<string> bowNames()

	bowNames.push_back("Bow");
	bowNames.push_back("Crossbow");

	vector<string> staffNames()

	staffNames.push_back("Staff");
	staffNames.push_back("Scepter");
	staffNames.push_back("Rod");

	vector<string> swordNames()

	swordNames.push_back("Sword");
	swordNames.push_back("Broadsword");
	swordNames.push_back("Rapier");

	vector<string> names();

	vector<string> surnames();

	// Introducao do jogo

	cout << "<<Lore vai aqui>>\n\n";

	// Lendo o nome do jogador

	cout << "Pick your name: ";

	string playerName;
	cin >> playerName;

	// Lendo a classe desejada

	string playerClass;

	do{
		cout << "Pick your class (Knight/Wizard/Archer): ";
		cin >> playerClass;
	}while(playerClass != "Knight" && playerClass != "Wizard" && playerClass != "Archer")

	cout << "\nYou have received the following items:\n\n"

	//
}