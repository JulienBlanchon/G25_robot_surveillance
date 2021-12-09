
#include <iostream>
#include <string>
using namespace std;

#include "CIhm.h"

int main()
{
	
	try
	{
		CIhm ihm ("Pekee", "localhost");
		ihm.demarrerPilotage();
	}
	catch (runtime_error &excep)
	{
		cout << excep.what();
	}
	return 0;
}