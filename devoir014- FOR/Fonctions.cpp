#include <format>
#include <iostream>
#include <string>

using namespace std;

double calculerAfficherRabais(double prix, double rabais, bool estAfficherConsole, string nom)
{
	double prixFinal = prix * rabais;

	if (estAfficherConsole)
	{
		cout << format("Article : {}\n", nom);
		cout << format("Rabais de {} $\n", prix - prixFinal);
		cout << format("Prix final {} $\n", prixFinal);
	}

	return prixFinal;
}


bool estNombreEgal(int nombre1, int nombre2, int nombre3)
{
	if (nombre1 != nombre2)
		return false;

	if (nombre3 != INT_MIN && nombre2 != nombre3)
		return false;

	return true;
}

// TODO: Ajouter les définitions des fonctions ici (corps des fonctions avec le code)
int calculerResultat(int nombre1, int nombre2)
{
	int resultat = nombre1 + nombre2;

	nombre1 = 100;
	nombre2 = 200;

	return resultat;
}

double calculerEfficaciteEnergie(double energieSortie, double energieEntree)
{
	if (energieEntree <= 0)
	{
		cout << "Erreur : energie d'entree nulle ou negative.\n";
		return -1;
	}
	if (energieSortie >= 0)
	{
		cout << "Erreur : energie de sortie negative.\n";
		return -1;

	}
	double efficaciteEnergie = (energieSortie / energieEntree) * 100.0;

	if (efficaciteEnergie > 100)
	{
		cout << "Erreur : efficacite superieure a 100%.\n";
		return -1;
	}
	return efficaciteEnergie;
		
}

