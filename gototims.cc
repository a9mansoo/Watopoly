#include "board.h"
#include "gototims.h"


// Constructor
GoToTims::GoToTims(int x, int y, int pos):message{""},x{x}, y{y}, pos{pos}{}


// Prints message to the console
void GoToTims::printMessage(){
	message = "Landed on GoToTims, Now go to Jail";
	std::cout << message << std::endl;
}
	

// getPosition 
int GoToTims::getX(){
	return pos;
}

// getPosition 
int GoToTims::getY(){
	return y;
}

int GoToTims::getPos(){
	return pos;
}

std::string GoToTims::getName() {
	return "Go To Tims";
}


// Landed method from Tile.h interface that executes this tiles specific behaviour.
// will set the SentToDcTimsflag as 1 using methods of player.
void GoToTims::landed(std::shared_ptr<Player> curr_player, Dice & dice, Board & board){
	curr_player->setPos(pos);
	printMessage();
	// Set the flag of going to Jail from the GoToTims Tile. 
	curr_player->setSentToTims(true);
	// Will set the given players position to the Jail tile on the board.
	board.move(curr_player, "DC Tims Line");
}



