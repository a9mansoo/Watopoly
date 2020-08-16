#include "board.h"
#include "slc.h"
#include <stdlib.h>     /* srand, rand */
#include <cstdlib>

using namespace std;

SLC::SLC(int x, int y, int pos) : x{x}, y{y}, pos{pos} {}


int SLC::getX(){
	return x;
}

int SLC::getY(){
	return y;
}

int SLC::getPos(){
	return pos;
}


std::string SLC::getName() {
	return "SLC";
}

// Generates the random number to extract from the nonproperty values of 
	int SLC::RandomNumberGenerator(int i){
		// set the seed
		srand (time(NULL));
		int probability = rand() % i; 
		return probability;
		
	}


void SLC::landed(std::shared_ptr<Player> p, Dice &d, Board &b) {
    cout << "You are currently at SLC." << endl;
    p->setPos(pos);
    // calculate rare chance if player receives roll up the rim cup 

    int index = RandomNumberGenerator(26);

    if (index == 25 && b.getActiveRollUpRim() < 4) {
        // check total number of cups on the board 
            cout << "Congratulations! You have won a Roll up the Rim cup!" << endl;
            p->setRollUpTheRim(1);
            b.setActiveRollUpRim(1);
    }
	else{
		index = RandomNumberGenerator(25);
		std::string amount = getSLCMoveGenerator(index);
		if ( amount[0] == 'B' ){
			cout << amount << endl;
			amount = amount.substr(5,amount.length());
			std::stringstream num(amount);
			int index;
			num >> index;
			b.move(p, -index);
			
		}
		else if ( amount[0] == 'F' ){
			cout << amount << endl;
			amount = amount.substr(7,amount.length());
			std::stringstream num(amount);
			int index;
			num >> index;
			b.move(p, index);
		}
		else if ( amount[0] == 'G' ){
			cout << amount << endl;
			amount = amount.substr(5,amount.length());
			b.move(p, amount);
		}
		else if ( amount[0] == 'A' ){
			cout << amount << endl;
			amount = amount.substr(11, amount.length());
			b.move(p, amount);
		}
	}
    // 25 tiles in SLC though
   

}






