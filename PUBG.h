#ifndef PUBG_H
#define PUBG_H

#include <thread>
#include <queue>

#include "requete/RequeteInfo.h"
#include "ServeurJeu.h"
#include "requete/Requete.h"
#include "InterfaceJournalisation.h"
#include "InterfaceLancement.h"

using namespace std;
using namespace requete;

class PUBG : public InterfaceJournalisation, public InterfaceLancement
{
public:
	static InterfaceLancement* getInterfaceLancement();
	static InterfaceJournalisation* getInterfaceJournalisation() ;

	static void gererRequeteInfo(PUBG* pubg, queue<RequeteInfo*>* mesRequetesInfo);		// Cette m�thode doit �tre static
	static void gererRequete(PUBG* pubg, queue<Requete*>* mesRequetes);					// Cette m�thode doit �tre static

	thread** getMesThreads() override{ return mesThreads; }
	void lancerRequete(Requete* requete) override;
	void lancerRequeteInfo(RequeteInfo* requeteInfo) override;
	void journaliserRequete(Requete* requete, ServeurJeu* serveurJeu) override;



private:
	PUBG();
	ServeurJeu* getServeurFromRequete(Requete* requete);

	thread** mesThreads;					// On va regrouper les threads dans un tableau pour le main
	ServeurJeu** serveursJeu;				// Un tableau de Serveurs de jeu pour T4-T6
	queue<Requete*> mesRequetes;			// ma file de requete pour T2
	queue<RequeteInfo*> mesRequetesInfo;	// ma file de requeteInfo pour T3
	static PUBG* instance;
};

#endif
