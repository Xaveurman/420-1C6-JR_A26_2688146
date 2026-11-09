#include <format>
#include <iostream>
#include <string>

using namespace std;

void executerExercice01()
{	
	int somme = 0;
	double resulatsDivision = 0;
	int elementsTableau[15] = { -5, 38, -8, -12, 50, -26, 28, 16, -29, -40, 5, 23, 40, 32, -25 };

	cout << "--- Informations du tableau ---\n";

	cout << format("Premiere valeur  : {}\n", elementsTableau[0]);
	cout << format("Derniere valeur  : {}\n", elementsTableau[14]);

	for (int i = 0; i < 14; i++)
	{
	
		  somme += elementsTableau[i];

	}
	cout << format("Somme du tableau   : {}\n", somme);




		resulatsDivision = somme /= 15;

	
	cout << format("Moyenne du tableau : {:.2f}\n", resulatsDivision);
}