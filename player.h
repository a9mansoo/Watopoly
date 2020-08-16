#ifndef PLAYER_H_
#define PLAYER_H_
#include "subject.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
//#include "tile.h"
#include "gameexception.h"

class Tile;


class Player{
	std::string symbol;
	std::string name;
	double funds;
	double totalValueOfProperties;
	double totalValueOfImprovements;
	bool bankrupt;
	std::shared_ptr <Tile> position;
	// Position in x-y plane
	int x;
	int y;
	int pos;
	bool collect;
	int rollUpTheRim;
	bool sentToTims;
	int gyms;
	int residences;
	bool payTuition;
	int turnsInTimsLine;	
	std::vector<std::string> properties;
	std::vector<int> blocks;
	//const std::string& checkChar(const std::string& );
	public:
	Player(std::string symbol, std::string name, std::shared_ptr <Tile> position, int x, int y, int pos);
	~Player();
	std::string getSymbol();
	std::string getName();
	double getFunds();
	double getTotalValueOfProperties();
	double getTotalValueOfImprovements();
	std::vector<std::string> getProperties();
	bool getBankrupt();
	void setBankrupt(bool val);
	std::shared_ptr <Tile> getPosition();
	void setPosition(std::shared_ptr<Tile> tile);
	int getX();
	int getY();
	void setX(int );
	void setY(int );
	int getPos();
	void setPos(int i);
	bool getCollect();
	void setCollect(bool val);
	int getRollUpTheRim();
	void setRollUpTheRim(int i);
	bool getSentToTims();
	void setSentToTims(bool i);
	int getPropertiesOwnedInABlock(int n);
	void addToPropertiesOwnedInABlock(int index, int i);
	int getGyms();
	void setGyms(int i);
	int getResidences();
	void setResidences(int i);
	bool getPayTuition();
	void setPayTuition(bool val);
	int getTurnsInTimsLine();
	void setTurnsInTimsLine(int i);
	void addTurnsInTimsLine();
	void addToFunds(double amount);
	void removeFromFunds(double amount);
	void payRent(std::shared_ptr<Player> other, double amount);
	bool ownsMonopolyBlock(int i);
	bool ownProperty(std::string name);	
	void settotalValueOfProperties(int i);
	void removeFromProperties(std::string name);
	void addToProperties(std::string name);
	int numberOfProperties();
	void displayAssets();
};

#endif


