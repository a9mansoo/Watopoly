#include "nonproperty.h"

std::string NonProperty::getSLCMoveGenerator(int n){
	return SLCMove.at(n);
}

int NonProperty::getNeedlesHallChangeGenerator(int n){
	return NeedlesHallChange.at(n);
}

void NonProperty::buyProperty(std::shared_ptr<Player> p, Board & board) {}
void NonProperty::mortgage(std::shared_ptr<Player> p) {}
void NonProperty::unmortgage(std::shared_ptr<Player> p, Board & board) {}
void NonProperty::buyImprovement(std::shared_ptr<Player> p, Board & board) {}
void NonProperty::sellImprovement(std::shared_ptr<Player> p) {}
void NonProperty::setOwner(std::shared_ptr<Player> p){}
int NonProperty::getIsMortgaged(){return -1; }
int NonProperty::getNumberOfImprovements(){ return -1;}
void NonProperty::setNumberOfImprovements(int num){};
std::shared_ptr<Player> NonProperty::getOwner(){ return nullptr;}
double NonProperty::getPurchaseCost() { return 0; }
std::string NonProperty::getBlock() { return " ";}
double NonProperty::getImprovementCost() { return 0; }
void NonProperty::setIsMortgaged(int i){}




