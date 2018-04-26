#ifndef JEU_MARIOADAPTEUR_H_
#define JEU_MARIOADAPTEUR_H_

#include "JeuInfo.h"
#include "Mario.h"
namespace jeu {

class MarioAdapteur: public JeuInfo {
public:
	MarioAdapteur(): mario(new Mario()) {}
	virtual ~MarioAdapteur();

	std::string getNomJeu() override;
	std::string getMode() override;
	std::string getInfo() override;

private:
	Mario* mario;
};

} /* namespace jeu */

#endif /* JEU_MARIOADAPTEUR_H_ */
