#include <vector>
#include <string>
#include <cstdlib>
#include <typeinfo>

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
    GameUtil::pushName("adjective", "Pristine");
    GameUtil::pushName("adjective", "Dirty");
    GameUtil::pushName("adjective", "Old");
    GameUtil::pushName("adjective", "Infernal");
    GameUtil::pushName("adjective", "Torn Apart");
    GameUtil::pushName("adjective", "Flying");
    GameUtil::pushName("adjective", "Swimming");
    GameUtil::pushName("adjective", "Winged");
    GameUtil::pushName("adjective", "Flaming");
    GameUtil::pushName("adjective", "Frozen");
    GameUtil::pushName("adjective", "Beautiful");
    GameUtil::pushName("adjective", "Marvelous");
    GameUtil::pushName("adjective", "Jolly");

    GameUtil::pushName("teamnames", "Elves");
    GameUtil::pushName("teamnames", "Dwarves");
    GameUtil::pushName("teamnames", "Destroyers");
    GameUtil::pushName("teamnames", "Jumpers");
    GameUtil::pushName("teamnames", "Rabbits");
    GameUtil::pushName("teamnames", "Women");
    GameUtil::pushName("teamnames", "Aliens");
    GameUtil::pushName("teamnames", "Lovers");
    GameUtil::pushName("teamnames", "Ninjas");
    GameUtil::pushName("teamnames", "Pirates");

    GameUtil::pushName("weapon", "Bow");
    GameUtil::pushName("weapon", "Crossbow");
    GameUtil::pushName("weapon", "Slingshot");
    GameUtil::pushName("weapon", "Staff");
    GameUtil::pushName("weapon", "Scepter");
    GameUtil::pushName("weapon", "Rod");
    GameUtil::pushName("weapon", "Broadsword");
    GameUtil::pushName("weapon", "Flamberge");
    GameUtil::pushName("weapon", "Rapier");
    GameUtil::pushName("weapon", "Ice Pick");

    GameUtil::pushName("armor", "Hat");
    GameUtil::pushName("armor", "Monocle");
    GameUtil::pushName("armor", "False Mustache");
    GameUtil::pushName("armor", "Iron Mail");
    GameUtil::pushName("armor", "Shoes");
    GameUtil::pushName("armor", "Boots");
    GameUtil::pushName("armor", "Leggings");
    GameUtil::pushName("armor", "Shield");

    GameUtil::pushName("manapot", "of Mana");
    GameUtil::pushName("healthpot", "of Vitality");

    GameUtil::pushName("potion", "Saliva");
    GameUtil::pushName("potion", "Essence");
    GameUtil::pushName("potion", "Elixir");
    GameUtil::pushName("potion", "Potion");
    GameUtil::pushName("potion", "Extract");

    GameUtil::pushName("name", "Urist");
    GameUtil::pushName("name", "Excelsa");
    GameUtil::pushName("name", "Asdrubal");
    GameUtil::pushName("name", "Rodney");
    GameUtil::pushName("name", "Farmacio");
    GameUtil::pushName("name", "Fridundino");
    GameUtil::pushName("name", "Gravitolina");
    GameUtil::pushName("name", "Horinando");
    GameUtil::pushName("name", "Lindulfo");
    GameUtil::pushName("name", "Reimar");
    GameUtil::pushName("name", "Rolando");
    GameUtil::pushName("name", "Telebentino");

    GameUtil::pushName("surname", "McDwarf");
    GameUtil::pushName("surname", "Mothram");
    GameUtil::pushName("surname", "Fid");
    GameUtil::pushName("surname", "Datan");
    GameUtil::pushName("surname", "Istam");
    GameUtil::pushName("surname", "Thuveg");
    GameUtil::pushName("surname", "Monon");
    GameUtil::pushName("surname", "Tashem");
    GameUtil::pushName("surname", "Urvag");

    GameUtil::pushName("surname", "Tharnas");

    // Introducao do jogo

    cout << "In a world full of darkness and injustice, the Great King of Lore Ipsum decided to create a tournament.";
    cout << " This deadly tournament will decide the new heros that can bring peace to kingdom.\n You, a famous adventurer,";
    cout << " hear about this and decide to ask about. A man, working for King Foo, explains that the battle will have 8";
    cout << " parties with three people each, and they'll fight till death.\n Hearing this, you decided to join the Great";
    cout << " Colossal Century Magic Tournament For The Peace of Mankind in This World Full of Darkness First Edition ";
    cout << "(a.k.a. GCCMTFTPoMiTWFoDFE) with another two friends.\n\n";

    // Lendo o nome do jogador

    cout << "Pick your name:  ";

    string playerName;
    cin >> playerName;

    // Lendo a classe desejada

    int playerClass;

    do{
        cout << "\nPick your class (1 - Knight/2 - Wizard/3 - Archer):  ";
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

    player->getInventory().addGold(60.0);

    cout << "\nYou have received the following items:\n\n";

    cout << "Pick your party name: " << endl;
    
    string partyName;
    cin >> partyName;

    // Cria um vetor de parties participantes do torneio
    vector<Party*> partyList;

    int partyColor = blue;

    // Cria o time do jogador
    Party *playerParty = new Party(partyName, (Color)partyColor);
    partyColor++;

    // Coloca o jogador no time
    playerParty->addChar(player);
    
    // Cria os NPC's do time do personagem do jogador
    for(unsigned int i = 0; i < 2; i++)
    {
        int npcClass = GameUtil::generateRandom(1, 3);

        switch(npcClass)
        {
            case 1: // Knight
                playerParty->addChar(new Knight(GameUtil::makeName("name", "surname"), 100, 0, 1));
                break;

            case 2: // Wizard
                playerParty->addChar(new Wizard(GameUtil::makeName("name", "surname"), 70, 50, 1));
                break;

            case 3: // Archer
                playerParty->addChar(new Archer(GameUtil::makeName("name", "surname"), 80, 0, 1));
                break;

            default:
                break;
        }
    }

    // Coloca o time do personagem do jogador na lista para o torneio
    partyList.push_back(playerParty);

    // Cria os times inimigos
    Party *party;
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
        armorShop.addProduct(new Armor(GameUtil::makeName("adjective", "armor"), GameUtil::generateDouble(10.0, 30.0), GameUtil::generateRandom(1, 20), GameUtil::generateDouble(1.0, 20.0)));
    }

    Shop<Weapon> weaponShop;
    for(unsigned int i = 0; i < SHOP_PRODUCTS; i++)
    {
        weaponShop.addProduct(new Weapon(GameUtil::makeName("adjective", "weapon"), GameUtil::generateDouble(15.0, 40.0), GameUtil::generateRandom(1, 20)));
    }

    Shop<Potion> potionShop;
    for(unsigned int i = 0; i < SHOP_PRODUCTS; i++)
    {
        if(GameUtil::generateRandom(1, 10) > 5)
            potionShop.addProduct((Potion*)new ManaPotion(GameUtil::makeName("potion", "manapot"), GameUtil::generateDouble(1.0, 8.0), GameUtil::generateRandom(1, 50)));
        else
            potionShop.addProduct((Potion*)new HealthPotion(GameUtil::makeName("potion", "healthpot"), GameUtil::generateDouble(2.0, 8.0), GameUtil::generateRandom(1, 50)));
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
            playerChoice = 0;
            cout << "Hello my friend, I'm Barnabas and I sell the best armors of this game. Do you want to:\n\n\t1 - Buy\n\t2 - Sell\n\t3 - Exit\n\nYour option: " << endl;
            cin >> playerChoice;

            bool success;

            switch(playerChoice)
            {
                case 1: // O jogador escolhe comprar um item da loja
                    cout << (string)armorShop << endl;
                    cin >> playerChoice;

                    success = armorShop.buy(player, playerChoice);

                    if(success){
                        cout << "Ha! Now THAT was a great deal!\n\n";
                    }else{
                        cout << "Sorry sir, you may not buy that item.\n\n";
                    }

                    break;
                case 2: // O jogador escolhe vender um item do seu inventario
                    cout << "Barnabas buys everything for a fair price. What do you want to sell?" << endl << endl;

                    cout << (string)(player->getInventory());

                    if(player->getInventory().getItemAmount() == 0){
                        cout << "Type anything to continue: ";
                        cin >> playerChoice;

                        break;
                    }

                    cout << endl;
                    cin >> playerChoice;

                    success = armorShop.sell(player, playerChoice);

                    if(success){
                        cout << "Thanks, sir!\n\n";
                    }else{
                        cout << "Sorry sir, you may not sell that item.\n\n";
                    }

                    break;
                case 3: // O jogador escolhe sair da loja
                    cout << "Goodbye fella!\n\n";
                    break;
                default:
                    cout << "Man, you must be deaf...\n\n";

                    break;
            }
        }

        //
        // Loja de Armas
        //

        playerChoice = 0;

        while(playerChoice != 3)
        {
            playerChoice = 0;
            cout << "Hi brave hero! My name is Asdrubal, the Blacksmith, and my weapons are the best in town. Do you want to:\n\n\t1 - Buy\n\t2 - Sell\n\t3 - Exit\n\nYour option: " << endl;
            cin >> playerChoice;

            bool success;

            switch(playerChoice)
            {
                case 1: // O jogador escolhe comprar um item da loja
                    cout << (string)weaponShop << endl;
                    cin >> playerChoice;

                    success = weaponShop.buy(player, playerChoice);

                    if(success)
                        cout << "Take this! It's too dangerous to go alone!\n\n";
                    else
                        cout << "Huh, you dummy. You can't do that.\n\n";

                    break;
                case 2: // O jogador escolhe vender um item do seu inventario
                    cout << "Another seller? This way I will be a poor!" << endl << endl;

                    cout << (string)(player->getInventory());

                    if(player->getInventory().getItemAmount() == 0){
                        cout << "Type anything to continue: ";
                        cin >> playerChoice;

                        break;
                    }

                    cout << endl;
                    cin >> playerChoice;

                    success = weaponShop.sell(player, playerChoice);

                    if(success){
                        cout << "And never come back again!\n\n";
                    }else{
                        cout << "You fool! You can't do that!\n\n";
                    }

                    break;
                case 3: // O jogador escolhe sair da loja
                    cout << "May the (get) lucky be with you.\n\n";
                    break;
                default:
                    cout << "Ah, these heroes nowadays...\n\n";
                    break;
            }
        }

        //
        // Loja de pocoes
        //

        playerChoice = 0;

        while(playerChoice != 3)
        {
            playerChoice = 0;
            cout << "Hey! You can call me Leslisson, the Wizard. I sell potions for the challengers in the Tournament. Do you want to\n\n\t1 - Buy\n\t2 - Sell\n\t3 - Exit\n\nYour option: " << endl;
            cin >> playerChoice;

            bool success;

            switch(playerChoice)
            {
                case 1: // O jogador escolhe comprar um item da loja
                    cout << (string)potionShop << endl;
                    cin >> playerChoice;

                    success = potionShop.buy(player, playerChoice);

                    if(success){
                        cout << "May your life be full of rabbits!\n\n";
                    }else{
                        cout << "You may not buy that.\n\n";
                    }

                    break;
                case 2: // O jogador escolhe vender um item do seu inventario
                    cout << "One hand washes another..." << endl << endl;

                    cout << (string)(player->getInventory());

                    if(player->getInventory().getItemAmount() == 0){
                        cout << "Type anything to continue: ";
                        cin >> playerChoice;

                        break;
                    }

                    cout << endl;
                    cin >> playerChoice;

                    success = potionShop.sell(player, playerChoice);

                    if(success){
                        cout << "May hair always grow in your foot!\n\n";
                    }else{
                        cout << "You may not sell that.\n\n";
                    }

                    break;
                case 3: // O jogador escolhe sair da loja
                    cout << "Break a leg!\n\n";
                    break;
                default:
                    cout << "No, you may not choose a fourth option.\n\n";
                    break;
            }
        }

        // Permite que o jogador equipe ou desequipe itens
        playerChoice = 0;
        while(playerChoice != 3){
        playerChoice = 0;
        
            cout << "\n\n\nDo you want to 1 - Equip Item, 2 - Unequip Item or 3 - Battle?:   ";
            cin >> playerChoice;
            cout << endl << endl;

            switch(playerChoice){
                case 1:
                    
                    for(unsigned int i = 0; i < player->getInventory().getItemAmount(); i++) {
                        if(dynamic_cast<Weapon*>(player->getInventory().searchItem(i)) != NULL || dynamic_cast<Armor*>(player->getInventory().searchItem(i)) != NULL)
                            if(!player->getInventory().isEquipped(player->getInventory().searchItem(i)->getName()))
                                cout << i << " - " << player->getInventory().searchItem(i)->getName() << endl;
                    }

                    cin >> playerChoice;

                    if(playerChoice >= 0 && playerChoice < player->getInventory().getItemAmount())
                        player->getInventory().equip(dynamic_cast<Equipment*>(player->getInventory().searchItem(playerChoice)));
                    
                    break;
                case 2:

                    for(unsigned int i = 0; i < player->getInventory().getEquipmentAmount(); i++)
                        cout << i << " - " << player->getInventory().searchEquipment(i)->getName() << endl;

                    cin >> playerChoice;

                    if(playerChoice >= 0 && playerChoice < player->getInventory().getEquipmentAmount())
                        player->getInventory().unequip(player->getInventory().searchEquipment(playerChoice));
                    
                    break;
                case 3:
                    break;
                default:
                    break;
            }
        
        }

        // Executa um round do torneio
        tournament.startRound();
    }

    if(tournament.getWinner() == playerParty)
        cout << "TODO<congratulations here>" << endl;
    else
        cout << "TODO<game over here>" << endl;

    // Deleta as parties que participaram do torneio
    for(unsigned int i = 0; i < partyList.size(); i++)
    {
        delete partyList.at(i);
    }

    return 0;
}
