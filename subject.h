#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>


class Observer;

class Subject {
	// A player is a subject, so each player has one observer, the board. 
	// can add the various textdisplay observers to display different updated displays. 
	std::vector<std::shared_ptr<Observer>> observers;
  public:
	// attach the board as an observer, meaning add it to the list
    virtual void attach(std::shared_ptr<Observer> );
    virtual void notifyObservers(int x, int y, std::string player, int prev_pos, int new_pos, int numberOfPlayers ) = 0; 
	virtual void notifyObservers(int x, int y, int pos, int numberOnTile) = 0;
};

#endif

