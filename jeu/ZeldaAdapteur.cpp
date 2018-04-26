#include "ZeldaAdapteur.h"

namespace jeu {

ZeldaAdapteur::~ZeldaAdapteur() {
	delete (zelda);
}

std::string ZeldaAdapteur::getNomJeu() {
	return this->zelda->nom;
}

std::string ZeldaAdapteur::getMode() {
	return this->zelda->getMode() == 1 ? "PvP" : "PvE";
}

std::string ZeldaAdapteur::getInfo() {
	return this->getNomJeu() +"("+ this->zelda->description
				+ ") est un jeu " + this->getMode();
}

} /* namespace jeu */
