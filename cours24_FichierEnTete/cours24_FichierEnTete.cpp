/*
	Auteur		: Xavier Blanchette
	Date		: 2026-10-22
	Description	: Fichiers d'en-tête en C++
*/

#include <format>
#include <iostream>
#include <string>
#include "Constantes.h"
#include "Fonctions.h"

using namespace std;


int main()
{
	cout << "--- Cours 24 - Parametres et fichier d'en-tete ---\n\n";

	// *** Fichiers ***
	// - Permettent d'organiser et répartir le code afin de se retrouver plus facilement
	// - Fichier d'en-tête (header file) .h
	//     - Contient des déclaration des fonctions (prototypes)
	//     - Contient des éléments global (constantes, enums, etc.)
	// - Fichier d'implémentation (C++ file) .cpp
	//     - Contient les définitions des fonctions (corps)
	// - Note
	//     - C++ est un des rares langages à utiliser des fichiers d'en-tête
	//	   - Langages modernes (C#, Java, Python, etc.) ont seulement des fichiers d'implémentation

	// *** Fichier de constantes ***
	// - Permettent de regrouper l'ensemble des valeurs constantes du projet
	//		- Constantes
	//		- Enums
	// - Dans un vrai projet qui doit supporter qui doit être localisé
	//		- Chaînes de caractères des différents messages
	//		- Voir plus tard avec les tableaux pour supporter plusieurs langages

	// TODO: Ajouter un fichier de constantes 'Constantes.h' avec les valeurs des constantes et enums
	// TODO: Inclure le fichier 'Constantes.h' dans le fichier principal du projet
	// TODO: Erreur de compilation en utilisant des constantes dans le fichier d'en-tête des fonctions (ex. AGE_MAJEUR)

	// *** Fichier d'en tête (header file) ***
	// - Contient seulement les déclaration des fonctions
	// - Doit inclure les définitions des types de données utilisées afin que les définitions de fonctions soient valides
	//		- Types de base toujours disponibles
	//			- int, double, char, bool
	//		- Problème classique de problème de compilation
	//			- std::string
	//			- Inclure la librairie  '#include <string>'
	//			- Ajouter le namespace standard 'using namespace std;'
	// - Inclure le fichier dans les autres fichiers (.cpp) qui doivent avoir les définitions des fonctions
	//		- #include "Header.h"
	//		- Fichiers qui contiennent au moins une utilisation des éléments suivants doivent inclure l'en-tête
	//			- Appel d'une des fonctions déclarée dans le fichier d'en-tête
	//			- Utilisation de constantes ou enum déclarées dans le fichier d'en-tête
	// - #pragma once
	//	    - Fichier d'en-tête est inclus plusieurs fois les définitions de fonctions serait normalement définies en doubles
	// 	    - S'assurer que le code est seulement présent une seule fois dans le projet au complet
	//		- Fichier d'en-tête doit toujours commencer par l'instruction #pragma once

	// TODO: Déplacer les Déclarations de fonctions (prototypes) créées précédemment dans le fichier d'en-tête
	// TODO: Compiler le code afin d'avoir un exemple d'erreurs d'inclusion de l'en-tête manquant
	// TODO: Fixer l'erreur en incluant le fichier d'en-tête dans le fichier cpp

	// *** Fichiers d'implémentation ***
	// - Permettent de distribuer le code des fonctions du projet
	// - Rend le code plus facile à lire
	// - Classes dans le cours de Programmation 2 utiliseront beaucoup de fichiers

	// TODO: Déplacer les définitions de fonctions (corps) dans un nouveau fichier 'Fonctions.cpp'
	// TODO: Inclure les librairies et le namespace nécessaires pour corriger les erreurs de compilation
	// TODO: Renommer le fichier d'en-tête pour 'Fonctions.h'

	if (false)
	{
		cout << format("Age majeur : {}\n", AGE_MAJEUR);
		cout << format("Taux de taxe : {}%\n", TAUX_TAXE * 100);
		cout << format("Vitesse de la lumiere : {} m/s\n\n", VITESSE_LUMIERE);

		Couleur couleurPreferee = Couleur::Bleu;
		cout << format("Couleur preferee valeur entiere : {}\n\n", (int)couleurPreferee);
	}

	// *** Paramètres par défaut ***
	// - Permettent lors de l'appel d'une fonction de ne pas avoir à entrer des valeurs pour tous les paramètres
	// - Utile pour ne pas avoir une fonction surchargée en 3-4 exemplaires avec code redondant
	// - En C++ spécifiquement
	//		- Définir une valeur par défaut dans la déclaration (prototype) de la fonction
	//		- Paramètres avec valeur doivent se suivre en bloc à partir de la fin
	//		- Dès qu'un paramètre a une valeur par défaut
	//		- Autres paramètres suivants doivent aussi avoir une valeur par défaut

	if (true)
	{
		double rabais1 = calculerAfficherRabais(100.0, 0.20, true, "Chaussures");
		double rabais2 = calculerAfficherRabais(100.0, 0.15, false, "");

		// TODO: Modifier la fonction afin de convertir les 2 dernier paramètres avec des valeurs par défaut
		// double rabais3 = calculerAfficherRabais(100.0, 0.3);

		// Erreur : paramètre obligatoire manquant
		// double rabais4 = calculerAfficherRabais(100.0);

		// Erreur : non pemis de sauter par dessus un paramètre avec valeur par défaut
		// double rabais5 = calculerAfficherRabais(100.0, 30, "");
	}

	// TODO: Modifier les fonctions afin d'avoir une seule fonction avec 3 paramètres avec une valeur par défaut 'INT_MIN'
	// TODO: Ne pas faire de comparaison dans la fonction si le nombre est 'INT_MIN'
	if (true)
	{
		int entierMinimal = INT_MIN; // -2147483648
		int entierMaximal = INT_MAX; // 2147483647

		bool estNombreEgal1 = estNombreEgal(10, 10);
		bool estNombreEgal2 = estNombreEgal(10, 10, 10);

		cout << format("Nombre egaux : {} {}\n", estNombreEgal1, estNombreEgal2);
	}

	// *** Early exit ***
	// - Permet de conserver le code des fonctions simples et if/else imbriqués
	// - Erreurs
	//		- Vérifier chaque erreur possible au début de la fonction
	//		- Retourner immédiatement une erreur
	// - Boucles
	//		- Retourner immédiatement lorsqu'une condition de fin est rencontrée
	//		- À voir plus tard avec les tableaux

	if (false)
	{
		// TODO: Transformer la fonction suivante avec 3 niveau de if avec des 'early exit'
		double efficacite1 = calculerEfficaciteEnergie(100, 200);
		cout << ("Efficacite 1 : {}%\n", efficacite1);

		double efficacite2 = calculerEfficaciteEnergie(0, 200);
		cout << ("Efficacite 2 : {}%\n", efficacite2);

		double efficacite3 = calculerEfficaciteEnergie(100, -1);
		cout << ("Efficacite 3 : {}%\n", efficacite3);

		// TODO: Créer une surcharge de la fonction afin d'écrire le message affiché dans une variable passée par référence (&)
		// string messageErreurEfficacite4;
		// double efficacite4 = calculerEfficaciteEnergie(100, -1, messageErreurEfficacite4);
		// if (efficacite4 == -1)
		//{
		// 	cout << "--- Erreur de lecture ---\n";
		//	cout << messageErreurEfficacite4;
		//}
		// else
		//{
		//	cout << ("Efficacite 4 : {}%\n", efficacite4);
		//}
	}
}

