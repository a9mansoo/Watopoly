#include "board.h"
#include "dctimsline.h"
#include <iostream>
using namespace std;

dcTimsLine::dcTimsLine(int x, int y, int pos) : x{x}, y{y}, pos{pos} {}

int dcTimsLine::getX(){
	return x;
}

int dcTimsLine::getY(){
	return y;
}
int dcTimsLine::getPos(){
	return pos;
}


std::string dcTimsLine::getName() {
	return "DC Tims Line";
}

void dcTimsLine::landed(std::shared_ptr<Player> p, Dice &d, Board& b) {
	p->setPos(pos);
	int dice1val = d.getValue();
	int dice2val = d.getValue();
	cout << "You have rolled" << dice1val << "and" << dice2val <<std::endl;
	std::string command;
	while (true) {
		
	if (p->getSentToTims()) {
		cout << "You were sent to DC Tim Line" << endl;
		cout << "You have rolled" << dice1val << "and" << dice2val <<std::endl;
		
		if (dice1val == dice2val) {
			p->setSentToTims(false);
			p->setTurnsInTimsLine(0);
			cout << "Congratulations, you got a double roll! You may leave the DC Tims line next turn, See ya later" << std::endl;
			break;
		} 
		else if (p->getTurnsInTimsLine() == 3) {
          cout << "Since this is your third time landing in the DC Tims line,  you MUST pay $50 or  use a rollUpTheRimCard right now " << endl;
		  cout << "You currently have " << p->getRollUpTheRim() << " number of roll up the rim cups" << std::endl;
		  cout << "Type the command: 'pay' to pay $50 and command: 'cup' to use the roll up the rim cup only if you have greater than 0 up the rim cups" << std::endl;
			std::getline(cin,command);
		    if (command == "pay"){
				p->removeFromFunds(50);
				if ( p->getBankrupt() ){
					std::cout << "You are bankrupt" << std::endl;
					b.Bankrupt(p, nullptr,50);
				}
				else{
					p->setSentToTims(false);
					p->setTurnsInTimsLine(0);
					cout << "you are allowed to leave on your next turn, See ya later" << std::endl;
					break;
				}
			}
			 else if (command == "cup"){
				p->setRollUpTheRim(-1);
				p->setSentToTims(false);
				p->setTurnsInTimsLine(0);
				cout << "you are allowed to leave on your next turn, See ya later" << std::endl;
				break;
			} 
		} else {
		cout << "This is your: " << p->getTurnsInTimsLine() << endl;
		cout << "You can leave by rolling doubles or by paying $50" << std::endl;
		cout << "Type the command: 'pay' to pay $50 and command: 'cup' to use the roll up the rim if you have any roll up the rim cups, or the command; 'N' if you are not planning to stay for now" << std::endl;
		cin >> command;
		    if (command == "pay"){
				p->removeFromFunds(50);
				if ( p->getBankrupt() ){
					std::cout << "You are bankrupt" << std::endl;
					b.Bankrupt(p, nullptr,50);
				}
				else{
					p->setSentToTims(false);
					p->setTurnsInTimsLine(0);
					cout << "you are allowed to leave on your next turn, See ya later" << std::endl;
					break;
				}
			}
			 else if (command == "cup"){
				p->setRollUpTheRim(-1);
				p->setSentToTims(false);
				p->setTurnsInTimsLine(0);
				cout << "you are allowed to leave on your next turn, See ya later" << std::endl;
				break;
			} else if (command == "N"){
				p->addTurnsInTimsLine();
				break;
			}
		}
	  } else {
		  cout << "You are just visiting DC Tims Line" << std::endl;
		  break;
	  }
  }
}





