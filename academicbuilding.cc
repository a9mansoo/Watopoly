#include "board.h"
#include "academicbuilding.h"

AcademicBuilding::AcademicBuilding(std::string name, std::string block, double purchaseCost, double improvementCost, 
					double tuition,std::vector<double>& tuitionWithImprovements, std::shared_ptr<Player> owner, int x, int y, int pos): 
					name{name}, block{block}, purchaseCost{purchaseCost}, improvementCost{improvementCost}, 
					tuition{tuition}, numberOfImprovements{0}, tuitionWithImprovements{tuitionWithImprovements}, owner{owner}, x{x}, y{y}, pos{pos}, isMortgaged{-1}{
						for ( auto i:tuitionWithImprovements ){
							tuitionWithImprovements.push_back(i);
						}
					}
					
int AcademicBuilding::getNumberOfImprovements(){
		return numberOfImprovements;
}

double AcademicBuilding::getPurchaseCost() {
	return purchaseCost;
}

void AcademicBuilding::addToNumberOfImprovements(int n){
		numberOfImprovements +=n;
}

int AcademicBuilding::getIsMortgaged(){
	return isMortgaged;
}

void AcademicBuilding::setIsMortgaged(int i){
	isMortgaged = i;
}

void AcademicBuilding::setNumberOfImprovements(int num) {
	numberOfImprovements = num;
}

std::string AcademicBuilding::getName(){
		return name;
}

std::string AcademicBuilding::getBlock(){
		return block;
}

double AcademicBuilding::getImprovementCost(){
		return improvementCost;
}

double AcademicBuilding::getTuition(){
		return tuition;
}


int AcademicBuilding::getX(){
	return x;
}

int AcademicBuilding::getPos(){
	return pos;
}

int AcademicBuilding::getY(){
	return y;
}


double AcademicBuilding::getValue(){
		return tuition;
}

double AcademicBuilding::getTuitionWithImprovements(){
	return tuitionWithImprovements.at(getNumberOfImprovements());
}

std::shared_ptr<Player> AcademicBuilding::getOwner(){
		return owner;
}

void AcademicBuilding::setOwner(std::shared_ptr<Player> p){
		owner = p;
}

void AcademicBuilding::buyProperty(std::shared_ptr<Player> p, Board & board){
	if (owner != nullptr) {
	throw GameException("This property has already been purchased, too late :D");
	}
	else if ( isMortgaged == 0 ){
		throw GameException("This property is mortgaged");
	}
	else {
		p->removeFromFunds(purchaseCost);
		if ( p->getBankrupt() ){
			std::cout << "You are bankrupt "  << std::endl;
			board.Bankrupt(p, this->getOwner(),purchaseCost);
		}
		else{
		owner = p;
		std::string currBlock = this->getBlock();
		p->addToProperties( this->getName() );
		p->settotalValueOfProperties(this->getPurchaseCost());
		if (currBlock == "Arts1")  {
			p->addToPropertiesOwnedInABlock(0,1);
		}else if (currBlock == "Arts2") {
			p->addToPropertiesOwnedInABlock(1,1);
		}else if (currBlock == "Eng")  {
			p->addToPropertiesOwnedInABlock(2,1);
		}else if (currBlock == "Health") {
			p->addToPropertiesOwnedInABlock(3,1);
		}else if (currBlock == "Env") {
			p->addToPropertiesOwnedInABlock(4,1);
		}else if (currBlock == "Sci1") {
			p->addToPropertiesOwnedInABlock(5,1);
		}else if (currBlock == "Sci2") {
			p->addToPropertiesOwnedInABlock(6,1);
		}else if (currBlock == "Math") {
			p->addToPropertiesOwnedInABlock(7,1);
		}
	}
}
}

void AcademicBuilding::buyImprovement(std::shared_ptr<Player> p, Board & board) {
	if (owner != p){
	throw GameException("You cannot buy improvements for a property you did not buy");
	} else if (numberOfImprovements == 5) {
	throw GameException("You cannot buy anymore improvements for this property, you already have 5 improvements.");
	} 
	else if ( isMortgaged == 0 ){
		throw GameException("This property is mortgaged");
	}
	p->removeFromFunds(improvementCost);
	if ( p->getBankrupt() ){
		std::cout << "You are bankrupt "  << std::endl;
		board.Bankrupt(p, this->getOwner(),improvementCost);
	}
	else{
		addToNumberOfImprovements(1);
	}
}

void AcademicBuilding::sellImprovement(std::shared_ptr<Player> p) {
	if (owner != p){
	throw GameException("You are not allowed to sell improvements for this property as you are not the owner of this property.");
	} else if (numberOfImprovements == 0) {
	throw GameException("There 0 improvements on this building and hence nothing can be sold.");
	} 
	else if ( isMortgaged == 0 ){
		throw GameException("This property is mortgaged");
	}
	else {
		p->addToFunds(improvementCost);
		addToNumberOfImprovements(-1);
	}
}

void AcademicBuilding::mortgage(std::shared_ptr<Player> p){
	if (numberOfImprovements != 0){
	throw GameException("This property still has improvements, you have to sell all the improvements before you can mortgage a property.");
	} 
	else if ( isMortgaged == 0 ){
		throw GameException("This property is already mortgaged");
	}else {
	p->addToFunds(0.5 * purchaseCost);
	isMortgaged = 0;
	}
}

void AcademicBuilding::unmortgage(std::shared_ptr<Player> p, Board & board){
	/*
	if (owner != nullptr) {
	throw GameException("This property has already been purchased by someone else.");
	}
	*/
	if ( isMortgaged == -1 ){
		throw GameException("This property is already unmortgaged");
	}
	else {
		double amount = 0.6 * purchaseCost;
		p->removeFromFunds(0.6 * purchaseCost);
		if ( p->getBankrupt() ){
			std::cout << "You are bankrupt "  << std::endl;
			board.Bankrupt(p, this->getOwner(),amount);
		}
		else{
			owner = p;
			isMortgaged = -1;
		}
	}
}

void AcademicBuilding::landed(std::shared_ptr<Player> curr_player, Dice & dice, Board & board) {
	curr_player->setPos(pos);
	std::cout << "Landed on " << this->getName() << std::endl;
	if ( this->getOwner() != nullptr && this->getOwner() != curr_player && isMortgaged == -1 ){
		curr_player->removeFromFunds(this->getTuitionWithImprovements());
		if ( curr_player->getBankrupt() ){
			std::cout << "You are bankrupt "  << std::endl;
			board.Bankrupt(curr_player, this->getOwner(),this->getTuitionWithImprovements());
		}
		else{
			(this->getOwner())->addToFunds(this->getTuitionWithImprovements());
		}
	}
	
	if ( this->getOwner() == nullptr ){
		std::cout << "Would you like to buy " << this->getName() << " ? enter yes/no" << std::endl;
		std::string answer; 
		std::getline(std::cin,answer);
		if ( answer == "no" ){
			board.auction(this);
		}
	
		else {
			buyProperty(curr_player,board);
		}
	}
}





