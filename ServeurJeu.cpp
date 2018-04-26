#include "ServeurJeu.h"
#include "PUBG.h"

#include <iostream>

#include <string>

void ServeurJeu::gererRequetes(ServeurJeu* monServeur)
{
	while(1) {
		if (monServeur->mesRequetes.size() != 0){
			Requete* requete = monServeur->mesRequetes.front();
			PUBG::getInterfaceJournalisation()->journaliserRequete(requete, monServeur);
			monServeur->mesRequetes.pop();
			delete(requete);
		}
		std::this_thread::sleep_for(1s);
	}
}
