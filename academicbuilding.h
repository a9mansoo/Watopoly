#ifndef ACADEMICBUILDING_H_
#define ACADEMICBUILDING_H_
#include <iostream>
#include <string>
#include <vector>
#include "tile.h"
#include "gameexception.h"

class AcademicBuilding : public Tile {
	std::string name;
	std::string block;
	double purchaseCost;
	double improvementCost;
	double tuition;
	int numberOfImprovements;
	std::vector<double> tuitionWithImprovements;
	std::shared_ptr <Player> owner;
	int x;
	int y;
	int pos;
	int isMortgaged;
	public:
	AcademicBuilding(std::string name, std::string block, double purchaseCost, double improvementCost, 
					double tuition, std::vector<double>& tuitionWithImprovements, std::shared_ptr<Player> owner, int x, int y, int pos);
					
	virtual int getNumberOfImprovements() override;
	void addToNumberOfImprovements(int );
	virtual void setNumberOfImprovements(int ) override;
	
	virtual int getIsMortgaged() override;
	virtual std::string getName() override;
	virtual double getPurchaseCost() override;  // ---> change in every tile file
	virtual std::string getBlock() override;  // ---------> change in every tile file
	virtual double getImprovementCost() override;  //---------> change in every file
	double getTuition();
	double getValue();
	double getTuitionWithImprovements();
	virtual std::shared_ptr<Player> getOwner() override;
	virtual void setOwner(std::shared_ptr<Player> p) override;
	virtual void buyProperty(std::shared_ptr<Player> p, Board &) override;
	virtual void buyImprovement(std::shared_ptr<Player> p, Board&) override;
	virtual void mortgage(std::shared_ptr<Player> p) override;
	virtual void unmortgage(std::shared_ptr<Player> p, Board &) override;
	virtual void sellImprovement(std::shared_ptr<Player> p) override;
	virtual int getX() override;
	virtual int getY() override;
	virtual int getPos() override;
	virtual void landed(std::shared_ptr<Player> , Dice& , Board &) override;
	virtual void setIsMortgaged(int ) override;
};

#endif




