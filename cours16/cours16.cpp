//	Auteur : Xavier Blanchete
//	Date : 2026-09-28
//	Description : Devoir 16 breakcontiune



// Inclusion des librairies
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "");

	// Affichage de l'en-tête
	cout << "--- Cours 16 - While ---\n\n";

	// *** Continue et break ***
	// - Permettent de passer à la prochaine boucle ou de terminer la boucle
	// - Utiles dans certains cas pour décomplexifier la condition de la boucle
	// - Préférer d'utiliser condition de la boucle au lieu de continue et break lorsque possible

	// Exemple de boucle simple avec break et continue
	if (false)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (i == 3 || i == 5)
				continue;

			if (i == 10)
				break;

			cout << i << "\n";
		}
	}

	// Exemple de boucle avec condition complexe avec break et continue
	if (false)
	{
		cout << "--- Exemple break et continue ---\n";

		int nombre1 = 1;
		int nombre2 = 25;

		while (nombre1 < 100)
		{
			// Incrémtener les nombres
			nombre1 += 3;
			nombre2 += 1;

			// Terminer la boucle si le calcul est impossible (division par zéro)
			if (nombre1 == nombre2)
			{
				cout << format("Division par zero : {} et {} fin prematuree de la boucle avant 100\n", nombre1, nombre2);

				// Continuer l'exécution du programme après la boucle while()
				break;
			}

			// Passer a la prochaine itération de la boucle while() sans l'afficher si le resultat est trop petit
			if (nombre1 < nombre2 / 4)
			{
				// Recommencer a l'instruction while() et réévaluer la condition
				continue;
			}

			// Calculer et afficher le resultat
			double resultat = (double)nombre1 / (nombre2 - nombre1);
			cout << format("Resultat {} et {} : {}\n", nombre1 - 3, nombre2 - 1, resultat);
		}

		cout << "Fin de l'exemple break et continue !\n";
	}

	// Exemple de boucle avec condition complexe sur 2 éléments distinct
	if (false)
	{
		cout << "--- 10 nombres ---\n";

		// Initialiser les variables afin d'entrer dans la boucle
		int nombresValides = 0;
		int nombre = 0;

		// Lire et comptabiliser jusqu'à 10 nombres à la Console tant que l'utilisateur n'entre pas un nombre négatif
		while (nombresValides < 10 && nombre >= 0)
		{
			// Lire un nombre à la Console
			cout << format("Entrer le nombre {} : ", nombresValides + 1);
			cin >> nombre;

			// Vérifier si le nombre doit être comptabilisé ou écrire une erreur à l'écran
			if (nombre > 1000)
			{
				cout << format("Erreur : Nombre {} est trop grand, maximum 1000.\n", nombre);
				continue;
			}
			else if (nombre >= 0)
			{
				nombresValides += 1;
			}
		}

		cout << "Fin du programme qui lit 10 nombres !\n";
	}

	// TODO: Simplifier la boucle avec break pour terminer la lecture des nombres
	// TODO: Simplifier la boucle avec continue pour passer à la prochaine lecture
	if (false)
	{
		cout << "--- 10 nombres avec break et continue ---\n";

		// Initialiser les variables afin d'entrer dans la boucle
		int nombresValides = 0;
		int nombre = 0;

		// Lire et comptabiliser jusqu'à 10 nombres à la Console tant que l'utilisateur n'entre pas un nombre négatif
		while (nombresValides < 10 && nombre >= 0)
		{
			// Lire un nombre à la Console
			cout << format("Entrer le nombre {} : ", nombresValides + 1);
			cin >> nombre;

			// Vérifier si le nombre doit être comptabilisé ou écrire une erreur à l'écran
			if (nombre > 1000)
			{
				cout << format("Erreur : Nombre {} est trop grand, maximum 1000.\n", nombre);
			}
			else if (nombre >= 0)
			{
				nombresValides += 1;
			}
		}

		cout << "Fin du programme 10 nombres avec break et continue !\n";
	}

	// TODO: Terminer la boucle à 2 niveaux avec un break lorsque i = 10
	if (false)
	{

	
		for (int j = 0; j < 100; j++)
		{
			bool estNombreValide = true;
			for (int i = 0; i < 1000; i++)
			{
				if (i >= 10)
				{
					estNombreValide = false;
					break;
				}
				cout << i << " ";
			}

			cout << "\n";

			if (!estNombreValide)
				break;
		}
	}
	// *** Programmes ***
	// Un programme standard de Console contient les éléments suivants :
	// - Boucle principale infinie qui permet de recommencer le programme
	// - Plusieurs boucles de lectures, une par variable à saisir à la Console
	// - Au moins une des saisie permet à l'utilisateur de terminer le programme
	// - Calculer et afficher les résultats

	if (false)
	{
		cout << "--- Structure de programme ---\n";

		// Alternative pour ne pas avoir une boucle principale while (true)
		//int variable1 = -1;
		//while (variable1 != 0)
		//{
		//	//Lire la variable 1
		//	cin >> variable1;
		// 
		//	// Vérifier pour ne pas effectuer le reste du code et terminer la boucle
		//	if (variable1 != 0)
		//	{
		//		// Reste du programme a effectuer si on ne quitte pas
		//	}
		//}

		// Boucle principale pour recommencer le programme à l'infini
		while (true)
		{
			// Lecture et validation de la variable 1
			int variable1 = -1;

			// Version 1 : Avec condition de fin de boucle dans le while
			while (variable1 < 0)
			{
				cout << "Entrer la variable 1 (0 pour quitter le programme) : ";
				cin >> variable1;

				// Valider que l'entrée est un nomrbe valide sinon afficher une erreur et recommencer la boucle
				if (cin.fail())
				{
					cout << "Erreur : variable 1 n'est pas un entier.\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}

				// Afficher un message d'erreur si la valeur n'est pas valide
				if (variable1 < 0)
				{
					cout << "Erreur : variable 1 n'est pas un nombre positif.\n";
				}
			}

			// Quitter le programme en terminant la boucle principale while (true)
			if (variable1 == 0)
				break;

			// Lecture et validation de la variable 2
			int variable2 = 0;

			// Version 2 : Avec boucle infinie terminée par un break; (moins recommandé)
			while (true)
			{
				cout << "Entrer la variable 2 : ";
				cin >> variable2;

				// Valider que l'entrée est un nomrbe valide sinon afficher une erreur et recommencer la boucle
				if (cin.fail())
				{
					cout << "Erreur : variable 2 n'est pas un entier.\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					continue;
				}

				// Terminer la boucle avec break si la valeur entrée est valide
				bool estValide = variable2 < 0;
				if (estValide)
					break;

				// Afficher une erreur et recommencer la boucle
				cout << "Erreur : variable 2 n'est pas un nombre negatif\n";
			}

			// Lecture et validation de la variable 3
			// Lecture et validation de la variable 4
			// Lecture et validation de la variable 5
			// etc.

			// Calculs avec les variables validées (1, 2, etc.)
			int resultat = variable1 + variable2;

			// Affichage des résultats des calculs
			cout << format("Resultat : {}\n", resultat);
		}

		cout << "Fin du programme !\n";
	}
}
