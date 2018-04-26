#ifndef REQUETTE_JEUINFO_H_
#define REQUETTE_JEUINFO_H_

#include <string>

namespace jeu {

class JeuInfo {
public:
//	JeuInfo();
//	virtual ~JeuInfo();

	virtual std::string getNomJeu() = 0;
	virtual std::string getMode() = 0;
	virtual std::string getInfo() = 0;
};

} /* namespace requete */

#endif /* REQUETTE_JEUINFO_H_ */
