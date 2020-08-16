#include "textdisplay.h"
using namespace std;



TextDisplay::TextDisplay() {
	                   //01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678
       std::string r1 = "|------------|------------|------------|------------|------------|------------|------------|------------|------------|-------------|-------------|";
       std::string r2 = "|Goose       |            |NEEDLES     |            |            | V1         |            |            |CIF         |             |GO TO        |";
       std::string r3 = "|Nesting     |____________|HALL        |____________|____________|            |____________|____________|            |_____________|TIMS         |";
       std::string r4 = "|            |EV1         |            |EV2         |EV3         |            |PHYS        |B1          |             B2           |             |";
	   std::string r5 = "|            |            |            |            |            |            |            |            |            |             |             |";
	   std::string r6 = "|            |            |            |            |            |            |            |            |            |             |             |";
	   std::string r7 = "|            |            |            |            |            |            |            |            |            |             |             |";
	   std::string r8 = "|            |            |            |            |            |            |            |            |            |             |             |";
	   std::string r9 = "|------------|------------|------------|------------|------------|------------|------------|------------|------------|-------------|-------------|";
	   std::string r10 ="|            |                                                                                                                     |             |";
	   std::string r11 ="|____________|                                                                                                                     |_____________|";
	   std::string r12= "|OPT         |                                                                                                                     |EIT          |";
	   std::string r13= "|            |                                                                                                                     |             |";
	   std::string r14 ="|            |                                                                                                                     |             |";
	   std::string r15 ="|            |                                                                                                                     |             |";
	   std::string r16= "|            |                                                                                                                     |             |";
	   std::string r17= "|------------|                                                                                                                     |-------------|";
	   std::string r18 ="|            |                                                                                                                     |             |";
	   std::string r19= "|____________|                                                                                                                     |_____________|";
	   std::string r20 ="|BMH         |                                                                                                                     |ESC          |";
	   std::string r21= "|            |                                                                                                                     |             |";
	   std::string r22= "|            |                                                                                                                     |             |";
	   std::string r23 ="|            |                                                                                                                     |             |";
	   std::string r24 ="|            |                                                                                                                     |             |";
	   std::string r25 ="|------------|                                                                                                                     |-------------|";
	   std::string r26= "|SLC         |                                                                                                                     |SLC          |";
	   std::string r27 ="|            |                                                                                                                     |             |";
	   std::string r28= "|            |                                                                                                                     |             |";
	   std::string r29= "|            |                                                                                                                     |             |";
	   std::string r30= "|            |               |------------------------------------------------------------------------------------|                |             |";
	   std::string r31= "|------------|               | #        #     ##   ########     ####    #####       ####    #       #       #     |                |-------------|";
	   std::string r32 ="|            |               | #        #    #  #     #        #    #   #    #     #    #   #       #       #     |                |             |";
	   std::string r33= "|____________|               | #        #   #    #    #       #      #  #    #    #      #  #       #       #     |                |_____________|";
	   std::string r34= "|LHI         |               | #        #   #    #    #       #      #  #    #    #      #  #        #     #      |                |C2           |";
	   std::string r35= "|            |               | #        #   ######    #       #      #  #####     #      #  #         #   #       |                |             |";
	   std::string r36= "|            |               | #        #   #    #    #       #      #  #         #      #  #          # #        |                |             |";
	   std::string r37 ="|            |               | #   #    #   #    #    #       #      #  #         #      #  #           #         |                |             |";
	   std::string r38= "|            |               | #   #    #   #    #    #       #      #  #         #      #  #           #         |                |             |";
	   std::string r39 ="|------------|               | #   #    #   #    #    #        #    #   #          #    #   #           #         |                |-------------|";
	   std::string r40 ="|UWP         |               | ##########   #    #    #         ####    #           ####    ########    #         |                |REV          |";
	   std::string r41 ="|            |               |                                                                                    |                |             |";
	   std::string r42= "|            |               |------------------------------------------------------------------------------------|                |             |";
	   std::string r43= "|            |                                                                                                                     |             |";
	   std::string r44= "|            |                                                                                                                     |             |";
	   std::string r45= "|            |                                                                                                                     |             |";
	   std::string r46= "|____________|                                                                                                                     |_____________|";
	   std::string r47= "|            |                               #############################################                                         |NEEDLES      |";
	   std::string r48= "|____________|                              # #                                          #                                         |HALL         |";
	   std::string r49= "|CPH         |                             #   #                                         #                                         |             |";
	   std::string r50= "|            |                            #     #                                        #                                         |             |";
	   std::string r51= "|            |                           #       #                                       #                                         |             |";
	   std::string r52= "|            |                          #         #                                      #                                         |             |";
	   std::string r53= "|            |                          ##################################################                                         |             |";
	   std::string r54= "|------------|                          #           #                                    #                                         |-------------|";
	   std::string r55= "|            |                          #           #   ####                   ####      #                                         |             |";
	   std::string r56= "|____________|                          #           #   #  #                   #  #      #                                         |_____________|";
	   std::string r57= "|DWE         |                          #           #   ####                   ####      #                                         |MC           |";
	   std::string r58= "|            |                          #           #                                    #                                         |             |";
	   std::string r59= "|            |                          #           #                                    #                                         |             |";
	   std::string r60= "|            |                          #           #                                    #                                         |             |";
	   std::string r61= "|            |                          #           #                                    #                                         |             |";
	   std::string r62= "|------------|                          #           #           #######                  #                                         |-------------|";
	   std::string r63= "|PAC         |                          #           #           #     #                  #                                         |COOP         |";
	   std::string r64= "|            |                          #           #           #     #                  #                                         | FEE         |";
	   std::string r65= "|            |                          ##################################################                                         |             |";
	   std::string r66= "|            |                                                                                                                     |             |";
	   std::string r67= "|            |                                                                                                                     |             |";
	   std::string r68= "|            |                                                                                                                     |             |";
	   std::string r69= "|____________|                                                                                                                     |_____________|";
	   std::string r70= "|            |                                                                                                                     |             |";
	   std::string r71= "|____________|                                                                                                                     |_____________|";
	   std::string r72= "|RCH         |                                                                                                                     |DC           |";
	   std::string r73= "|            |                                                                                                                     |             |";
	   std::string r74 ="|            |                                                                                                                     |             |";
	   std::string r75= "|            |                                                                                                                     |             |";
	   std::string r76= "|            |                                                                                                                     |             |";
	   std::string r77= "|------------|------------|------------|------------|------------|------------|------------|------------|------------|-------------|-------------|";
	   std::string r78= "|DC Tims     |            |            |NEEDLES     |            |MKV         |TUITION     |            |SLC         |             |Collect      |";
       std::string r79= "|Line        |____________|____________|HALL        |____________|            |            |____________|            |_____________|Osap         |";
       std::string r80= "|            |HH          |PAS         |            |ECH         |            |            |ML          |            |AL           |             |";
	   std::string r81= "|            |            |            |            |            |            |            |            |            |             |             |";
	   std::string r82= "|            |            |            |            |            |            |            |            |            |             |             |";
	   std::string r83= "|            |            |            |            |            |            |            |            |            |             |             |";
	   std::string r84= "|            |            |            |            |            |            |            |            |            |             |             |";
	   std::string r85= "|------------|------------|------------|------------|------------|------------|------------|------------|------------|-------------|-------------|";
	   
	   td.push_back(r1);
	   td.push_back(r2);
	   td.push_back(r3);
	   td.push_back(r4);
	   td.push_back(r5);
	   td.push_back(r6);
	   td.push_back(r7);
	   td.push_back(r8);
	   td.push_back(r9);
	   td.push_back(r10);
	   td.push_back(r11);
	   td.push_back(r12);
	   td.push_back(r13);
	   td.push_back(r14);
	   td.push_back(r15);
	   td.push_back(r16);
	   td.push_back(r17);
	   td.push_back(r18);
	   td.push_back(r19);
	   td.push_back(r20);
	   td.push_back(r21);
	   td.push_back(r22);
	   td.push_back(r24);
	   td.push_back(r25);
	   td.push_back(r26);
	   td.push_back(r27);
	   td.push_back(r28);
	   td.push_back(r29);
	   td.push_back(r30);
	   td.push_back(r31);
	   td.push_back(r32);
	   td.push_back(r33);
	   td.push_back(r34);
	   td.push_back(r35);
	   td.push_back(r36);
	   td.push_back(r37);
	   td.push_back(r38);
	   td.push_back(r39);
	   td.push_back(r40);
	   td.push_back(r41);
	   td.push_back(r42);
	   td.push_back(r43);
	   td.push_back(r44);
	   td.push_back(r45);
	   td.push_back(r46);
	   td.push_back(r47);
	   td.push_back(r48);
	   td.push_back(r49);
	   td.push_back(r50);
	   td.push_back(r51);
	   td.push_back(r52);
	   td.push_back(r53);
	   td.push_back(r54);
	   td.push_back(r55);
	   td.push_back(r56);
	   td.push_back(r57);
	   td.push_back(r58);
	   td.push_back(r59);
	   td.push_back(r60);
	   td.push_back(r61);
	   td.push_back(r62);
	   td.push_back(r63);
	   td.push_back(r64);
	   td.push_back(r65);
	   td.push_back(r66);
	   td.push_back(r67);
	   td.push_back(r68);
	   td.push_back(r69);
	   td.push_back(r70);
	   td.push_back(r71);
	   td.push_back(r72);
	   td.push_back(r73);
	   td.push_back(r74);
	   td.push_back(r75);
	   td.push_back(r76);
	   td.push_back(r77);
	   td.push_back(r78);
	   td.push_back(r79);
	   td.push_back(r80);
	   td.push_back(r81);
	   td.push_back(r82);
	   td.push_back(r83);
	   td.push_back(r84);
	   td.push_back(r85);
}


void TextDisplay::printMyCurrentBoard(){
	  for(int i =0; i < td.size(); ++i)
	  std::cout << td.at(i) << std::endl;
	}

// FIX


void TextDisplay::addPlayerToTile(int x, int y, int pos,  int prevPos, std::string symbol, int numPlayersOnThisTile, std::shared_ptr<Player> p){
	(td.at(y))[x] = ' ';
	if (pos == 0){
		if ((td.at(81))[137] == ' '){
			(td.at(81))[137] = symbol[0];
			p->setY(81);
			p->setX(137);
		} else if (td.at(83)[137] == ' '){
			(td.at(83))[137] = symbol[0];
			p->setY(83);
			p->setX(137);
		} else if (td.at(83)[139] == ' '){
			(td.at(83))[139] = symbol[0];
			p->setY(83);
			p->setX(139);
		} else if ((td.at(79))[139] == ' '){
			(td.at(79))[139] = symbol[0];
			p->setY(79);
			p->setX(139);
		} else if ((td.at(81))[139] == ' ') {
			(td.at(81))[139] = symbol[0];
			p->setY(81);
			p->setX(139);
		}
		else if ((td.at(83))[139] == ' ') {
			(td.at(83))[139] = symbol[0];
			p->setY(83);
			p->setX(139);
		}
	}
	else if (pos == 1){
		if ((td.at(81))[124] == ' '){
			(td.at(81))[124] = symbol[0];
			p->setY(81);
			p->setX(124);
		} else if ((td.at(83))[124] == ' '){
			(td.at(83))[124] = symbol[0];
			p->setY(83);
			p->setX(124);
		} else if ((td.at(83))[126] == ' '){
			(td.at(83))[126] = symbol[0];
			p->setY(83);
			p->setX(126);
		} else if ((td.at(79))[126] == ' '){
			(td.at(79))[126] = symbol[0];
			p->setY(79);
			p->setX(126);
		}
	} else if (pos == 2){
		if ((td.at(81))[111] == ' '){
			(td.at(81))[111] = symbol[0];
			p->setY(81);
			p->setX(111);
		} else if ((td.at(83))[111] == ' '){
			(td.at(83))[111] = symbol[0];
			p->setY(83);
			p->setX(111);
		} else if ((td.at(83))[113] == ' '){
			(td.at(83))[113] = symbol[0];
			p->setY(83);
			p->setX(113);
		} else if ((td.at(79))[113] == ' '){
			(td.at(79))[113] = symbol[0];
			p->setY(79);
			p->setX(113);
		}
	} else if (pos == 3){
		if ((td.at(82))[98] == ' '){
			(td.at(82))[98] = symbol[0];
			p->setY(82);
			p->setX(98);
		} else if ((td.at(80))[98] == ' '){
			(td.at(80))[98] = symbol[0];
			p->setY(80);
			p->setX(98);
		} else if ((td.at(84))[98] == ' '){
			(td.at(84))[198] = symbol[0];
			p->setY(84);
			p->setX(98);
		} else if ((td.at(82))[96] == ' '){
			(td.at(82))[96] = symbol[0];
			p->setY(82);
			p->setX(96);
		}
	} else if (pos == 4){
		if ((td.at(82))[85] == ' '){
			td.at(82)[85] = symbol[0];
			p->setY(82);
			p->setX(85);
		} else if (td.at(82)[87] == ' '){
			td.at(82)[87] = symbol[0];
			p->setY(82);
			p->setX(87);
		} else if (td.at(80)[83] == ' '){
			td.at(80)[83] = symbol[0];
			p->setY(80);
			p->setX(83);
		} else if (td.at(80)[87] == ' '){
			td.at(80)[87] = symbol[0];
			p->setY(80);
			p->setX(87);
		}
	} else if (pos == 5){
		if (td.at(82)[72] == ' '){
			td.at(82)[72] = symbol[0];
			p->setY(82);
			p->setX(72);
		} else if (td.at(82)[74] == ' '){
			td.at(82)[74] = symbol[0];
			p->setY(82);
			p->setX(74);
		} else if (td.at(80)[72] == ' '){
			td.at(80)[72] = symbol[0];
			p->setY(80);
			p->setX(72);
		} else if (td.at(80)[70] == ' '){
			td.at(80)[70] = symbol[0];
			p->setY(80);
			p->setX(70);
		}
	} else if (pos == 6){
		if (td.at(82)[59] == ' '){
			td.at(82)[59] = symbol[0];
			p->setY(82);
			p->setX(59);
		} else if (td.at(82)[61] == ' '){
			td.at(82)[61] = symbol[0];
			p->setY(82);
			p->setX(61);
		} else if (td.at(80)[59] == ' '){
			td.at(80)[59] = symbol[0];
			p->setY(80);
			p->setX(59);
		} else if (td.at(80)[57] == ' '){
			td.at(80)[57] = symbol[0];
			p->setY(80);
			p->setX(57);
		}
	} else if (pos == 7){
		if (td.at(82)[46] == ' '){
			td.at(82)[46] = symbol[0];
			p->setY(82);
			p->setX(46);
		} else if (td.at(82)[48] == ' '){
			td.at(82)[48] = symbol[0];
			p->setY(82);
			p->setX(48);
		} else if (td.at(80)[46] == ' '){
			td.at(80)[46] = symbol[0];
			p->setY(80);
			p->setX(46);
		} else if (td.at(80)[48] == ' '){
			td.at(80)[48] = symbol[0];
			p->setY(80);
			p->setX(48);
		}
	} else if (pos == 8){
		if (td.at(82)[34] == ' '){
			td.at(82)[34] = symbol[0];
			p->setY(82);
			p->setX(34);
		} else if (td.at(82)[36] == ' '){
			td.at(82)[36] = symbol[0];
			p->setY(82);
			p->setX(36);
		} else if (td.at(80)[36] == ' '){
			td.at(80)[36] = symbol[0];
			p->setY(80);
			p->setX(36);
		} else if (td.at(80)[34] == ' '){
			td.at(80)[34] = symbol[0];
			p->setY(80);
			p->setX(34);
		}
	} else if (pos == 9){
		if (td.at(82)[20] == ' '){
			td.at(82)[20] = symbol[0];
			p->setY(82);
			p->setX(20);
		} else if (td.at(82)[22] == ' '){
			td.at(82)[22] = symbol[0];
			p->setY(82);
			p->setX(22);
		} else if (td.at(80)[20] == ' '){
			td.at(80)[20] = symbol[0];
			p->setY(80);
			p->setX(20);
		} else if (td.at(80)[22] == ' '){
			td.at(80)[22] = symbol[0];
			p->setY(80);
			p->setX(22);
		}
	} else if (pos == 10){
		if (td.at(82)[6] == ' '){
			td.at(82)[6] = symbol[0];
			p->setY(82);
			p->setX(6);
		} else if (td.at(82)[8] == ' '){
			td.at(82)[8] = symbol[0];
			p->setY(82);
			p->setX(8);
		} else if (td.at(80)[6] == ' '){
			td.at(80)[6] = symbol[0];
			p->setY(80);
			p->setX(6);
		} else if (td.at(80)[8] == ' '){
			td.at(80)[8] = symbol[0];
			p->setY(80);
			p->setX(8);
		}
	} else if (pos == 11){
		if (td.at(74)[6] == ' '){
			td.at(74)[6] = symbol[0];
			p->setY(74);
			p->setX(6);
		} else if (td.at(74)[8] == ' '){
			td.at(74)[8] = symbol[0];
			p->setY(74);
			p->setX(8);
		} else if (td.at(72)[6] == ' '){
			td.at(72)[6]= symbol[0];
			p->setY(72);
			p->setX(6);
		} else if (td.at(72)[8] == ' '){
			td.at(72)[8] = symbol[0];
			p->setY(72);
			p->setX(8);
		}
	} else if (pos == 12){
		if (td.at(66)[6] == ' '){
			td.at(66)[6] = symbol[0];
			p->setY(66);
			p->setX(6);
		} else if (td.at(66)[8] == ' '){
			td.at(66)[8] = symbol[0];
			p->setY(66);
			p->setX(8);
		} else if (td.at(68)[6] == ' '){
			td.at(68)[6]= symbol[0];
			p->setY(68);
			p->setX(6);
		} else if (td.at(68)[8] == ' '){
			td.at(68)[8] = symbol[0];
			p->setY(68);
			p->setX(8);
		}
	} else if (pos == 13){
		if (td.at(59)[6] == ' '){
			td.at(59)[6] = symbol[0];
			p->setY(59);
			p->setX(6);
		} else if (td.at(59)[8] == ' '){
			td.at(59)[8] = symbol[0];
			p->setY(59);
			p->setX(8);
		} else if (td.at(61)[6] == ' '){
			td.at(61)[6]= symbol[0];
			p->setY(61);
			p->setX(6);
		} else if (td.at(61)[8] == ' '){
			td.at(61)[8] = symbol[0];
			p->setY(61);
			p->setX(8);
		}
	} else if (pos == 14){
		if (td.at(51)[6] == ' '){
			td.at(51)[6] = symbol[0];
			p->setY(51);
			p->setX(6);
		} else if (td.at(51)[8] == ' '){
			td.at(51)[8] = symbol[0];
			p->setY(51);
			p->setX(8);
		} else if (td.at(53)[6] == ' '){
			td.at(53)[6]= symbol[0];
			p->setY(53);
			p->setX(6);
		} else if (td.at(53)[8] == ' '){
			td.at(53)[8] = symbol[0];
			p->setY(53);
			p->setX(8);
		}
	}else if (pos == 15){
		if (td.at(43)[6] == ' '){
			td.at(43)[6] = symbol[0];
			p->setY(43);
			p->setX(6);
		} else if (td.at(43)[8] == ' '){
			td.at(43)[8] = symbol[0];
			p->setY(43);
			p->setX(8);
		} else if (td.at(41)[6] == ' '){
			td.at(41)[6]= symbol[0];
			p->setY(41);
			p->setX(6);
		} else if (td.at(41)[8] == ' '){
			td.at(41)[8] = symbol[0];
			p->setY(41);
			p->setX(8);
		}
	} else if (pos == 16){
		if (td.at(36)[6] == ' '){
			td.at(36)[6] = symbol[0];
			p->setY(36);
			p->setX(6);
		} else if (td.at(36)[8] == ' '){
			td.at(36)[8] = symbol[0];
			p->setY(36);
			p->setX(8);
		} else if (td.at(34)[6] == ' '){
			td.at(34)[6]= symbol[0];
			p->setY(34);
			p->setX(6);
		} else if (td.at(34)[8] == ' '){
			td.at(34)[8] = symbol[0];
			p->setY(34);
			p->setX(8);
		}
	} else if (pos == 17){
		if (td.at(28)[6] == ' '){
			td.at(28)[6] = symbol[0];
			p->setY(28);
			p->setX(6);
		} else if (td.at(28)[8] == ' '){
			td.at(28)[8] = symbol[0];
			p->setY(28);
			p->setX(8);
		} else if (td.at(26)[6] == ' '){
			td.at(26)[6]= symbol[0];
			p->setY(26);
			p->setX(6);
		} else if (td.at(26)[8] == ' '){
			td.at(26)[8] = symbol[0];
			p->setY(26);
			p->setX(8);
		}
	} else if (pos == 18){
		if (td.at(22)[6] == ' '){
			td.at(22)[6] = symbol[0];
			p->setY(22);
			p->setX(6);
		} else if (td.at(22)[8] == ' '){
			td.at(22)[8] = symbol[0];
			p->setY(22);
			p->setX(8);
		} else if (td.at(20)[6] == ' '){
			td.at(20)[6]= symbol[0];
			p->setY(20);
			p->setX(6);
		} else if (td.at(20)[8] == ' '){
			td.at(20)[8] = symbol[0];
			p->setY(20);
			p->setX(8);
		}
	} else if (pos == 19){
		if (td.at(14)[6] == ' '){
			td.at(14)[6] = symbol[0];
			p->setY(14);
			p->setX(6);
		} else if (td.at(14)[8] == ' '){
			td.at(14)[8] = symbol[0];
			p->setY(14);
			p->setX(8);
		} else if (td.at(12)[6] == ' '){
			td.at(12)[6]= symbol[0];
			p->setY(12);
			p->setX(6);
		} else if (td.at(12)[8] == ' '){
			td.at(12)[8] = symbol[0];
			p->setY(12);
			p->setX(8);
		}
	} else if (pos == 20){
		if (td.at(6)[6] == ' '){
			td.at(6)[6] = symbol[0];
			p->setY(6);
			p->setX(6);
		} else if (td.at(6)[8] == ' '){
			td.at(6)[8] = symbol[0];
			p->setY(6);
			p->setX(8);
		} else if (td.at(8)[6] == ' '){
			td.at(8)[6]= symbol[0];
			p->setY(8);
			p->setX(6);
		} else if (td.at(8)[8] == ' '){
			td.at(8)[8] = symbol[0];
			p->setY(8);
			p->setX(8);
		}
	} else if (pos == 21){
		if (td.at(6)[20] == ' '){
			td.at(6)[20] = symbol[0];
			p->setY(6);
			p->setX(20);
		} else if (td.at(6)[22] == ' '){
			td.at(6)[22] = symbol[0];
			p->setY(6);
			p->setX(22);
		} else if (td.at(8)[20] == ' '){
			td.at(8)[20]= symbol[0];
			p->setY(8);
			p->setX(20);
		} else if (td.at(8)[22] == ' '){
			td.at(8)[22] = symbol[0];
			p->setY(8);
			p->setX(22);
		}
	} else if (pos == 22){
		if (td.at(6)[34] == ' '){
			td.at(6)[34] = symbol[0];
			p->setY(6);
			p->setX(34);
		} else if (td.at(6)[32] == ' '){
			td.at(6)[32] = symbol[0];
			p->setY(6);
			p->setX(32);
		} else if (td.at(8)[34] == ' '){
			td.at(8)[34]= symbol[0];
			p->setY(8);
			p->setX(34);
		} else if (td.at(8)[32] == ' '){
			td.at(8)[32] = symbol[0];
			p->setY(8);
			p->setX(32);
		}
	} else if (pos == 23){
		if (td.at(6)[46] == ' '){
			td.at(6)[46] = symbol[0];
			p->setY(6);
			p->setX(46);
		} else if (td.at(6)[48] == ' '){
			td.at(6)[48] = symbol[0];
			p->setY(6);
			p->setX(48);
		} else if (td.at(8)[48] == ' '){
			td.at(8)[48]= symbol[0];
			p->setY(8);
			p->setX(48);
		} else if (td.at(8)[48] == ' '){
			td.at(8)[48] = symbol[0];
			p->setY(8);
			p->setX(48);
		}
	} else if (pos == 24){
		if (td.at(6)[59] == ' '){
			td.at(6)[59] = symbol[0];
			p->setY(6);
			p->setX(59);
		} else if (td.at(6)[57] == ' '){
			td.at(6)[57] = symbol[0];
			p->setY(6);
			p->setX(57);
		} else if (td.at(8)[59] == ' '){
			td.at(8)[59]= symbol[0];
			p->setY(8);
			p->setX(59);
		} else if (td.at(8)[57] == ' '){
			td.at(8)[57] = symbol[0];
			p->setY(8);
			p->setX(57);
		}
	} else if (pos == 25){
		if (td.at(6)[72] == ' '){
			td.at(6)[72] = symbol[0];
			p->setY(6);
			p->setX(72);
		} else if (td.at(6)[74] == ' '){
			td.at(6)[74] = symbol[0];
			p->setY(6);
			p->setX(74);
		} else if (td.at(8)[72] == ' '){
			td.at(8)[72]= symbol[0];
			p->setY(8);
			p->setX(72);
		} else if (td.at(8)[74] == ' '){
			td.at(8)[74] = symbol[0];
			p->setY(8);
			p->setX(74);
		}
	}  else if (pos == 26){
		if (td.at(6)[85] == ' '){
			td.at(6)[85] = symbol[0];
			p->setY(6);
			p->setX(85);
		} else if (td.at(6)[83] == ' '){
			td.at(6)[85] = symbol[0];
			p->setY(6);
			p->setX(83);
		} else if (td.at(8)[85] == ' '){
			td.at(8)[85]= symbol[0];
			p->setY(8);
			p->setX(85);
		} else if (td.at(8)[83] == ' '){
			td.at(8)[83] = symbol[0];
			p->setY(8);
			p->setX(83);
		}
	} else if (pos == 27){
		if (td.at(6)[98] == ' '){
			td.at(6)[98] = symbol[0];
			p->setY(6);
			p->setX(98);
		} else if (td.at(6)[96] == ' '){
			td.at(6)[96] = symbol[0];
			p->setY(6);
			p->setX(96);
		} else if (td.at(8)[98] == ' '){
			td.at(8)[98]= symbol[0];
			p->setY(8);
			p->setX(98);
		} else if (td.at(8)[96] == ' '){
			td.at(8)[96] = symbol[0];
			p->setY(8);
			p->setX(96);
		}
	} else if (pos == 28){
		if (td.at(6)[111] == ' '){
			td.at(6)[111] = symbol[0];
			p->setY(6);
			p->setX(111);
		} else if (td.at(6)[113] == ' '){
			td.at(6)[113] = symbol[0];
			p->setY(6);
			p->setX(113);
		} else if (td.at(8)[111] == ' '){
			td.at(8)[111]= symbol[0];
			p->setY(8);
			p->setX(111);
		} else if (td.at(8)[113] == ' '){
			td.at(8)[113] = symbol[0];
			p->setY(8);
			p->setX(113);
		}
	} else if (pos == 29){
		if (td.at(6)[124] == ' '){
			td.at(6)[124] = symbol[0];
			p->setY(6);
			p->setX(124);
		} else if (td.at(6)[126] == ' '){
			td.at(6)[126] = symbol[0];
			p->setY(6);
			p->setX(126);
		} else if (td.at(8)[124] == ' '){
			td.at(8)[124]= symbol[0];
			p->setY(8);
			p->setX(124);
		} else if (td.at(8)[126] == ' '){
			td.at(8)[126] = symbol[0];
			p->setY(8);
			p->setX(126);
		}
	} else if (pos == 30){
		if (td.at(6)[137] == ' '){
			td.at(6)[137] = symbol[0];
			p->setY(6);
			p->setX(137);
		} else if (td.at(6)[135] == ' '){
			td.at(6)[135] = symbol[0];
			p->setY(6);
			p->setX(135);
		} else if (td.at(8)[137] == ' '){
			td.at(8)[137]= symbol[0];
			p->setY(8);
			p->setX(137);
		} else if (td.at(8)[135] == ' '){
			td.at(8)[135] = symbol[0];
			p->setY(8);
			p->setX(135);
		}
	} else if (pos == 31){
		if (td.at(14)[137] == ' '){
			td.at(14)[137] = symbol[0];
			p->setY(14);
			p->setX(137);
		} else if (td.at(14)[135] == ' '){
			td.at(14)[135] = symbol[0];
			p->setY(14);
			p->setX(135);
		} else if (td.at(16)[137] == ' '){
			td.at(16)[137]= symbol[0];
			p->setY(16);
			p->setX(137);
		} else if (td.at(16)[135] == ' '){
			td.at(16)[135] = symbol[0];
			p->setY(16);
			p->setX(135);
		}
	} else if (pos == 32){
		if (td.at(22)[137] == ' '){
			td.at(22)[137] = symbol[0];
			p->setY(22);
			p->setX(137);
		} else if (td.at(22)[135] == ' '){
			td.at(22)[135] = symbol[0];
			p->setY(22);
			p->setX(135);
		} else if (td.at(24)[137] == ' '){
			td.at(24)[137]= symbol[0];
			p->setY(24);
			p->setX(137);
		} else if (td.at(24)[135] == ' '){
			td.at(24)[135] = symbol[0];
			p->setY(24);
			p->setX(135);
		}
	} else if (pos == 33){
		if (td.at(28)[137] == ' '){
			td.at(28)[137] = symbol[0];
			p->setY(28);
			p->setX(137);
		} else if (td.at(28)[135] == ' '){
			td.at(28)[135] = symbol[0];
			p->setY(28);
			p->setX(135);
		} else if (td.at(30)[137] == ' '){
			td.at(30)[137]= symbol[0];
			p->setY(30);
			p->setX(137);
		} else if (td.at(30)[135] == ' '){
			td.at(30)[135] = symbol[0];
			p->setY(30);
			p->setX(135);
		}
	}  else if (pos == 34){
		if (td.at(36)[137] == ' '){
			td.at(36)[137] = symbol[0];
			p->setY(36);
			p->setX(137);
		} else if (td.at(36)[135] == ' '){
			td.at(36)[135] = symbol[0];
			p->setY(36);
			p->setX(135);
		} else if (td.at(38)[137] == ' '){
			td.at(38)[137]= symbol[0];
			p->setY(38);
			p->setX(137);
		} else if (td.at(38)[135] == ' '){
			td.at(38)[135] = symbol[0];
			p->setY(38);
			p->setX(135);
		}
	} else if (pos == 35){
		if (td.at(43)[137] == ' '){
			td.at(43)[137] = symbol[0];
			p->setY(43);
			p->setX(137);
		} else if (td.at(43)[135] == ' '){
			td.at(43)[135] = symbol[0];
			p->setY(43);
			p->setX(135);
		} else if (td.at(45)[137] == ' '){
			td.at(45)[137]= symbol[0];
			p->setY(45);
			p->setX(137);
		} else if (td.at(45)[135] == ' '){
			td.at(45)[135] = symbol[0];
			p->setY(45);
			p->setX(135);
		}
	}  else if (pos == 36){
		if (td.at(51)[137] == ' '){
			td.at(51)[137] = symbol[0];
			p->setY(51);
			p->setX(137);
		} else if (td.at(51)[135] == ' '){
			td.at(51)[135] = symbol[0];
			p->setY(51);
			p->setX(135);
		} else if (td.at(53)[137] == ' '){
			td.at(53)[137]= symbol[0];
			p->setY(53);
			p->setX(137);
		} else if (td.at(53)[135] == ' '){
			td.at(53)[135] = symbol[0];
			p->setY(45);
			p->setX(135);
		}
	} else if (pos == 37){
		if (td.at(58)[137] == ' '){
			td.at(58)[137] = symbol[0];
			p->setY(58);
			p->setX(137);
		} else if (td.at(58)[135] == ' '){
			td.at(58)[135] = symbol[0];
			p->setY(58);
			p->setX(135);
		} else if (td.at(60)[137] == ' '){
			td.at(60)[137]= symbol[0];
			p->setY(60);
			p->setX(137);
		} else if (td.at(60)[135] == ' '){
			td.at(60)[135] = symbol[0];
			p->setY(60);
			p->setX(135);
		}
	} else if (pos == 38){
		if (td.at(66)[137] == ' '){
			td.at(66)[137] = symbol[0];
			p->setY(66);
			p->setX(137);
		} else if (td.at(66)[135] == ' '){
			td.at(66)[135] = symbol[0];
			p->setY(66);
			p->setX(135);
		} else if (td.at(68)[137] == ' '){
			td.at(68)[137]= symbol[0];
			p->setY(68);
			p->setX(137);
		} else if (td.at(68)[135] == ' '){
			td.at(68)[135] = symbol[0];
			p->setY(68);
			p->setX(135);
		}
	} else if (pos == 39){
		if (td.at(74)[137] == ' '){
			td.at(74)[137] = symbol[0];
			p->setY(74);
			p->setX(137);
		} else if (td.at(74)[135] == ' '){
			td.at(74)[135] = symbol[0];
			p->setY(74);
			p->setX(135);
		} else if (td.at(76)[137] == ' '){
			td.at(76)[137]= symbol[0];
			p->setY(76);
			p->setX(137);
		} else if (td.at(76)[135] == ' '){
			td.at(76)[135] = symbol[0];
			p->setY(76);
			p->setX(135);
		}
	}
	printMyCurrentBoard();
}



	   // so we need improvements and player char printed.
	   
	   // if you are on Goose Nesting, set r6[6] to the char for player
	   // if you are on EV1, set r6[20] to the char for player
	   // if you are on Needles Hall, set r6[34] to the char for player
	   // if you are on EV2, set r6[46] to the char for player
	   // if you are on EV3, set r6[59] to the char for player
	   // if you are on V1, set r6[72] to the char for player
	   // if you are on Phys, set r6[85] to the char for player
	   // if you are on B1, set r6[98] to the char for player
	   // if you are on CIF, set r6[111] to the char for player
	   // if you are on B2, set r6[124] to the char for player
	   // if you are on Go to Tims, set r6[137] to the char for player
	   // if you are on EIT, set r14[137] to the char for player
	   // if you are on ESC, set r22[137] to the char for player
	   // if you are on SLC, set r28[137] to the char for player
	   // if you are on C2, set r36[137] to the char for player
	    // if you are on REV, set r43[137] to the char for player
		 // if you are on Needles Hall, set r51[137] to the char for player -----> ummmmm 2 needles halls ??
	   
	   // if you are on OPT, set r14[6] to the char for player ----> check for this
	   
	   
	   // if you are on BMH, set r22[6] to the char for player
	   
	   
	   // if you are on SLC, set r28[6] to the char for player  ---------------------> umm 2 SLC
	   // if you are on SLC, set r28[137] to the char for player
	   
	   // if you are on LHI, set r36[6] to the char for player
	   
	   
	   // if you are on UWP, set r43[6] to the char for player
	  
	   
	   // if you are on CPH, set r51[6] to the char for player
	  
	   
	    // if you are on DWE, set r59[6] to the char for playe
	   
	    
	   // if you are on DC, set r74[137] to the char for player
	   // if you are on COOPFEE, set r66[137] to the char for player
	   
	    // if you are on PAC, set r66[6] to the char for player
	   // if you are on RCH, set r74[6] to the char for player
	   // if you are on DC Tims Line, set r82[6] to the char for player
	   // if you are on HH, set r82[20] to the char for player
	   // if you are on PAS, set r82[34] to the char for player
	   // if you are on Needles hall, set r82[46] to the char for player --------------> umm 3 needles halls
	   // if you are on ECH, set r82[59] to the char for player
	   // if you are on MKV, set r82[72] to the char for player
	   // if you are on Tuition, set r82[85] to the char for player
	   // if you are on ML, set r82[98] to the char for player
	   // if you are on SLC, set r82[111] to the char for player--------------> umm 3 SLCs can probably print according to pos on board
	   // if you are on AL, set r82[124] to the char for player
	   // if you are on Collect OSAP, set r82[137] to the char for player
	   
	   // EV1 improvements, r2[m], where m is 19, 20, 21, 22, 23 depedning on the improvement number.
	   // EV2 improvements, r2[m], where m is 44, 45, 46, 47, 48 depedning on the improvement number.
	   // EV3 improvements, r2[m], where m is 57, 58, 59, 60, 61 depedning on the improvement number.
	   // B1 improvements, r2[m], where m is 96, 97, 98, 99, 100 depedning on the improvement number.
	   // B2 improvements, r2[m], where m is 123, 124, 125, 126, 127 depedning on the improvement number.
	   // OPT improvements, r10[m], where m is 7, 8, 9, 10, 11 depedning on the improvement number.
	   // EIT improvements, r10[m], where m is 137 138 139 140 141 depedning on the improvement number.
	   // BMH improvements, r18[m], where m is 7, 8, 9, 10, 11 depedning on the improvement number.
	   // ESC improvements, r18[m], where m is 137 138 139 140 141 depedning on the improvement number.
	   // LHI improvements, r32[m], where m is 7, 8, 9, 10, 11 depedning on the improvement number.
	   // C2 improvements, r32[m], where m is 137 138 139 140 141 depedning on the improvement number.
	   // CPH improvements, r47[m], where m is 7, 8, 9, 10, 11 depedning on the improvement number.
	   // DWE improvements, r55[m], where m is 7, 8, 9, 10, 11 depedning on the improvement number.
	   // MC improvements, r55[m], where m is 137 138 139 140 141 depedning on the improvement number.
	   
	   // RCH improvements, r70[m], where m is 137 138 139 140 141 depedning on the improvement number.
	   //DC improvements, r70[m], where m is 137 138 139 140 141 depedning on the improvement number.
	   
	   // HH improvements, r78[m], where m is 19, 20, 21, 22, 23 depedning on the improvement number.
	   // PAS improvements, r78[m], where m is 30, 31, 32, 33, 34 depedning on the improvement number.
	   // ECH improvements, r78[m], where m is 57, 58, 59, 60, 61 depedning on the improvement number.
	   // ML improvements, r78[m], where m is 96, 97, 98, 99, 100 depedning on the improvement number.
	   // AL improvements, r78[m], where m is 123, 124, 125, 126, 127 depedning on the improvement number.
	   
	      



// get their symbol, set the string at that point to the symbol.

void TextDisplay::removeImprovementsFromTile(int x, int y, int pos, int numOfImprovements){
	if(pos == 1){
		if (numOfImprovements == 0){
		td.at(77)[123] = ' ';
		}if (numOfImprovements == 1){
		td.at(77)[124] = ' ';
		} if (numOfImprovements == 2){
		td.at(77)[125] = ' ';
		}  if (numOfImprovements == 3){
		td.at(77)[126] = ' ';
		}if (numOfImprovements == 4){
		td.at(77)[127] = ' ';
		}
	} else if (pos == 3){
		if (numOfImprovements == 0){
		td.at(77)[96] = ' ';
		}if (numOfImprovements == 1){
		td.at(77)[97] = ' ';
		} if (numOfImprovements == 2){
		td.at(77)[98] = ' ';
		}  if (numOfImprovements == 3){
		td.at(77)[99] = ' ';
		}if (numOfImprovements == 4){
		td.at(77)[100] = ' ';
		}
	} else if (pos == 6){
		if (numOfImprovements == 0){
		td.at(77)[57] = ' ';
		}if (numOfImprovements == 1){
		td.at(77)[58] = ' ';
		} if (numOfImprovements == 2){
		td.at(77)[59] = ' ';
		}  if (numOfImprovements == 3){
		td.at(77)[60] = ' ';
		}if (numOfImprovements == 4){
		td.at(77)[61] = ' ';
		}
	} else if (pos == 8){
		if (numOfImprovements == 0){
		td.at(77)[30] = ' ';
		}if (numOfImprovements == 1){
		td.at(77)[31] = ' ';
		} if (numOfImprovements == 2){
		td.at(77)[32] = ' ';
		}  if (numOfImprovements == 3){
		td.at(77)[33] = ' ';
		}if (numOfImprovements == 4){
		td.at(77)[34] = ' ';
		}
	}else if (pos == 9){
		if (numOfImprovements == 0){
		td.at(77)[19] = ' ';
		}if (numOfImprovements == 1){
		td.at(77)[20] = ' ';
		} if (numOfImprovements == 2){
		td.at(77)[21] = ' ';
		}  if (numOfImprovements == 3){
		td.at(77)[22] = ' ';
		}if (numOfImprovements == 4){
		td.at(77)[23] = ' ';
		}
	}else if (pos == 11){
		if (numOfImprovements == 0){
		td.at(69)[137] = ' ';
		}if (numOfImprovements == 1){
		td.at(69)[138] = ' ';
		} if (numOfImprovements == 2){
		td.at(69)[139] = ' ';
		}  if (numOfImprovements == 3){
		td.at(69)[140] = ' ';
		}if (numOfImprovements == 4){
		td.at(69)[141] = ' ';
		}
	}else if (pos == 13){
		if (numOfImprovements == 0){
		td.at(54)[7] = ' ';
		}if (numOfImprovements == 1){
		td.at(54)[8] = ' ';
		} if (numOfImprovements == 2){
		td.at(54)[9] = ' ';
		}  if (numOfImprovements == 3){
		td.at(54)[10] = ' ';
		}if (numOfImprovements == 4){
		td.at(54)[11] = ' ';
		}
	}else if (pos == 14){
		if (numOfImprovements == 0){
		td.at(46)[7] = ' ';
		}if (numOfImprovements == 1){
		td.at(46)[8] = ' ';
		} if (numOfImprovements == 2){
		td.at(46)[9] = ' ';
		}  if (numOfImprovements == 3){
		td.at(46)[10] = ' ';
		}if (numOfImprovements == 4){
		td.at(46)[11] = ' ';
		}
	} else if (pos == 16){
		if (numOfImprovements == 0){
		td.at(31)[7] = ' ';
		}if (numOfImprovements == 1){
		td.at(31)[8] = ' ';
		} if (numOfImprovements == 2){
		td.at(31)[9] = ' ';
		}  if (numOfImprovements == 3){
		td.at(31)[10] = ' ';
		}if (numOfImprovements == 4){
		td.at(31)[11] = ' ';
		}
	} else if (pos == 18){
		if (numOfImprovements == 0){
		td.at(17)[7] = ' ';
		}if (numOfImprovements == 1){
		td.at(17)[8] = ' ';
		} if (numOfImprovements == 2){
		td.at(17)[9] = ' ';
		}  if (numOfImprovements == 3){
		td.at(17)[10] = ' ';
		}if (numOfImprovements == 4){
		td.at(17)[11] = ' ';
		}
	} else if (pos == 19){
		if (numOfImprovements == 0){
		td.at(9)[7] = ' ';
		}if (numOfImprovements == 1){
		td.at(9)[8] = ' ';
		} if (numOfImprovements == 2){
		td.at(9)[9] = ' ';
		}  if (numOfImprovements == 3){
		td.at(9)[10] = ' ';
		}if (numOfImprovements == 4){
		td.at(9)[11] = ' ';
		}
	} else if (pos == 21){
		if (numOfImprovements == 0){
		td.at(1)[19] = ' ';
		}if (numOfImprovements == 1){
		td.at(1)[16] = ' ';
		} if (numOfImprovements == 2){
		td.at(1)[20] = ' ';
		}  if (numOfImprovements == 3){
		td.at(1)[21] = ' ';
		}if (numOfImprovements == 4){
		td.at(1)[21] = ' ';
		}
	} else if (pos == 23){
		if (numOfImprovements == 0){
		td.at(1)[44] = ' ';
		}if (numOfImprovements == 1){
		td.at(1)[45] = ' ';
		} if (numOfImprovements == 2){
		td.at(1)[46] = ' ';
		}  if (numOfImprovements == 3){
		td.at(1)[47] = ' ';
		}if (numOfImprovements == 4){
		td.at(1)[48] = ' ';
		}
	} else if (pos == 24){
		if (numOfImprovements == 0){
		td.at(1)[57] = ' ';
		}if (numOfImprovements == 1){
		td.at(1)[58] = ' ';
		} if (numOfImprovements == 2){
		td.at(1)[59] = ' ';
		}  if (numOfImprovements == 3){
		td.at(1)[60] = ' ';
		}if (numOfImprovements == 4){
		td.at(1)[61] = ' ';
		}
	} else if (pos == 26){
		if (numOfImprovements == 0){
		td.at(1)[82] = ' ';
		}if (numOfImprovements == 1){
		td.at(1)[83] = ' ';
		} if (numOfImprovements == 2){
		td.at(1)[84] = ' ';
		}  if (numOfImprovements == 3){
		td.at(1)[85] = ' ';
		}if (numOfImprovements == 4){
		td.at(1)[86] = ' ';
		}
	} else if (pos == 27){
		if (numOfImprovements == 0){
		td.at(1)[96] = ' ';
		}if (numOfImprovements == 1){
		td.at(1)[97] = ' ';
		} if (numOfImprovements == 2){
		td.at(1)[98] = ' ';
		}  if (numOfImprovements == 3){
		td.at(1)[99] = ' ';
		}if (numOfImprovements == 4){
		td.at(1)[100] = ' ';
		}
	} else if (pos == 29){
		if (numOfImprovements == 0){
		td.at(1)[123] = ' ';
		}if (numOfImprovements == 1){
		td.at(1)[124] = ' ';
		} if (numOfImprovements == 2){
		td.at(1)[125] = ' ';
		}  if (numOfImprovements == 3){
		td.at(1)[126] = ' ';
		}if (numOfImprovements == 4){
		td.at(1)[127] = ' ';
		}
	} else if (pos == 31){
		if (numOfImprovements == 0){
		td.at(9)[137] = ' ';
		}if (numOfImprovements == 1){
		td.at(9)[138] = ' ';
		} if (numOfImprovements == 2){
		td.at(9)[139] = ' ';
		}  if (numOfImprovements == 3){
		td.at(9)[140] = ' ';
		}if (numOfImprovements == 4){
		td.at(9)[141] = ' ';
		}
	} else if (pos == 32){
		if (numOfImprovements == 0){
		td.at(17)[137] = ' ';
		}if (numOfImprovements == 1){
		td.at(17)[138] = ' ';
		} if (numOfImprovements == 2){
		td.at(17)[139] = ' ';
		}  if (numOfImprovements == 3){
		td.at(17)[140] = ' ';
		}if (numOfImprovements == 4){
		td.at(17)[141] = ' ';
		}
	} else if (pos == 34){
		if (numOfImprovements == 0){
		td.at(31)[137] = ' ';
		}if (numOfImprovements == 1){
		td.at(31)[138] = ' ';
		} if (numOfImprovements == 2){
		td.at(31)[139] = ' ';
		}  if (numOfImprovements == 3){
		td.at(31)[140] = ' ';
		}if (numOfImprovements == 4){
		td.at(31)[141] = ' ';
		}
	} else if (pos == 37){
		if (numOfImprovements == 0){
		td.at(54)[137] = ' ';
		}if (numOfImprovements == 1){
		td.at(54)[138] = ' ';
		} if (numOfImprovements == 2){
		td.at(54)[139] = ' ';
		}  if (numOfImprovements == 3){
		td.at(54)[140] = ' ';
		}if (numOfImprovements == 4){
		td.at(54)[141] = ' ';
		}
	}else if (pos == 39){
		if (numOfImprovements == 0){
		td.at(69)[137] = ' ';
		}if (numOfImprovements == 1){
		td.at(69)[138] = ' ';
		} if (numOfImprovements == 2){
		td.at(69)[139] = ' ';
		}  if (numOfImprovements == 3){
		td.at(69)[140] = ' ';
		}if (numOfImprovements == 4){
		td.at(69)[141] = ' ';
		}
	}
}

void TextDisplay::addImprovementsToTile(int x, int y, int pos, int numOfImprovements){
	if(pos == 1){
		if (numOfImprovements == 1){
		td.at(77)[123] = 'I';
		}if (numOfImprovements == 2){
		td.at(77)[124] = 'I';
		} if (numOfImprovements == 3){
		td.at(77)[125] = 'I';
		}  if (numOfImprovements == 4){
		td.at(77)[126] = 'I';
		}if (numOfImprovements == 5){
		td.at(77)[127] = 'I';
		}
	} else if (pos == 3){
		if (numOfImprovements == 1){
		td.at(77)[96] = 'I';
		}if (numOfImprovements == 2){
		td.at(77)[97] = 'I';
		} if (numOfImprovements == 3){
		td.at(77)[98] = 'I';
		}  if (numOfImprovements == 4){
		td.at(77)[99] = 'I';
		}if (numOfImprovements == 5){
		td.at(77)[100] = 'I';
		}
	} else if (pos == 6){
		if (numOfImprovements == 1){
		td.at(77)[57] = 'I';
		}if (numOfImprovements == 2){
		td.at(77)[58] = 'I';
		} if (numOfImprovements == 3){
		td.at(77)[59] = 'I';
		}  if (numOfImprovements == 4){
		td.at(77)[60] = 'I';
		}if (numOfImprovements == 5){
		td.at(77)[61] = 'I';
		}
	} else if (pos == 8){
		if (numOfImprovements == 1){
		td.at(77)[30] = 'I';
		}if (numOfImprovements == 2){
		td.at(77)[31] = 'I';
		} if (numOfImprovements == 3){
		td.at(77)[32] = 'I';
		}  if (numOfImprovements == 4){
		td.at(77)[33] = 'I';
		}if (numOfImprovements == 5){
		td.at(77)[34] = 'I';
		}
	}else if (pos == 9){
		if (numOfImprovements == 1){
		td.at(77)[19] = 'I';
		}if (numOfImprovements == 2){
		td.at(77)[20] = 'I';
		} if (numOfImprovements == 3){
		td.at(77)[21] = 'I';
		}  if (numOfImprovements == 4){
		td.at(77)[22] = 'I';
		}if (numOfImprovements == 5){
		td.at(77)[23] = 'I';
		}
	}else if (pos == 11){
		if (numOfImprovements == 1){
		td.at(69)[137] = 'I';
		}if (numOfImprovements == 2){
		td.at(69)[138] = 'I';
		} if (numOfImprovements == 3){
		td.at(69)[139] = 'I';
		}  if (numOfImprovements == 4){
		td.at(69)[140] = 'I';
		}if (numOfImprovements == 5){
		td.at(69)[141] = 'I';
		}
	}else if (pos == 13){
		if (numOfImprovements == 1){
		td.at(54)[7] = 'I';
		}if (numOfImprovements == 2){
		td.at(54)[8] = 'I';
		} if (numOfImprovements == 3){
		td.at(54)[9] = 'I';
		}  if (numOfImprovements == 4){
		td.at(54)[10] = 'I';
		}if (numOfImprovements == 5){
		td.at(54)[11] = 'I';
		}
	}else if (pos == 14){
		if (numOfImprovements == 1){
		td.at(46)[7] = 'I';
		}if (numOfImprovements == 2){
		td.at(46)[8] = 'I';
		} if (numOfImprovements == 3){
		td.at(46)[9] = 'I';
		}  if (numOfImprovements == 4){
		td.at(46)[10] = 'I';
		}if (numOfImprovements == 5){
		td.at(46)[11] = 'I';
		}
	} else if (pos == 16){
		if (numOfImprovements == 1){
		td.at(31)[7] = 'I';
		}if (numOfImprovements == 2){
		td.at(31)[8] = 'I';
		} if (numOfImprovements == 3){
		td.at(31)[9] = 'I';
		}  if (numOfImprovements == 4){
		td.at(31)[10] = 'I';
		}if (numOfImprovements == 5){
		td.at(31)[11] = 'I';
		}
	} else if (pos == 18){
		if (numOfImprovements == 1){
		td.at(17)[7] = 'I';
		}if (numOfImprovements == 2){
		td.at(17)[8] = 'I';
		} if (numOfImprovements == 3){
		td.at(17)[9] = 'I';
		}  if (numOfImprovements == 4){
		td.at(17)[10] = 'I';
		}if (numOfImprovements == 5){
		td.at(17)[11] = 'I';
		}
	} else if (pos == 19){
		if (numOfImprovements == 1){
		td.at(9)[7] = 'I';
		}if (numOfImprovements == 2){
		td.at(9)[8] = 'I';
		} if (numOfImprovements == 3){
		td.at(9)[9] = 'I';
		}  if (numOfImprovements == 4){
		td.at(9)[10] = 'I';
		}if (numOfImprovements == 5){
		td.at(9)[11] = 'I';
		}
	} else if (pos == 21){
		if (numOfImprovements == 1){
		td.at(1)[19] = 'I';
		}if (numOfImprovements == 2){
		td.at(1)[16] = 'I';
		} if (numOfImprovements == 3){
		td.at(1)[20] = 'I';
		}  if (numOfImprovements == 4){
		td.at(1)[21] = 'I';
		}if (numOfImprovements == 5){
		td.at(1)[21] = 'I';
		}
	} else if (pos == 23){
		if (numOfImprovements == 1){
		td.at(1)[44] = 'I';
		}if (numOfImprovements == 2){
		td.at(1)[45] = 'I';
		} if (numOfImprovements == 3){
		td.at(1)[46] = 'I';
		}  if (numOfImprovements == 4){
		td.at(1)[47] = 'I';
		}if (numOfImprovements == 5){
		td.at(1)[48] = 'I';
		}
	} else if (pos == 24){
		if (numOfImprovements == 1){
		td.at(1)[57] = 'I';
		}if (numOfImprovements == 2){
		td.at(1)[58] = 'I';
		} if (numOfImprovements == 3){
		td.at(1)[59] = 'I';
		}  if (numOfImprovements == 4){
		td.at(1)[60] = 'I';
		}if (numOfImprovements == 5){
		td.at(1)[61] = 'I';
		}
	} else if (pos == 26){
		if (numOfImprovements == 1){
		td.at(1)[82] = 'I';
		}if (numOfImprovements == 2){
		td.at(1)[83] = 'I';
		} if (numOfImprovements == 3){
		td.at(1)[84] = 'I';
		}  if (numOfImprovements == 4){
		td.at(1)[85] = 'I';
		}if (numOfImprovements == 5){
		td.at(1)[86] = 'I';
		}
	} else if (pos == 27){
		if (numOfImprovements == 1){
		td.at(1)[96] = 'I';
		}if (numOfImprovements == 2){
		td.at(1)[97] = 'I';
		} if (numOfImprovements == 3){
		td.at(1)[98] = 'I';
		}  if (numOfImprovements == 4){
		td.at(1)[99] = 'I';
		}if (numOfImprovements == 5){
		td.at(1)[100] = 'I';
		}
	} else if (pos == 29){
		if (numOfImprovements == 1){
		td.at(1)[123] = 'I';
		}if (numOfImprovements == 2){
		td.at(1)[124] = 'I';
		} if (numOfImprovements == 3){
		td.at(1)[125] = 'I';
		}  if (numOfImprovements == 4){
		td.at(1)[126] = 'I';
		}if (numOfImprovements == 5){
		td.at(1)[127] = 'I';
		}
	} else if (pos == 31){
		if (numOfImprovements == 1){
		td.at(9)[137] = 'I';
		}if (numOfImprovements == 2){
		td.at(9)[138] = 'I';
		} if (numOfImprovements == 3){
		td.at(9)[139] = 'I';
		}  if (numOfImprovements == 4){
		td.at(9)[140] = 'I';
		}if (numOfImprovements == 5){
		td.at(9)[141] = 'I';
		}
	} else if (pos == 32){
		if (numOfImprovements == 1){
		td.at(17)[137] = 'I';
		}if (numOfImprovements == 2){
		td.at(17)[138] = 'I';
		} if (numOfImprovements == 3){
		td.at(17)[139] = 'I';
		}  if (numOfImprovements == 4){
		td.at(17)[140] = 'I';
		}if (numOfImprovements == 5){
		td.at(17)[141] = 'I';
		}
	} else if (pos == 34){
		if (numOfImprovements == 1){
		td.at(31)[137] = 'I';
		}if (numOfImprovements == 2){
		td.at(31)[138] = 'I';
		} if (numOfImprovements == 3){
		td.at(31)[139] = 'I';
		}  if (numOfImprovements == 4){
		td.at(31)[140] = 'I';
		}if (numOfImprovements == 5){
		td.at(31)[141] = 'I';
		}
	} else if (pos == 37){
		if (numOfImprovements == 1){
		td.at(54)[137] = 'I';
		}if (numOfImprovements == 2){
		td.at(54)[138] = 'I';
		} if (numOfImprovements == 3){
		td.at(54)[139] = 'I';
		}  if (numOfImprovements == 4){
		td.at(54)[140] = 'I';
		}if (numOfImprovements == 5){
		td.at(54)[141] = 'I';
		}
	}else if (pos == 39){
		if (numOfImprovements == 1){
		td.at(69)[137] = 'I';
		}if (numOfImprovements == 2){
		td.at(69)[138] = 'I';
		} if (numOfImprovements == 3){
		td.at(69)[139] = 'I';
		}  if (numOfImprovements == 4){
		td.at(69)[140] = 'I';
		}if (numOfImprovements == 5){
		td.at(69)[141] = 'I';
		}
	}
	printMyCurrentBoard();
}





 TextDisplay::~TextDisplay(){}

