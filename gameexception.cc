#include "gameexception.h"

GameException::GameException(const char * Exception): message{Exception}{}


const char * GameException::what() const noexcept{
	return message;
}

