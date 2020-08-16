#ifndef COOP_FEE_H
#define COOP_FEE_H
#include <iostream> 
#include <string>
#include "nonproperty.h"

class CoopFee: public NonProperty{
	// A string message to be printed
	std::string message;
	// A constant which is the cost of the Coop Fee $150
	double Cost;
	// Position of the tile on the board
	int x;
	int y;
	int pos;
	public:
	// Constructor for our tile
	CoopFee(int , int, int );
	// Prints message to the console
	void printMessage();
	// Gets the cost of the coop fee
	double getCost();
	// getPosition 
	virtual int getX() override; 
	virtual int getY() override;
	virtual int getPos() override;
	virtual std::string getName() override;
	// Landed method from Tile.h interface that executes this tiles specific behaviour.
	virtual void landed(std::shared_ptr<Player>, Dice &, Board &) override;
	
	

};
#endif


