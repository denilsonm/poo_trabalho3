#include <vector>
#include <string>
#include <cstdlib>

#include "GameUtil.hpp"
#include "Character.hpp"
#include "Knight.hpp"
#include "Wizard.hpp"
#include "Archer.hpp"
#include "Tournament.hpp"
#include "Color.hpp"

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

    cout << "TODO<<Lore vai aqui>>\n\n";

    // Lendo o nome do jogador

    cout << "Pick your name: " << endl;

    string playerName;
    cin >> playerName;

    // Lendo a classe desejada

    int playerClass;

    do{
        cout << "Pick your class (1 - Knight/2 - Wizard/3 - Archer): " << endl;
        cin >> playerClass;
    }while(playerClass < 1 || playerClass > 3)

    // Cria o personagem do jogador
    Character player;

    switch(playerClass)
    {
        case 1: // Knight
            player = new Knight(playerName, 100, 0, 1);
            break;
        case 2: // Wizard
            player = new Wizard(playerName, 70, 50, 1);
            break;
        case 3: // Archer
            player = new Archer(playerName, 80, 0, 1);
            break;
        default:
            break;
    }

    cout << "\nYou have received the following items:\n\n";
    // TODO start kit

    cout << "Pick your party name: " << endl;
    
    string partyName;
    cin >> partyName;

    // Cria um vetor de parties participantes do torneio
    vector<Party*> partyList;

    Color partyColor = blue;

    // Cria o time do jogador
    Party party = new Party(partyName, partyColor++);

    // Coloca o jogador no time
    party.addChar(player);
    
    // Cria os NPC's do time do personagem do jogador
    for(unsigned int i = 0; i < 2; i++)
    {
        int npcClass = GameUtil::generateRandom(1, 3);

        switch(npcClass)
        {
            case 1: // Knight
                party.addChar(new Knight(GameUtil::makeName("name", "surname"), 100, 0, 1));
                break;

            case 2: // Wizard
                party.addChar(new Wizard(GameUtil::makeName("name", "surname"), 70, 50, 1));
                break;

            case 3: // Archer
                party.addChar(new Archer(GameUtil::makeName("name", "surname"), 80, 0, 1));
                break;

            default:
                break;
        }
    }

    // Coloca o time do personagem do jogador na lista para o torneio
    partyList.push_back(party);

    // Cria os times inimigos
    for(unsigned int i = 0; i < 7; i++)
    {
        party = new Party(GameUtil::makeName("TODO", "TODO"), partyColor++);

        // Cria os NPC's dos outros times
        for(unsigned int i = 0; i < 3; i++)
        {
            int npcClass = GameUtil::generateRandom(1, 3);

            switch(npcClass)
            {
                case 1: // Knight
                    party.addChar(new Knight(GameUtil::makeName("name", "surname"), 100, 0, 1));
                    break;
                case 2: // Wizard
                    party.addChar(new Wizard(GameUtil::makeName("name", "surname"), 70, 50, 1));
                    break;
                case 3: // Archer
                    party.addChar(new Archer(GameUtil::makeName("name", "surname"), 80, 0, 1));
                    break;
                default:
                    break;
            }
        }
    
        // Coloca os times inimigos na lista para o torneio
        partyList.push_back(party);
    }

    // Cria um torneio e coloca a lista de parties
    Tournament tournament(partyList);

    cout << "May the bravest of all win!";
    
    // Inicia o torneio
    while(tournament.getWinner() == NULL && player.isAlive())
    {
        // Executa um round do torneio
        tournament.startRound();

        // Abre a loja para o jogador
        //TODO shop
    }

    if(tournmant.getWinner() == player)
        cout << "TODO<congratulations here>" << endl;
    else
        cout << "TODO<game over here>" << endl;

    // Deleta as parties que participaram do torneio
    for(unsigned int i = 0; i < partyList.size(); i++)
    {
        delete partyList.at(i);
    }
    partyList.erase();

    // Deleta a memoria usada pelo jogador
    delete player;
}
