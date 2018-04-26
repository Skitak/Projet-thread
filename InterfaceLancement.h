#ifndef INTERFACELANCEMENT_H_
#define INTERFACELANCEMENT_H_

#include "requete/Requete.h"
#include "requete/RequeteInfo.h"
#include "ServeurJeu.h"
#include <thread>

class InterfaceLancement {
public:
//	InterfaceLancement();
//	virtual ~InterfaceLancement();

	virtual void lancerRequete(requete::Requete* requete) = 0;
	virtual void lancerRequeteInfo(requete::RequeteInfo* requeteInfo) = 0;
	virtual thread** getMesThreads() = 0;

};

#endif /* INTERFACELANCEMENT_H_ */
