#ifndef SLC_H
#define SLC_H
#include <sstream>
#include <string>
#include "nonproperty.h"

class SLC: public NonProperty {
	int x;
	int y;
	int pos;
public:
	SLC(int , int, int);
	virtual int getX() override;
	virtual int getY() override;
	virtual int getPos() override;
	virtual std::string getName() override;
	int RandomNumberGenerator(int );
	virtual void landed(std::shared_ptr<Player>, Dice&, Board& ) override; 

};

#endif




