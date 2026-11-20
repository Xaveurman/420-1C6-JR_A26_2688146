/*
	Auteur		: Mael Perreault
	Date		: 2026-11-20
	Description	: Introduction aux structs et classes
*/

#include <algorithm>
#include <format>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// TODO: Creer Etudiant.h et include
struct Etudiant
{
	string prenom = "";
	string nom = "";
	int age = -1;
	double moyenne = 0.0;
};

// TODO: Creer Position.h et include
struct Position
{
	int ligne = -1;
	int colonne = -1;
};

//void trouverPositionPremierNombre(const int tableau[][8], int nombreRecherche, int& ligneReponse, int& colonneReponse);
Position trouverPositionPremierNombre(const int tableau[][8], int nombreRecherche);
vector<Position> trouverPositionTousNombres(const int tableau[][8], int nombreRecherche);

void afficherEtudiant(Etudiant& etudiant)
{
	cout << format("--- Etudiant : {}, {} ---\n", etudiant.nom, etudiant.prenom);
	cout << format("Age: {}\n", etudiant.age);
	cout << format("Moyenne: {}\n\n", etudiant.moyenne);
}

Etudiant creerNouvelEtudiant()
{
	Etudiant etudiant;

	cout << "Entrer le prenom : ";
	cin >> etudiant.prenom;

	cout << "Entrer le nom : ";
	cin >> etudiant.nom;

	while (etudiant.age <= 0)
	{
		cout << "Entrer l'age : ";
		cin >> etudiant.age;
	}

	while (etudiant.moyenne <= 0)
	{
		cout << "Entrer la moyenne : ";
		cin >> etudiant.moyenne;
	}

	return etudiant;
}

int main()
{
	std::cout << "--- Cours 36 - Struct (classes) ---\n";

	// *** Classes (struct) ***
	// - Définir un type de données personnalisé contenant plusieurs variables
	//		- int, double, char, bool, string
	//		- int[], vector<double>, etc.
	//		- Peut contenir d'autres classes / struct
	// - Utilisation
	//		- Représenter des objets du monde réel (ex. Etudiant, Cours)
	//		- Regrouper des données liées ensemble dans un seul objet
	//		- Retourner plusieurs valeurs d'une fonction
	// - Syntaxe
	// 		- class MaClasse { ... };
	//		- struct MaStruct { ... };
	//		- Nomenclature
	//			- PascalCase
	//			- Normalement nom au singulier
	//				- Etudiant, Cours, Voiture, etc.
	// - Différences
	//		- class : variables sont privée par défaut
	//		- struct : variables sont publiques par défaut
	// - Classes seront utilisées dans le prochain cours de programmation

	if (false)
	{
		struct MaStruct
		{
			// Variables sont publiques par défaut, mot clé 'public:' implicite au début de la classe
			// public:
			int variablePublique1 = -1;			// Bonne pratique de définir des valeurs par défaut
			double variablePublique2 = 0;
			char variablePublique3 = '\0';
			bool variablePublique4 = false;
			string variablePublique5 = "Vide";

			// Variables après le mot clé 'private:' sont privées
		private:
			int variablePrivee1 = -1;
			double variablePrivee2 = 0;
			char variablePrivee3 = '\0';
			bool variablePrivee4 = false;
			string variablePrivee5 = "Vide";
		};
		// Attention au point-virgule à la fin de la struct

		class MaClasse
		{
			// Variables sont privées par défaut, mot clé 'private:' implicite au début de la classe
			// private:
			int variablePrivee1 = -1;
			double variablePrivee2 = 0;
			char variablePrivee3 = '\0';
			bool variablePrivee4 = false;
			string variablePrivee5 = "Vide";

			// Variables après le mot clé 'public:' sont publiques
		public:
			int variablePublique1 = -1;
			double variablePublique2 = 0;
			char variablePublique3 = '\0';
			bool variablePublique4 = false;
			string variablePublique5 = "Vide";
		};
		// Attention au point-virgule à la fin de la classe

		// TOOD: Créer une instance de MaStruct et MaClasse et assigner des valeurs aux variables publiques
		MaStruct maStruct1;

		maStruct1.variablePublique1 = 100;
		maStruct1.variablePublique2 = 123.456;
		maStruct1.variablePublique3 = 'a';
		maStruct1.variablePublique4 = true;
		maStruct1.variablePublique5 = "abcde";

		MaClasse maClasse1;

		maClasse1.variablePublique1 = 100;
		maClasse1.variablePublique2 = 123.456;
		maClasse1.variablePublique3 = 'a';
		maClasse1.variablePublique4 = true;
		maClasse1.variablePublique5 = "abcde";

		// TODO: Tentrer de modifier les variables privées
		//maStruct1.variablePrivee1 = 15; // Erreur : variable privée inaccessible
		//maClasse1.variablePrivee1 = 5;  // Erreur : variable privée inaccessible

		// TODO: Créer un vecteur de MaStruct et ajouter 2 copies de MaStruct au vecteur
		vector<MaStruct> maStructs;

		maStructs.push_back(maStruct1);
		maStructs.push_back(maStruct1);

		maStructs[0].variablePublique1 = 500;
		maStructs[0].variablePublique3 = 'z';

		maStructs[1].variablePublique1 = 456456789;
	}

	// *** Utilisation *** 
	// - Fichier d'en-tête séparé (.h)
	//		- Définir une nouveau type de données struct contenant des variables avec des valeurs par défaut
	//			struct MaStruct
	// 			{
	//			    int variable1 = 0;
	//			    int variable2 = -1;
	// 			};
	// - Utilisation dans un autre fichier source (ex. main.cpp)
	//		- Inclure le fichier d'en-tête
	//			#include "MaStruct.h"
	// 		- Déclarer des variables du nouveau type (instances) et assigner les valeurs des variables
	//			MaStruct maStruct;
	//			maStruct.variable1 = valeur;
	// 			maStruct.variable2 = valeur;
	//		- Utiliser les valeurs des variables lorsque nécessaires
	//			cout << maStruct.variable1;
	//			cout << "Total : " << maStruct.variable1 + maStruct.variable2;

	if (false)
	{
		// TODO: Créer une struct Etudiant avec les données : prenom, nom, age, moyenne

		// TODO: Créer un premier étudiant avec des valeurs
		// - Charles Patenaude, 24 ans, moyenne 85.5
		Etudiant etudiantCharles;

		etudiantCharles.prenom = "Charles";
		etudiantCharles.nom = "Patenaude";
		etudiantCharles.age = 24;
		etudiantCharles.moyenne = 85.5;

		// TODO: Afficher l'étudiant à l'écran à l'aide des données de la struct
		afficherEtudiant(etudiantCharles);

		// TODO: Créer un deuxième étudiant avec une initialisation rapide des valeurs
		// - Bob Avec-Cheveux, 21 ans, moyenne 90.5
		// - Attention, les valeur doivent être dans le même ordre que la struct
		//		- Etudiant etudiant = { "Prenom", "Nom", age, moyenne };
		//		- Dangeureux pour se tromper ou si la struct est modifiée plus tard
		//			- Ajouter une variable 'adresse' entre 'nom' et 'age' brise les initialisations rapides
		//			- Inverser l'ordre de 'prenom' et 'nom' brise les initialisations rapides
		Etudiant etudiantBob = { "Bob", "Avec-Cheveux", 21, 90.5 };

		// TODO: Afficher l'étudiant à l'écran
		afficherEtudiant(etudiantBob);

		// TODO: Initialiser le vecteur d'étudiants avec 3 etudiants :
		// - Alan Turing, 19 ans, moyenne 80.2
		// - Ben Franklin, 50 ans, moyenne 65.3
		// - Carl Sagan, 21 ans, moyenne 78.4
		vector<Etudiant> etudiants =
		{
			{ "Alan", "Turing", 19, 80.2 },
			{ "Ben", "Franklin", 50, 65.3 },
			{ "Carl", "Sagan", 21, 78.4 }
		};

		// TODO: Ajouter les 2 étudiants créés précédemment au vecteur (Charles, Bob)
		etudiants.push_back(etudiantCharles);
		etudiants.push_back(etudiantBob);

		// TODO : Afficher tous les étudiants du vecteur avec la fonction 'afficherEtudiant()'
		for (int i = 0; i < etudiants.size(); i++)
		{
			afficherEtudiant(etudiants[i]);
		}

		// TODO: Modifier la moyenne de tous les étudiants du vecteur directement un index [i]
		for (int i = 0; i < etudiants.size(); i++)
		{
			etudiants[i].moyenne = 0.0;
		}

		// TODO : Afficher tous les étudiants du vecteur à l'écran
		for (int i = 0; i < etudiants.size(); i++)
		{
			afficherEtudiant(etudiants[i]);
		}

		// TODO: Récupérer un 'Etudiant' à partir de l'index du vecteur et modifier la moyenne
		// - Copie temporaire modifiée, n'affecte pas le tableau
		Etudiant etudiantModifier = etudiants[0];
		etudiantModifier.moyenne = 100;

		// TODO : Afficher tous les étudiants du vecteur à l'écran
		for (int i = 0; i < etudiants.size(); i++)
		{
			afficherEtudiant(etudiants[i]);
		}

		// TODO: Récupérer un 'Etudiant&' à partir de l'index du vecteur et modifier la moyenne
		// - Modifications une référence modifient les éléments du tableau
		Etudiant& etudiantReference = etudiants[0];
		etudiantReference.moyenne = 100;

		// TODO : Afficher tous les étudiants du vecteur à l'écran
		for (int i = 0; i < etudiants.size(); i++)
		{
			afficherEtudiant(etudiants[i]);
		}
	}

	// *** Fonctions ***
	// - Paramètre par valeur (copie) 
	// 		- void fonction(MaStruct parametre) { ... }
	//		- Aucune des modifications des variables n'affectent l'original
	//		- Sauf les pointeurs comme les tableaux qui pointent sur la même adresse
	//			- Ex. int[], int[][]
	// - Paramètre par référence (&)
	// 		- void fonction(MaStruct& parametre) { ... }
	//		- Modifications des variables affectent l'original
	// - Retour d'une struct
	//		- Retourner une struct pour retourner plusieurs valeurs d'une seule fonction
	//			- MaStruct fonction() { ... return maStruct; }
	//			- Préférable à l'utilisation de plusieurs références (&)
	//			- Empêcher les 'effets de bord' des fonctions (modifications involontaires ou cachées)
	//			- Assigner les valeurs retournées aux bonnes variables rend le code plus facile à suivre
	//		- Éviter
	//			void fonction(int& valeur1, int& valeur2) { ... }
	//		- Préférer
	//			MaStruct fonction(int valeur1, int valeur2) 
	//		    {
	//				MaStruct maStruct;
	//				maStruct.valeur1 = valeur1 + 5;
	//				maStruct.valeur2 = valeur2 + 10;
	//				return maStruct; 
	//		    }
	//	
	//			MaStruct maStructReponse = fonction(10, 20);
	//		    variable1 = maStructReponse.valeur1;
	//		    variable2 = maStructReponse.valeur2;
	if (false)
	{
		// TODO : Créer une fonction capable de créer un nouvel étudiant
		//Etudiant nouvelEtudiant = creerNouvelEtudiant();

		// TODO: Appeler la fonction plusieurs fois pour remplir un vecteur d'étudiants
		vector<Etudiant> etudiants;

		for (int i = 0; i < 5; i++)
		{
			Etudiant etudiant = creerNouvelEtudiant();
			etudiants.push_back(etudiant);
		}

		for (int i = 0; i < etudiants.size(); i++)
		{
			afficherEtudiant(etudiants[i]);
		}
	}

	if (true)
	{
		int tableau[8][8] =
		{
			{ 1, 2, 3, 4, 5, 6, 7, 8 },
			{ 8, 7, 6, 5, 4, 3, 2, 1 },
			{ 1, 2, 3, 4, 5, 6, 7, 8 },
			{ 8, 7, 6, 5, 4, 3, 2, 1 },
			{ 1, 2, 3, 4, 5, 6, 7, 8 },
			{ 8, 7, 6, 5, 4, 3, 2, 1 },
			{ 1, 2, 3, 4, 5, 6, 7, 8 },
			{ 8, 7, 6, 5, 4, 3, 2, 1 },
		};

		// Afficher le tableau à l'écran
		cout << "Tableau 8x8 :\n";
		for (int ligne = 0; ligne < 8; ligne++)
		{
			for (int colonne = 0; colonne < 8; colonne++)
			{
				cout << format("{:3} ", tableau[ligne][colonne]);
			}
			cout << "\n";
		}

		// TODO: Trouver la première position du tableau ('ligne' et 'colonne') qui contient une valeur spécifique (ex. 8 ou 123)
		// TODO: Créer une structure 'Position' pour les fonctions avec : ligne et colonne
		//int ligne;
		//int colonne;
		//trouverPositionPremierNombre(tableau, 8, ligne, colonne);
		Position position8 = trouverPositionPremierNombre(tableau, 8);
		cout << format("Position du premier 8   : ({}, {})\n", position8.ligne, position8.colonne);

		Position position123 = trouverPositionPremierNombre(tableau, 123);
		cout << format("Position du premier 123 : ({}, {})\n", position123.ligne, position123.colonne);

		// TODO: Trouver toutes les positions du tableau 'ligne' et 'colonne' qui contiennent une valeur spécifique
		vector<Position> positions8 = trouverPositionTousNombres(tableau, 8);
		cout << format("Positions de tous les nombres 8 :\n");

		for (int i = 0; i < positions8.size(); i++)
		{
			cout << format("  ({}, {})\n", positions8[i].ligne, positions8[i].colonne);
		}
	}

	// TODO: Déplacer les structures et les fonctions dans des fichiers d'en-tête séparés (.h)
	// - C# : simplement faire 'Ctrl+.' sur le nom de la classe et choisir 'Déplacer vers le fichier...'
	// - C++ : option n'existe pas
}

//void trouverPositionPremierNombre(const int tableau[][8], int nombreRecherche, int& ligneReponse, int& colonneReponse)
Position trouverPositionPremierNombre(const int tableau[][8], int nombreRecherche)
{
	// Initialiser la position à des valeurs invalides (-1, -1)
	Position position;

	for (int ligne = 0; ligne < 8; ligne++)
	{
		for (int colonne = 0; colonne < 8; colonne++)
		{
			int nombre = tableau[ligne][colonne];
			if (nombre == nombreRecherche)
			{
				position.ligne = ligne;
				position.colonne = colonne;

				// Retourner la position trouvée
				return position;
			}
		}
	}

	// Retourner une position invalide (-1, -1)
	return position;
}

vector<Position> trouverPositionTousNombres(const int tableau[][8], int nombreRecherche)
{
	vector<Position> positions;

	for (int ligne = 0; ligne < 8; ligne++)
	{
		for (int colonne = 0; colonne < 8; colonne++)
		{
			int nombre = tableau[ligne][colonne];
			if (nombre == nombreRecherche)
			{
				Position position;

				position.ligne = ligne;
				position.colonne = colonne;

				positions.push_back(position);
			}
		}
	}

	return positions;
}
