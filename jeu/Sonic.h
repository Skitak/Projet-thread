#ifndef JEU_SONIC_H_
#define JEU_SONIC_H_

#include <string>

namespace jeu {

class Sonic {	//Jeu 2
public:
	Sonic() { nom = "Sonic"; }
	virtual ~Sonic();


	std::string getNom() { return nom; }

private:
	std::string nom;
};

} /* namespace jeu */

#endif /* JEU_SONIC_H_ */
