#ifndef GYM_H
#define GYM_H
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "tile.h"



class Gym: public Tile{
	// Name of the gym
	std::string Name;
	// Purchase cost of the gym
	double PurchaseCost; 
	// Position
	int x;
	int y;
	int pos;
	// Owner of the gym
	std::shared_ptr<Player> Owner;
	int isMortgaged;
	public:
	// Constructor
	Gym( std::string  , double , int, int, int );
	// returns the name of the building
	virtual std::string getName() override;
	// returngs the PurchaseCost()
	virtual double getPurchaseCost() override;
	// returns the owner of the tile
	virtual std::shared_ptr<Player> getOwner() override;
	// sets the Owner to the player passed in 
	virtual void setOwner(std::shared_ptr<Player> ) override;
	//allows Player to buy any Property tile. check the funds,
	// if they can purchase the property, set the Owner shared_ptr to point to the Player, 
	// remove the amount from the funds of the player. increase the gyms owns field for that player.
	virtual void buyProperty(std::shared_ptr<Player>, Board& ) override; 
	// mortgages a property 
	virtual void mortgage(std::shared_ptr<Player>) override;
	// Removes the property from the Player's mortgages collection
	virtual void unmortgage(std::shared_ptr<Player>, Board &) override;
	// Landed in Tile
	virtual void landed(std::shared_ptr<Player> , Dice&, Board&) override;
	// getPosition 
	virtual int getX() override;
	virtual int getY() override;
	virtual int getPos() override;
	virtual std::string getBlock() override;  // ---------> change in every tile file
	virtual double getImprovementCost() override;   //---------> change in every file
	virtual void buyImprovement(std::shared_ptr<Player>, Board &) override;
	virtual void sellImprovement(std::shared_ptr<Player>) override;
	 // getisMortgaged
	 virtual int getIsMortgaged() override;
	 virtual int getNumberOfImprovements() override;
	 virtual void setNumberOfImprovements(int ) override;
	 virtual void setIsMortgaged(int ) override;

};
#endif


