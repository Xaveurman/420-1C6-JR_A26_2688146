#pragma once

// *** Déclaration de fonctions ***
// - Permet de déplacer le corps de la fonction à un autre endroit que le début du main()
// - Indique au compilateur qu'une fonction existera plus tard qui respecte la signature de fonction
//		- Signature : type de retour, nom et paramètres du bon type dans l'ordre
// - Compilateur s'occupe plutard de faire la liaison (linking) vers le code de la fonction
//
// type nomFonction(type1, type2, ...);
// 
// TODO: Convertir les fonctions suivantes en 2 parties : déclaration et définition
// - F12 : Aller à la déclaration contenant le code
// - Ctrl+F12 : Aller à la définition courte

#include <string>

using namespace std;

double calculerAfficherRabais(double prix, double rabais, bool estAfficherConsole, string nom = "");


bool estNombreEgal(int nombre1, int nombre2, int nombre3 = INT_MIN);

int calculerResultat(int nombre1, int nombre2);
double calculerEfficaciteEnergie(double energieSortie, double energieEntree);
