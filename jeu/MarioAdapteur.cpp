#include "MarioAdapteur.h"

namespace jeu {


MarioAdapteur::~MarioAdapteur() {
	delete (mario);
}

std::string MarioAdapteur::getNomJeu(){
	return this->mario->name;
}

std::string MarioAdapteur::getMode() {
	return this->mario->isPvP() ? "PvP" : "PvE";
}

std::string MarioAdapteur::getInfo() {
	return getNomJeu() + " est un jeu " + getMode();
}

} /* namespace jeu */
