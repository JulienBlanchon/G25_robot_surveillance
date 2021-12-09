#include <iostream>
using namespace std;
#include "CRobotPekeeClign.h"
#include "libRobotPekee.h"

CRobotPekeeClign :: CRobotPekeeClign(string un_nom, string une_adrIP, int clign)
		:RobotPekee(un_nom, une_adrIP)
{
    this->nbclign = clign;
	
};



CRobotPekeeClign::~CRobotPekeeClign()
{
    
};



void CRobotPekeeClign :: avancer(float distance, int VitesseT)
{
	int nbclign = 10;
	this->RobotPekee::avancer(distance,100);
	this->RobotPekee::clignoter(nbclign);
};

void CRobotPekeeClign :: reculer(float distance, int VitesseT)
{
	int nbclign = 10;
	this->RobotPekee::reculer(distance,100);
	this->RobotPekee::clignoter(nbclign);
};
