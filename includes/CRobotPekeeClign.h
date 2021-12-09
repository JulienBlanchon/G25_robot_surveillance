#pragma once
#include <string>
using namespace std;
#include "librobotpekee.h"
#include "RobotPekee.h"

class CRobotPekeeClign :	
		public RobotPekee
{
public:
	CRobotPekeeClign(string un_nom, string une_adrIP, int clign);
	~CRobotPekeeClign(void);
	void avancer(float distance, int VitesseT=100);
	void reculer(float distance, int VitesseT=100);

private: 
	int nbclign;
};