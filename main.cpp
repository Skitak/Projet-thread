#include <iostream>
#include <thread>
#include <string>
#include <cstdlib>
#include "PUBG.h"
#include "requete/RequeteFactory.h"

using namespace std;
using namespace requete;

template <class T>
void afficher(T* requete) {
	cout << *requete << endl;
}

void maFonctionDeGestionDuMain()
{

	while (1)
	{
		string compte = "8INF114";
		int ip[4] = {127,0,0,1};
		int random = (rand() % 10) + 1;
		if (random == 10){
			RequeteInfo* requeteInfo = RequeteFactory::getInstance()->createRequeteInfo(ip);
			afficher(requeteInfo);
			PUBG::getInterfaceLancement()->lancerRequeteInfo(requeteInfo);
		}
		else {
			Requete* requete = RequeteFactory::getInstance()->createRequete(ip,compte);
			afficher(requete);
			PUBG::getInterfaceLancement()->lancerRequete(requete);
		}
		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	// On récupère les threads du Singleton afin de pouvoir les "joindre" avec le main
	thread** mesThreads = PUBG::getInterfaceLancement()->getMesThreads();

	thread t1(&maFonctionDeGestionDuMain);	// creation du thread qui va gérer les lancements dans le main
	for (int x = 0; x < 5; x++)
		mesThreads[x]->join();		// Jointure des threads T2-T6 avec le main
	t1.join();						// Jointure du thread T1 avec le main
	return 0;
}

