#ifndef GOOSE_NESTING_H
#define GOOSE_NESTING_H
#include <iostream> 
#include <string>
#include <cstdlib>
#include <vector>
#include "nonproperty.h"

class GooseNesting : public NonProperty{
	// Position of tile
	int x;
	int y;
	int pos;
	public: 
	// Constructor
	GooseNesting(int, int, int );
	// getPosition 
	virtual int getX() override;
	virtual int getY() override;
	virtual int getPos() override;
	virtual std::string getName() override;
	// landed method
	virtual void landed(std::shared_ptr<Player>, Dice &, Board & ) override;



};

#endif

