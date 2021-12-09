
#include <iostream>
#include <string>
using namespace std;

#include "CRobotPekee.h"


CRobotPekee::CRobotPekee(string un_nom, string une_adrIP)
{
	this->nom = un_nom;
	this->adresseIP = une_adrIP;
	
	char adr[16];
	strcpy(adr, this->adresseIP.c_str());

	char n[10];
	strcpy(n, this->nom.c_str());

	this->connexion = this->Connect(adr,n);

	if (this->estConnecte() == false)
	{
	throw runtime_error("Erreur : le robot n’est pas connecté");
	}
}

bool CRobotPekee::estConnecte(void)
{
	return this->connexion;
}

void CRobotPekee::avancer(void)
{
	this->SetSpeed(100,0);
}

void CRobotPekee::reculer(void)
{
	this->SetSpeed(-100,0);
}

void CRobotPekee::tournerG(void)
{
	this->SetSpeed(0,-45);
}

void CRobotPekee::tournerD(void)
{
	this->SetSpeed(0,45);
}

void CRobotPekee::clignoter(int nbclign)
{
	for (int i=0;i<nbclign;i++)
	{
		this->LedOn();
		Sleep(100);
		this->LedOff();
		Sleep(100);
	}
}

void CRobotPekee::avancer(float distance, int vitesseT)
{
	float x,y,angle;
	x=0;
	this->ResetPosition();
	do
	{
		this->SetSpeed(vitesseT,0);
		this->GetPosition(x,y,angle);
	}while(distance > x);
}

void CRobotPekee::reculer(float distance, int vitesseT)
{
	vitesseT = -vitesseT;
	float x,y,angle;
	x=0;
	this->ResetPosition();
	do
	{
		this->SetSpeed(vitesseT,0);
		this->GetPosition(x,y,angle);
	}while(distance > -x);
	vitesseT = -vitesseT;
}

void CRobotPekee::tournerG(float angle, int vitesseA)
{
	
}

void CRobotPekee::tournerD(float angle, int vitesseA)
{
	
}

CRobotPekee::~CRobotPekee(void)
{
	this->Disconnect();
}
