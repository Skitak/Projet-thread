#ifndef REQUETE_H_
#define REQUETE_H_

#include <string>
#include "../jeu/JeuInfo.h"

using namespace jeu;

namespace requete {

class Requete {
public:
	Requete(int ip[], int id, std::string compte, JeuInfo* jeuInfo): ip(ip), id(id), compte(compte),jeuInfo(jeuInfo) {}

	virtual ~Requete();

	std::string getCompte() {
		return compte;
	}

	int getId() const {
		return id;
	}

	int* getIp() const{
		return ip;
	}

	JeuInfo* getJeuInfo() const {
		return jeuInfo;
	}

private:
	int* ip;
	int id;
	std::string compte;
	JeuInfo* jeuInfo;
};

std::ostream& operator<<( std::ostream &flux, Requete const& requete);

} /* namespace requete */

#endif /* REQUETE_H_ */
