#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <cstdlib>

#include "Party.hpp"

using namespace std;

	/*	Construtor	*/

Party::Party(string partyName, Color partyColor){

	name = partyName;
	color = partyColor;

	win = 0;
	lose = 0;
	draw = 0;
	
}

	/*	Destrutor	*/

Party::~Party(){

	int i;

	for(i=0; i<characters.size(); i++){
		delete characters[i];
	}

}

	/*	Metodos getters	*/

string Party::getName(){
	return name;
}

string Party::getResults(){

	ostringstream buffer;

	buffer << "Wins : " << win << ", losses: " << lose << ", draws: " << draw << "\n";

	return buffer.str();
}

string Party::toString(){

	ostringstream buffer;

	buffer << "Party name: " << name << ", color: ";

	switch(color){
		case blue:
			buffer << "Blue";
			break;
		case red:
			buffer << "Red";
			break;
		case green:
			buffer << "Green";
			break;
		case yellow:
			buffer << "Yellow";
			break;
		case white:
			buffer << "White";
			break;
		case black:
			buffer << "Black";
			break;
	}

	buffer << "\n";

	return buffer.str();
}

double Party::getPoints(){
	double buffer = 0;
	int i;

	for(i=0; i<characters.size(); i++){
		buffer += (double)characters[i]->getHP();
	}

	return buffer/(double)characters.size();
}

void Party::resolveBattle(Party & party){
	if(getPoints() > party.getPoints()){
		win++;
	}else if(getPoints() == party.getPoints()){
		draw++;
	}else{
		lose++;
	}
}

void Party::addChar(Character * newchar){

	if(searchChar(newchar->getName()) == NULL)
		characters.push_back(newchar);

}

void Party::removeChar(int pos){

	if(pos < characters.size() && pos >= 0)
		characters.erase(characters.begin() + pos);

}

void Party::removeChar(Character * toRemove){

	int i;

	for(i=0; i<characters.size(); i++){
		if(characters[i] == toRemove){
			characters.erase(characters.begin() + i);
			return;
		}
	}

}

Character * Party::searchChar(string name){

	int i;

	for(i=0; i<characters.size(); i++){
		if(characters[i]->getName() == name)
			return characters[i];
	}

	return NULL;

}

queue<Character *> Party::shuffleCharacters(){
	int i, j, characterNumber = characters.size();

	/*	Gera um numero primo maior que o numero de characters no time	*/

	vector<int> primes;
	primes.push_back(2);

	for(i=3; primes[primes.size()-1] < characterNumber; i+=2){

		bool isPrime = true;

		for(j=0; j<primes.size() && isPrime; j++){
			if(i%primes[j]==0)
				isPrime = false;
		}

		//cout << isPrime << " || " << ;

		if(isPrime)
			primes.push_back(i);

	}

	/*	Monta a queue com a fila de characters a executarem o round!	*/

	queue<Character *> ret;

	int prime = primes[primes.size()-1];

	int currentCharacter = rand()%characters.size(), addedCharacters;

	for(addedCharacters = 0; addedCharacters < characters.size(); addedCharacters++){
		ret.push(characters[currentCharacter]);
		currentCharacter = (currentCharacter + prime)%characters.size();
	}

	return ret;
}

Character * Party::getRandomAliveCharacter(){
	int i;

	while(isAlive()){
		i = rand()%characters.size();
		if(characters[i]->isAlive())
			return characters[i];
	}

	return NULL;
}

bool Party::isAlive(){
	int i;

	for(i=0; i<characters.size(); i++){
		if(characters[i]->isAlive())
			return true;
	}

	return false;
}

void Party::resurrectCharacters(){
	int i;

	for(i=0; i<characters.size(); i++){
		characters[i]->resurrect();
	}
}