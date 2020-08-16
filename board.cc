#include "board.h"

Board::Board():ActiveRollUpRim{0},textd{nullptr}, Curr_Player{nullptr}{ board.reserve(40);
Players.reserve(0);}
Board::~Board(){}

int Board::getActiveRollUpRim(){// returns the current number of roll up the rim cards. 
	return ActiveRollUpRim;
}

void Board::setActiveRollUpRim(int i){
	ActiveRollUpRim += i;
}

bool Board::isProperty(std::string & Name) {
	if ( board.at(1)->getName() == Name || board.at(3)->getName() == Name || board.at(5)->getName() == Name || board.at(6)->getName() == Name || board.at(8)->getName() == Name || board.at(9)->getName() == Name ||
		board.at(11)->getName() == Name || board.at(12)->getName() == Name || board.at(13)->getName() == Name || board.at(14)->getName() == Name || board.at(15)->getName() == Name || board.at(16)->getName() == Name || 
		board.at(18)->getName() == Name || board.at(19)->getName() == Name || board.at(21)->getName() == Name || board.at(23)->getName() == Name || board.at(24)->getName() == Name || board.at(25)->getName() == Name ||
		board.at(26)->getName() == Name || board.at(27)->getName() == Name || board.at(28)->getName() == Name || board.at(29)->getName() == Name || board.at(31)->getName() == Name || board.at(32)->getName() == Name ||
		board.at(34)->getName() == Name || board.at(35)->getName() == Name || board.at(37)->getName() == Name || board.at(38)->getName() == Name || board.at(39)->getName() == Name){
			return true;
		}
	return false;
}

int Board::getNumPlayers(){
	return Players.size();
}



std::shared_ptr<Player> Board::getCurrentPlayers( int i ){
	return Players.at(i);
}

// Number of players on this current tile

void Board::notifyObservers(int x, int y, std::string player, int prev_pos, int new_pos, int numberOfPlayers){ // notifies text display when tile or dice invoke their notify methods and display the td
	textd->addPlayerToTile(x,y, new_pos, prev_pos, player, numberOfPlayers, Curr_Player);
}

void Board::notifyObservers(int x, int y, int pos, int numberOnTile){
	if ( numberOnTile != -1 ){
	textd->addImprovementsToTile(x,y,pos,numberOnTile);
	}
	else{
		textd->removeImprovementsFromTile(x,y,pos,numberOnTile);
	}
}

std::shared_ptr<Player> Board::getCurrPlayer(){
	return Curr_Player;
}


void Board::init(int num){ // initializes the current board. 
	//Players.resize(num);
	std::vector<double> AL_imp {2,10,30,90,160,250};
	std::vector<double> ML_imp {4, 20, 60, 180, 320, 450};
	std::vector<double> ECHPAS_imp {6,30, 90, 270, 400, 550};
	std::vector<double> HH_imp{8,40, 100,300,450,600};
	std::vector<double> RCHDWE_imp {10,50,150,450,625,750};
	std::vector<double> LHIBMH_imp {14,70,200, 550, 750, 950};
	std::vector<double> CPH_imp {12,60,180,500,700,900};
	std::vector<double> OPT_imp {16, 80, 220, 600, 800, 1000};
	std::vector<double> EV1EV2_imp {18, 90, 250, 700, 875, 1050};
	std::vector<double> EV3_imp {20, 100, 300, 750, 925, 1100};
	std::vector<double> PHYB1_imp {22, 110, 330, 800, 975, 1150};
	std::vector<double> B2_imp {24,120, 360, 850, 1025, 1200};
	std::vector<double> EITESC_imp {26, 130,390,900,1100,1275};
	std::vector<double> C2_imp {28, 150, 450, 1000, 1200, 1400};
	std::vector<double> MC_imp {35, 175, 500, 1100, 1300, 1500};
	std::vector<double> DC_imp {50, 200, 600, 1400, 1700, 2000};
	// 0 Collect Osap
	board.emplace_back(std::make_shared<CollectOSAP>(10,10,0));
	// 1 AL
	board.emplace_back(std::make_shared<AcademicBuilding>("AL", "Arts1", 40, 50, 2, AL_imp, nullptr, 10,9,1));
	// 2 SLC
	board.emplace_back(std::make_shared<SLC>(10,8,2));
	// 3 ML
	board.emplace_back(std::make_shared<AcademicBuilding>("ML", "Arts1", 60, 50, 4, ML_imp, nullptr, 10,7,3));
	// 4 Tuition
	board.emplace_back(std::make_shared<Tuition>(10,6,4));
	// 5 MKV
	board.emplace_back(std::make_shared<Residence>("MKV", 200 ,10,5, 5));
	// 6 ECH
	board.emplace_back(std::make_shared<AcademicBuilding>("ECH", "Arts2", 100, 50, 6, ECHPAS_imp, nullptr, 10,4, 6));
	// 7 Needles Hall
	board.emplace_back(std::make_shared<NeedlesHall>(10,3,7));
	// 8 PAS
	board.emplace_back(std::make_shared<AcademicBuilding>("PAS", "Arts2", 100, 50, 6, ECHPAS_imp, nullptr, 10,2,8));
	// 9 HH
	board.emplace_back(std::make_shared<AcademicBuilding>("HH", "Arts2", 120, 50, 8,HH_imp, nullptr, 10,1, 9));
	// 10 DC Tims line
	board.emplace_back(std::make_shared<dcTimsLine>(10,0,10));
	// 11 RCH
	board.emplace_back(std::make_shared<AcademicBuilding>("RCH", "Eng", 140, 100, 10, RCHDWE_imp, nullptr, 9,0,11));
	// 12 PAC
	board.emplace_back(std::make_shared<Gym>("PAC", 150 , 8,0,12));
	// 13 DWE
	board.emplace_back(std::make_shared<AcademicBuilding>("DWE", "Eng", 140, 100, 10, RCHDWE_imp, nullptr, 7,0,13));
	// 14 CPH
	board.emplace_back(std::make_shared<AcademicBuilding>("CPH", "Eng", 160, 100, 12, CPH_imp, nullptr, 6,0,14));
	// 15 UWP
	board.emplace_back(std::make_shared<Residence>("UWP", 200 , 5,0,15));
	// 16 LHI
	board.emplace_back(std::make_shared<AcademicBuilding>("LHI", "Health", 180, 100, 14, LHIBMH_imp, nullptr, 4,0,16));
	// 17 SLC
	board.emplace_back(std::make_shared<SLC>(3,0,17));
	// 18 BMH
	board.emplace_back(std::make_shared<AcademicBuilding>("BMH", "Health", 180, 100, 14, LHIBMH_imp, nullptr, 2,0, 18));
	// 19 OPT
	board.emplace_back(std::make_shared<AcademicBuilding>("OPT", "Health", 200, 100, 16, OPT_imp, nullptr, 1,0,19)); 
	// 20 Goose Nesting
	board.emplace_back(std::make_shared<GooseNesting>(0,0,20));
	// 21 EV1
	board.emplace_back(std::make_shared<AcademicBuilding>("EV1", "Env", 220, 150, 18, EV1EV2_imp, nullptr, 0,1,21));
	// 22 Needles Hall
	board.emplace_back(std::make_shared<NeedlesHall>(0,2,22));
	// 23 EV2
	board.emplace_back(std::make_shared<AcademicBuilding>("EV2", "Env", 220, 150, 18, EV1EV2_imp, nullptr, 0,3, 23));
	// 24 EV3
	board.emplace_back(std::make_shared<AcademicBuilding>("EV3", "Env", 240, 150, 20, EV3_imp, nullptr,0,4, 24));
	// 25 V1
	board.emplace_back(std::make_shared<Residence>("V1", 200 , 0,5,25));
	// 26 PHYS
	board.emplace_back(std::make_shared<AcademicBuilding>("PHYS", "Sci1", 260, 150, 22, PHYB1_imp, nullptr,0,6, 26));
	// 27 B1
	board.emplace_back(std::make_shared<AcademicBuilding>("B1", "Sci1", 250, 150, 22, PHYB1_imp, nullptr, 0,7,27));
	// 28 CIF
	board.emplace_back(std::make_shared<Gym>("CIF", 150,0,8, 28));
	// 29 B2
	board.emplace_back(std::make_shared<AcademicBuilding>("B2", "Sci1", 280, 150, 24, B2_imp, nullptr, 0,9, 29));
	// 30 Go To Tims
	board.emplace_back(std::make_shared<GoToTims>(0,10,30));
	// 31 EIT
	board.emplace_back(std::make_shared<AcademicBuilding>("EIT", "Sci2", 300, 200, 26, EITESC_imp, nullptr, 1,10,31));
	// 32 ESC
	board.emplace_back(std::make_shared<AcademicBuilding>("ESC", "Sci2", 300, 200, 26, EITESC_imp, nullptr, 2,10,32));
	// 33 SLC
	board.emplace_back(std::make_shared<SLC>(3,10,33));
	// 34 C2
	board.emplace_back(std::make_shared<AcademicBuilding>("C2", "Sci2", 320, 200, 28,C2_imp, nullptr,4,10, 34));
	// 35 REV
	board.emplace_back(std::make_shared<Residence>("REV", 200 ,5,10, 5));
	// 36 Needles Hall
	board.emplace_back(std::make_shared<NeedlesHall>(6,10,36));
	// 37 MC
	board.emplace_back(std::make_shared<AcademicBuilding>("MC", "Math", 350, 200, 35, MC_imp, nullptr, 7,10,37));
	// 38 Coop Fee
	board.emplace_back(std::make_shared<CoopFee>(8,10,38));
	// 39 DC
	board.emplace_back(std::make_shared<AcademicBuilding>("DC", "Math", 400, 200, 50, DC_imp, nullptr,9,10, 39));
	textd = std::make_shared<TextDisplay>();
	this->attach(textd);
	textd->printMyCurrentBoard();

}


int Board::numOfPlayersOnTile(std::shared_ptr<Tile> tile){
	int num = 0;
	for ( auto player:Players ) {
		int p_pos = player->getPos();
		int t_pos = tile->getPos();
		if ( p_pos == t_pos ){
			num += 1;
		}
	}
	return num;
}



void Board::rollTheDice(std::shared_ptr<Player> p){// simulates the turn of rolling the Dice objects. 
	std::shared_ptr<Dice> temp_d;
	if ( Curr_Player->getSentToTims() ){
		std::shared_ptr<Tile> temp = board.at(10);
		temp->landed(Curr_Player, *temp_d, *this);
		//int num = numOfPlayersOnTile(temp);
		//this->notifyObservers(Curr_Player->getX(), Curr_Player->getY(), Curr_Player->getSymbol(), 10, 10, num);
	}
	/*
	else if ( (Curr_Player->getPosition())->getName() == "PAC" || (Curr_Player->getPosition())->getName() == "CIF" ){
		std::shared_ptr<Tile> temp = board.at((Curr_Player->getPosition())->getPos());
		temp->landed(Curr_Player, *temp_d, *this);
		int num = numOfPlayersOnTile(temp);
		this->notifyObservers(Curr_Player->getX(), Curr_Player->getY(), Curr_Player->getSymbol(), Curr_Player->getPos(), Curr_Player->getPos(), num);
	}
	*/
	
	else{
		std::unique_ptr<Dice> d1 = std::make_unique<Dice>();
		std::unique_ptr<Dice> d2 = std::make_unique<Dice>();
		int sum  = d1->getValue() + d2->getValue();
		std::cout << "Current Player : "<< Curr_Player->getSymbol() << " Roll is: " << sum << std::endl;
		int new_pos = Curr_Player->getPos() + sum;
	
		if ( new_pos > 39 ){
			// check the landed for tile 
			std::shared_ptr<Tile> temp = board.at(0);
			temp->landed(Curr_Player, *d1, *this);
			new_pos -= 40; 
			if ( new_pos == 30 || new_pos == 2 || new_pos == 33 ){
				temp = board.at(new_pos);
				temp->landed(Curr_Player, *d1, *this);
				//int num = numOfPlayersOnTile(temp);
				//this->notifyObservers(Curr_Player->getX(), Curr_Player->getY(), Curr_Player->getSymbol(), Curr_Player->getPos(), new_pos, num);
				//Curr_Player->setPos(new_pos);
				//Curr_Player->setPosition(temp);
			}
			else{
				int num = numOfPlayersOnTile(temp);
				this->notifyObservers(Curr_Player->getX(), Curr_Player->getY(), Curr_Player->getSymbol(), Curr_Player->getPos(), new_pos, num);
				Curr_Player->setPos(new_pos);
				Curr_Player->setPosition(temp);
			}
			
		}
		else{
			std::shared_ptr<Tile> temp = board.at(new_pos);
			temp->landed(Curr_Player, *d1, *this);
			if ( new_pos == 30 || new_pos == 2 || new_pos == 33 ){
				//int num = numOfPlayersOnTile(temp);
				//this->notifyObservers(Curr_Player->getX(), Curr_Player->getY(), Curr_Player->getSymbol(), Curr_Player->getPos(), new_pos, num);
			}
			else{
				int num = numOfPlayersOnTile(temp);
				this->notifyObservers(Curr_Player->getX(), Curr_Player->getY(), Curr_Player->getSymbol(), Curr_Player->getPos(), new_pos, num);
				Curr_Player->setPos(new_pos);
				Curr_Player->setPosition(temp);
			}
		}
	}
}

void Board::displayAll(){// displays all the assets of the current Players, does not work while a Player is deciding to pay Tuition. 
	for (auto player: Players){
		std::cout << "Player Name: " << player->getName() << std::endl;
		std::cout << "Player Symbol: " << player->getSymbol() << std::endl;
		std::cout << "---- Player  Assests List ----" << std::endl;
		player->displayAssets();
		std::cout << "------------------------------" << std::endl;
	}
}


bool Board::checkPlayer(std::string & Name){
	for ( auto player: Players ){
		std::string name_of_player = player->getName();
		if ( name_of_player == Name ){
			return true;
		}
	}
	return false;
}


std::shared_ptr<Player> Board::getPlayer(std::string Name){ //returns requested player in the game
	if ( !checkPlayer(Name) ){
		throw GameException( "Player does not exist in game" );
	}
	else{
		for ( auto player: Players ){
			std::string name_of_player = player->getName();
			if ( name_of_player == Name ){
				return player;
			}
		}
	}
	return nullptr;
}


void Board::removePlayer(std::shared_ptr<Player> curr_player){// remove the given player from the Players collection. 
	auto it = find(Players.begin(), Players.end(), curr_player);
	int rutr = curr_player->getRollUpTheRim();
	this->setActiveRollUpRim(-rutr);
	// we found the player
	if ( it != Players.end() ){
		Players.erase(it);
	}
}

void Board::addPlayer(std::string player_char, std::string player_name, std::shared_ptr<Tile> t, int x, int y, int pos){
	std::shared_ptr<Player> newPlayer;
    newPlayer = std::make_shared<Player>(player_char, player_name, t , x, y, pos);// add the given player to the Players collection. 
	Players.push_back(newPlayer);
	std::shared_ptr<Tile> temp = board.at(pos);
	Curr_Player = newPlayer;
	int num = numOfPlayersOnTile(temp);
	this->notifyObservers(newPlayer->getX(), newPlayer->getY(), newPlayer->getSymbol(),  newPlayer->getPos(), newPlayer->getPos(), num);
}

void Board::next(){// moves to the next Player in the Players collection
	int size = Players.size();
	for ( int i = 0; i < size; i++ ){
		if ( Players.at(i) == Curr_Player ){
			if ( i == size - 1 ){
				Curr_Player = Players.at(0);
				break;
			}
			else{
				Curr_Player = Players.at(i+1);
				break;
			}
		}
	}
}


std::shared_ptr<Tile> Board::getTile(std::string Name){
	for ( auto tile: board){
			std::string search = Name;
			if ( search == tile->getName() ){
				return tile;
			}
	}
	return nullptr;
}

std::string Board::nonProperty(int position){
	if ( position == 0 ){
		return "Collect OSAP";
	}
	else if ( position == 2 || position == 17 || position == 33 ){
		return "SLC";
	}
	else if ( position == 4 ){
		return "Tuition";
	}
	else if ( position == 7 || position == 22 || position == 36){
		return "Needles Hall";
	}
	else if ( position == 10 ){
		return "DC Tims Line";
	}
	else if ( position == 20 ){
		return "Goose Nesting";
	}
	else if ( position == 30 ){
		return "Go To Tims Line";
	}
	else if ( position == 38 ){
		return "CoopFee";
	}
	else{
		return " ";
	}
}

std::shared_ptr<Tile> Board::getTilepos( int pos ){
	return board.at(pos);
}

void Board::addPlayStats( std::string line ){
	//// add the string stream failure *****************************************************************************************************************************************************************************************************************
	int len = line.size();
	int size = 0;
	// for ( int i = 0; i < len; ++i ){
	// 	if ( line[i] == ' ' ){
	// 		size += 1;
	// 	}
	// }
	std::string player_name{""};
	std::string player_char{""};
	std::stringstream ss{line};
	int num = 0;
	int in_tims = 0;
	int player_funds = 0;
	int player_cups = 0;
	int player_pos = 0;
	ss >> player_name;
	ss >> player_char;
	ss >> player_cups;
	ss >> player_funds;
	ss >> player_pos;
	
	if ( size == 6 ){
		ss >> num;
	}
	if ( size == 7 ){
		ss >> in_tims;
		ss >> num;
		
	}
	// Invoke player constructor and add the Player to the array. 
	
	//std::shared_ptr<Player> temp = std::make_shared<Player>(player_char, player_name, getTilepos(player_pos),player_pos, player_pos, player_pos);
	addPlayer(player_char, player_name, getTilepos(player_pos),player_pos, player_pos, player_pos);
	// Check current positions and set the appropriate flags for tims
	for (auto player: Players ){
		if ( player->getPos() == 10 ){
			if ( in_tims == 1 ){
				player->setCollect(false);
				player->setSentToTims(true);
				player->setSentToTims(num);
			}
		}
		player->addToFunds(-1500);
		player->addToFunds(player_funds);
	}
}

bool Board::hasImprovements( int pos ){
	if ( pos ==  1 || pos == 3 || pos == 6 || pos == 8 || pos == 9 || pos == 11 || pos == 13 || pos == 14 || pos == 16 || pos == 18 || pos == 21 || pos == 23 || pos == 24 || pos == 26 || pos == 27 || pos == 29 || pos == 31 || pos == 32 || pos == 34 || pos == 37 || pos == 39){
			return true;
	}
	return false;
}

bool Board::isProperty( int pos ){
		if ( pos == 1 || pos == 3 || pos == 5 || pos == 6 || pos == 8 || pos == 9 ||
		pos == 11 || pos == 12 || pos == 13 || pos == 14 || pos == 15 || pos == 16 || 
		pos == 18 || pos == 19 || pos == 21 || pos == 23 || pos == 24 || pos == 25 ||
		pos == 26 || pos == 27 || pos == 28 || pos == 29 || pos == 31 || pos == 32 ||
		pos == 34 || pos == 35 ||  pos == 37 || pos == 38 || pos == 39){
			return true;
		}
	return false;
}


void Board::load(std::string filename){// loads a previous game file
	// load the std::cin 
	std::unique_ptr<std::ifstream> infile = std::make_unique<std::ifstream>(filename);
	if ( infile == nullptr || infile->fail() ){
		throw GameException("Cannot load the file");
	}
	// the file opened
	std::string line; 
	// first line numPlayers
	std::getline( *infile, line); 
	std::stringstream ss{line};
	int numPlayers = 0;
	ss >> numPlayers;
	init(numPlayers);
	for ( int i = 0; i < numPlayers; ++i ){
		// Get the line for each player
		std::string player_info;
		std::getline(*infile, player_info);
		std::cout << player_info << std::endl;
		// go through the line parts, 6 parts or 7 parts
		addPlayStats(player_info);
	}
	
	
	
	
	// Now set the owners for any of the properties and the improvements they have
	for ( auto tile: board ){
		std::getline(*infile, line);
		std::stringstream ss{line};
		int position = tile->getPos();
		std::string tile_name{""};
		std::string owner{""};
		int improvements = 0;
		// it is an Academic Building
		if ( hasImprovements(position) ){
			ss >> tile_name;
			ss >> owner;
			ss >> improvements;
			tile->setNumberOfImprovements(improvements);
			for ( auto player: Players ){
				if ( player->getName() == owner ){
					tile->setOwner(player);
					std::string currBlock = tile->getBlock();
					player->addToProperties( tile->getName() );
					player->settotalValueOfProperties(tile->getPurchaseCost());
					if (currBlock == "Arts1")  {
						player->addToPropertiesOwnedInABlock(0,1);
					}else if (currBlock == "Arts2") {
						player->addToPropertiesOwnedInABlock(1,1);
					}else if (currBlock == "Eng")  {
						player->addToPropertiesOwnedInABlock(2,1);
					}else if (currBlock == "Health") {
						player->addToPropertiesOwnedInABlock(3,1);
					}else if (currBlock == "Env") {
						player->addToPropertiesOwnedInABlock(4,1);
					}else if (currBlock == "Sci1") {
						player->addToPropertiesOwnedInABlock(5,1);
					}else if (currBlock == "Sci2") {
						player->addToPropertiesOwnedInABlock(6,1);
					}else if (currBlock == "Math") {
						player->addToPropertiesOwnedInABlock(7,1);
					}
					
				}
			}
		}
		else if ( isProperty(position) ){
			ss >> tile_name;
			ss >> owner;
			ss >> improvements; 
			for ( auto player: Players ){
				if ( player->getName() == owner ){
					tile->setOwner(player);
					player->addToProperties( tile->getName() );
					player->settotalValueOfProperties(tile->getPurchaseCost());
					
				}
			}
		}
	}
}


void Board::save(std::string filename){// saves the current board. to the filename
	std::ofstream outfile{filename}; 
	outfile << Players.size() << std::endl;
	// store the players
	for ( auto player: Players ){
		int curr = player->getPos();
		// in DC Tims we got some more stuff to write
		if ( curr == 10 ){
			int times_in_tims = player->getTurnsInTimsLine();
			if ( times_in_tims > 0 ){
				outfile << player->getName() << " " << player->getSymbol() << " " << player->getRollUpTheRim() << " " << player->getFunds() << " " << player->getPos() << " " << player->getSentToTims() << " " << player->getTurnsInTimsLine() << std::endl;
			}
			else{
				outfile << player->getName() << " " << player->getSymbol() << " " << player->getRollUpTheRim() << " " << player->getFunds() << " " << player->getPos() << " " << player->getSentToTims() <<  std::endl;
			}
		}
		else{
			outfile << player->getName() << " " << player->getSymbol() << " " << player->getRollUpTheRim() << " " << player->getFunds() << " " << player->getPos() << std::endl;
		}
	}
	
	// store the tiles on the board 
	for ( auto tile: board){
		int position = tile->getPos();
		// isProperty
		if ( isProperty( position ) ){
			// Academic building
			if ( hasImprovements( position ) ){
				if ( tile->getIsMortgaged() == 1 ){
					std::shared_ptr<Player> owner = tile->getOwner();
					if ( tile->getOwner() == nullptr ) {
						outfile << tile->getName() << " " << "-1" << std::endl;
					}
					else{
						outfile << tile->getName() << " " << (tile->getOwner())->getName() << " " << "-1" << std::endl;
						}
				}
				else{
					if ( tile->getOwner() == nullptr ) {
						outfile << tile->getName() << " " << tile->getNumberOfImprovements() << std::endl;
					}
					else{
						outfile << tile->getName() << " " << (tile->getOwner())->getName() << " " << tile->getNumberOfImprovements() << std::endl;
						}
				}
			}
			// Gym or Residence
			else{
				if ( tile->getIsMortgaged() == 1 ){
					if ( tile->getOwner() == nullptr ) {
						outfile << tile->getName() << " " << "-1" << std::endl;
					}
					else{
						outfile << tile->getName() << " " << (tile->getOwner())->getName() << " " << "-1" << std::endl;
						}
					
				}
				else{
					if ( tile->getOwner() == nullptr ) {
						outfile << tile->getName() << " " << "0" << std::endl;
					}
					else{
						outfile << tile->getName() << " " << (tile->getOwner())->getName() << " " << "0" << std::endl;
						}
				}
			}
		}
		// Non property 
		else{
			std::string tile_name = nonProperty(position);
			outfile << tile_name << " " << "BANK" << std::endl;
		}
	}
}

void Board::move(std::shared_ptr<Player> curr_player, std::string Name){ // sets the given Player's position to the DC Tims Line, Collect OSAP
	int curr_pos = curr_player->getPos();
	if ( Name == "DC Tims Line" ){
		curr_player->setPosition(board.at(10));
		curr_player->setPos(10);
		// notify td
		std::shared_ptr<Tile> temp = board.at(10);
		int num = numOfPlayersOnTile(temp);
		this->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player->getSymbol(), curr_pos, curr_player->getPos(), num);
	}
	else if ( Name == "Collect OSAP" ){
		curr_player->setPosition(board.at(0));
		curr_player->setPos(0);
		std::shared_ptr<Tile> temp = board.at(0);
		int num = numOfPlayersOnTile(temp);
		this->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player->getSymbol(), curr_pos, curr_player->getPos(), num);
	}
}

void Board::move(std::shared_ptr<Player> curr_player, int i ){ // set the player's position using the setPosition method in Player
	// get the current position of the player
	int index = curr_player->getPos(); 
	// Add or subtract from the value
	int new_position = index + i;
	if ( new_position > 39 ){
		new_position = new_position - 40; 
	}
	if ( new_position < 0 ){
		new_position = 40 + new_position;
	}
	// find the tile with that position and move the player there
	for ( auto tile: board ){
			if ( tile->getPos() == new_position ){
				curr_player->setPosition(tile);
				curr_player->setPos(new_position);
			}
	}
	
	
	std::shared_ptr<Tile> temp = curr_player->getPosition();
	int num = numOfPlayersOnTile(temp);
	this->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player->getSymbol(), index, curr_player->getPos(), num);
}


bool Board::canBuy(std::string Name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player){ // only check if it is a property or not. 
	// if the player wants to buy the tile they are on
	if ( curr_player->getPosition() == tile ){
		if ( isProperty(Name) ){
			return true;
		}
		else{
			return false;
		}
	}
	// else the player is trying to sell a property but they are not on it
	else{
		if ( isProperty(Name) ){
			return true;
		}
		else{
			return false;
		}
	}
}

/*
void Board::buyProperty(std::string Name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player){
	if ( tile->getOwner() != nullptr ){
		throw GameException("This property is owned!");
	}
	else if ( !isProperty( tile->getPos()) ){
		throw GameException("This is a non property!");
	}
	// check if the tile is an academic tile
	if ( hasImprovements( tile->getPos() ) ){
		std::string currBlock = tile->getBlock();
		curr_player->addToProperties( tile->getName() );
		curr_player->settotalValueOfProperties(tile->getPurchaseCost());
		if (currBlock == "Arts1")  {
			curr_player->addToPropertiesOwnedInABlock(0,1);
		}else if (currBlock == "Arts2") {
			curr_player->addToPropertiesOwnedInABlock(1,1);
		}else if (currBlock == "Eng")  {
			curr_player->addToPropertiesOwnedInABlock(2,1);
		}else if (currBlock == "Health") {
			curr_player->addToPropertiesOwnedInABlock(3,1);
		}else if (currBlock == "Env") {
			curr_player->addToPropertiesOwnedInABlock(4,1);
		}else if (currBlock == "Sci1") {
			curr_player->addToPropertiesOwnedInABlock(5,1);
		}else if (currBlock == "Sci2") {
			curr_player->addToPropertiesOwnedInABlock(6,1);
		}else if (currBlock == "Math") {
			curr_player->addToPropertiesOwnedInABlock(7,1);
		}
	}
}
*/



void Board::buyImprovements(std::string name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player){
	if ( !isProperty( tile->getPos()) ){
		throw GameException("This is a non property!");
	}
	if ( curr_player->ownProperty(name) ){
		curr_player->settotalValueOfProperties(tile->getImprovementCost());
		std::string currBlock = tile->getBlock();
		if ((currBlock == "Arts1") && (curr_player->getPropertiesOwnedInABlock(0) == 2)) {
			tile->buyImprovement(curr_player, *this);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), tile->getNumberOfImprovements());
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if ((currBlock == "Arts2") && (curr_player->getPropertiesOwnedInABlock(1) == 3)) {
			tile->buyImprovement(curr_player,*this);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), tile->getNumberOfImprovements());
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if ((currBlock == "Eng") && (curr_player->getPropertiesOwnedInABlock(2) == 3)) {
			tile->buyImprovement(curr_player,*this);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), tile->getNumberOfImprovements());
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if ((currBlock == "Health") && (curr_player->getPropertiesOwnedInABlock(3) == 3)) {
			tile->buyImprovement(curr_player,*this);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), tile->getNumberOfImprovements());
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if ((currBlock == "Env") && (curr_player->getPropertiesOwnedInABlock(4) == 3)) {
			tile->buyImprovement(curr_player,*this);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), tile->getNumberOfImprovements());
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if ((currBlock == "Sci1") && (curr_player->getPropertiesOwnedInABlock(5) == 3)) {
			tile->buyImprovement(curr_player,*this);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), tile->getNumberOfImprovements());
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if ((currBlock == "Sci2") && (curr_player->getPropertiesOwnedInABlock(6) == 3)) {
			tile->buyImprovement(curr_player,*this);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), tile->getNumberOfImprovements());
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if ((currBlock == "Math") && (curr_player->getPropertiesOwnedInABlock(7) == 3)) {
			tile->buyImprovement(curr_player, *this);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), tile->getNumberOfImprovements());
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		} else {
			throw GameException("You don't own enough buildings from the block to buy improvements");
		}
	} else {
	throw GameException("You don't own the builing so you can't buy any improvements"); 
	}
}

void Board::sellImprovements(std::string name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player){
	if ( !isProperty( tile->getPos()) ){
		throw GameException("This is a non property!");
	}
	if (curr_player->ownProperty(name)){
		curr_player->settotalValueOfProperties(-tile->getImprovementCost());
		std::string currBlock = tile->getBlock();
		if (currBlock == "Arts1") {
			tile->sellImprovement(curr_player);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), -1);
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if (currBlock == "Arts2")  {
			tile->sellImprovement(curr_player);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), -1);
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if (currBlock == "Eng") {
			tile->sellImprovement(curr_player);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), -1);
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if (currBlock == "Health") {
			tile->sellImprovement(curr_player);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), -1);
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if (currBlock == "Env") {
			tile->sellImprovement(curr_player);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), -1);
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if (currBlock == "Sci1")  {
			tile->sellImprovement(curr_player);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), -1);
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if (currBlock == "Sci2")  {
			tile->sellImprovement(curr_player);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), -1);
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}else if (currBlock == "Math")  {
			tile->sellImprovement(curr_player);
			this->notifyObservers(tile->getX(), tile->getY(), tile->getPos(), -1);
			//curr_player->notifyObservers(curr_player->getX(), curr_player->getY(), curr_player);
		}
	} else {
	throw GameException("You don't own the builing therefore you can't sell improvements!!");
	}
}


void Board::mortgage(std::string name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player){
	if ( !isProperty( tile->getPos()) ){
		throw GameException("This is a non property!");
	}
	if (!(curr_player->ownProperty(name))){
	throw GameException("You dont own this property, you can't mortage it!");
	} else {
	tile->mortgage(curr_player);
	curr_player->settotalValueOfProperties(-tile->getPurchaseCost());
	if ( hasImprovements( tile->getPos() ) ){
		std::string currBlock = tile->getBlock();
		if (currBlock == "Arts1")  {
			curr_player->addToPropertiesOwnedInABlock(0,-1);
		}else if (currBlock == "Arts2") {
			curr_player->addToPropertiesOwnedInABlock(1,-1);
		}else if (currBlock == "Eng")  {
			curr_player->addToPropertiesOwnedInABlock(2,-1);
		}else if (currBlock == "Health") {
			curr_player->addToPropertiesOwnedInABlock(3,-1);
		}else if (currBlock == "Env") {
			curr_player->addToPropertiesOwnedInABlock(4,-1);
		}else if (currBlock == "Sci1") {
			curr_player->addToPropertiesOwnedInABlock(5,-1);
		}else if (currBlock == "Sci2") {
			curr_player->addToPropertiesOwnedInABlock(6,-1);
		}else if (currBlock == "Math") {
			curr_player->addToPropertiesOwnedInABlock(7,-1);
		}
	}
	}
}



void Board::unmortgage(std::string name, std::shared_ptr<Tile> tile, std::shared_ptr<Player> curr_player){
	if ( !isProperty( tile->getPos()) ){
		throw GameException("This is a non property!");
	}
	if (!(curr_player->ownProperty(name))){
	throw GameException("You dont own this property, you can't mortage it!");
	} else {
	tile->unmortgage(curr_player,*this);
	curr_player->addToProperties(name);
	curr_player->settotalValueOfProperties(tile->getPurchaseCost());
	if ( hasImprovements( tile->getPos() ) ){
		std::string currBlock = tile->getBlock();
		if (currBlock == "Arts1")  {
			curr_player->addToPropertiesOwnedInABlock(0,1);
		}else if (currBlock == "Arts2") {
			curr_player->addToPropertiesOwnedInABlock(1,1);
		}else if (currBlock == "Eng")  {
			curr_player->addToPropertiesOwnedInABlock(2,1);
		}else if (currBlock == "Health") {
			curr_player->addToPropertiesOwnedInABlock(3,1);
		}else if (currBlock == "Env") {
			curr_player->addToPropertiesOwnedInABlock(4,1);
		}else if (currBlock == "Sci1") {
			curr_player->addToPropertiesOwnedInABlock(5,1);
		}else if (currBlock == "Sci2") {
			curr_player->addToPropertiesOwnedInABlock(6,1);
		}else if (currBlock == "Math") {
			curr_player->addToPropertiesOwnedInABlock(7,1);
		}
	}
	}
}

void Board::trade(std::string give, std::string recieve,std::shared_ptr<Tile> tile1, std::shared_ptr<Tile> tile2, std::shared_ptr<Player> me, std::shared_ptr<Player> otherPlayer){
	std::stringstream ss;
	ss << give;
	double giveDouble;
	std::stringstream mm;
	mm << recieve;
	double recieveDouble;
	if(ss >> giveDouble){
		if(! (otherPlayer->ownProperty(recieve))) {
			throw GameException(" You are trading and trying to receive something the player doesn't even have, THIS IS INVALID!!");
			}
			
			else if (tile1->getNumberOfImprovements() !=	0) {
				throw GameException("You can't trade if you have improvements, what is wrong with you?!");
			}
		else {
				otherPlayer->addToFunds(giveDouble);
				me->removeFromFunds(giveDouble);
				me->addToProperties(recieve);
				otherPlayer->removeFromProperties(recieve);
				tile1->setOwner(me);
			
		}}
	mm  << recieve;
	if(mm >> recieveDouble){
	if (!(me->ownProperty(give))){
		throw GameException(" You are trying to trade for something that you dont have, please don't do that again");
	}
	else if (tile1->getNumberOfImprovements() != 0) {
		throw GameException("You can't trade if you have improvements, what is wrong with you?!");
		}else {
			otherPlayer->removeFromFunds(recieveDouble);
			me->addToFunds(recieveDouble);
			otherPlayer->addToProperties(give);
			me->removeFromProperties(give);
			tile1->setOwner(otherPlayer);
			}
	} else {
		if ( hasImprovements(tile1->getPos()) && hasImprovements(tile2->getPos()) ){
			if ((tile1->getNumberOfImprovements() != 0) || (tile2->getNumberOfImprovements() != 0)) {
			throw GameException("You can't trade if you have improvements, what is wrong with you?!");
		} 
		}
	  otherPlayer->addToProperties(give);
	  me->removeFromProperties(give);
	  me->addToProperties(recieve);
	  otherPlayer->removeFromProperties(recieve);
	  tile1->setOwner(otherPlayer);
	  tile2->setOwner(me);
	  }
}


void Board::roll(int d1, int d2){
	addPlayer("D", "Tester", board.at(0) , 0, 82, 0);
	std::cout << "Hello to testing mode Tester" << std::endl;
	int sum = d1 + d2; 
	std::cout << "Your roll is : " << sum << std::endl;
	int new_pos = Curr_Player->getPos() + sum;
	std::shared_ptr<Dice> d = std::make_shared<Dice>();
	while ( new_pos > 39 ){
		std::shared_ptr<Tile> t = board.at(0);
		t->landed(Curr_Player, *d, *this);
		Curr_Player->setPos(new_pos);
		Curr_Player->setPosition(t);
		new_pos -= 40;
	}
	std::shared_ptr<Tile> t = board.at(new_pos);
	t->landed(Curr_Player, *d, *this);
	if ( t->getName() != "SLC" && t->getName() != "Go To Tims" ){
		int num = numOfPlayersOnTile(t);
		this->notifyObservers(Curr_Player->getX(), Curr_Player->getY(), Curr_Player->getSymbol(), Curr_Player->getPos(), new_pos, num);
		Curr_Player->setPos(new_pos);
		Curr_Player->setPosition(t);
	}
	
}

void Board::createBids(std::map<std::shared_ptr<Player>,double> & bids){
	for ( auto player: Players ){
		if ( Curr_Player != player ){
			bids[player] = 0;
		}
	}
}


void Board::printBids(std::map<std::shared_ptr<Player>,double>& bids){
	for (auto& x:bids){
		std::string p_char = (x.first)->getSymbol();
		std::cout << "Player : " << p_char << "'s bid: " << x.second << std::endl;
	}
}




void Board::auction(Tile* tile){
	std::cout << "///////////// START AUCTION /////////////" << std::endl; 
	std::cout << " Property Cost/ Initial bid: " << tile->getPurchaseCost() << std::endl;
	// create a map called bids
	std::map<std::shared_ptr<Player>, double> bids;
	// Initialize this map 
	createBids(bids);
	
	if ( bids.size() == 1 ){
		std::string line1{""};
		std::cout << "Player: " << ((bids.begin())->first)->getSymbol() << std::endl;
		std::cout << "Would you like to place a bid?" << std::endl; 
		std::cout << " Enter y/n ? " << std::endl; 
		std::getline(std::cin, line1);
		if ( line1 == "y" ) {
			std::string line;
			std::cout << "Enter bid value: " << std::endl;
			std::getline(std::cin, line);
			std::stringstream ss(line); 
			int num;
			ss >> num;
			auto it = (bids.begin());
			(*it).second = num;
		}
		else{
			auto it = (bids.begin());
			bids.erase(it);
		}
	}
	
	
	else{
		while ( bids.size() >= 2 ){
			for ( auto &player: bids ){
				//if ( bids.size() == 1 ){ break; }
				std::cout << "Player: " << (player.first)->getSymbol() << std::endl;
				std::cout << "Would you like to place a bid?" << std::endl; 
				std::cout << " Enter y/n ? " << std::endl; 
				std::string line1;
				std::getline(std::cin, line1);
				if ( line1 == "y" ) {
					std::string line;
					std::cout << "Enter bid value: " << std::endl;
					std::getline(std::cin, line);
					std::stringstream ss(line); 
					int num;
					ss >> num;
					player.second = num;
				}
				else{
					auto it = bids.find(player.first);
					bids.erase(it);
				}
				
			}
		
		printBids(bids);
		}
	}
	if ( bids.size() == 1 ){
		auto it = bids.begin();
		std::cout << "**************** AUCTION WINNER ****************" << std::endl;
		std::cout << ((*it).first)->getSymbol() << " " << (*it).second << std::endl;
		tile->buyProperty((*it).first,*this);
		double leftover = (*it).second - tile->getPurchaseCost();
		((*it).first)->removeFromFunds(leftover);
		if ( ((*it).first)->getBankrupt() ){
			std::cout << "You are bankrupt" << std::endl;
			tile->setOwner(nullptr);
			this->Bankrupt(((*it).first), nullptr, ((*it).second) );
		}
		else{
			tile->setOwner((*it).first);
		}
	}
}

void Board::setSeed(int i){
	if ( i > 0 ){
		srand(i);
	}
	else{
		srand(time(NULL));
	}
}


void Board::Bankrupt(std::shared_ptr<Player> bankrupt, std::shared_ptr<Player> receiver, double amount){
	std::cout << "Would you like to sell all of your properties and improvements? Enter yes/no: " << std::endl;
	std::string line;
	std::getline(std::cin, line);
	if ( line == "yes" ){
		std::cout << "Selling all improvements and properties" << std::endl;
		// sell all of the improvements and properties the player owns
		std::vector<std::string> properties = bankrupt->getProperties();
		for ( auto prop: properties ){
			std::cout << "First Property: " << prop << std::endl;
			std::shared_ptr<Tile> tile;
			// get the tile
			tile = getTile(prop);
			int pos = tile->getPos();
			// Academic Building sell the improvements
			if ( hasImprovements( pos ) ){
				sellImprovements(line, tile, bankrupt);
			}
			int isMort = tile->getIsMortgaged();
			// it is unmortgaged
			if ( isMort == -1 ){
				mortgage(prop, tile, bankrupt);
			}
		}
		// check if the player can pay
		double p_funds = bankrupt->getFunds();
		if ( p_funds < amount ){
			// they can't stay in the game anymore
			std::cout << "You are still bankrupt and out of the game" << std::endl;
			this->removePlayer(bankrupt);
		}
	}
	// we owe money to someone else
	if ( receiver != nullptr ){
		std::cout << "Paying off your debt to Player: " << receiver->getName() << std::endl;
		std::vector<std::string> properties = bankrupt->getProperties();
		for ( auto prop: properties ){
			std::shared_ptr<Tile> temp = getTile(prop);
			// remove owner
			temp->setOwner(nullptr);
			// "buy" the property
			temp->buyProperty(receiver, *this);
			double amount = temp->getPurchaseCost();
			receiver->addToFunds(amount);
			amount = amount * 0.1;
			double curr_funds = receiver->getFunds();
			// check if the property is mortgaged
			if ( temp->getIsMortgaged() == 0 ){
				curr_funds -= amount;
				if ( curr_funds < 0 ){
					receiver->setBankrupt(true);
					this->Bankrupt(receiver, nullptr, amount);
				}
				else{
					// successfully have the property
					receiver->removeFromFunds(amount);
					std::cout << "This property was mortgaged, do you want to keep it that way? Enter yes/no: " << std::endl;
					std::string line;
					std::getline(std::cin, line);
					// keep it mortgaged
					if ( line == "yes" ){
						amount = (temp->getPurchaseCost()) * 0.1;
						curr_funds = receiver->getFunds();
						curr_funds -= amount;
						if ( curr_funds < 0 ){
							receiver->setBankrupt(true);
							this->Bankrupt(receiver, nullptr, amount);
						}
						else{
							receiver->removeFromFunds(amount);
						}
					}
					
					// keep it mortgaged
					else{
						// chose to unmortgage the property 
						amount = (temp->getPurchaseCost()) * 0.5;
						curr_funds = receiver->getFunds();
						curr_funds -= amount;
						if ( curr_funds < 0 ){
							receiver->setBankrupt(true);
							this->Bankrupt(receiver, nullptr,amount);
						}
						else{
							// remove the value from the funds
							receiver->removeFromFunds(amount);
						}
					}
				}
			}
		}
		removePlayer(bankrupt);
	}
	else{
	// we owe money to the bank
	// all assets are returned to the bank as unmortgaged properties and all cups destroyed
	// set number of improvements as 0 
	std::vector<std::string> properties = bankrupt->getProperties();
	for ( auto prop: properties ){
		std::shared_ptr<Tile> temp = getTile(prop);
		// if it is an academic building
		if ( hasImprovements(temp->getPos()) ){
			// sell the improvements first
				int num_of_improv = temp->getNumberOfImprovements();
				while ( num_of_improv > 0 ){
					temp->sellImprovement(bankrupt);
				}
			// set the owner to nullptr
			temp->setOwner(nullptr);
			
			// set the mortgage flag
			temp->setIsMortgaged(-1);
		}
		else{
			// it's a gym or a residence
			temp->setOwner(nullptr);
			temp->setIsMortgaged(-1);
		}
		// auction them off
		this->auction(&*(getTile(prop)));
		removePlayer(bankrupt);
	}
	}
}





