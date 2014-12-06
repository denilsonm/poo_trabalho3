#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <vector>

#include "Bracket.hpp"
#include "Party.hpp"

using namespace std;

class Tournament{

	private:
		Bracket * mainBracket;

	public:
		Tournament(vector<Party *> characterList);

		void startRound();

};

#endif