#include <cstdlib>
#include "dice.h"

Dice::Dice(){}

int Dice::getValue(){
	int prob = rand()% 6 + 1;
	return prob;
}


