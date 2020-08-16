#include "board.h"
#include "gym.h"

	// Constructor
	Gym::Gym( std::string Name, double PurchaseCost, int x, int y, int pos):Name{Name},PurchaseCost{PurchaseCost},x{x},y{y}, pos{pos}, Owner{nullptr}, isMortgaged{-1}{}
	
	std::string Gym::getName(){
		return Name;
	}
	double Gym::getPurchaseCost(){
		return PurchaseCost;
	}
	std::shared_ptr<Player> Gym::getOwner(){
		return Owner;
	}
	
	void Gym::setOwner(std::shared_ptr<Player> curr_player){
		Owner = curr_player;
	}
	
	int Gym::getIsMortgaged(){
	return isMortgaged;
}

void Gym::setIsMortgaged(int i){
	isMortgaged = i;
}
	
	
	//allows Player to buy any Property tile. check the funds,
	// if they can purchase the property, set the Owner shared_ptr to point to the Player, 
	// remove the amount from the funds of the player. increase the gyms owns field for that player.
	void Gym::buyProperty(std::shared_ptr<Player> curr_player, Board & board){
		if ( Owner != nullptr ){
			throw GameException( "Gym Property is owned, cannot buy" );
		}
		else if ( isMortgaged == 0 ){
		throw GameException("This property is mortgaged");
	}
		curr_player->removeFromFunds(PurchaseCost);
		if ( curr_player->getBankrupt() ){
			std::cout << "You are bankrupt and owe player: " << std::endl;
			board.Bankrupt(curr_player, this->getOwner(),PurchaseCost);
		}
		else{
			curr_player->addToProperties( this->getName() );
			curr_player->settotalValueOfProperties(this->getPurchaseCost());
			curr_player->setGyms(1);
			Owner = curr_player;
		}
	} 
	
	// Removes the property, mortgages a property 
	void Gym::mortgage( std::shared_ptr<Player> curr_player){
		if ( Owner != curr_player ){
			throw GameException("Gym Property is owned, cannot mortgage");
		}
		else if ( isMortgaged == 0 ){
			throw GameException("This property is already mortgaged");
		}
		double amount = 0.5 * PurchaseCost;
		curr_player->addToFunds(amount);
		isMortgaged = 0;
	}
	// Adds the property from the Player's mortgages collection
	void Gym::unmortgage(std::shared_ptr<Player> curr_player, Board & board){
		/*
		if ( Owner != nullptr ) {
			throw GameException( "Gym Property is owned, cannot unmortgage" );
		}*/
		if ( isMortgaged == -1 ){
			throw GameException("This property is already unmortgaged");
		}
		double amount = 0.6 * PurchaseCost;
		curr_player->removeFromFunds(amount);
		if ( curr_player->getBankrupt() ){
			std::cout << "You are bankrupt and owe player: " << std::endl;
			board.Bankrupt(curr_player, this->getOwner(),amount);
		}
		else{
			Owner = curr_player;
			isMortgaged = -1;
		}
	}
	
	// Carry out any payment of rent if required
	void Gym::landed(std::shared_ptr<Player> curr_player, Dice & dice, Board & board){
		curr_player->setPos(pos);
		// check if any rent is owed
		if ( this->getOwner() != nullptr && this->getOwner() != curr_player && isMortgaged == -1 ){
			// Calculate the amount owed 
			if ( Owner->getGyms() == 1 ){
				double amount = 4 * (dice.getValue() + dice.getValue());

				curr_player->removeFromFunds(amount);
				if ( curr_player->getBankrupt() ){
					std::cout << "You are bankrupt and owe player: " << std::endl;
					board.Bankrupt(curr_player, this->getOwner(),amount);
				}
				else{
					(this->getOwner())->addToFunds(amount);
				}
			}
			// Two gyms are owned
			else{
				double amount = 10 * (dice.getValue() + dice.getValue());
				curr_player->removeFromFunds(amount);
				if ( curr_player->getBankrupt() ){
					std::cout << "You are bankrupt and owe player: " << std::endl;
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
				buyProperty(curr_player,board);
			}
		}
	}
	
	int Gym::getX(){
		return x;
	}
	int Gym::getY(){
		return y;
	}
	
	int Gym::getPos(){
		return pos;
	}
	
	std::string Gym::getBlock() {
		return "";
	}
	
	double Gym::getImprovementCost() {
		return 0;
	}
		

void Gym::buyImprovement(std::shared_ptr<Player> player, Board & board){}
void Gym::sellImprovement(std::shared_ptr<Player> player) {}
int Gym::getNumberOfImprovements() { return -1; }
void Gym::setNumberOfImprovements(int num) {}


