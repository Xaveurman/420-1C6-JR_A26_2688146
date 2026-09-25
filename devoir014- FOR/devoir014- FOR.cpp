//	Auteur : Xavier Blanchete
//	Date : 2026-09-25
//	Description : Devoir 14 For



#include <iostream>
#include <string>
#include <format>
using namespace std;

int main()
{
	setlocale(LC_ALL, "fr_CA.UTF-8");

	// Exercice 1


	// i : 0 1 2 3 4
	//
	// Sorties à la Console
	// 0 1 2 3
	
	int somme = 0;
	for (int i = 0; i < 4; ++i)
	{
		somme += i;
		cout << i;
	}

	// i : -5 
	//
	// Sorties à la Console
	// -5 0
	// -3 1
	// -1 2
	// 1 3
	// 3 4
	// 5 5
	// 7 6
	// 9 7

	int compteur = 0;
	for (int i = -5; i <= 10; i += 2)
	{
		cout << format("{} ", i);
		cout << format("{}\n", compteur++);
	}


	// Exercice 2
	// 
	// A
	cout << "\n\n";

	for (int i = 1; i < 12; i += 2)
	{
		cout << format("{}\n", i);
	}


	//B
	cout << "\n\n";

	for (int j = 19 - 1; j >= 1; j -= 4)
	{
		cout << format("{}\n", j);
	}


	//C
	cout << "\n\n";

	cout << "Nombre : ";

	int sommeC = 0;
	for (int i = 5; i <= 40; i += 5)
	{
		if (i != 40)
		{
		cout << i;
		cout << ", ";
		}
		else
		{
		cout << i;
		}
		sommeC += i;
	}

	cout << format("\nTotal : {}\n", sommeC);

}