#include <cstdlib>

#include "GameUtil.hpp"

int GameUtil::checkInterval(int a, int n, int b){
	if(n < a)
		return a;
	else if(n > b)
		return b;
	else
		return n;
}

int GameUtil::generateRandom(int a, int b){
	return rand()%(b-a+1)+a;
}
