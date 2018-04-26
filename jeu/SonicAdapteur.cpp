#include "SonicAdapteur.h"

namespace jeu {

SonicAdapteur::~SonicAdapteur() {
	delete(sonic);
}

std::string SonicAdapteur::getNomJeu() {
	return this->sonic->getNom();
}

std::string SonicAdapteur::getMode() {
	return "PvE";
}

std::string SonicAdapteur::getInfo() {
	return getNomJeu() + " est un jeu " + getMode();
}

} /* namespace jeu */
