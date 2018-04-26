#ifndef JEU_MARIO_H_
#define JEU_MARIO_H_

#include <string>

namespace jeu {

class Mario { // Jeu 1
public:
	Mario(){ pvp = true; name = "Mario"; }
	virtual ~Mario();

	bool isPvP() { return pvp; }
	std::string name;

private:
	bool pvp;
};

} /* namespace jeu */

#endif /* JEU_MARIO_H_ */
