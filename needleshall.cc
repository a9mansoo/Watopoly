#include "board.h"
#include "needleshall.h"


// Constructor for our tile
	NeedlesHall::NeedlesHall(int x, int y, int pos): message{""},x{x}, y{y}, pos{pos}{}
	
// Prints message to the console
	void NeedlesHall::printMessage(std::string & message, double & amount){
		std::cout << message << std::endl;
		std::cout << amount << std::endl;
	}
	
// Generates the random number to extract from the nonproperty values of 
	int NeedlesHall::RandomNumberGenerator(int i){
		// generates a number between 0 - 18
		int probability = rand() % i; 
		return probability;
		
	}
	
	// returns position
	int NeedlesHall::getX(){
		return x;
	}
	// returns position
	int NeedlesHall::getY(){
		return y;
	}
	
	int NeedlesHall::getPos(){
		return pos;
	}

	
	std::string NeedlesHall::getName() {
		return "Needles Hall";
	}
	
// Landed method from Tile.h interface that executes this tiles specific behaviour.
	void NeedlesHall::landed(std::shared_ptr<Player> curr_player, Dice & dice, Board & board){
		curr_player->setPos(pos);
		message = "Landed on Needles Hall";
		std::cout << message << std::endl;
		int index = RandomNumberGenerator(19);
		
		
		if ( index == 18 && board.getActiveRollUpRim() < 4){
			message = "Roll up the Rim Time!!!";
			std::cout << message << std::endl;
			curr_player->setRollUpTheRim(1);
			board.setActiveRollUpRim(1);
		}
		else{
			index = RandomNumberGenerator(18);
			message = "Change found: ";
			double change = this->getNeedlesHallChangeGenerator(index);
			printMessage(message,change);
			double curr_amount = curr_player->getFunds();
			curr_amount -= change; 
			if ( curr_amount < 0 ){
				curr_player->setBankrupt(true);
				std::cout << "You are bankrupt" << std::endl;
				board.Bankrupt(curr_player, nullptr, curr_amount);
			}
			else{
				curr_player->addToFunds(change);
			}
		}
	}
	


