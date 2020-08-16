#include "goosenesting.h"

// Constructor
GooseNesting::GooseNesting(int x, int y, int pos):x{x}, y{y}, pos{pos}{}


// return Position

int GooseNesting::getX(){
	return x;
}

int GooseNesting::getY(){
	return y;
}

int GooseNesting::getPos(){
	return pos;
}


std::string GooseNesting::getName() {
	return "GooseNesting";
}


// landed method
void GooseNesting::landed(std::shared_ptr<Player> player, Dice & dice, Board & board){
	player->setPos(pos);
	std::cout << "AHHHH GEESEEE!!" << std::endl;
}




