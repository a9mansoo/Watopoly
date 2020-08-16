#include "collectosap.h"

CollectOSAP::CollectOSAP(int x, int y, int pos): x{x}, y{y}, pos{pos}, cost{200} {}

void CollectOSAP::landed(std::shared_ptr<Player> p, Dice& d, Board& b) {
	p->setPos(pos);
	if (p->getCollect() == true) {
		p->addToFunds(cost);
		std::cout << "Passed or Landed on CollectOsap, 200$ were added to your account." << std::endl;
	} else {
		std::cout << "You are not allowed to collect OSAP this turn :(" << std::endl;
	}
}

int CollectOSAP::getX(){
	return x;
}

int CollectOSAP::getPos(){
	return pos;
}

int CollectOSAP::getY(){
	return y;
}


std::string CollectOSAP::getName() {
	return "CollectOSAP";
}



