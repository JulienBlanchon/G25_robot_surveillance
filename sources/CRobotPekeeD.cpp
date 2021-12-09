#include <iostream>
using namespace std;
#include "CRobotPekeeD.h"
#include "libRobotPekee.h"

CRobotPekeeD :: CRobotPekeeD(string un_nom, string une_adrIP, float cV, float cD)
		:RobotPekee(un_nom, une_adrIP)
{
	this-> coeffD = cD ;
	this-> coeffV = cV ;
};



CRobotPekeeD::~CRobotPekeeD()
{

};



void CRobotPekeeD :: avancer(float distance, int VitesseT)
{
	float DP;
	int VP;
	DP = this-> coeffD*distance;
	VP = this-> coeffV*VitesseT;
	this->RobotPekee::avancer(DP,VP);
	//phase de demarrage

	int DG;
	DG = distance-(2*DP);
	this->RobotPekee::avancer(DG,VitesseT);
	//phase de croisiere

	this->RobotPekee::avancer(DP,VP);
	//phase d'arret
};

void CRobotPekeeD :: reculer(float distance, int VitesseT)
{
	float DP;
	int VP;
	DP = this-> coeffD*distance;
	VP = this-> coeffV*VitesseT;
	this->RobotPekee::reculer(DP,VP);
	//phase de demarrage

	int DG;
	DG = distance-(2*DP);
	this->RobotPekee::reculer(DG,VitesseT);
	//phase normale

	this->RobotPekee::reculer(DP,VP);
	//phase d'arret
};
