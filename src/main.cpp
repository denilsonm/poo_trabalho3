#include <vector>
#include <string>
#include <cstdlib>

#include "GameUtil.hpp"
#include "Tournament.hpp"

using namespace std;

int main(){

	srand(time(NULL));

	// Dando dados para o gerador de nomes

	GameUtil::pushName("adjective", "Powerful");
	GameUtil::pushName("adjective", "Chaotic");
	GameUtil::pushName("adjective", "Elven");
	GameUtil::pushName("adjective", "Dwarven");
	GameUtil::pushName("adjective", "Mighty");

	GameUtil::pushName("bow", "Bow");
	GameUtil::pushName("bow", "Crossbow");
	GameUtil::pushName("bow", "Slingshot");

	GameUtil::pushName("staff", "Staff");
	GameUtil::pushName("staff", "Scepter");
	GameUtil::pushName("staff", "Rod");

	GameUtil::pushName("name", "Urist");

	GameUtil::pushName("surname", "McDwarf");

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

	cout << "May the bravest of all win!";
}