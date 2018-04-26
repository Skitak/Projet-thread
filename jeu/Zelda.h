#ifndef JEU_ZELDA_H_
#define JEU_ZELDA_H_

#include <string>

namespace jeu {

class Zelda { //Jeu 3
public:
	Zelda(){
		nom = "Zelda";
		description = "super jeu";
		mode = 2;
	}
	virtual ~Zelda();

	std::string nom;
	std::string description;

	int getMode() { return mode; }

private:
	int mode;

};

} /* namespace jeu */

#endif /* JEU_ZELDA_H_ */
