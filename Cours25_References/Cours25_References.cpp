/*
	Auteur		: Xavier Blanchette
	Date		: 2026-10-23
	Description	: Passage de paramètres par valeur (copie) et par référence (&)
*/

#include <format>
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

// Ne jamais faire de variables globales, seulement pour l'exemple de mémoire
int variableGlobale = 123;

// TODO: Déplacer les fonctions dans d'autres fichiers
void incrementer(int& compteur)
{
	compteur += 1;
}
void decrementer(int& compteur)
{
	compteur -= 1;
}

void ajouterPoints(int& score, string& messageScore, int pointsObtenus)
{
	score += pointsObtenus;
	messageScore += format("Joueur a obtenus {} points!\n", pointsObtenus);
}

void echangerNombres(int& nombre1, int& nombre2)
{
	int temporaire = nombre1;
	nombre1 = nombre2;
	nombre2 = temporaire;
}

void fonctionA()
{
	int b = 20;
	int resultat = fonctionB(b);
	cout << "Resultat est : " << resultat << "\n";
}


int main()
{
	cout << "--- Cours 25 - Parametres par reference ---\n\n";

	// *** Stack (Pile) ***
	// - Espace réservé pour les appels de fonctions afin de conserver les variables
	// - Fo
	//
	// *** Fonctionnement d'un appel de fonction ***
	// TODO: Dessiner le fonctionnement des fonctions
	// - Fonctionnement du Stack et des Scopes
	// - Appel d'une fonction
	//		- Réservation des espaces mémoires
	//			- Adresse de retour après appel de fonction
	//			- Valeur de retour lors du retour de la fonction
	//			- Paramètres de la fonction
	//			- Variables de la fonction
	//		- Notions de pointeur d'instruction et d'exécution des programmes
	//		- Saut à l'adresse du code de la fonction
	// - Retour d'une fonction
	//		- Écriture de la valeur dans la case de valeur de retour temporaire
	//		- Retour à l'adresse de retour dans la fonction originale
	//		- Utilisation de la valeur de retour
	//		- Suppression du Stack des espacers mémoires reservés pour l'appel de la fonction
	//			- Adresse retour, valeur de retour, paramètres et variables
	// - Tracer les fonctions : main(), fonctionA(), fonctionB()

	if (false)
	{
		cout << format("Variable globale avant : {}\n", variableGlobale);

		int a = 10;
		fonctionA();

		cout << format("Variable globale apres : {}\n", variableGlobale);
	}

	// *** Références (&) et pointeurs (*) ***
	// - Normalement, les cases en mémoire qui contiennent des valeurs
	//		- int, double, char, string, etc.
	// - Possible de définir un lien vers une autre case en mémoire plutôt qu'une valeur
	//		- Références (&)
	//			 - int&, double&, char&, string&, etc.
	//		- Pointeurs (*)
	//			- int*, double*, char*, string*, etc.
	//		- Très similaires, simplement un lien vers une adresse en mémoire (ex. 0x123456)
	//		- Pour le cours
	//			- Références (&) seront utilisées, car elles sont plus simples
	//			- Pointeurs (*) sont plus puissants, mais beaucoup de langages empêchent leur utilisation directe

	// TODO : Dessiner le fonctionnement en mémoire des références
	if (false)
	{
		// Variables réservent des emplacements mémoire
		int x = 10;
		int y = 50;

		cout << format("Adresse memoire de x : {:#x}\n", (unsigned int)(&x));
		cout << format("Valeur de x : {}\n\n", x);

		cout << format("Adresse memoire de y : {:#x}\n", (unsigned int)(&y));
		cout << format("Valeur de y : {}\n\n", y);

		// & : pas une nouvelle case mémoire, mais une référence (pointeur) à l'emplacement mémoire de 'x'
		int& reference = x;

		cout << format("Adresse memoire de reference : {:#x}\n", (unsigned int)(&reference));
		cout << format("Valeur de reference : {}\n\n", reference);

		// Référence permet de modifier la valeur de la case mémoire 'x' à la valeur 20
		reference = 20;

		cout << format("Adresse memoire de x : {:#x}\n", (unsigned int)(&x));
		cout << format("Adresse memoire de reference : {:#x}\n", (unsigned int)(&reference));

		cout << format("Valeur de x : {}\n", x);
		cout << format("Valeur de reference : {}\n\n", reference);

		cout << format("Valeur de x après modification via référence : {}\n", x);
	}

	// *** Paramètre par référence (&) ***
	// - Permettent de recevoir un pointeur vers une variable de la fonction parant afin de modifier sa valeurs
	// - Paramètre par copie
	//		- Par défaut, les valeurs des paramètres sont passées par 'copie'
	//			- int calculerResultat(int nombre)
	//		- Appel de la fonction
	//			- Nouvelle boite en mémoire est créée
	//			- Valeur est copiée dans la nouvelle boite
	//		- Fin de la fonction
	//			- Boites sont détruites
	//			- Valeurs modifiées sont perdues
	// - Paramètre par référence
	//		- Utiliser la syntaxe (&) après le type d'un paramètre
	//			- int calculerResultat(int& nombre)
	//		- Appel de la fonction
	//			- Nouvelle boite en mémoire est créée
	//			- Adresse de la variable originale est inscrite dans la boite plutôt que la valeur
	//		- Fin de la fonction
	//			- Nouvelle boite en mémoire est créée
	//			- Paramètres est maintenant un lien vers l'adresse
	// - Utile pour avoir une fonction qui 'retourne' plusieurs valeurs
	//		- int calculerResultat(int& nombre, double& valeur, string& chaine)
	//			- Valeur du type de retour
	//				- 1 valeur int retourné
	//			- Chaque variable passée par référence (&) est aussi 'retournée' ou en fait 'modifiée' par la fonction
	//				- 3 variables modifiées : int&, double&, string&

	// TODO : Dessiner le fonctionnement en mémoire de l'appel des fonctions suivantes
	if (false)
	{
		cout << "--- calculerResultat() ---\n\n";

		int nombre1 = 10;
		int nombre2 = 20;

		cout << format("Nombre 1 (avant appel) : {}\n", nombre1);
		cout << format("Nombre 2 (avant appel) : {}\n\n", nombre2);

		int resultat1 = calculerResultat(nombre1, nombre2);

		cout << format("Resultat 1 : {}\n\n", resultat1);

		cout << format("Nombre 1 (apres appel) : {}\n", nombre1);
		cout << format("Nombre 2 (apres appel) : {}\n\n", nombre2);

		// TODO : Convertir le 2ème paramètre de la fonction 'calculerResultatReference()' en paramètre par référence (&)
		cout << "--- calculerResultatReference() ---\n\n";

		int nombre3 = 10;
		int nombre4 = 20;

		cout << format("Nombre 3 (avant appel) : {}\n", nombre3);
		cout << format("Nombre 4 (avant appel) : {}\n\n", nombre4);

		int resultat2 = calculerResultatReference(nombre3, nombre4);

		cout << format("Resultat 2 : {}\n\n", resultat2);

		cout << format("Nombre 3 (apres appel) : {}\n", nombre3);
		cout << format("Nombre 4 (apres appel) : {}\n\n", nombre4);
	}

	// TODO: Créer 2 fonctions qui permettent d'incrémter ou décrémenter une valeur par référence
	if (false)
	{
		int compteur = 0;

		incrementer(compteur);
		incrementer(compteur);
		incrementer(compteur);
		decrementer(compteur);
		decrementer(compteur);
		incrementer(compteur);

		cout << format("Valeur du compteur : {}\n", compteur);
	}

	// TODO: Créer la fonction suivante qui permet d'incrémenter le score et de modifier le message
	if (false)
	{
		string messageModificationsScore = "";
		int score = 100;

		ajouterPoints(score, messageModificationsScore, 50);
		ajouterPoints(score, messageModificationsScore, 30);
		ajouterPoints(score, messageModificationsScore, 40);

		cout << format("Score final : {}\n", score);
		cout << format("Points obtenus : \n{}\n", messageModificationsScore);
	}

	// TODO : Créer la fonction suivante qui permet d'échanger 2 nombres par référence
	if (true)
	{
		int valeur1 = 50;
		int valeur2 = 30;

		cout << format("Valeurs avant l'echange : {} {}\n", valeur1, valeur2);

		echangerNombres(valeur1, valeur2);

		cout << format("Valeurs apres l'echange : {} {}\n", valeur1, valeur2);

		echangerNombres(valeur1, valeur2);

		cout << format("Valeurs apres 2eme echange : {} {}\n", valeur1, valeur2);
	}

	// *** Récursion ***
	// - Seulement pour le plaisir, n'est pas dans la matière du cours
	// - Façon avancée et complexe d'écrire une fonction
	//		- Fonction s'appelle elle-même une ou plusieurs fois (récursion)
	//		- Terminer la récursion
	//			- Appels décrémentent la valeur ou épuisent les cas à traiter
	//			- Cas de base retournent une valeur au début de la fonction pour terminer la récursion
	// - Certains problèmes complexes sont beaucoup plus simples avec la récursion (ex. graphes)
	//		- Peu optimisé car les fonctions ont un coût d'appel
	//		- Peu être résolu par des boucles ou programmation avancée (voir dynamic programming)

	// TODO: Exemple de fonction récursive
	// TODO: Montrer exemple de 'stack overflow' en enlevant les conditions de fin de la récursion
	if (false)
	{
		// Afficher les 20 premiers termes de la suite de Fibonnaci
		for (int terme = 0; terme <= 20; terme++)
		{
			int resultatFibonacci = calculerFibonacci(terme);
			cout << format("Fibonacci {} : {}\n", terme, resultatFibonacci);
		}
	}
}


int calculerResultat(int nombre1, int nombre2)
{
	int resultat = nombre1 + nombre2;

	nombre1 = 100;
	nombre2 = 200;

	return resultat;
}

int calculerResultatReference(int nombre1, int nombre2)
{
	int resultat = nombre1 + nombre2;

	nombre1 = 100;
	nombre2 = 200;

	return resultat;
}

/// <summary>
/// Calculer un terme entier de la série de Fibonacci en utilisant une fonction recursive.
/// <para>Fibonacci : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, etc.</para>
/// </summary>
/// <param name="terme">: Valeur entière de la position de la série à partir du terme 0.</param>
/// <returns>Valeur entière du terme de la série Fibonacci. (ex. pour le terme 6 retourne 8)</returns>
int calculerFibonacci(int terme)
{
	// Retourner les valeurs pour les termes 0 et 1 afin de terminer la récursion
	if (terme == 0)
		return 0;

	if (terme == 1)
		return 1;

	// Exemple
	// calculerFibonnaci(3) = calculerFibonnaci(1) + calculerFibonnaci(2);
	// calculerFibonnaci(3) = calculerFibonnaci(1) + (calculerFibonnaci(0) + (calculerFibonnaci(1))
	// calculerFibonnaci(3) = 1 + (0 + 1)
	// calculerFibonnaci(3) = 2
	return calculerFibonacci(terme - 2) + calculerFibonacci(terme - 1);
}

int fonctionB(int valeur)
{
	variableGlobale += 1;
	valeur += 5;
	return valeur + 10;
}

