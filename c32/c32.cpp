/*
	Auteur		: Xavier Blanchette
	Date		: 2026-11-09
	Description	: Introduction aux tableaux à une dimension (arrays)
*/

#include <format>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "en_US");
	srand((unsigned int)time(0));

	std::cout << "--- Cours 31 - Tableaux ---\n";

	// *** Tableaux (Arrays) ***
	// - Déclare un bloc de mémoire contigu du type spécifié pour stocker plusieurs valeurs du même type
	// - Équivalent à créer plusieurs variables du même type
	// 
	// type nomTableau[tailleTableau];
	// 
	// Nomenclature
	// - Suivre les mêmes règles de nomenclature que les variables
	// - Terminer avec un 's' pour indiquer une variable qui contient plusieurs éléments

	// TODO: Faire un dessin du fonctionnement en mémoire avec les index : [0], [1], [2], etc.

	// TODO: Créer un tableau de chaque type de base
	// int 		(10 elements 	[0] - [9])
	// double 	(5 elements 	[0] - [4])
	// char 	(26 elements 	[0] - [25])
	// string 	(100 elements 	[0] - [99])
	// bool 	(15 elements 	[0] - [14])
	if (true)
	{
		int nombreEntiers[10];
		double nombreVirgules[100];
		char lettre[26];
		string messages[100];
		bool estUtilisateurConnectes[15];

		cout << "Mettre un point d'arret pour voir les valeurs\n";
	}

	// *** Valeurs de base ***
	// - Valeurs sont non initialisée par défaut dans un tableau similaire aux variables
	// - Dépend des langages de programmation (C#, Java, etc. initialisent à zéro par défaut)
	// - Utiliser la syntaxe d'initialisation pour définir des valeurs par défaut
	// 
	// type nomTableau[tailleTableau] = { valeurIndex0, valeurIndex1, valeurIndex2 };

	// TODO: Initialiser des tableaux avec des valeurs par défaut
	// - Tableau entiers avec une taille de 5 elements et les valeurs : 10, 20, 30, 40, 50
	// - Tableau de caractères sans utiliser de taille de tableau en assignant les valeurs : 'a', 'b', 'c', 'd'
	//		- Mettre la souris sur un nom de tableau pour afficher la taille automatiquement définie
	if (true)
	{
		int nombreEntiers[5] = { 10, 20, 30, 40, 50 };
		char lettres[] = { 'a', 'b', 'c', 'd' };

		cout << "Mettre un point d'arret pour voir les valeurs\n";
	}

	// *** Initialisation tbaleaus ***
	// - Tableau sans taille et un seul élément dans les accolades initialise tout le tableau à cette valeur
	// - Utile pour mettre les valeurs non initialisées à zéro (0, 0.0, '\0', false, etc.)
	//		- int valeurs[] = { 0, 0, 0, 0, 0 };	// 0, 0, 0, 0, 0 => [5]
	//		- int valeurs[] = { 10, 20, 30 };		// 10, 20, 30 => [3]
	// 
	// *** Initialisation partielle ***
	//- Tableau avec une taille initialise seulement une partie du tableau à cette valeur et le reste à zéro
	//		- int valeurs[5] = { 0 };		//  0,  0, 0, 0, 0 (fonctionne donc quand même)
	//		- int valeurs[5] = { 10 };		// 10,  0, 0, 0, 0
	//		- int valeurs[5] = { 10, 20 };	// 10, 20, 0, 0, 0
	if (true)
	{
		int entiersVide[] = { 0, 0, 0, 0, 0 };
		// TODO: Plus rapide d'écrire [5] = { 0 }
		int entiersVides2[5] = { 0 };

		char caracteres[] = { '\0', '\0', '\0', '\0' };
		// TODO: Plus rapide d'écrire [4] = { '\0' } 
		char caracteres2[4] = { '\0' };

		string chaines[] = { "", "", "" };
		// TODO: Plus rapide d'écrire [3] = ""
		string chaines2[] = { "" };

		// Initialisation partielle, souvent des erreurs
		int entiersPartiels[5] = { 10, 20 }; // Oups, [5] implique 3 cases vides
		int entiersPartielsEquivalent[] = { 10, 20, 0, 0, 0 }; // Ce que fait le compilateur

		char caracteresPartiels[4] = { 'a', 'b' }; // Oups, [4] impliques 2 cases vides
		char caracteresPartielsEquivalent[] = { 'a', 'b', '\0', '\0' }; // Ce que fait le compilateur

		cout << "Mettre un point d'arret pour voir les valeurs\n";
	}

	// *** Accès aux éléments du tableau ***
	// - Utiliser un entier (index) pour accéder à un élément du tableau
	//		- nomTableau[index]
	// - Index débute à 0 et se termine à la taille du tableau - 1
	//		- [0, taille - 1]
	//		- Exemple : tableau de 5 éléments [0, 5 - 1] = [0, 4]
	// - Utiliser une boucle pour itérer sur les éléments du tableau à partir de 0
	//		- for (int i = 0; i < taille; i++) 
	//		  { 
	//			cout << nomTableau[i];
	//		  }
	// - Toujours vérifier que l'index utilisé est dans les limites du tableau ('bounds')
	//		- C++
	//			- 'Undefined behaviour' pour vitesse exécution et compatibilité avec le langage C
	//			- Accède à la mémoire à l'adresse choisi en lecture ou écriture
	//			- Résultats possibles : retourner mauvaise valeur, crasher, etc.
	//				- tableau[-1] = ??? (valeur vide, valeur aléatoire, crash, etc.)
	//		- C#
	//			- Accès prévus sécurisé
	//			- Programme crash par sécurité
	//			- Empêcher un accès à des données non prévus : mots de passe, droits d'accès, etc.
	//				- tableau[-1] = CRASH

	if (false)
	{
		int nombres[5] = { 10, 20, 30, 40, 50 };

		// Afficher chaque élément individuellement
		cout << format("Premier element : {}\n", nombres[0]);		// 10
		cout << format("Deuxieme element : {}\n", nombres[1]);		// 20
		cout << format("Troisieme element : {}\n", nombres[2]);		// 30
		cout << format("Quatrieme element : {}\n", nombres[3]);		// 40
		cout << format("Cinquieme element : {}\n\n", nombres[4]);	// 50

		// Exemple de 'underfined' en accédant hors des limites du tableau
		cout << format("Avant premier element : {}\n", nombres[-1]);	// ???
		cout << format("Apres dernier element : {}\n\n", nombres[5]);	// ???

		// Exemple d'erreur de compilation en utilisant un tableau sans index
		//cout << format("Tableau : {}\n", nombres); // Erreur

		// TODO: Utiliser une boucle pour afficher chaque élément du tableau
		for (int i = 0; i < 5; i++)
		{

			cout << format("Element {} : {}\n", i,nombres[i]);
		}



		// TODO: Modifier le premier et 3e élément du tableau aux valeurs 100 et 200
		nombres[0] = 100;
		nombres[2] = 200;

		// TODO: Réutiliser la boucle pour afficher chaque élément du tableau
		for (int i = 0; i < 5; i++)
		{

			cout << format("Element {} : {}\n", i, nombres[i]);
		}

		// TODO: Ajouter 5 à chaque élément du tableau
		for (int i = 0; i < 5; i++)
		{
			nombres[i] += 5;
		
		}

		// TODO: Réutiliser la boucle pour afficher chaque élément du tableau
		for (int i = 0; i < 5; i++)
		{

			cout << format("Element {} : {}\n", i, nombres[i]);
		}
	}

	// *** Utilisation de tableaux ***
	// - Permettent de réduire le nombre de variables nécessaires pour gérer plusieurs valeurs du même type
	//		- Répétitions de variables
	//			- int nombre1;
	// 			- int nombre2;
	// 			- int nombre3;
	// 		- Tableau équivalent
	//			- int nombres[3];
	// - Attention, ne pas mélanges des variables différentes significations dans un même tableau
	//		- Exemples variables
	//			- int compteur;
	//			- int nombre;
	//			- int somme;
	// 			- int moyenne;
	// 		- Mauvais exemple de tableau
	//			- int valeurs[4];
	// - Exemples de bonnes utilisation de tableaux
	// 	    - Stocker les notes finales d'un étudiant pour ses 5 cours
	//			- double notesCours[5];
	//		- Stocker les noms des 50 employés d'une entreprise
	//			- string nomEmployes[50];
	//		- Stocker les valeurs de 100 lancers de dés
	//			- int resultatDes[100];

	// Compter le nombre d'apparition de chaque face d'un dé lancé 100 fois sans tableau
	// - Voici un mauvais exemple de programmation sans utiliser les tableaux
	if (false)
	{
		int compteurFace1 = 0;
		int compteurFace2 = 0;
		int compteurFace3 = 0;
		int compteurFace4 = 0;
		int compteurFace5 = 0;
		int compteurFace6 = 0;

		// Simuler 100 lancers de dé
		for (int i = 0; i < 100; i++)
		{
			int lancerAleatoire = 1 + rand() % 6; // [1, 6]

			switch (lancerAleatoire)
			{
			case 1:
				compteurFace1++;
				break;
			case 2:
				compteurFace2++;
				break;
			case 3:
				compteurFace3++;
				break;
			case 4:
				compteurFace4++;
				break;
			case 5:
				compteurFace5++;
				break;
			case 6:
				compteurFace6++;
				break;
			}
		}

		cout << format("Face 1 : {}\n", compteurFace1);
		cout << format("Face 2 : {}\n", compteurFace2);
		cout << format("Face 3 : {}\n", compteurFace3);
		cout << format("Face 4 : {}\n", compteurFace4);
		cout << format("Face 5 : {}\n", compteurFace5);
		cout << format("Face 6 : {}\n", compteurFace6);
	}

	// TODO: Programmer l'exemple précédent en utilisant un tableau pour compter et afficher les faces du dé
	if (false)
	{
		const int NOMBRE_FACES = 6;

		int compteurFaces[NOMBRE_FACES] = { 0 };


		for (int i = 0; i < 100; i++)
		{
			int lancerAleatoire = 1 + rand() % NOMBRE_FACES;
			int indexCompteur = lancerAleatoire - 1;
			++compteurFaces[indexCompteur];
		}
		for (int i = 0; i < NOMBRE_FACES; i++)
		{
			cout << format("Face {} : {}\n",i + 1 , compteurFaces[i]);
		}
	}
	// TODO: Compléter le programme afin de lire 10 nombres et d'afficher les nombres pairs et impairs
	if (true)
	{
		cout << "--- Entrez 10 nombres ---\n\n";

		int nombresSaisis[10] = { 0 };
		int nombresPairs[10] = { 0 };
		int nombresImpairs[10] = { 0 };

		int compteurPair = 0;
			int compteurImpair = 0;

		for (int i = 0; i < 10; i++)
		{
			cout << format("Nombre {} : ", i + 1);
			int nombre;
			cin >> nombre;

			// TODO: Conserver les nombres saisis, pairs et impairs ainsi que le compte de chacun
			nombresSaisis[i] = nombre;
			if (nombre % 2 == 0)
			{
				nombresPairs[compteurPair] = nombre;
					++compteurPair;
			}
			else
			{
				nombresImpairs[compteurImpair] = nombre;
					++compteurImpair;
			}
		}

		// TODO: Afficher les nombres saisis
		cout << "Nombres saisis : ";
		for (int i = 0; i < 10; i++)
		{
			if (i != 0)
				cout << ", ";

			cout << nombresSaisis[i];
				
			
		}

		// TODO: Afficher les informations des nombres pairs
		cout << format("Compte de nombre pairs : {}\n", 0);
		cout << format("Nombre pairs : ");
		for (int i = 0; i < 10; i++)
		{
						if (i != 0)
				cout << ", ";

			cout << nombresPairs[i];
		}
		cout << "\n ";

		// TODO: Afficher les informations des nombres impairs
		cout << format("Compte de nombre impairs : {}\n", 0);
		cout << format("Nombre impairs : ");
		for (int i = 0; i < 10; i++)
		{
			if (i != 0)
				cout << ", ";

			cout << nombresImpairs[i];
		}
		cout << "\n ";
	}

	// *** Tableau de constantes ***
	// - Utiliser des tableaux de constantes pour des données fixes afin de réduire le nombre de variables
	// - Utiliser un enum pour identifier les index du tableau [0] ... [Quantite]
	if (true)
	{
		// Créer un enum qui contient la valeur des index et la taille des tableaux de constantes
		enum Choix
		{
			// Constante pour gérer les choix du menu invalides
			// - Non nécessaire, version fancy pour gérer les choix invalides
			// - Nommer xxxInvalide pour éviter les conflits avec les autres enum
			ChoixInvalide = -1,

			// Constantes des index des choix du menu contenus dans les tableaux de constantes
			// - Commencer à 0 et laisser le compilateur incrémenter automatiquement à chaque valeur
			Pogo,		// 0
			Poutine,	// 1
			Patate,		// 2

			// Constante de la taille des tableaux de constantes (utiliser la nomenclature 'Count' en anglais)
			// - Mettre à la fin du enum et laisser le compilateur incrémenter automatiquement
			// - Nommer xxxQuantite pour éviter les conflits avec les autres enum
			ChoixQuantite // 3
		};

		// Créer des tableaux reliés au enum Choix pour le nom et le prix de chaque choix
		const string CHOIX_NOMS[] =
		{
			"Combo pogos",		// CHOIX_NOMS[0] ou CHOIX_NOM[Choix::Pogo]
			"Poutine medium",	// CHOIX_NOMS[1] ou CHOIX_NOM[Choix::Poutine]
			"Petite frite"		// CHOIX_NOMS[2] ou CHOIX_NOM[Choix::Patate]
		};

		const double CHOIX_PRIX[] =
		{
			5.99,				// CHOIX_PRIX[0] ou CHOIX_PRIX[Choix::Pogo]
			10.99,				// CHOIX_PRIX[1] ou CHOIX_PRIX[Choix::Poutine]
			4.99				// CHOIX_PRIX[2] ou CHOIX_PRIX[Choix::Patate]
		};

		// Version 1 : de base avec des choix entier du enum
		if (true)
		{
			cout << "--- Menu avec enum ---\n\n";

			// Afficher le nom et le prix pour chaque item du menu
			for (int i = 0; i < Choix::ChoixQuantite; i++) // 0 ... 2 
			{
				cout << format("{}) {} ({} $)\n", i, CHOIX_NOMS[i], CHOIX_PRIX[i]);
			}

			// Lire choix de l'utilisateur à la Console
			cout << "\nEntrer votre choix : ";
			int choix;
			cin >> choix;

			// Vérifier que le choix est valide afin d'afficher la commande ou un message d'erreur
			// Préférer à un switch si jamais les valeurs du enum changent
			if (choix >= 0 && choix < Choix::ChoixQuantite) // 3
			{
				string nom = CHOIX_NOMS[choix];
				double prix = CHOIX_PRIX[choix];
				cout << format("\nVotre commande est {} pour un total de {} $.\n\n", nom, prix);
			}
			else
			{
				cout << format("\nErreur : choix {} est invalide.\n\n", choix);
			}
		}

		// Version 2 : extra fancy avec des choix en caractères convertis en choix du enum

		// Créer des tableaux reliés au enum Choix pour le nom et le prix de chaque choix
		const char CHOIX_LETTRES[] =
		{
			'c', // CHOIX_LETTRES[0] ou CHOIX_LETTRES[Choix::Pogo]
			'p', // CHOIX_LETTRES[1] ou CHOIX_LETTRES[Choix::Poutine]
			'f'	 // CHOIX_LETTRES[2] ou CHOIX_LETTRES[Choix::Patate]
		};

		if (true)
		{
			cout << "--- Menu avec lettre et enum ---\n\n";

			// Afficher le nom et le prix pour chaque item du menu
			for (int i = 0; i < Choix::ChoixQuantite; i++) // 0 ... 2
			{
				cout << format("{}) {} ({} $)\n", CHOIX_LETTRES[i], CHOIX_NOMS[i], CHOIX_PRIX[i]);
			}

			// Lire choix de l'utilisateur à la Console
			cout << "\nEntrer votre choix : ";
			char lettre;
			cin >> lettre;

			// Trouver le choix de l'utilisateur à l'aide du caractère saisi au clavier
			int choixSelection = Choix::ChoixInvalide; // -1

			// Rechercher le choix élément par élément dans tableau afin de trouver l'index correspondant
			for (int i = 0; i < Choix::ChoixQuantite; i++) // 0 ... 2
			{
				if (lettre == CHOIX_LETTRES[i])
				{
					// Convertir l'index en valeur du enum Choix pour être plus fancy
					choixSelection = i;
					break;
				}
			}

			// Utiliser le choix sélectionné afin d'afficher les informations ou un message d'erreur
			if (choixSelection != Choix::ChoixInvalide) // -1
			{
				char lettre = CHOIX_LETTRES[choixSelection];
				string nom = CHOIX_NOMS[choixSelection];
				double prix = CHOIX_PRIX[choixSelection];

				cout << format("\nVotre commande avec lettre {} est {} pour un total de {} $.\n\n", lettre, nom, prix);
			}
			else
			{
				cout << format("\nErreur : choix de la lettre {} est invalide.\n\n", lettre);
			}

			// Erreur : Utiliser une boucle, car les switch ne supportent pas les tableaux en C++
			//switch (lettre)
			//{
			//case CHOIX_LETTRES[i]:
			//    break;
			//default:
			//    break;
			//}
		}
	}
}