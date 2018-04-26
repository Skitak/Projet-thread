#ifndef SERVEUR_JEU_H
#define SERVEUR_JEU_H

#include <queue>
#include "requete/Requete.h"
using namespace std;

class ServeurJeu
{
public:
	static void gererRequetes(ServeurJeu* monServeur);
	void lancer(requete::Requete* requete) {mesRequetes.push(requete);};
private:
	queue<requete::Requete*> mesRequetes;
};

#endif
