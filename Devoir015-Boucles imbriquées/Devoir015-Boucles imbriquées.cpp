//	Auteur : Xavier Blanchete
//	Date : 2026-09-25
//	Description : Devoir 15 boucles



#include <iostream>
#include <string>
#include <format>
using namespace std;

int main()
{
	setlocale(LC_ALL, "fr_CA.UTF-8");

	// Exercice 1
	
	// Variables 
	// i : 1 2 3 4
	// j : -2 -1 0 1 2 3 -2 -1 0 1 2 3 . -2 -1 0 1 2 3 . -2 -1 0 1 2 3
	// k : 1 2 3 . 1 2 3 . 1 2 3
	// 
	// Sortie à la Console
	// -2
	// -1
	// 0
	// 2 3 4
	// 3 4 5
	// -2
	// -1 
	// 0
	// 1
	// 3 4 5
	// -2 
	// -1
	// 0
	// 1
	// 2
	// -2
	// -1 
	// 0
	// 1 
	// 2
	
	

	

	for (int i = 1; i <= 4; ++i)
	{
		for (int j = -2; j < 3; j++)
		{
			if (j < i)
			{
				cout << j << " ";
			}
			else
			{
				for (int k = 1; k <= 3; k++)
				{
					cout << i + k << " ";
				}
			}

			cout << "\n";
		}
	}

}