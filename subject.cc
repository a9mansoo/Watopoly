#include "subject.h"


void Subject::attach( std::shared_ptr<Observer> observer ){
	observers.push_back(observer);
}

/*
void Subject::notifyObservers(int x, int y, std::shared_ptr<Subject> p){
	for ( auto ob: observers ){
		ob->notify(x, y, p );
	}
}
*/

