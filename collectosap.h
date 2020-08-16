#ifndef CollectOSAP_H_
#define CollectOSAP_H_
#include "nonproperty.h"
#include <iostream>
#include <string>

class CollectOSAP: public NonProperty{
	// position
	int x;
	int y;
	int pos;
	double cost;
public:
	CollectOSAP(int , int, int );
	virtual void landed(std::shared_ptr<Player>, Dice &, Board &) override;
	virtual int getX() override;
	virtual int getY() override;
	virtual int getPos() override;
	virtual std::string getName() override;
};
#endif



