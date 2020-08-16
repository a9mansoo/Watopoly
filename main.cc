#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "board.h"
#include "player.h"


/*
All Command Interpreter Error checking and handling can be done in main. 

///////////////////////////////////////////////////////////////////////////////////////
1) roll -> rolls the die, have to also check if it is a double as a double is needed by the following methods (add methods here);
2) next -> give the control to the next player
3) trade <name> <give> <receive> get the tile pointers from board (board has this method) call the trade method in player  trade(Player &p, std::string give, std::string receive, std::shared_ptr<Tile> tile1, std::share_ptr<Tile> tile2)
4) improve <property> buy: call the buyImprovements method in player, send in the name of the property and a shared pointer to tile. buyImprovements(std::string name, std::shared_ptr<Tile> tile);
5) improve <property> sel: call the sellImprovements method in player, send in the name of the property and a shared pointer to tile. sellImprovements(std::string name, std::shared_ptr<Tile> tile);
6) mortgage <property> call the mortgage method in player.
7) unmortgage <property> call the unmortgage method in player
8) buyProperty <property> call the buyProperty method in player.
9) bankrupt: set the bankrupt flag for that player call the set bankrupt method in player.
10) assets: call the displaay assets method in player.
11) all: loop through each player and call the displayassets method for that player.
12) save <filename>: save the current state of the game in a file with the given name
13) -load <filename>: load the file
14) -testing: enables testing mode
*/


void printMenu(){
	std::cout << "/////////////// WATOPOLY COMMANDS ///////////////" << std::endl;
	std::cout << "1) roll -> rolls the die" << std::endl;
	std::cout << "2) next -> give the control to the next player" << std::endl;
	std::cout << "3) trade <name> <give> <receive> -> trade with another player a property or money" << std::endl;
	std::cout << "4) improve <property> buy -> buy an improvement on an Academic Building" << std::endl;
	std::cout << "5) improve <property> sell -> sell an improvement on an Academic Building" << std::endl;
	std::cout << "6) mortgage <property> -> mortgage a property" << std::endl;
	std::cout << "7) unmortgage <property> -> unmortgage a property" << std::endl;
	//std::cout << "8) buy <property> -> buy a propery" << std::endl;
	std::cout << "8) bankrupt -> declare bankruptcy" << std::endl;
	std::cout << "9) assets -> display a player's assets" << std::endl;
	std::cout << "10) all -> print the assets of all players" << std::endl;
	std::cout << "11) save <filename> -> save the game in the given filename" << std::endl;
	std::cout << "12) -load <filename>: load the file" << std::endl;
	std::cout << "13) -testing: enables testing mode" << std::endl;
	std::cout << "14) quit: quits the game entirely" << std::endl;
	std::cout << "15) menu : prints the menu of commands again" << std::endl;
}








int main( int argc, char *argv[]){
	// Set testingMode flag
	bool testingMode = false;
	// just use cin. 
	int num_of_players = 0;
	// string for commands, give, receive, property, player_name, filename
	std::string command;
	std::string give;
	std::string receive;
	std::string property; 
	std::string player_name;
	std::string filename;
	int num = 0;
	bool load = false;
	std::unique_ptr<Board> b = std::make_unique<Board>();
	b->setSeed(0);
	b->init(num);
	if ( argc > 1 ){
		std::string cmd{argv[1]};
		if ( cmd == "-testing" ){
			testingMode = true;
		}
		else if ( cmd == "-load" ){
			b->load(argv[2]);
			load = true;
		}
		else if ( cmd == "-seed" ){
			b->setSeed(246);
		}
	}
	// extract number of players in the game
	std::cout << "*************** Welcome to our game *************** " << std::endl;
	while (true && !load && !testingMode){
		std::cout << "Enter number of players (2-6)" << std::endl;
		std::string line;
		std::getline(std::cin,line);
		std::stringstream ss(line);
		ss >> num; 
		if ( ss.fail() || num < 2 || num > 6 ){
			std::cout << "Please enter a number between 2 and 6" << std::endl;
		}
		else{
			num_of_players = num;
			break;
		}
	}
	// Add the players to the game
	int i = 0;
	std::shared_ptr<Player> p;
	while ( i < num_of_players && !testingMode ){
		std::cout << "Enter Player's Name" << std::endl;
		std::string player_char;
		std::getline(std::cin,player_name);
		try{
			std::cout << "Enter Player's Char" << std::endl;
			std::cout << " G | B | D | P | S | $ | L | T " << std::endl;
			std::getline(std::cin,player_char);
			b->addPlayer(player_char, player_name, b->getTilepos(0),9,83,0);
			++i;
		}
		catch (GameException & ge){
			std::cout << ge.what() << std::endl;
		}
	}
	int roll = 0;
	while (true && !testingMode && command != "quit" && b->getNumPlayers() != 1 ){
		// Read in the command
		printMenu();
		while ( true ){
			std::cout << "Current Player Char: " << (b->getCurrPlayer())->getSymbol() << std::endl;
			std::cout << "Current Player Name: " << (b->getCurrPlayer())->getName() << std::endl;
			std::cout << "Current Player's Tile: " << (b->getTilepos((b->getCurrPlayer())->getPos()))->getName() << std::endl;
			std::cout << "Enter Command : " << std::endl;
			std::getline(std::cin, command);
			if ( b->getNumPlayers() == 1 ){ break; }
			p = b->getCurrPlayer();
			// continue into while loop and not roll again
			if ( command == "quit" ){
				break;
			}
			if (command == "roll" && roll == 0){
				try{
					b->rollTheDice(p);
					roll = 1;
				}
				catch (GameException &ge){
					std::cout << ge.what() << std::endl;
				}
			}
			else if (command == "roll" && roll == 0){
				std::cout << "You just rolled! Input another command." << std::endl;
			}
			else if ( command == "next" ){
				b->next();
				roll = 0;
			}
			else if ( command.substr(0,5) == "trade" ){
				try{
					std::string accept;
					std::cout << "Would you like to accept this offer";
					//std::getline(std::cin, accept);
					
					command = command.substr(5,command.length());
					std::vector<std::string> commands;
					commands.resize(4);
					std::stringstream ss(command);
					int i = 0;
					while ( i < commands.size() ){
						ss >> commands[i];
						++i;
					}
					b->checkPlayer(commands[0]);
					std::cout << "Player  " << b->getPlayer(commands[0])->getSymbol() << " Please Type 'accept or reject'!" << std::endl;
					std::getline(std::cin, accept);
					if ( accept == "accept"){
						// check if give and receive are tiles
						if (b->getTile(commands[1]) == nullptr){
						b->trade(commands[1], commands[2] ,b->getTile(commands[2]),b->getTile(commands[1]), b->getCurrPlayer(), b->getPlayer(commands[0]));
						} else {
						b->trade(commands[1], commands[2] ,b->getTile(commands[1]),b->getTile(commands[2]), b->getCurrPlayer(), b->getPlayer(commands[0]));
						}
					} else if ( accept != "reject"  && accept != "accept"){
						std::cout << "Please enter accept or reject to move forward" << std::endl;
					}
				}
				catch ( GameException & ge){
					std::cout << ge.what() << std::endl;
				}
			}
			
			else if ( command.substr(0,7) == "improve" ){
				try{
					command = command.substr(7,command.length());
					std::vector<std::string> commands;
					commands.resize(2);
					std::stringstream ss(command);
					int i = 0;
					while ( i < commands.size() ){
						ss >> commands[i];
						++i;
					}
					
					if ( commands[1] == "buy" ){
						b->buyImprovements( commands[0] ,b->getTile(commands[0]), b->getCurrPlayer() );
					}
					else if ( commands[1] == "sell" ){
						b->sellImprovements( commands[0] , b->getTile(commands[0]), b->getCurrPlayer() );
					}
					else{
						std::cout << "Please enter a valid command" << std::endl;
						continue;
					}
				}
				catch ( GameException &ge ){
					std::cout << ge.what() << std::endl;
				}
			}
			/*
			else if ( command.substr(0,3) == "buy" ){
				try{
					command = command.substr(3,command.length());
					std::vector<std::string> commands;
					commands.resize(1);
					std::stringstream ss(command);
					int i = 0;
					while ( i < commands.size() ){
						ss >> commands[i];
						++i;
					}
					b->buyProperty(commands[0], b->getCurrPlayer())->getPosition(),  b->getCurrPlayer());
				
				}
				catch ( GameException & ge ){
					std::cout << ge.what() << std::endl;
				}
			}
			*/
			
			
			else if ( command == "menu" ){
				try{
					printMenu();
				
				}
				catch ( GameException & ge ){
					std::cout << ge.what() << std::endl;
				}
			}
			
			else if ( command == "bankrupt" ){
				try{
					(b->getCurrPlayer())->setBankrupt(true);
					b->Bankrupt(b->getCurrPlayer(), nullptr,0);
					//b->removePlayer(b->getCurrPlayer());
				}
				catch ( GameException &ge ){
					std::cout << ge.what() << std::endl;
				}
			}
			else if ( command.substr(0,8) == "mortgage" ){
				try{
					command = command.substr(8,command.length());
					std::vector<std::string> commands;
					commands.resize(1);
					std::stringstream ss(command);
					int i = 0;
					while ( i < commands.size() ){
						ss >> commands[i];
						++i;
					}
					b->mortgage(commands[0], b->getTile(commands[0]), b->getCurrPlayer());
				}
				catch ( GameException & ge ){
					std::cout << ge.what() << std::endl;
				}
			}
			else if ( command.substr(0,10) == "unmortgage" ){
				try{
					command = command.substr(10,command.length());
					std::vector<std::string> commands;
					commands.resize(1);
					std::stringstream ss(command);
					int i = 0;
					while ( i < commands.size() ){
						ss >> commands[i];
						++i;
					}
					b->unmortgage(commands[0], b->getTile(commands[0]), b->getCurrPlayer());
				}
				
				catch ( GameException &ge ){
					std::cout << ge.what() << std::endl;
				}
			}
			else if ( command == "assets" ){
				(b->getCurrPlayer())->displayAssets();
			}
			else if ( command == "all" ){
				(b->displayAll());
			}
			else if ( command.substr(0,4) == "save" ){
				std::string filename; 
				filename = command.substr(5,command.length());
				b->save(filename);
				break;
			}
			
			else {
				std::cout << "Please input correct command!" << std::endl;
			}
		}
	}
	
	if ( testingMode ){
		std::cout << "Testing Mode" << std::endl;
		std::cout << "Enter roll <die1> <die2> where die1 and die2 is an int" << std::endl;
		std::string command;
		std::getline(std::cin, command);
		std::vector<std::string> commands;
		commands.resize(3);
		std::stringstream ss(command);
		int i = 0;
		while ( i < commands.size() ){
			ss >> commands[i];
			++i;
		}
		if ( commands[0] == "roll" ){
			int die1;
			int die2;
			std::stringstream d1(commands[1]);
			std::stringstream d2(commands[2]);
			d1 >> die1;
			d2 >> die2;
			if ( d1.fail() || d2.fail() ){
				b->rollTheDice(p);
			}
			b->roll(die1, die2);
		}
		
	}
	
	
	if ( b->getNumPlayers() == 1 ){
		std::cout << "Winner is: " << b->getCurrentPlayers(0)->getName() << std::endl;
	}
	
	
	
	
	std::cout << "Thanks for playing!" << std::endl;
	return 0;
	

}


