/*
	Auteur		: Xavier Blanchette
	Date		: 2026-11-16
	Description	: Introduction aux collections génériques avec vector<T>
*/

#include <format>
#include <iostream>
#include <string>

// Pour accès au type de données vector<T> et les fonctions vector (ex. push_back())
#include <vector> 

// Pour accès à la fonction sort() afin de trier le contenu d'un vecteur
#include <algorithm>

using namespace std;



int main()

{

	//exercice numero 1

	setlocale(LC_ALL, "fr_CA.UTF-8");


	vector<int> nombres;
	int valeurAjoutee = 1;

		

	while (valeurAjoutee != 0)
	{
		cout << "Entrer une valeur a ajouter au vecteur : ";
		cin >> valeurAjoutee;
		nombres.push_back(valeurAjoutee);
	}

	cout << format("\nNombres entres : {}\n", nombres.size() - 1);

	cout << "\nNombres : ";

	for (int i = 0; i < nombres.size(); i++)
	{
		cout << format(" {},", nombres[i]);
	}
	
	cout << "\n\n";

	// exercice numero 2

	

		int nombresGenerer = 0;
		cout << "Entrer la quantite de nombres a generer :  ";
		cin >> nombresGenerer;

		for (int i = 1; i < nombresGenerer; i++)
		{

			int nombreAleatoire = 1 + rand() % 100;
			nombres.push_back(nombreAleatoire);
			cout << format(" {}," ,nombres[i]);
			
		}
		cout << "\n\n";
}