#include "board.h"
#include "residence.h"

	// Constructor
	Residence::Residence( std::string  Name, double PurchaseCost, int x, int y, int pos):Name{Name},PurchaseCost{PurchaseCost},x{x},y{y}, pos{pos}, Owner{nullptr},isMortgaged{-1}{}
	
	std::string Residence::getName(){
		return Name;
	}
	double Residence::getPurchaseCost(){
		return PurchaseCost;
	}
	std::shared_ptr<Player> Residence::getOwner(){
		return Owner;
	}
	
	void Residence::setOwner(std::shared_ptr<Player> curr_player){
		Owner = curr_player;
	}
	
	void Residence::setIsMortgaged(int i){
	isMortgaged = i;
}
	
	//allows Player to buy any Property tile. check the funds,
	// if they can purchase the property, set the Owner shared_ptr to point to the Player, 
	// remove the amount from the funds of the player. increase the Residences owns field for that player.
	void Residence::buyProperty(std::shared_ptr<Player> curr_player, Board & board){
		if ( Owner != nullptr ){
			throw GameException( "Residence Property is owned, cannot buy" );
		}
		else if ( isMortgaged == 0 ){
		throw GameException("This property is mortgaged");
	}
		curr_player->removeFromFunds(PurchaseCost);
		if ( curr_player->getBankrupt() ){
			
			std::cout << "You are bankrupt" << std::endl;
			board.Bankrupt(curr_player, this->getOwner(),PurchaseCost);
		}
		else{
		curr_player->addToProperties( this->getName() );
		curr_player->settotalValueOfProperties(this->getPurchaseCost());
		curr_player->setResidences(1);
		Owner = curr_player;
	}
	}	
	
	// Removes the property, mortgages a property 
	void Residence::mortgage(std::shared_ptr<Player> curr_player){
		if ( Owner != curr_player ){
			throw GameException("Residence Property is owned, cannot mortgage");
		}
		else if ( isMortgaged == 0 ){
		throw GameException("This property is already mortgaged");
	}
		double amount = 0.5 * PurchaseCost;
		curr_player->addToFunds(amount);
		isMortgaged = 0;
	}
	// Adds the property from the Player's mortgages collection
	void Residence::unmortgage(std::shared_ptr<Player> curr_player, Board & board){
		/*
		if ( Owner != nullptr || ) {
			throw GameException( "Residence Property is owned, cannot unmortgage" );
		}
		*/
		 if ( isMortgaged == -1 ){
		throw GameException("This property is already unmortgaged");
	}
		double amount = 0.6 * PurchaseCost;
		curr_player->removeFromFunds(amount);
		if ( curr_player->getBankrupt() ){
			std::cout << "You are bankrupt" << std::endl;
			board.Bankrupt(curr_player, this->getOwner(),amount);
		}
		else{
			Owner = curr_player;
			isMortgaged = -1;
		}
	}
	
	void Residence::landed(std::shared_ptr<Player> curr_player, Dice & dice, Board & board){
		curr_player->setPos(pos);
		// check if any rent is owed
		if ( this->getOwner() != nullptr && this->getOwner() != curr_player && isMortgaged == -1 ){
			// Calculate the amount owed 
			if ( Owner->getResidences() == 1 ){
				double amount = 25;
				curr_player->removeFromFunds(amount);
				if ( curr_player->getBankrupt() ){
					std::cout << "You are bankrupt" << std::endl;
					board.Bankrupt(curr_player, this->getOwner(),amount);
				}
				else{
					(this->getOwner())->addToFunds(amount);
				}
			}
			// Two Residences are owned
			else if ( Owner->getResidences() == 2 ){
				double amount = 50;
				curr_player->removeFromFunds(amount);
				if ( curr_player->getBankrupt() ){
					std::cout << "You are bankrupt" << std::endl;
					board.Bankrupt(curr_player, this->getOwner(),amount);
				}
				else{
					(this->getOwner())->addToFunds(amount);
				}
			}
			else if ( Owner->getResidences() == 3 ){
				double amount = 100;
				curr_player->removeFromFunds(amount);
				if ( curr_player->getBankrupt() ){
					std::cout << "You are bankrupt" << std::endl;
					board.Bankrupt(curr_player, this->getOwner(),amount);
				}
				else{
					(this->getOwner())->addToFunds(amount);
				}
			}
			else if ( Owner->getResidences() == 4 ){
				double amount = 200;
				curr_player->removeFromFunds(amount);
				if ( curr_player->getBankrupt() ){
					std::cout << "You are bankrupt" << std::endl;
					board.Bankrupt(curr_player, this->getOwner(),amount);
				}
				else{
					(this->getOwner())->addToFunds(amount);
				}
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
				buyProperty(curr_player, board);
			}
		}
}

	int Residence::getX(){
		return x;
	}
	
	int Residence::getY(){
		return y;
	}
	
	int Residence::getPos(){
		return pos;
	}
	
	
	int Residence::getIsMortgaged(){
	return isMortgaged;
}

int Residence::getNumberOfImprovements() { return -1; }


std::string Residence::getBlock(){
	return "";
}

double Residence::getImprovementCost() {
	return 0;
}

void Residence::buyImprovement(std::shared_ptr<Player> player, Board & board){}
void Residence::sellImprovement(std::shared_ptr<Player> player) {}
void Residence::setNumberOfImprovements(int num) {}


