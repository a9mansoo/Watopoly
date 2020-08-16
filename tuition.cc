#include <sstream>
#include "board.h"
#include "tuition.h"
using namespace std;

Tuition::Tuition(int x, int y, int pos): x{x},y{y}, pos{pos}, cost{300} {}

void Tuition::landed(std::shared_ptr<Player> p, Dice& d, Board& b) {
	p->setPos(pos);
	double input;
	// do we need improvements here as well??
	double worth = p->getTotalValueOfProperties();
	worth = (worth + p->getFunds()) * 0.1;
	std::cout << "You have to pay tuition. Would you like to pay $300 or $" << worth << std::endl;
	std::cout << "Please type what you would like to pay (without the dollar sign)." << std::endl;
	std::string line;
	std::getline(std::cin, line);
	std::stringstream ss(line);
	ss >> input;
	if ( ss.fail() && input != cost && input != worth ){
		throw GameException(" You did not enter a proper amount" ); 
	}
	if (input == cost){
			p->removeFromFunds(cost);
		} 
		else {
			p->removeFromFunds(worth);
		}
	if ( p->getBankrupt() ){
		std::cout << "You are bankrupt" << std::endl;
		if ( input == cost ){
			b.Bankrupt(p, nullptr,cost);
		}
		else{
			b.Bankrupt(p, nullptr,worth);
		}
	}
}

int Tuition::getX(){
	return x;
}

int Tuition::getY(){
	return y;
}

int Tuition::getPos(){
	return pos;
}


std::string Tuition::getName() {
	return "Tuition";
}



