#pragma once
#include <string>
using namespace std;
#include "librobotpekee.h"
#include "RobotPekee.h"

class CRobotPekeeD :	
		public RobotPekee
{
public:
	CRobotPekeeD(string un_nom, string une_adrIP, float coeffV, float coeffD);
	~CRobotPekeeD(void);
	void avancer(float distance, int VitesseT=100);
	void reculer(float distance, int VitesseT=100);

private: 
	float coeffV;
	float coeffD;
};