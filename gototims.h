#ifndef GO_TO_TIMS_H
#define GO_TO_TIMS_H
#include <iostream> 
#include <string>
#include "nonproperty.h"

class GoToTims: public NonProperty{
	// A string message to be printed
	std::string message;
	// Position of the tile on the board
	int x;
	int y;
	int pos;
	public:
	// Constructor for our tile
	GoToTims(int ,int, int );
	// Prints message to the console
	void printMessage();
	// getPosition 
	virtual int getX() override;
	virtual int getY() override;
	virtual int getPos() override;
	virtual std::string getName() override;
	// Landed method from Tile.h interface that executes this tiles specific behaviour.
	virtual void landed(std::shared_ptr<Player>, Dice &, Board &) override;

	
	

};
#endif


