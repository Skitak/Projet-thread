#include "RequeteInfo.h"

namespace requete {

RequeteInfo::~RequeteInfo() {
	delete (jeuInfo);
}

ostream& operator<<( ostream &flux, RequeteInfo const& requeteInfo){
	flux << "Envoie d'une RequeteInfo : (" + requeteInfo.getJeuInfo()->getNomJeu() + ")";
	return flux;
}


} /* namespace requete */

