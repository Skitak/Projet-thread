#ifndef JEU_ZELDAADAPTEUR_H_
#define JEU_ZELDAADAPTEUR_H_

#include "JeuInfo.h"
#include "Zelda.h"
namespace jeu {

class ZeldaAdapteur: public JeuInfo {
public:
	ZeldaAdapteur() : zelda(new Zelda()) { }
	virtual ~ZeldaAdapteur();

	std::string getNomJeu();
	std::string getMode();
	std::string getInfo();

private:
	Zelda *zelda;
};

} /* namespace jeu */

#endif /* JEU_ZELDAADAPTEUR_H_ */
