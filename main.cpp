#include <iostream>
#include <thread>
#include <string>
#include <regex>
#include <cstdlib>
#include "PUBG.h"
#include "requete/RequeteFactory.h"

using namespace std;
using namespace requete;

template <class T>
void afficher(T* requete) {
	cout << *requete << endl;
}

void maFonctionDeGestionDuMain(string compte, int* ip)
{

	while (1)
	{
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

void convertIp(string &ipStr, int* ip){
	size_t lastPos = 0;
	ip = new int[4]{};
	for (int i = 0; i < 4; ++i, ++lastPos){
		if (i != 3){
			size_t pos = ipStr.substr(lastPos).find(".");
			string ipByte = ipStr.substr(lastPos, pos);
			ip[i] = atoi(ipByte.c_str());
			lastPos += pos;
		}
		else {
			string ipByte = ipStr.substr(lastPos);
			ip[i] = atoi(ipByte.c_str());
		}
	}
}

void getInformationsUtilisateur (string &compte, int ip[]){
	cout << "Nom de compte?" << endl;
	cin >> compte ;
	string ipStr = "";
	bool firstError = true;
	while (!std::regex_match (ipStr, std::regex("^\\d{1,3}(\\.\\d{1,3}){3}$") )){
		if (!firstError){
			cout << "L'ip entrée est incorrecte." << endl;
			cout << "Veuillez entréer l'ip de nouveau." << endl;
		} else
			cout << "Ip?" << endl;
		cin >> ipStr;
		firstError = false;
	}
	convertIp(ipStr, ip);
}

int main()
{
	string compte = "hi";
//	compte = new string("hi");
	int* ip;
	getInformationsUtilisateur(compte, ip);
	// On récupère les threads du Singleton afin de pouvoir les "joindre" avec le main
	thread** mesThreads = PUBG::getInterfaceLancement()->getMesThreads();

	thread t1(&maFonctionDeGestionDuMain, compte, ip);	// creation du thread qui va gérer les lancements dans le main
	for (int x = 0; x < 5; x++)
		mesThreads[x]->join();		// Jointure des threads T2-T6 avec le main
	t1.join();						// Jointure du thread T1 avec le main
	return 0;
}

