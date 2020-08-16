#ifndef DCTIMSLINE_H
#define DCTIMSLINE_H
#include "nonproperty.h"

class dcTimsLine : public NonProperty {
	// Position
	int x;
	int y;
	int pos;
	public:
	dcTimsLine(int , int, int );
    virtual void landed (std::shared_ptr<Player>, Dice &, Board &);
	virtual int getX() override;
	virtual int getY() override;
	virtual std::string getName() override;
	virtual int getPos() override;

};


#endif


