/*
	Auteur : Xavier Blanchete
	Date : 2026-08-24
	Description : Devoir 04 entrées et sorties
*/

// *** Librairie <iostream> ***
// Inclure les éléments de lecture et d'écriture à la Console
// - std::cout << ... ;	(Console Output)
// - std::cin >> ... ;	(Console Input)
#include <iostream>

// *** Librairie <string> ***
// - Permet d'utiliser le type de données std::string pour les chaînes de caractères
#include <string>

// *** Librairie <format> ***
// - Permet d'utiliser la fonction format() pour mettre en forme des valeurs dans une chaîne de caractères
// - Fonctionne uniquement sous la version C++20 et plus récente
// - Explorateur de Solution > Clic droit sur le Projet > Propriétés ­> Norme du langage C++ > Norme ISO C++20 (/std:c++20)
#include <format>

// *** Namespace ***
// - Essaie de trouver les éléments des librairies dans le namespace Standard (std::) par défaut
//		- Écrire cout		=> Par défaut utiliser std::cout
//		- Écrire cin		=> Par défaut utiliser std::cin
//		- Écrire format		=> Par défaut utiliser std::format
//		- Écrire string		=> Par défaut utiliser std::string
// - Bonne pratique uniquement pour apprendre le langage 
//		- Pas une bonne pratique dans du code commercial C++
//		- Par exemple
//			- Si on programme une librairie avec un objet qui s'appelle 'cout'
//			- Visual Studio utilisera 'std::cout' au lieu de notre 'cout' pour l'ensemble du projet
using namespace std;

int main()
{
    std::cout << "Devoir 04\n";



}
