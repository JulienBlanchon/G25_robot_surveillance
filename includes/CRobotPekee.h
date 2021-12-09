#pragma once

#include <iostream>
#include <string>
using namespace std;

#include "libRobotPekee.h"

class CRobotPekee : public WRobotPekee
{
	public:
	CRobotPekee(string un_nom, string une_adrIP);

	bool estConnecte(void);

	void avancer(void);

	void reculer(void);

	void tournerG(void);

	void tournerD(void);

	void clignoter(int nbclign);

	void avancer(float distance, int vitesseT = 100);

	void reculer(float distance, int vitesseT = 100);

	void tournerG(float angle, int vitesseA = 45);

	void tournerD(float angle, int vitesseA = 45);

	~CRobotPekee(void);

private:

	string nom;

	string adresseIP;

	bool connexion;
};

