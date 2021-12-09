
#include <iostream>
#include <string>
using namespace std;

#include "CIhm.h"



CIhm::CIhm(string nomRobot, string adrIPRobot)
: robotAPiloter(nomRobot, adrIPRobot)
{
}

void CIhm::demarrerPilotage(void)
{
	int choix = 10;
	if (robotAPiloter.estConnecte())
	{
		cout << "connexion avec le robot ok \n";
		while(choix !=0)
		{
		afficherMenu();
		cin >> choix;
		traiterChoixCommande(choix);
		}
	}
		cout << "probleme de connexion avec le robot  \n";
		cout << "pour sortir : appuyer sur une touche\n";
}

void CIhm::afficherMenu(void)
{
		cout << "Test unitaire des méthodes du robot" << endl;
		cout << "**************************" << endl<< endl;
		cout << "Quelle méthode dois tu tester ?" << endl;
		cout << "1 - Avancer" << endl;
		cout << "2 - Reculer" << endl;
		cout << "3 - Tourner à gauche  " << endl;
		cout << "4 - Tourner à droite" << endl;
		cout << "5 - Clignoter la led" << endl;
		cout << "6 - Avancer sur une distance" << endl;
		cout << "7 - Reculer sur une distance" << endl;	
		cout << "8 - Tourner à gauche sur un certain angle" << endl;
		cout << "9 - Tourner à droite sur un certain angle" << endl;	
		cout << "0 - Fin des tests" <<endl;
}

void CIhm::traiterChoixCommande(int choix)
{
	float distance;    // distance du déplacement

	int vitesse = 100; // vitesse robot

	int vjidshoipsd = 0; // nb clignotements
	
	int angle = 0; // angle robot

	switch (choix)
		{
			case 1 :		
					//  AVANCER
					robotAPiloter.avancer();
					break;
			case 2 :	
					//  RECULER
					robotAPiloter.reculer();
					break;		
			case 3 :	
					//  TOURNER A GAUCHE
					robotAPiloter.tournerG();
					break;

			case 4 :	
					//  TOURNER A DROITE
					robotAPiloter.tournerD();
					break;

			case 5 :	
					// Clignoter LA LED
					cout << "combien de clignotements tu veux ?";
					cin >> vjidshoipsd;
					robotAPiloter.clignoter(vjidshoipsd);
					break;
			
			case 6 :	//  AVANCER sur une distance
						cout << "Quelle distance de déplacement ? :" <<endl;
						cin >> distance;
						robotAPiloter.avancer(distance,vitesse);
						break;
			case 7 :	//  RECULER sur une distance
						cout << "Quelle distance de déplacement ? :" <<endl;
						cin >> distance;
						robotAPiloter.reculer(distance, vitesse);
						break;
			case 8 :	//  Tourner G sur angle
						cout << "Quel angle ? :" <<endl;
						cin >> angle;
						robotAPiloter.tournerG(angle,vitesse);
						break;
			case 9 :	//  Tourner D sur angle
						cout << "Quel angle ? :" <<endl;
						cin >> angle;
						robotAPiloter.tournerD(angle,vitesse);
						break;
			case 0 :	
						{
							cout << "Fin commande du robot" <<endl;
							cout << "*********************" << endl;
							break;
						}
			default :	cout << "Erreur de saisie" <<endl;
						break;
		} 	
}

CIhm::~CIhm(void){}
