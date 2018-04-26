#include <thread>
#include <iostream>
#include <thread>
#include <string>
#include <queue>
#include "PUBG.h"

PUBG* PUBG::instance = NULL;

void PUBG::lancerRequete(Requete* requete) {
	mesRequetes.push(requete);
}

void PUBG::lancerRequeteInfo(RequeteInfo* requeteInfo) {
	mesRequetesInfo.push(requeteInfo);
}

void PUBG::journaliserRequete(Requete* requete, ServeurJeu* serveurJeu) {
	cout << "id (" << requete->getId() << ") -> ";
	cout << "Traitement du jeu " << requete->getJeuInfo()->getInfo() << endl;
}

PUBG::PUBG()
{
	mesThreads = new thread*[5];		// Pour regrouper les threads T2-T6
	serveursJeu = new ServeurJeu*[3];
	serveursJeu[0] = new ServeurJeu();	// Le serveur pour les JEU1
	serveursJeu[1] = new ServeurJeu();	// Le serveur pour les JEU2
	serveursJeu[2] = new ServeurJeu();	// Le serveur pour les JEU3
	// Aucun serveur de jeu pour JEU4

	mesThreads[0] = new thread (&PUBG::gererRequete, this, &mesRequetes);			// T2 : Pour la gestion des requetes
	mesThreads[1] = new thread(&PUBG::gererRequeteInfo, this, &mesRequetesInfo);	// T3 : Pour la gestion des requetesInfo
	mesThreads[2] = new thread(&ServeurJeu::gererRequetes, serveursJeu[0]);			// T4 : Pour g�rer le serveur de JEU1
	mesThreads[3] = new thread(&ServeurJeu::gererRequetes, serveursJeu[1]);			// T5 : Pour g�rer le serveur de JEU2
	mesThreads[4] = new thread(&ServeurJeu::gererRequetes, serveursJeu[2]);			// T6 : Pour g�rer le serveur de JEU3
}

void PUBG::gererRequete(PUBG* pubg, queue<Requete*>* mesRequetes)
{
	while(1) {
		if (mesRequetes->size() != 0){
			Requete* requete= mesRequetes->front();
			ServeurJeu* serveur = pubg->getServeurFromRequete(requete);
			if (serveur == NULL)
				cout << "le serveur de jeu (" << requete->getJeuInfo()->getNomJeu() << ") n'existe pas." << endl;
			else
				serveur->lancer(requete);
			mesRequetes->pop();
		}
		std::this_thread::sleep_for(2s);
	}
}


void PUBG::gererRequeteInfo(PUBG* pubg, queue<RequeteInfo*>* mesRequetesInfo)
{
	while(1) {
		if (mesRequetesInfo->size() != 0){
			RequeteInfo* requeteInfo= mesRequetesInfo->front();
			cout << "id (" << "-1" << ") -> ";
			cout << "Information pour le jeu " << requeteInfo->getJeuInfo()->getNomJeu() << endl;
			mesRequetesInfo->pop();
			delete(requeteInfo);
		}
		std::this_thread::sleep_for(5s);
	}
}

InterfaceLancement* PUBG::getInterfaceLancement() {
	if (instance == NULL)
		instance = new PUBG();
	return instance;
}

InterfaceJournalisation* PUBG::getInterfaceJournalisation() {
	if (instance == NULL)
			instance = new PUBG();
		return instance;
}

ServeurJeu* PUBG::getServeurFromRequete(Requete* requete) {
	if (requete->getJeuInfo()->getNomJeu() == "Mario")
		return serveursJeu[0];
	if (requete->getJeuInfo()->getNomJeu() == "Sonic")
			return serveursJeu[1];
	if (requete->getJeuInfo()->getNomJeu() == "Zelda")
			return serveursJeu[2];
	return NULL;
}
