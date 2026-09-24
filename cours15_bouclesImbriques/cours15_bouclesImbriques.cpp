//	Auteur : Xavier Blanchete
//	Date : 2026-09-10
//	Description : TP 1 - IMPRIMERIE


// Inclure les librairies
#include <format>
#include <iostream>
#include <string>

// Utiliser le namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "fr_CA.UTF-8");

	std::cout << "--- Cours 15 - Boucles imbriquées ---\n";

	// *** Boucles imbriquées ***
	// - Imbriquer les boucles for permet des travaux super puissants
	// - Dans les éléments les plus difficiles à apprendre à utiliser
	// - Visualiser les boucles comme des dimensions
	//		- Exemple avec 2 boucles (x par y)
	//		- Dessiner un écran (hauteur par largeur)
	//		- Calculer le total pour des utilisateurs leurs transactions (transactions par utilisateur)
	// - Par convention
	//		- Variables itérateurs sont nommées à partir de 'i' (i, j, k, etc.)
	//		- Recommandé de les renommer pour aider la compréhension de la boucle

	// TODO: Tracer les valeurs des variables et affichage à la console de la boucle imbriquée
	if (false)
	{
		cout << "\n--- Tracer la boucle 1 ---\n\n";

		// Variables
		// i : 0 1 2 3
		// j : 0 1 2 3 0 1 2 3 0 1 2 3
		//
		// Sortie à la Console
		// 0:0 1 2
		// 1:0 1 2
		// 2:0 1 2


		for (int i = 0; i < 3; i++)
		{
			cout << i << ":";

			for (int j = 0; j < 3; j++)
			{
				cout << j << " ";
			}

			cout << "\n";
		}
	}

	// TODO: Tracer les valeurs des variables et affichage à la console de la boucle imbriquée
	if (false)
	{
		cout << "\n--- Tracer la boucle 2 ---\n\n";

		// Variables
		// total : 0 1 10
		// i : 0 1
		// j : 0 1 2 0
		//
		// Sortie à la Console
		// DEBUT
		// *0
		// 1
		// #*12
		// #total = 10
		// FIN
		// 

		int total = 0;

		cout << "DEBUT\n";

		for (int i = 0;	i < 2; i++) // i = 0
		{
			cout << "*";

			for (int j = 0; j < 2; j++)// j = 0
			{
				cout << i + j; // cout

				if (i > j) // i + que j
				{
					total += i;
				}
				else
				{
					total *= 10;
					cout << "\n";
				}
			}

			cout << "#";
		}

		cout << format("total = {}\n", total);
		cout << "FIN\n";
	}

	// TODO: Afficher le message suivant avec une seule boucle for
	// 1 2 3 4 5 6 7 8 9
	if (false)
	{
		cout << "\n--- Boucle à 1 niveau ---\n\n";

		for (int i = 0; i < 9; i++)
		{
			cout << i << " ";
		}
	}

	// TODO: Afficher le message suivant avec 2 boucles for
	// 
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 
	// - Englober la boucle for du dernier exercice (ligne) dans une autre boucle pour la reproduire 5 fois
	// - Renommer la variable 'i' de la boucle intérieure à 'j' par convention
	// - Retour de ligne doit être fait à la fin de chaque ligne donc dans la boucle !
	//		1 2 3 4 5 6 7 8 9\n
	//		...\n
	//		1 2 3 4 5 6 7 8 9\n

	if (false)
	{
		cout << "\n--- Boucle à 2 niveaux ---\n\n";

		for (int j = 0; j < 5; j++) // 0.... 4 (5 itéractions)
		{
			for (int i = 1; i <= 9; i++)
					{
						cout << i << " ";
					}

			cout << "\n";
		}



		
		
	}

	// TODO:  Afficher les nombres descendant par ligne avec 2 boucles for
	// 9 8 7 6 5 4 3 2 1
	// 9 8 7 6 5 4 3 2 1
	// 9 8 7 6 5 4 3 2 1
	// 9 8 7 6 5 4 3 2 1
	// 9 8 7 6 5 4 3 2 1
	if (false)
	{
		cout << "\n--- Boucle négative 1 ---\n\n";

		for (int i = 0; i < 5; i++)
		{
			for (int i = 9 - 1; i >= 1; i--)
				{
					cout << i << " ";
				}
				cout << "\n";
		}

		// Version 1 : Avec itération négative
	
	}

	if (false)
	{
		cout << "\n--- Boucle négative 2 ---\n\n";

		// Version 2 : Avec itération positive
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 9; i++)
				{
					int nombre = 9 - i;
					cout << nombre << " ";
				}
		cout << "\n";
		}
		
	}

	// TODO: Afficher le même nombre par ligne plusieurs fois avec 2 boucles for
	// 1 1 1 1 1
	// 2 2 2 2 2
	// 3 3 3 3 3
	// 4 4 4 4 4
	// 5 5 5 5 5
	// 6 6 6 6 6
	// 7 7 7 7 7
	// 8 8 8 8 8
	// 9 9 9 9 9
	if (false)
	{
		cout << "\n--- Plusieurs fois un nombre ---\n\n";

		int nombre = 1;


		for (int j = 0; j < 9; j++)
		{
	for (int i = 0; i < 5; i++)
		{
			cout << nombre << " ";
			
		}
		cout << "\n";
		++nombre;
		}
	

	}

	// TODO: Afficher le message suivant avec 3 boucles for
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 
	// ---
	// 
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 
	// ---
	// 
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9
	if (false)
	{
		cout << "\n--- Boucle 3 niveaux ---\n\n";

		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < 5; j++)
					{
						for (int i = 0; i < 9; i++)
							{
								int nombre = i + 1;
								cout << nombre << " ";
							}
						cout << "\n";
					}
			cout << "\n";
			cout << "---\n";
			cout << "\n";
		}
	}

	// TODO: Exclure les nombres (4 et 7) avec 2 boucles for
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 
	// TODO: Modifier pour afficher seulement les 20 premiers nombres
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 9
	// 1 2 3 5 6 8 
	if (false)
	{
		cout << "\n--- Nombres sauf 4 et 7 ---\n\n";

		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 9; i++)
					{
						int nombre = i + 1;
						if (nombre != 4 && nombre != 7)
						{
							cout << nombre << " ";	
						}

					}
			cout << "\n";
		}

		
	}

	// TODO: Version avec lecture de nombre maximal et nombre de lignes au clavier
	if (false)
	{
		cout << "\n--- Boucles avec lecture au clavier ---\n\n";

		cout << "Entrer le nombre maximal d'une ligne : ";
		int nombreMaximal;
		cin >> nombreMaximal;

		cout << "Entrer le nombre de lignes : ";
		int nombreLignes;
		cin >> nombreLignes;

		for (int j = 0; j < nombreLignes; j++)
		{
			for (int i = 0; i < nombreMaximal; i++)
			{
				int nombre = i + 1;
				cout << nombre << " ";
			}
			cout << "\n";
		}

	}

	// TODO : Faire la somme des nombres entre les nombres et la somme totale
	// 
	// Somme 0 à 99	: ###
	// Somme 1000 à 1099 : ###
	// Somme 2000 à 2099 : ###
	// Somme 3000 à 3099 : ###
	// Somme 4000 à 4099 : ###
	// Somme 5000 à 5099 : ###
	// 
	// Somme de tous les nombres : ###
	if (true)
	{
		cout << "\n--- Sommes des nombres ---\n\n";

		int grandTotal = 0;
		int nombreDepart = 0;

		for (int j = 0; j < 6; j++)
		{
	// Initialiser le total à 0
		int total = 0;

		// somme 0 à 99 : ##
		for (int i = 0; i < 100; i++)
		{
			int nombre = nombreDepart + i;
			//cout << nombre << "\n";
			//cout << i << "\n";
			total += nombre;
		}
		int nombreFin = nombreDepart + 99;
		cout << format("Somme {} à {} : {}\n",nombreDepart,nombreFin,total);

		grandTotal += total;
		nombreDepart += 1000;
		}

	

		// Afficher le total une fois les boucles terminées
		cout << format("Somme de tous les nombres : {}\n", grandTotal);
	}
}
