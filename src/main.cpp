#include <vector>
#include <string>
#include <cstdlib>

#include "GameUtil.hpp"
#include "Character.hpp"
#include "Characters.hpp"
#include "Tournament.hpp"
#include "Color.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include "Potion.hpp"
#include "ManaPotion.hpp"
#include "HealthPotion.hpp"
#include "Shop.hpp"

#define SHOP_PRODUCTS 5 // Quantidade de itens em cada loja

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
    }while(playerClass < 1 || playerClass > 3);

    // Cria o personagem do jogador
    Character *player;

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

    int partyColor = blue;

    // Cria o time do jogador
    Party *party = new Party(partyName, (Color)partyColor);
    partyColor++;

    // Coloca o jogador no time
    party->addChar(player);
    
    // Cria os NPC's do time do personagem do jogador
    for(unsigned int i = 0; i < 2; i++)
    {
        int npcClass = GameUtil::generateRandom(1, 3);

        switch(npcClass)
        {
            case 1: // Knight
                party->addChar(new Knight(GameUtil::makeName("name", "surname"), 100, 0, 1));
                break;

            case 2: // Wizard
                party->addChar(new Wizard(GameUtil::makeName("name", "surname"), 70, 50, 1));
                break;

            case 3: // Archer
                party->addChar(new Archer(GameUtil::makeName("name", "surname"), 80, 0, 1));
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
        party = new Party(GameUtil::makeName("TODO", "TODO"), (Color)partyColor);
        partyColor++;

        // Cria os NPC's dos outros times
        for(unsigned int i = 0; i < 3; i++)
        {
            int npcClass = GameUtil::generateRandom(1, 3);

            switch(npcClass)
            {
                case 1: // Knight
                    party->addChar(new Knight(GameUtil::makeName("name", "surname"), 100, 0, 1));
                    break;
                case 2: // Wizard
                    party->addChar(new Wizard(GameUtil::makeName("name", "surname"), 70, 50, 1));
                    break;
                case 3: // Archer
                    party->addChar(new Archer(GameUtil::makeName("name", "surname"), 80, 0, 1));
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

    // Cria as lojas para o jogador
    Shop<Armor> armorShop;
    for(unsigned int i = 0; i < SHOP_PRODUCTS; i++)
    {
        armorShop.addProduct(new Armor(GameUtil::makeName("TODO", "TODO"), GameUtil::generateDouble(10.0, 30.0), GameUtil::generateRandom(1, 20), GameUtil::generateDouble(1.0, 20.0)));
    }

    Shop<Weapon> weaponShop;
    for(unsigned int i = 0; i < SHOP_PRODUCTS; i++)
    {
        weaponShop.addProduct(new Weapon(GameUtil::makeName("TODO", "TODO"), GameUtil::generateDouble(15.0, 40.0), GameUtil::generateRandom(1, 20)));
    }

    Shop<Potion> potionShop;
    for(unsigned int i = 0; i < SHOP_PRODUCTS; i++)
    {
        if(GameUtil::generateRandom(1, 10) > 5)
            potionShop.addProduct((Potion*)new ManaPotion(GameUtil::makeName("TODO", "TODO"), GameUtil::generateDouble(1.0, 8.0), GameUtil::generateRandom(1, 50)));
        else
            potionShop.addProduct((Potion*)new HealthPotion(GameUtil::makeName("TODO", "TODO"), GameUtil::generateDouble(2.0, 8.0), GameUtil::generateRandom(1, 50)));
    }
    
    // Inicia o torneio
    while(tournament.getWinner() == NULL && player->isAlive())
    {
        // Abre as lojas para o jogador


        //
        // Loja de armaduras
        //
        int playerChoice = 0;

        while(playerChoice != 3)
        {
            cout << "Hello my friend, I'm Barnabas and I sell the best armors of this game. Do you want to 1 - Buy, 2 - Sell or 3 - Exit?" << endl;
            cin >> playerChoice;

            switch(playerChoice)
            {
                case 1: // O jogador escolhe comprar um item da loja
                    cout << (string)armorShop << endl;
                    cin >> playerChoice;

                    armorShop.buy(player, playerChoice);

                    break;
                case 2: // O jogador escolhe vender um item do seu inventario
                    cout << "Barnabas buys everything for a fair price. What do you want to sell?" << endl << endl;
                    
                    for(unsigned int i = 0; i < player->getInventory().getItemAmount(); i++) 
                    {
                        cout << i << " - " << player->getInventory().searchItem(i)->getName() << endl;
                    }

                    cout << endl;
                    cin >> playerChoice;

                    armorShop.sell(player, playerChoice);

                    break;
                case 3: // O jogador escolhe sair da loja
                    cout << "Goodbye fella!" << endl;
                    break;
                default:
                    break;
            }
        }

        //
        // Loja de Armas
        //

        playerChoice = 0;

        while(playerChoice != 3)
        {
            cout << "Hi brave hero! My name is Asdrubal, the Blacksmith, and my weapons are the best in town. Do you want to 1 - Buy, 2 - Sell or 3 - Exit?" << endl;
            cin >> playerChoice;

            switch(playerChoice)
            {
                case 1: // O jogador escolhe comprar um item da loja
                    cout << (string)armorShop << endl;
                    cin >> playerChoice;

                    armorShop.buy(player, playerChoice);

                    break;
                case 2: // O jogador escolhe vender um item do seu inventario
                    cout << "Another seller? This way I will be a poor!" << endl << endl;
                    
                    for(unsigned int i = 0; i < player->getInventory().getItemAmount(); i++) 
                    {
                        cout << i << " - " << player->getInventory().searchItem(i)->getName() << endl;
                    }

                    cout << endl;
                    cin >> playerChoice;

                    armorShop.sell(player, playerChoice);

                    break;
                case 3: // O jogador escolhe sair da loja
                    cout << "May the lucky be with you." << endl;
                    break;
                default:
                    break;
            }
        }

        //
        // Loja de pocoes
        //

        playerChoice = 0;

        while(playerChoice != 3)
        {
            cout << "Hey! You can call me Leslisson, the Wizard. I sell potions for the challengers in the Tournament. Do you want to 1 - Buy, 2 - Sell or 3 - Exit?" << endl;
            cin >> playerChoice;

            switch(playerChoice)
            {
                case 1: // O jogador escolhe comprar um item da loja
                    cout << (string)armorShop << endl;
                    cin >> playerChoice;

                    armorShop.buy(player, playerChoice);

                    break;
                case 2: // O jogador escolhe vender um item do seu inventario
                    cout << "One hand washes another..." << endl << endl;
                    
                    for(unsigned int i = 0; i < player->getInventory().getItemAmount(); i++) 
                    {
                        cout << i << " - " << player->getInventory().searchItem(i)->getName() << endl;
                    }

                    cout << endl;
                    cin >> playerChoice;

                    armorShop.sell(player, playerChoice);

                    break;
                case 3: // O jogador escolhe sair da loja
                    cout << "Break a leg!" << endl;
                    break;
                default:
                    break;
            }
        }

        // Executa um round do torneio
        tournament.startRound();
    }

    if(player->isAlive())
        cout << "TODO<congratulations here>" << endl;
    else
        cout << "TODO<game over here>" << endl;

    // Deleta as parties que participaram do torneio
    for(unsigned int i = 0; i < partyList.size(); i++)
    {
        delete partyList.at(i);
    }

    // Deleta a memoria usada pelo jogador
    delete player;
}
