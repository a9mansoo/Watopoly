#include "player.h"
using namespace std;


/*
const std::string& Player::checkChar(const std::string& symbol){
	if ( symbol != "G" || symbol != "B" || symbol != "D" || symbol != "P" || symbol != "S" || symbol != "$" 
		|| symbol != "L" || symbol != "T" ){
			throw GameException("Please enter a symbol from the table");
		}
		return symbol;
}

*/

// Constructor for a player
Player::Player(std::string symbol, std::string name, std::shared_ptr <Tile> position, int x, int y, int pos):
					symbol{symbol}, name{name}, funds{1500}, totalValueOfProperties{0}, totalValueOfImprovements{0}, bankrupt{false}, 
					position{position}, x{x}, y{y}, pos{pos}, collect{true}, rollUpTheRim{0}, sentToTims{false},
					gyms{0}, residences{0}, payTuition{false}, turnsInTimsLine{0}  { properties.resize(0); blocks.resize(8); }



Player::~Player(){}

std::string Player::getSymbol(){
	return symbol;
}

std::string Player::getName(){
	return name;
}

double Player::getFunds(){
	return funds;
}

double Player::getTotalValueOfProperties(){
	return totalValueOfProperties;
}

double Player::getTotalValueOfImprovements(){
	return totalValueOfImprovements;
}

void Player::setX(int position){
	x = position;
}

void Player::setY(int position){
	y = position;
}


std::vector<std::string> Player::getProperties(){
	return properties;
}

bool Player::getBankrupt(){
	return bankrupt;
}

void Player::setBankrupt(bool val){
	bankrupt = val;
}

std::shared_ptr<Tile> Player::getPosition(){
	return position;
}

void Player::setPosition(std::shared_ptr<Tile> tile){
	position = tile;
}


int Player::getX(){
	return x;
}
int Player::getY(){
	return y;
}

int Player::getPos(){
	return pos;
}

void Player::setPos(int i) {
	pos = i;
}

bool Player::getCollect(){
	return collect;
}

void Player::setCollect(bool val){
	collect = val;
}

int Player::getRollUpTheRim(){
	return rollUpTheRim;
}

void Player::setRollUpTheRim(int i){
	if ( getRollUpTheRim() == 0 && i < 0 ){
		throw GameException("You do not have enough Roll Up The Rim Cups");
	}
	rollUpTheRim += i;
}

bool Player::getSentToTims(){
	return sentToTims;
}

void Player::setSentToTims(bool val){
	sentToTims = val;
}

int Player::getPropertiesOwnedInABlock(int n){
	return blocks.at(n);
}

void Player::addToPropertiesOwnedInABlock(int index, int i ){
	blocks.at(index) += i;
}


int Player::getGyms(){
	return gyms;
}

void Player::setGyms(int i){
	gyms += i;
}

int Player::getResidences(){
	return residences;
}

void Player::setResidences(int i){
	residences += i;
}

bool Player::getPayTuition(){
	return payTuition;
}

void Player::setPayTuition(bool val){
	payTuition = val;
}


int Player::getTurnsInTimsLine(){
	return turnsInTimsLine;
}

void Player::setTurnsInTimsLine(int i){
	turnsInTimsLine = i;
}

void Player::addTurnsInTimsLine(){
	++turnsInTimsLine;
}

void Player::addToFunds(double amount){
	funds += amount;
}

void Player::removeFromFunds(double amount){
	if ( funds < amount ){
		bankrupt = true;
	}
	else{
		funds -= amount;
	}
}

void Player::payRent(std::shared_ptr<Player> other, double amount){
	this->removeFromFunds(amount);
	if ( bankrupt ){
		std::cout << "Sorry you are bankrupt, have to sell assets to make up for : " << amount << std::endl;
		displayAssets();
	}
	else{
		other->addToFunds(amount);
	}
}

bool Player::ownsMonopolyBlock(int i){
	if (i == 0 || i == 7){
		if (blocks.at(i) == 2) {
		return true;
		}
	} else if (blocks.at(i) == 3) {
		return true;
	}
	return false;
}

bool Player::ownProperty(std::string name) {
	for(auto& i: properties){
	if (i == name){
		return true;
		}
	} return false;
}

void Player::settotalValueOfProperties(int i){
	totalValueOfProperties += i;
}


void Player::removeFromProperties(std::string name) {
	auto it = find(properties.begin(), properties.end(), name);
	properties.erase(it);
}

void Player::addToProperties(std::string name) {
	properties.emplace_back(name);
}

int Player::numberOfProperties() {
	return properties.size();
}


void Player::displayAssets(){
	cout << "You have a total of " << funds << " dollars" << std::endl;
	int own = this->numberOfProperties() - this->getGyms() - this->getResidences();
	if (own < 0){
		cout << "You own " << 0 << " Academic buildings" << std::endl;
	} else {
		cout << "You own " << own << " Academic buildings" << std::endl;
	}
	cout << "You own " << this->getGyms() << " gyms" << std::endl;
	cout << "You own " << this->getResidences()  << " residences" << std::endl;
	cout << "The total value of all the properties you own is: " << totalValueOfProperties << std::endl;
	cout <<  "The total value of all the improvements you own is: " << totalValueOfImprovements << std::endl;
	cout << "Total value of properties with improvements is: " << totalValueOfImprovements + totalValueOfProperties << std::endl;
	cout << "Total RollUp the Rim: " << getRollUpTheRim() << std::endl;
}









