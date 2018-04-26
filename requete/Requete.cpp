#include "Requete.h"
#include <string>

namespace requete {


Requete::~Requete() {
	delete (jeuInfo);
}

std::ostream& operator<<( std::ostream &flux, Requete const& requete){
	flux << "Envoie de la requete id : " + std::to_string(requete.getId()) + " (" + requete.getJeuInfo()->getNomJeu() + ")";
	return flux;
}

} /* namespace requete */

