#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>
#include <cstdlib>
#include <memory>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <utility>
#include "subject.h"
#include "player.h"
#include "textdisplay.h"
//#include "tile.h"
#include "academicbuilding.h"
#include "gym.h"
#include "residence.h"
#include "dice.h"
#include "slc.h"
#include "gototims.h"
#include "dctimsline.h"
#include "coopfee.h"
#include "tuition.h"
#include "collectosap.h"
#include "goosenesting.h"
#include "needleshall.h"
#include "gameexception.h"

class Tile;


class Board: public Subject{
	int ActiveRollUpRim; // The number of Active Roll Up the Rim cards
	std::shared_ptr<TextDisplay> textd;// A shared_ptr to a TextDisplay object. 
	std::shared_ptr<Player> Curr_Player;// a pointer to the current Player active. 
	std::vector<std::shared_ptr<Player>> Players;// Collection of current Players
	std::vector<std::shared_ptr<Tile>> board;// Collection shared_ptrs to Tile objects (tiles) on the board. 
	bool isProperty( std::string & ); // checks if the name is a property
	bool isProperty( int pos ); // checks according to the position
	void addPlayStats( std::string ); // updates the players according to load file
	bool hasImprovements( int pos ); // gets if a tile can have improvements
	std::string nonProperty(int position); // returns the name of the non property
	void createBids(std::map<std::shared_ptr<Player>,double> &);
	int numOfPlayersOnTile(std::shared_ptr<Tile>); 
	void printBids(std::map<std::shared_ptr<Player>,double>&);
	public:
	Board(); // constructor
	~Board();//destructor
	int getActiveRollUpRim();// returns the current number of roll up the rim cards. 
	void setActiveRollUpRim(int ); // adds/decrements to the current available RUTR if int i is 1 and removes if i is 0 
	int getNumPlayers();
	bool checkPlayer( std::string & ); // checks if the player name exists
	void init(int); // initializes the current board. 
	void save(std::string filename);// saves the current board. to the filename
	void rollTheDice(std::shared_ptr<Player>); // simulates the turn of rolling the Dice objects. 
	void displayAll();// displays all the assets of the current Players, does not work while a Player is deciding to pay Tuition. 
	std::shared_ptr<Tile> getTilepos( int pos ); // returns the tile at the give position in the Board
	std::shared_ptr<Player> getPlayer(std::string ); //returns the player requested in the game
	std::shared_ptr<Player> getCurrPlayer(); 
	void removePlayer(std::shared_ptr<Player> );// remove the given player from the Players collection. 
	//void addPlayer(std::shared_ptr<Player> );// add the given player to the Players collection. 

    void addPlayer(std::string player_char, std::string player_name, std::shared_ptr<Tile> t, int x, int y, int pos);

	void next();// moves to the next Player in the Players collection
	void load(std::string ); // loads a previous game file
	void move(std::shared_ptr<Player> , std::string ); // sets the given Player's position to the DCTimsLine
	void move(std::shared_ptr<Player>, int i ); // sets the given Player's position by the number of steps given by i. 
	// checks whether a tile can be bought or not, for eg, buyProperty for player has to check if the current tile is a property, matches what the player is on
	// for a mortgage, player calls this 
	bool canBuy(std::string Name, std::shared_ptr<Tile>, std::shared_ptr<Player> );
	virtual void notifyObservers(int, int, std::string player, int prev_pos, int new_pos,int numberOfPlayers ) override; 
	virtual void notifyObservers(int, int, int pos, int numberOnTile ) override;
	//void buyProperty(std::string Name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player);
	void buyImprovements(std::string name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player);
	void sellImprovements(std::string name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player);
	void mortgage(std::string name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player);
	void unmortgage(std::string name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player);
	void trade(std::string give, std::string receive,std::shared_ptr<Tile> tile1, std::shared_ptr<Tile> tile2, std::shared_ptr<Player> p, std::shared_ptr<Player> giver);
	std::shared_ptr<Player> getCurrentPlayers(std::string);
	std::shared_ptr<Tile> getTile(std::string ); // returns a shared ptr the tile name
	std::shared_ptr<Player> getCurrentPlayers( int );
	void roll(int , int);
	void Bankrupt(std::shared_ptr<Player>, std::shared_ptr<Player>, double );
	void auction(Tile * );
	void setSeed(int); 



};
#endif

