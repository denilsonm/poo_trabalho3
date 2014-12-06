#ifndef BRACKET_H
#define BRACKET_H

#include <vector>
#include <thread>

#include "Character.hpp"
#include "GameUtil.hpp"

using namespace std;

class Bracket{

	private:
		Party * winner;

		Bracket * leftBracket;
		Bracket * rightBracket;

	public:
		Bracket(vector<Party *> characterList);

		void solveTree(vector<thread> battles);

		void solveBattle();

};

#endif