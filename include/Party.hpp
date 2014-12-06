#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include <queue>

#include "Color.hpp"
#include "Character.hpp"

//using namespace std;

class Party{

    private:

    /*    Atributos da classe    */

        string name;
        Color color;

        int win;
        int lose;
        int draw;

        vector<Character *> characters;

    public:

    /*    Metodos da classe    */

        /*    Construtor    */

        Party(string, Color);

        /*    Destrutor    */

        ~Party();

        /*    Outros    */

        string getName();

        string getResults();

        string toString();

        double getPoints();

        void resolveBattle(Party &);    // Nao existe razao para resolveBattle retornar um inteiro

        void addChar(Character *);

        void removeChar(int);
        void removeChar(Character *);

        Character * searchChar(string);

        queue<Character *> shuffleCharacters();
        Character * getRandomAliveCharacter();

        bool isAlive();

        void resurrectCharacters();
        
};


#endif
