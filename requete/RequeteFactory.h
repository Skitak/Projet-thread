#ifndef REQUETEFACTORY_H_
#define REQUETEFACTORY_H_
#include "Requete.h"
#include "RequeteInfo.h"
#include <string>

using namespace requete;

class RequeteFactory {
public:
	static RequeteFactory* getInstance();
	Requete* createRequete(int* ip, std::string compte);
	RequeteInfo* createRequeteInfo(int* ip);
	virtual ~RequeteFactory();


private:
	static RequeteFactory* instance;
	int sequenceId;
	RequeteFactory() {sequenceId = 0;}
	int getId();
	JeuInfo* getRandomJeuInfo();
};

#endif /* REQUETEFACTORY_H_ */
