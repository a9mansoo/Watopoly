#include "board.h"
#include "coopfee.h"

// Constructor for our tile
CoopFee::CoopFee(int x, int y, int pos):message{""},Cost{150}, x(x), y{y}, pos{pos}{}

// Prints message to the console
void CoopFee::printMessage(){
	message = "Landed on Coop Fee, Pay $150";
	std::cout << message << std::endl;
}

// returns to position

int CoopFee::getX(){
	return x;
}
int CoopFee::getY(){
	return y;
}

int CoopFee::getPos(){
	return pos;
}



std::string CoopFee::getName() {
	return "CoopFee";
}

// Gets the cost of the coop fee
double CoopFee::getCost(){
	return Cost;
}
	
// Landed method from Tile.h interface that executes this tiles specific behaviour.
void CoopFee::landed(std::shared_ptr<Player> curr_player, Dice & dice, Board & board){
	curr_player->setPos(pos);
	printMessage(); 
	curr_player->removeFromFunds(Cost);
	if ( curr_player->getBankrupt() ){
		std::cout << "You are bankrupt" << std::endl;
		board.Bankrupt(curr_player, nullptr,Cost);
	}
}




