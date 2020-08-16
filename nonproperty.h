#ifndef NONPROPERTY_H_
#define NONPROPERTY_H_
#include <iostream>
#include <string>
#include <vector>
#include "tile.h"

class NonProperty: public Tile{
	std::vector<std::string> SLCMove = {"Back 3", "Back 3", "Back 3", "Back 2", "Back 2", "Back 2", "Back 2", 
											"Back 1", "Back 1", "Back 1", "Back 1", "Forward 1", "Forward 1", "Forward 1",
											"Forward 1", "Forward 2", "Forward 2", "Forward 2", "Forward 2", 
											"Forward 3", "Forward 3", "Forward 3", "Forward 3", "Go to DC Tims Line",
											"Advance to Collect OSAP"};
	std::vector<double> NeedlesHallChange = {-200, -100, -100, -50, -50, -50, 25, 25, 25, 25, 25, 25, 50, 50, 50,
											100, 100, 200};
public:
	virtual void landed(std::shared_ptr<Player>, Dice& , Board &) = 0;
	virtual void buyProperty(std::shared_ptr<Player>, Board &) override;
	virtual void mortgage(std::shared_ptr<Player>) override;
	virtual void unmortgage(std::shared_ptr<Player>, Board &) override;
	virtual void buyImprovement(std::shared_ptr<Player>, Board &) override;
	virtual void sellImprovement(std::shared_ptr<Player>) override;
	std::string getSLCMoveGenerator(int n);
	int getNeedlesHallChangeGenerator(int n);
	virtual double getPurchaseCost() override; 
	virtual std::string getBlock() override; 
	virtual double getImprovementCost() override; 
	virtual void setOwner(std::shared_ptr<Player> p) override;
	virtual int getIsMortgaged() override;
	virtual int getNumberOfImprovements() override;
	virtual std::shared_ptr<Player> getOwner() override;
	virtual void setNumberOfImprovements(int) override;
	virtual void setIsMortgaged(int ) override;

};
#endif




