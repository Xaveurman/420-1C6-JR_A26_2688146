/*
	Auteur		: Xavier Blanchette
	Date		: 2026 - 10 -19
	Description	: Utilisation de sous-programmes à l'aide de fonctions
*/

// *** Librairies ***
#include <format>
#include <iostream>
#include <string>

// *** Namespace ***
using namespace std;

// *** Declaration des fonctions ***
#pragma region Fonctions
void programmeA()
{
	cout << "Bienvenue dans le programme A!\n";
	cout << "Fin du programme A!\n";
}

void programmeB()
{
	cout << "Fonction B ne retourne rien (void)\n";
	// Implicite à la fin de l'accolade fermante '}' n'est pas nécessaire pour un type de retour void
	//return;
}

int programmeC()
{
	cout << "Fonction C retourne toujours la valeur entiere 10 (int).\n";
	return 10;
}

string programmeD()
{
	cout << "Fonction D retourne toujours la chaine de charactere bonjour (string).\n";
	return "Bonjour!";
}

bool programmeE()
{
	cout << "Fonction E retourne toujours la valeur booleene true (bool).\n";
	return true;

	cout << "Message impossible à atteindre, la fonction se termine au 'return'\n";
}

int programmeF(int nombre)
{
	// Valeur temporaire est perdue après la fin de la fonction
	int valeurTemporaire = nombre + 100;
	cout << format("Valeur temporaire : {}\n" ,valeurTemporaire );

	// Valeur de retour peut être recupérée 
	return nombre + 15;
}

void programmeG(string messageDebut, string messageFin, int nombreAddition1, int nombreAddition2)
{
	cout << format("Message de debut : {}\n", messageDebut);

	int valeurRetour1 = programmeF(10);
	cout << format("Valeur de retour 1 : {}\n", valeurRetour1);

	int valeurRetour2 = programmeF(20);
	cout << format("Valeur de retour 2 : {}\n", valeurRetour2);

	// Ordre de résolution
	// 1. programmeF(10) = 25
	// 2. programmeF(20) = 35
	// 3. 25 + 35 = 60
	// 4. programmeF(30) = 45
	// 5. 60 + 45 = 105
	// 6. 105 + 1000 = 1105
	int valeurRetour3 = programmeF(10) + programmeF(20) + programmeF(30) + nombreAddition1;
	cout << format("Valeur de retour 3 : {}\n", valeurRetour3);

	// Ordre de résolution
	// 1. programmeF(10) = 25
	// 2. 25 + 50 = 75
	// 2. programmeF(75) = 90
	cout << "\nAppels 6-7 de la fonction B avec valeurs 10 et la réponse de l'appel 6 + 50 :\n";
	int valeurRetour4 = programmeF(programmeF(10) + nombreAddition2);
	cout << format("Valeur de retour 4 : {}\n", valeurRetour4);

	cout << format("Message de debut : {}\n", messageFin);
}

void afficherBonjour()
{
	cout << "Bonjour\n";
}

int multiplierPar10(int nombreMultiplie)
{
	return nombreMultiplie * 10;
}

double calculerTotal(double prix, int quantite, double pourcentageTaxe)
{
	double sousTotal = prix * quantite;
	double taxe = sousTotal * pourcentageTaxe;
	return sousTotal + pourcentageTaxe;
}

bool estNombreSuperieur10(int n)
{
	return n > 10;
}

// TODO: Ajouter les nouvelles fonctions ici avant la fonction main()
void afficherEnTete()
{
	cout << "==========================================\n";
	cout << "          DEMONSTRATION D'EN-TETE         \n";
	cout << "==========================================\n";
	cout << " Enseignant  : Mael Perreault\n";
	cout << " Cours       : Programmation structuree\n";
	cout << " Sujet       : Exemple de fonctions\n";
	cout << "------------------------------------------\n";
	cout << " Ce programme affiche un message\n";
	cout << " sur plusieurs lignes a la Console.\n";
	cout << "------------------------------------------\n";
	cout << " Contenu de l'en-tete :\n";
	cout << "   - Utilisation de cout\n";
	cout << "   - Retour de lignes\n";
	cout << "------------------------------------------\n";
	cout << " Date de compilation : 2026-10-19\n";
	cout << "==========================================\n";
}

void afficherMessageNombre(string message, int nombre)
{
	cout << format("Votre message d'aujourdhui est : '{}' et le nombre est : {}\n", message, nombre);
}

void afficherEtoiles (int nombreEtoiles)
{
	for (int i = 0; i < nombreEtoiles; i++)
	{
		cout << "*";
	}
}
void afficherLignesEtoiles(int nombreLignes, int nombreEtoiles)
{
	for (int i = 0; i < nombreLignes; i++)
	{
		afficherEtoiles(nombreEtoiles);
	}
}
int calculerSomme(int nombre1, int nombre2)
{
	return nombre1 + nombre2; 
}

double calculerMoyenne(double nombre1, double nombre2, double nombre3)
{
	double somme = nombre1 + nombre2 + nombre3;
	double moyenne = somme / 3.0;
	return moyenne; 
}

bool estPlusGrand(int nombre1, int nombre2)
{
	return nombre1 > nombre2;

	if (nombre1 > nombre2)
	{
		return true;
	}
	return false;
}

string genererMessageBienvenue(string nomUtulisateur)
{
	return format("Bienvenu dans le systeeme utulisateur {}!", nomUtulisateur);
}
char obtenirVoyelle(int indexVoyelle)
{
	switch (indexVoyelle)
	{
	default:
	case 0: return 'a';
	case 1: return 'e';
	case 2: return 'i';
	case 3: return 'o';
	case 4: return 'u';
	case 5: return 'y';
		break; return '\0';
	}
}
#pragma endregion

// *** Fonction main() ***
// - Une seule fonction main() dans le programme, sinon erreur de compilation du programme
// - Programme débute automatiquement au début de la fonction main()
// - Programme se termine lorsqu'on arrive à la fin de la fonction main()
int main()
{
	// Configuration de la Console pour la saisie des nombres à virgule avec un point (.)
	setlocale(LC_ALL, "en_US");

	cout << "--- Cours 23 - Fonctions ---\n\n";

	// *** Fonctions ***
	// - Sous-programmes comme la fonction main()
	//		- Peuvent être déclarés sans être exécutés avant la fonction main()
	//		- Peuvent ensuite être exécutés une ou plusieurs fois afin d'effectuer le même travail
	// - Raccourcis
	//		- F12 : Aller à la définition de la fonction
	//		- Ctrl+- : Revenir au dernier emplacement du curseur après F12
	//		- Alt+F12 : Voir la définition sans se déplacer
	// - Déboguer permet de visualiser l'exécution du programme
	//		- Mettre un point d'arrêt dans la marge à droit du numéro de lignes
	//		- F5 : pour lancer le programme en mode débogage
	//		- F11 : entrer dans le sous-programme de fonction instruction par instruction
	//		- F10 : passer à la prochaine ligne en exécutant l'ensemble du sous-programme de fonction sur la ligne
	//		- F5 : continuer l'éxécution au prochain point d'arrêt
	if (false)
	{
		//int programmeA()
		//{
		//	cout << "Bienvenue dans le programme A!\n";
		//	cout << "Fin du programme A!\n";
		//}

		cout << "--- Exemple de fonction A ---\n";

		cout << "Fonction main() exécute le programme A\n";
		programmeA();

		cout << "Fonction main() exécute le programme A une 2ème fois!\n";
		programmeA();
	}

	// *** Définition de la fonction ***
	// type nomFonction(type nomParametre1, type nomParametre2)
	// {
	//		// Travail à effectuer
	// 
	//		// Valeur de retour de la fonction
	//		return ...;
	// }
	//
	// *** Exemple ***
	// int exempleFonction(int parametre1, string parametre2)
	// {
	//		// Travail à effectuer
	//		cout << parametre2;
	// 
	//		// Valeur de retour de la fonction
	//		return parametre1 + 10;
	// }

	// *** Type de retour ***
	// - Contrat à remplir à la fin de la fonction
	//		- Valeur ou variable du bon type doit être retourné par la fonction par l'instruction 'return'
	//		- Tous les chemins de la fonction doivent retourne une valeur du bon type
	//			- Tous les branches possible de if/else if/else, switch, etc.
	//		- Un seul type de retour possible
	//			- Pour l'instant, fonctions retourne une seul valeur 
	//			- Plus tard, il sera possible de retourner plusieurs valeurs à l'aide des tableaux et des structs
	// - Types de base
	//		- int		=>		return 10;
	//		- double	=>		return 10.123;
	//		- char		=>		return 'a';
	//		- string	=>		return "bonjour";
	//		- etc.
	// - Aucune valeur
	//		- void		=>		return; ou atteindre la fin de la fonction '}'
	{
		//void programmeB()
		//{
		//	cout << "Fonction B ne retourne rien (void)\n";
		//	// Implicite à la fin de l'accolade fermante '}' n'est pas nécessaire pour un type de retour void
		//	//return;
		//}
		//
		//int programmeC()
		//{
		//	cout << "Fonction C retourne toujours la valeur entiere 10 (int).\n";
		//	return 10;
		//}
		//
		//string programmeD()
		//{
		//	cout << "Fonction D retourne toujours la chaine de charactere bonjour (string).\n";
		//	return "Bonjour!";
		//}
		//
		//bool programmeE()
		//{
		//	cout << "Fonction E retourne toujours la valeur booleene true (bool).\n";
		//	return true;
		//
		//	cout << "Message impossible à atteindre, la fonction se termine au 'return'\n";
		//}

		programmeB();

		int valeurB = programmeC();
		cout << format("Valeur de retour de la fonction C : {}\n", valeurB);

		string valeurD = programmeD();
		cout << format("Valeur de retour de la fonction D : {}\n", valeurD);

		// bool valeurE = programmeE();
		programmeE(); // Valeur de retour de la fonction disparait apres la ligne		
		cout << format("Valeur de retour de la fonction D est perdue, pas recue dans une variable comme C et D\n");
	}

	// *** Paramètres de fonctions ***
	// - Fonctionnement similaire aux variables, mais l'appellation pour une fonction est 'paramètre'
	// - À l'appel de la fonction
	//		- Espace est reservé en mémoire
	//		- Valeurs passées lors de l'appel de la fonction sont copiées
	//			- calculerMoyenne(10, 20, 30)
	//			- Copier 10 dans la variable 1
	//			- Copier 20 dans la variable 2
	//			- Copier 30 dans la variable 3
	// - À la fin de la fonction ou lors d'une instruction 'return' qui termine la fonction
	//		- Fin du 'Scope' de la fonction
	//		- Espace est libéré	comme les variables normales
	//		- Seule la valeur de retour est conservée temporairement
	{
		//int programmeF(int nombre)
		//{
		//	// Valeur temporaire est perdue après la fin de la fonction
		//	int valeurTemporaire = nombre + 100;
		//	cout << "Valeur temporaire : {}\n";
		//
		//	// Valeur de retour peut être recupérée 
		//	return nombre + 15;
		//}
		//
		//void programmeG(string messageDebut, string messageFin, int nombreAddition1, int nombreAddition2)
		//{
		//	cout << format("Message de debut : {}\n", messageDebut);
		//
		//	int valeurRetour1 = programmeF(10);
		//	cout << format("Valeur de retour 1 : {}\n", valeurRetour1);
		//
		//	int valeurRetour2 = programmeF(20);
		//	cout << format("Valeur de retour 2 : {}\n", valeurRetour2);
		//
		//	// Ordre de résolution
		//	// 1. programmeF(10) = 25
		//	// 2. programmeF(20) = 35
		//	// 3. 25 + 35 = 60
		//	// 4. programmeF(30) = 45
		//	// 5. 60 + 45 = 105
		//	// 6. 105 + 1000 = 1105
		//	int valeurRetour3 = programmeF(10) + programmeF(20) + programmeF(30) + nombreAddition1;
		//	cout << format("Valeur de retour 3 : {}\n", valeurRetour3);
		//
		//	// Ordre de résolution
		//	// 1. programmeF(10) = 25
		//	// 2. 25 + 50 = 75
		//	// 2. programmeF(75) = 90
		//	cout << "\nAppels 6-7 de la fonction B avec valeurs 10 et la réponse de l'appel 6 + 50 :\n";
		//	int valeurRetour4 = programmeF(programmeF(10) + nombreAddition2);
		//	cout << format("Valeur de retour 4 : {}\n", valeurRetour4);
		//}

		cout << "--- Fonction qui appelle une autre fonction ---\n";
		programmeF(1);
		programmeG("Hello!", "Bye!", 1000, 50);
	}

	// *** Nomenclature de fonctions ***
	// - Notation 'camelCase' pour le cours avec les mêmes règles que les variables
	//		- Pas d'accents
	//		- Pas d'abréviations
	//		- Pas de prépositions (ex. le, de, au, etc.)
	// - Commencer par un verbe d'action à l'infinitif suivi de noms et/ou adjectifs descriptifs
	//		- void afficherMenuPrincipal()
	//		- void afficherEnTete()
	//		- void afficherOperation()
	//			- afficher...() (display...() ou print...() en anglais) 
	//			- Implique une fonction d'affichage seulement à la Console qui ne retourne pas de valeur
	//			- Type de retour (void)
	//		- double calculerMoyenne()
	//		- int calculerNombreJoursEntreDates()
	//		- double trouverPlusPetitNombre()
	//		- double trouverMinimum()
	//		- int trouverNombreVoyelles()
	//		- int lireEntier()
	//		- int lireExemplaires()
	//		- char lireChoixMenu()
	//		- etc.
	// - Fonctions qui retourne un bool doivent plutôt commencer par 'est...()' (ou 'is...()' en anglais), etc.
	//		- bool estNegatif()
	//		- bool estVoyelle()
	//		- bool peutTerminer()
	//		- etc.

	// TODO: Renommer les fonctions suivantes en suivant les règles de nomenclature pour les noms des fonctions et parametres
	// - Utiliser Ctrl+R,R pour renommer la fonction ou les paramètres
	if (false)
	{
		afficherBonjour();
		afficherBonjour();
		afficherBonjour();

		multiplierPar10(100);

		calculerTotal(9.99, 10, 0.05);

		estNombreSuperieur10(20);
		estNombreSuperieur10(5);
	}

	// TODO: Créer une fonction qui affiche un message statique sans retour (void) et l'appeler une fois
	if (false)
	{
		afficherEnTete();
	}

	// TODO: Créer une fonction qui affiche un message dynamique sans retour (void) et l'appeler plusieurs fois
	if (false)
	{
		cout << "\nSans fonctions :\n";
		cout << "Votre message d'aujourdhui est : 'Bonjour' et le nombre est : 10\n";
		cout << "Votre message d'aujourdhui est : 'Hello' et le nombre est : 5555\n";
		cout << "Votre message d'aujourdhui est : 'Buenos Dias' et le nombre est : 123456789\n";

		//cout << format("Votre message d'aujourdhui est : '{}' et le nombre est : {}\n", ..., ...);

		cout << "\nAvec fonctions :\n";
		afficherMessageNombre("Bonjour", 10);
		afficherMessageNombre("Hello", 5555);
		afficherMessageNombre("Buenos Dias", 123456789);
	}

	// TODO: Créer une fonction qui affiche le nombre d'étoiles demandé
	if (false)
	{
		cout << "\nSans fonction :\n";
		cout << "**************************************\n";
		cout << "******************************************************************************\n";

		cout << "\nAvec fonction :\n";
		afficherEtoiles(40);
		afficherEtoiles(80);
	}

	// TODO: Appeler autre fonction 5 fois afficherEtoiles(80);
	if (true)
	{
		cout << "\nSans fonction :\n";
		cout << "**************************************\n";
		cout << "**************************************\n";
		cout << "**************************************\n";

		cout << "******************************************************************************\n";
		cout << "******************************************************************************\n";
		cout << "******************************************************************************\n";
		cout << "******************************************************************************\n";
		cout << "******************************************************************************\n";

		cout << "\nAvec fonction :\n";
		afficherLignesEtoiles(3, 40);
		afficherLignesEtoiles(5, 80);
	}

	// TODO: Créer une fonction qui retourne une valeur entière (int)
	if (true)
	{
		int resultatSomme1 = calculerSomme(10, 20); // 30
		cout << format("Resultat somme : 10 + 20 = {}\n", resultatSomme1);
		 
		int resultatSomme2 = calculerSomme(15, 45); // 50
		cout << format("Resultat somme : 15 + 45 = {}\n", resultatSomme2);
		 
		int resultatSomme3 = calculerSomme(18, 34); // 52
		cout << format("Resultat somme : 18 + 34 = {}\n", resultatSomme3);
	}

	// TODO: Créer une fonction qui retourne un nombre à virgule (double)
	if (true)
	{
		double resultatCalculMoyenne = calculerMoyenne(10, 15, 30); // 18.333...
		cout << format("Resultat calcul moyenne : {}\n", resultatCalculMoyenne); 
	}

	// TODO: Créer une fonction qui retourne un booléen (bool)
	if (true)
	{
		// Tester si le nombre 1 est plus grand que le nombre 2
		bool estPlusGrandResultat0 = estPlusGrand(123, 10); // true
		bool estPlusGrandResultat1 = estPlusGrand(-10, 10); // false

		// Tester si plus grand que 1000
		bool estPlusGrandResultat2 = estPlusGrand(1001, 1000); // true
		bool estPlusGrandResultat3 = estPlusGrand(1000, 1000); // false
		bool estPlusGrandResultat4 = estPlusGrand(999, 1000); // false

		cout << format("Plus grand : {} {} {} {} {}\n", 
		 estPlusGrandResultat0, 
		 estPlusGrandResultat1, 
		 estPlusGrandResultat2, 
		 estPlusGrandResultat3, 
		 estPlusGrandResultat4);
	}

	// TODO: Créer une fonction qui retourne une chaîne de caractère (string)
	if (true)
	{
		string messageBienvenue = genererMessageBienvenue("Mael");
		cout << messageBienvenue;
	}

	// TODO: Créer une fonction qui retourne un caractère (char)
	if (true)
	{
		char voyelle0 = obtenirVoyelle(0); // 'a'
		char voyelle1 = obtenirVoyelle(1); // 'e'
		char voyelle2 = obtenirVoyelle(2); // 'i'
		char voyelle3 = obtenirVoyelle(3); // 'o'
		char voyelle4 = obtenirVoyelle(4); // 'u'
		char voyelle5 = obtenirVoyelle(5); // '\0'
		 
		cout << format("Voyelles : {} {} {} {} {} {}\n", voyelle0, voyelle1, voyelle2, voyelle3, voyelle4, voyelle5);
	}
}