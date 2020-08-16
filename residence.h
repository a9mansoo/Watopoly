#ifndef RESIDENCE_H
#define RESIDENCE_H
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "tile.h"

class Residence: public Tile{
	// Name of the Residence
	std::string Name;
	// Purchase cost of the Residence
	double PurchaseCost; 
	// Position
	int x;
	int y;
	int pos;
	// Owner of the Residence
	std::shared_ptr<Player> Owner;
	// If residence is mortgaged
	int isMortgaged;
	public:
	// Constructor
	Residence( std::string  , double , int , int, int );
	// returns the name of the building
	virtual std::string  getName() override;
	// returngs the PurchaseCost()
	virtual double getPurchaseCost() override;
	// returns the owner of the tile
	virtual std::shared_ptr<Player> getOwner() override;
	// sets the Owner to the player passed in 
	virtual void setOwner(std::shared_ptr<Player> ) override;
	//allows Player to buy any Property tile. check the funds,
	// if they can purchase the property, set the Owner shared_ptr to point to the Player, 
	// remove the amount from the funds of the player. increase the gyms owns field for that player.
	virtual void buyProperty(std::shared_ptr<Player>, Board &) override; 
	// mortgages a property 
	virtual void mortgage(std::shared_ptr<Player>) override;
	// Removes the property from the Player's mortgages collection
	virtual void unmortgage(std::shared_ptr<Player>, Board&) override;
	// Landed in Tile
	virtual void landed(std::shared_ptr<Player>, Dice&, Board&) override;
	// getPosition 
	 //int getPosition();
	 // getisMortgaged
	 virtual int getIsMortgaged() override;
	 // getX
	 virtual int getX() override;
	 // getY
	 virtual int getY() override;
	 virtual int getPos() override;
	 virtual int getNumberOfImprovements() override;
	 virtual void buyImprovement(std::shared_ptr<Player>, Board &) override;
	virtual void sellImprovement(std::shared_ptr<Player>) override;
	virtual std::string getBlock() override;  // ---------> change in every tile file
	virtual double getImprovementCost() override;   //---------> change in every file
	virtual void setNumberOfImprovements( int ) override;
	virtual void setIsMortgaged(int ) override;
};
#endif


