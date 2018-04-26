#include "RequeteFactory.h"
#include <cstdlib>
#include "../jeu/SonicAdapteur.h"
#include "../jeu/MarioAdapteur.h"
#include "../jeu/ZeldaAdapteur.h"
#include "../jeu/Tetris.h"


RequeteFactory* RequeteFactory::instance = NULL;

RequeteFactory* RequeteFactory::getInstance() {
	if (RequeteFactory::instance == NULL)
		RequeteFactory::instance = new RequeteFactory();
	return RequeteFactory::instance;
}

Requete* RequeteFactory::createRequete(int* ip, std::string compte) {
	return new Requete(ip, getId(), compte, getRandomJeuInfo());
}

RequeteInfo* RequeteFactory::createRequeteInfo(int* ip) {
	return new RequeteInfo(ip, getRandomJeuInfo());
}

int RequeteFactory::getId() {
	return ++sequenceId;
}

JeuInfo* RequeteFactory::getRandomJeuInfo(){
	int randomNumber = (rand() % 4) + 1;
	switch(randomNumber){
	case 1:
		return new SonicAdapteur();
	case 2:
		return new MarioAdapteur();
	case 3:
		return new ZeldaAdapteur();
	case 4:
	default:
		return new Tetris();
	}
}

RequeteFactory::~RequeteFactory() {
	// TODO Auto-generated destructor stub
}

