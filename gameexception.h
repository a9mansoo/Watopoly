#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H
#include <string>
#include <exception>

class GameException: std::exception{
	const char* message;
public:
	GameException(const char * );
	virtual const char * what() const noexcept override;

};

#endif

