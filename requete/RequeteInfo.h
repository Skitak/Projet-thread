#ifndef REQUETE_REQUETEINFO_H_
#define REQUETE_REQUETEINFO_H_

#include "../jeu/JeuInfo.h"

using namespace jeu;
using namespace std;

namespace requete {

class RequeteInfo {
public:
	RequeteInfo(int ip[], JeuInfo* jeuInfo): ip(ip), jeuInfo(jeuInfo){}
	virtual ~RequeteInfo();

	int* getIp() const {
		return ip;
	}

	jeu::JeuInfo* getJeuInfo() const {
		return jeuInfo;
	}

private:
	int* ip;
	jeu::JeuInfo* jeuInfo;
};

std::ostream& operator<<( std::ostream &flux, RequeteInfo const& requeteInfo);

} /* namespace requete */

#endif /* REQUETE_REQUETEINFO_H_ */
