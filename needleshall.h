#ifndef NEEDLES_HALL_H
#define NEEDLES_HALL_H
#include <iostream> 
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include "nonproperty.h"

class NeedlesHall: public NonProperty{
	// A string message to be printed
	std::string message;
	// Position of the tile on the board
	int x;
	int y;
	int pos;
	// A vector that contains the change that can be acquired
	//std::vector<double> Change;
	public:
	// Constructor for our tile
	NeedlesHall(int, int, int );
	// Prints message to the console
	void printMessage(std::string & , double & );
	// getPosition 
	virtual int getX() override;
	virtual int getY() override;
	virtual int getPos() override;
	virtual std::string getName() override;
	// Generates the random number to extract from the nonproperty values of 
	int RandomNumberGenerator(int );
	// Landed method from Tile.h interface that executes this tiles specific behaviour.
	virtual void landed(std::shared_ptr<Player>, Dice &, Board &) override;
	
	

};
#endif


