#ifndef TUITION_H_
#define TUITION_H_
#include "nonproperty.h"
#include <iostream>
#include <sstream>
#include <string>

class Tuition: public NonProperty{
	int x;
	int y;
	int pos;
	double cost;
public:
	Tuition(int x, int y, int pos);
	virtual void landed(std::shared_ptr<Player>, Dice &, Board &) override;
	virtual int getX() override;
	virtual int getY() override;
	virtual std::string getName() override;
	virtual int getPos() override;
};
	
#endif






