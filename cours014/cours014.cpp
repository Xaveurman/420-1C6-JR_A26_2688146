//	Auteur : Xavier Blanchete
//	Date : 2026-09-18
//	Description : Devoir cours 013


// Inclure les librairies

#include <iostream>
#include <string>
#include <format>
using namespace std;

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "fr_CA.UTF-8");

	std::cout << "--- Cours 14 - For ---\n\n";

#pragma region OperateursIncrementation
	if (false)
	{
		std::cout << "--- Operateurs (++, --) ---\n\n";
		// *** Incrémentation et décrémentation ***
		// - Raccourci qui permet d'incrémenter (++) ou de décrémenter (--) une variable
		// 
		// Opérateur d'incrémentation
		// ----------------------------
		// ++variable;
		// 
		// variable += 1;
		// variable = variable + 1;
		// 
		// Opérateur de décrémentation
		// ----------------------------
		// --variable;
		// 
		// variable -= 1;
		// variable = variable - 1;
		// 
		// - Existe 2 types d'opérateurs selon s'il sont écrits avant ou après la variable
		//		- Pré-incrementation
		//			- ++nombre, --nombre
		//		- Post-incremenation
		//			- nombre++, nombre--
		int pre = 0;
		int post = 0;

		// Opérateurs ont un comportement différent sur la ligne sur laquelle ils sont utilisés
		cout << format("Pre sur la ligne : {}\n", ++pre);		// Incrémente avant (0 + 1) et retourne pour la ligne (1)
		cout << format("Post sur la ligne : {}\n\n", post++);	// Retourne pour la ligne (0) et incrémente après (0 + 1)

		// Opérateurs sont équivalent une fois la ligne passée
		cout << format("Pre apres la ligne : {}\n", pre);		// 1
		cout << format("Post apres la ligne : {}\n\n", post);	// 1

		// Pour ne pas se tromper, utiliser l'op�rateur sur une ligne seule et non dans un affichage ou un calcul
		++pre;  // Incrémente (1 + 1) et n'est pas utilisé sur la ligne
		post++; // N'est pas utilisé sur la ligne et incrémente après (1 + 1)

		cout << format("Pre apres la ligne : {}\n", pre);		// 2
		cout << format("Post apres la ligne : {}\n\n", post);	// 2

		// Exemple d'un programme qui utilise les opérateurs d'incrémentation et de décrémentation
		// - Débuter avec x = -5 et y = 10
		// - Après chaque affichage 
		//			- Incrémenter x
		//			- Décrémenter y
		// - Continuer tant que x est un nombre négatif

		std::cout << "--- Programme avec operateurs (++, --) ---\n\n";

		int x = -5;
		int y = 10;

		while (x < 0)
		{
			int resultat = x * y;
			cout << format("Resultat : {} * {} = {}\n", x, y, resultat);

			++x; // x = x + 1;
			--y; // y = y - 1;
		}

		cout << "Fin du programme avec operateurs\n";
	}
#pragma endregion

#pragma region For
	if (false)
	{
		// *** For ***
		// - Autre type de boucle afin de répéter un travail un nombre de fois prédéfini
		// - While
		//		- Nombre de répétitions inconnues ou infinies
		//		- Ex. lecture utilisateur, boucle principale infinie du programme, etc.
		// - For
		//		- Nombre de répétition connu
		//		- Ex. afficher 10 messages, permettre 10 tentatives de mot de passe, etc.
		// 
		// for ( déclaration iterateur; condition; incrémentation de l'itérateur )
		// {
		//		// Travail à effectuer un certain nombres de fois (itérations)
		// }
		//
		// Note : par convention, utiliser 'int i' comme variable itérateur dans une boucle for()

		// *** for() ***
		// Afficher à la Console les nombre 1 à 5 séparés par un espace
		cout << "\n--- Instruction for() ---\n\n";

		// 1) Variable i définie avec la valeur de départ une seule fois avant le début de la boucle
		// 2) Condition est vérifiée à chaque début de boucle passer à l'étape 3 (true) ou 5 (false)
		for (int i = 1; i <= 5; i++)
		{
			// 3) Travail à effectuer à chaque itération de la boucle
			cout << i;
			cout << " ";

			// 4) Détruire le Scope, incrémenter la variable i (i++) et recommencer à l'étape 2
		}
		// 5) Variable i détruite après l'exécution complète de la boucle

		cout << "Fin du for\n\n";

		// Erreur : variable i a été détruite après la fin du for() bien qu'elle semble être contenue dans le main()
		//cout << i;

		// *** while() ***
		// Afficher à la Console les nombre 1 à 5 séparés par un espace
		cout << "\n\n--- Instruction while() equivalente ---\n\n";

		{
			// 1) Variable i définie avec la valeur de départ une seule fois avant le début de la boucle
			int i = 1;

			// 2) Condition est vérifiée à chaque début de boucle passer à l'étape 3 (true) ou 5 (false)
			while (i <= 5)
			{
				// 3) Travail à effectuer à chaque itération de la boucle
				cout << i;
				cout << " ";

				// 4) Détruire le Scope, incrémenter la variable i et recommencer à l'étape 2
				++i;

				// Note : post ou pré-incrémentation n'a aucun impact sur la boucle
				// i++;
			}
		}
		// 5) Variable i détruite après l'exécution complète de la boucle

		cout << "Fin du while\n\n";

		// Erreur : variable i a été détruite après la fin du while() car elle est dans un Scope
		//cout << i;

		// *** Itérateur ***
		// Incrémentation de 1 par boucle
		for (int i = 0; i < 10; i++)
		{
			// Travail
		}

		// Décrémentation de 1 par boucle (boucle négative)
		for (int i = 10; i >= 0; i--)
		{
			// Travail
		}

		// Incrémentation d'une valeur supérieure à 1 (non standard)
		for (int i = 0; i < 10; i += 2)
		{
			// Travail
		}

		// Décrémentation d'une valeur supérieure à 1 (non standard)
		for (int i = 10; i >= 0; i -= 3)
		{
			// Travail
		}
	}
#pragma endregion

#pragma region TracerBouclesFor
	// *** Tracer une boucle for ***
	// Il faut avant tout être capable de tracer les résultats des boucles
	// - Plus tard, les boucles contiendront des erreurs 
	// - Il faudra identifier les erreurs pour les corriger

	// TODO: Tracer la boucle 1 suivante
	if (false)
	{
		cout << "\n\n--- Tracer boucle 1 ---\n\n";

		// Variables
		// i : 1, 2, 3, 4, 5, 6
		// 
		// Sorties à la Console
		// Avant
		// 1 2 3 4 5 Apres
		//

		cout << "Avant\n";

		for (int i = 1; i <= 5; i++)
		{
			cout << i;
			cout << " ";
		}

		cout << "Apres\n";
	}

	// TODO: Tracer la boucle 2 suivante
	if (false)
	{
		cout << "\n\n--- Tracer boucle 2 ---\n\n";

		// Variables
		// i		: 5, 4, 3, 2, 1
		// valeur	: 50, 40, 30, 20
		// resultat : 10, -40, 0, -30, -10
		// 
		// Sorties à la Console
		// 50 40
		// 30 20
		// Resultat : -10 

		int resultat = 10;

		for (int i = 5; i > 1; i--)
		{
			int valeur = i * 10;

			cout << valeur;

			if (i == 2 || i == 4)
			{
				cout << "\n";

				resultat += valeur;
			}
			else
			{
				cout << " ";

				resultat -= valeur;
			}
		}

		cout << format("Resultat : {}\n", resultat);
	}
#pragma endregion

#pragma region EcrireBouclesFor
	// *** Techniques d'écriture de boucle ***

	if (false)
	{
		// *** Exemple simple ***
		// 1) Identifier un travail répétitif à optimiser
		// Parfois le travail est simple à identifier, car les lignes se répètent exactement sans changements
		// Compter le nombre d'itérations à effectuer (ex. 10 fois)
		cout << "--- Version sans for ---\n\n";

		cout << "Bonjour!\n"; // 1
		cout << "Bonjour!\n"; // 2
		cout << "Bonjour!\n"; // 3
		cout << "Bonjour!\n"; // 4
		cout << "Bonjour!\n"; // 5
		cout << "Bonjour!\n"; // 6
		cout << "Bonjour!\n"; // 7
		cout << "Bonjour!\n"; // 8
		cout << "Bonjour!\n"; // 9
		cout << "Bonjour!\n"; // 10

		// 2) Créer une boucle avec le nombre d'itérations et le travail à répéter

		// TODO : Utiliser 0 comme valeur initiale pour l'utilisateur de tableaux plus tard (0 < itérations)
		// 10 itérations : 0 1 2 3 4 5 6 7 8 9
		cout << "\n--- Version 1 ---\n\n";

		for (int i = 0; i < 10; i++)
		{
			cout << "Bonjour!\n";
		}

		// TODO : Commencer à 1 et arrêter au nombre d'itérations (1 <= itérations)
		// 10 itérations : 1 2 3 4 5 6 7 8 9 10
		cout << "\n--- Version 2 ---\n\n";

		for (int i = 0; i <= 12; i++)
		{
			cout << format("bonjour {}\n", i);
		}
	}

	if (false)
	{
		// *** Exemple avec itérateur ***
		// 1) Identifier un travail répétitif à optimiser
		// Parfois le travail se répète, mais une partie du travail change (1, 2, 3 ... 12)
		// Bonjour étudiant ###! (12 fois)
		cout << "--- Version sans for ---\n\n";

		cout << "Bonjour etudiant 1!\n";
		cout << "Bonjour etudiant 2!\n";
		cout << "Bonjour etudiant 3!\n";
		cout << "Bonjour etudiant 4!\n";
		cout << "Bonjour etudiant 5!\n";
		cout << "Bonjour etudiant 6!\n";
		cout << "Bonjour etudiant 7!\n";
		cout << "Bonjour etudiant 8!\n";
		cout << "Bonjour etudiant 9!\n";
		cout << "Bonjour etudiant 10!\n";
		cout << "Bonjour etudiant 11!\n";
		cout << "Bonjour etudiant 12!\n";

		// 2) Créer une boucle avec le bon nombre d'itérations et le travail inclus une seule fois

		// TODO : Version avec le nombre d'itérations (1 <= itérations)
		// 12 itérations : 1 2 3 4 5 6 7 8 9 10 11 12
		cout << "\n--- Version 1 ---\n\n";



		// TODO : Version avec 0 comme valeur initiale pour l'utilisateur de tableaux plus tard (0 < itérations)
		// 12 itérations :  0 1 2 3 4 5 6 7 8 9 10 11
		// - Utiliser l'itérateur afin de générer le nombre à utiliser
		cout << "\n--- Version 2 ---\n\n";


	}

	if (false)
	{
		// *** Exemple complexe ***
		// 1) Identifier un travail répétitif à optimiser
		// Parfois le travail se répète, mais une partie du travail change
		// Bonjour étudiant ###! (2500000 + 1001, 2002, 3003 ...  9009)
		cout << "--- Version sans for ---\n\n";

		cout << "Bonjour etudiant 2501001!\n";
		cout << "Bonjour etudiant 2502002!\n";
		cout << "Bonjour etudiant 2503003!\n";
		cout << "Bonjour etudiant 2504004!\n";
		cout << "Bonjour etudiant 2505005!\n";
		cout << "Bonjour etudiant 2506006!\n";
		cout << "Bonjour etudiant 2507007!\n";
		cout << "Bonjour etudiant 2508008!\n";
		cout << "Bonjour etudiant 2509009!\n";

		const int NUMERO_ETUDIANT_BASE = 2500000;

		// Éviter, car difficile à suivre et à déboguer
		// Penser plutôt en terme de nombre d'itérations à effecter pour les itérateurs (i)
		cout << "--- Version a eviter ---\n\n";

		// 9 itérations : 2501001, ... ???
		for (int i = 2501001; i <= 2509009; i += 1001)
		{
			cout << format("Bonjour etudiant {}!\n", i);
		}

		// TODO : Version avec le nombre d'itérations (1 <= itérations)
		// 9 itérations : 1 2 3 4 5 6 7 8 9
		cout << "\n--- Version 1 ---\n\n";

		for (int i = 0; i < 9; i++)
		{
			int numeroEtudiant = 2500000 + 1001 * i;
			cout << format("Bonjour etudiant {}!\n", numeroEtudiant);
		}

		// TODO : Version avec 0 comme valeur initiale pour l'utilisateur de tableaux plus tard (0 < itérations)
		// 9 itérations : 0 1 2 3 4 5 6 7 8
		cout << "\n--- Version 2 ---\n\n";


	}

	if (false)
	{
		cout << "--- Plusieurs operations ---\n\n";

		// TODO: Plusieurs calculs ou travaux en même temps dans une itération de la boucle for()
		// 
		// Hello, 0 valeur 10 et 100 !
		// Hello, 1 valeur 11 et 200 !
		// Hello, 2 valeur 12 et 300 !

		for (int i = 0; i < 3; i++)
		{
			int valeur2 = 10 + i; 
		
			int valeur3 = 100 * (i + 1);

			cout << format("Hello, {} valeur {} et {} !\n",i, valeur2, valeur3);
		}

	}

	if (false)
	{
		cout << "--- Somme nombres ---\n\n";

		// Accumuler un résultat plusieurs fois et l'afficher après la boucle
		// TODO: Faire une somme des nombres 0 à 99

		const int NOMBRE_MAX_SOMME_NOMBRES = 9343;

		int somme = 0;

		for (int i = 0; i < NOMBRE_MAX_SOMME_NOMBRES; i++)
		{

			somme += i;
		}

		cout << format("Somme des nombres : {}\n", somme);

		// TODO: Créer une constante pour la valeur de fin de la boucle
	}

#pragma endregion

#pragma region ProgrammeFor
	// TODO: Compléter le programme afin d'afficher les numéros pour les étudiants : 1000, 1001, 1002, etc.
	if (true)
	{
		int nombreEtudiant = 0;
		int dernierMatricule = 1000;
		// Terminer la boucle si le nombre d'étudiant est négatif
		while (nombreEtudiant >= 0)
		{
			// Lire le nombre d'étudiant entier
			cout << "Entrer le nombre d'etudiants (negatif pour terminer) : ";
			cin >> nombreEtudiant;

			// Afficher une erreur si le nombre d'étudiants n'est pas un entier et recommencer la lecture
			if (cin.fail())
			{
				// Vider la mauvaise entrée dans le buffer de cin
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "Erreur : le nombre d'etudiant doit etre un entier.\n";
			}
			else
			{
				cout << format("Les nombre pour les {} etudiants sont :\n", nombreEtudiant);

				for (int i = 0; i < nombreEtudiant; i++)
				{
					int matricule = dernierMatricule + i;
					cout << format("{}\n", matricule);
				}
				
			
			}
		}
	}
#pragma endregion
}
