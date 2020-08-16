#ifndef TILE_H
#define TILE_H
#include <memory>
#include <iostream>
#include "player.h"
#include "dice.h"

class Board;

class Tile{
public:
	virtual void landed(std::shared_ptr<Player>, Dice& , Board &) = 0;
	virtual ~Tile() = 0;
	virtual void buyProperty(std::shared_ptr<Player>, Board &) = 0;
	virtual void mortgage(std::shared_ptr<Player>) = 0;
	virtual void unmortgage(std::shared_ptr<Player>, Board &) = 0;
	virtual void buyImprovement(std::shared_ptr<Player>, Board &) = 0;
	virtual void sellImprovement(std::shared_ptr<Player>) = 0;
	virtual std::string getName() = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getPos() = 0;
	virtual int getIsMortgaged() = 0;
	virtual int getNumberOfImprovements() = 0;
	virtual void setNumberOfImprovements(int ) = 0;
	virtual void setOwner(std::shared_ptr<Player>) = 0;
	virtual std::shared_ptr<Player> getOwner() = 0;
	virtual double getPurchaseCost() = 0;  // ---> change in every tile file
	virtual std::string getBlock() = 0;  // ---------> change in every tile file
	virtual double getImprovementCost() = 0;   //---------> change in every file
	virtual void setIsMortgaged(int ) = 0;
};
#endif





