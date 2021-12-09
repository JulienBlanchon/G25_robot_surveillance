#pragma once
#include <iostream>
#include <string>
#include "CRobotPekee.h"
using namespace std;
class CIhm 
{
public:
	CIhm(string nomRobot, string adrIPRobot);
	~CIhm(void);
	void demarrerPilotage(void);
	void afficherMenu(void);
	void traiterChoixCommande(int choix);
private:
	CRobotPekee robotAPiloter;
};

