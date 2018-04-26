#ifndef JEU_TETRIS_H_
#define JEU_TETRIS_H_

#include <iostream>
#include <string>
#include "JeuInfo.h"

namespace jeu {

class Tetris: public JeuInfo {	//Jeu 4
public:
	Tetris() {}
	virtual ~Tetris();

	std::string getNomJeu() override {return "Tetris";}

	std::string getMode() override {return "PvP";}

	std::string getInfo() override {return "Jeu 4 est un PvP!";}
};

} /* namespace jeu */

#endif /* JEU_TETRIS_H_ */
