#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H
#include <string> 
#include <memory>
#include <iostream>
#include <vector>
#include "player.h"
#include "observer.h"

class Player;

class TextDisplay: public Observer {
	std::string r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30, r31, r32, r33, r34, r35, r36, r37, r38, r39, r40, r41, r42, r43, r44, r45, r46, r47, r48,
				r49, r50, r51, r52, r53, r54, r55, r56, r57, r58, r59, r60, r61, r62, r63, r64, r65, r66, r67, r68, r69, r70, r71, r72, r73, r74, r75, r76, r77, r78,r79, r80, r81, r82, r83, r84, r85;
	std::vector<std::string>::iterator it;
	std::vector<std::string> td;
	public: 
	TextDisplay();
	~TextDisplay();
	// Adds the improvement number on the given academic tile
	void addImprovementsToTile(int x, int y, int pos, int numOfImprovements);
	
	// Removes the improvement number on the given academic tile
	void removeImprovementsFromTile(int x, int y, int pos, int numOfImprovements);
	// Draws the full board
	void printMyCurrentBoard();
	// Updates the position of the Player on the board after a roll
	void addPlayerToTile(int x, int y, int pos,  int prevPos, std::string symbol, int numPlayersOnThisTile, std::shared_ptr<Player> p);


};

#endif


