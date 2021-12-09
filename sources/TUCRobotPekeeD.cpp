#include <iostream>
using namespace std;
#include "CRobotPekeeD.h"
#include "libRobotPekee.h"




//***********************************************************************
// Déclaration des fonctions
//**********************************************************************

void avancer_robot(WRobotPekee &robot, float vitesse, float distance);


//*********************************************************************




//**********************************************************************
// Fonction : main
// Rôle : se connecter au robot et le commander
//**********************************************************************

int main(void)
{
	CRobotPekeeD robot("Pekee","localhost",0.2,0.2);  // Instance de WRobotPekee
	//bool estConnect=false;  // indique si la connexion avec le robot est faite
	// Connexion au robot simulé

	
	cout << "Connexion avec le robot :" << endl;
	cout << "-------------------------" << endl;

	//estConnect = robot.Connect("localhost", "Pekee");

	if (robot.estConnecte())
	{
		cout << "connexion avec le robot ok \n";
		wint16	vitesse = 500 ,	// vitesse de translation en mm/s
		vrotation  = 45   ; 	// vitesse de rotation en degre/s;
		float distance;    // distance du déplacement
		int rep;		// choix de l'utilisateur
		int i;
	do
	{
		cout << "Test unitaire de la classe Robot Pekee" << endl;
		cout << "**************************" << endl<< endl;
		cout << "Quel test unitaire voulez vous faire ?" << endl;
		cout << "1 - Avancer" << endl;
		cout << "2 - Reculer" << endl;
		
		cout << "0 - Fin commande du robot" <<endl;

		cin >> rep;

		switch (rep)
		{
			case 1 ://  AVANCER
					cout << "Quelle distance de déplacement ? :" <<endl;
					cin >> distance;
					robot.avancer(distance, vitesse);
					break;

			case 2 ://  RECULER
					cout << "Quelle distance de déplacement ? :" <<endl;
					cin >> distance;
					robot.reculer(distance, vitesse);
					break;
						
		} 
	} while (rep != 0);
			
						
	
		// Déconnexion au robot
		robot.Disconnect();
		
			
	}
	else
	{
		cout << "probleme de connexion avec le robot  \n";
		cout << "pour sortir : appuyer sur une touche\n";

	}

	return 0 ;
}