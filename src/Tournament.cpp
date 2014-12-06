#include <vector>
#include <thread>

#include "Tournament.hpp"
#include "Bracket.hpp"
#include "Party.hpp"

using namespace std;

Tournament::Tournament(vector<Party *> partyList){
	mainBracket = new Bracket(partyList);
}

Tournament::~Tournament(){
	delete mainBracket;
}

void Tournament::startRound(){
	vector<thread> battles();

	mainBracket->solveTree(battles);

	int i;

	for(i=0; i<battles.size(); i++)
		if(battles[i].joinable())
			battles[i].join();
}