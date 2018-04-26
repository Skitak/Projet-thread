#ifndef JEU_SONICADAPTEUR_H_
#define JEU_SONICADAPTEUR_H_

#include "JeuInfo.h"
#include "Sonic.h"

namespace jeu {

class SonicAdapteur: public JeuInfo {
public:
	SonicAdapteur(): sonic (new Sonic()) { }
	virtual ~SonicAdapteur();

	std::string getNomJeu() override;
	std::string getMode() override;
	std::string getInfo() override;

private:
	Sonic* sonic;

};

} /* namespace jeu */

#endif /* JEU_SONICADAPTEUR_H_ */
