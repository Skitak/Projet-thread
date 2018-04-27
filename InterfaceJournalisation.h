#ifndef INTERFACEJOURNALISATION_H_
#define INTERFACEJOURNALISATION_H_

#include "requete/Requete.h"
#include "ServeurJeu.h"

class InterfaceJournalisation {
public:
//	InterfaceJournalisation();
	virtual ~InterfaceJournalisation(){}

	virtual void journaliserRequete(requete::Requete* requete, ServeurJeu* serveurJeu) = 0;
};

#endif /* INTERFACEJOURNALISATION_H_ */
