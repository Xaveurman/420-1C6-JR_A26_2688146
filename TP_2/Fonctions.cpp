#include <format>
#include <iostream>
#include <string>
#include "Fonctions.h"
#include "Constantes.h"
using namespace std;

double nombre = 0;
double resultat = 0;
string message = "";
double ancienResultat = 0;
string symbole = "";

void afficherMenu()
{ 
	// Affichage de l'en-tête
	cout << "\n***********************************************************\n";
	cout << "*                     Imprimerie CSTJ                     *\n";
	cout << "*           Par Votre Xavier Blanchette (2688146)         *\n";
	cout << "***********************************************************\n";
	
	if (message != "")
	{
		cout << format("{}\n", message);
		message = "";
	}

	if (false)
	{
		cout << format("Opération : {} {} {} = \n\n", ancienResultat, symbole, nombre);
		cout << format("Résultat : {} \n\n", resultat);
	}

	cout << "+) Addition\n";
	cout << "-) Soustraction\n";
	cout << "*) Multiplication\n";
	cout << "/) Division\n";
	cout << "^) Exposant\n\n";

	cout << "!) Factorielle\n";
	cout << "s) Série de Taylor\n\n";

	cout << "r) Rectangle\n";
	cout << "t) Triangle\n\n";

	cout << "q) Quitter\n\n";
}
void calculeAddition()
void calculeSoustraction()
void calculeMultiplication()
void calculeDivision()
void calculeExposant()
void calculeFactorielle()
void calculeSérie de Taylor()
void calculeRectangle()
void calculeTriangle()
void calculeQuitter()
