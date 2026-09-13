// devoir06.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
/*
	Auteur : Xavier Blanchete
	Date : 2026-08-24
	Description : Devoir 06
*/

#include <iostream>
#include <string>
#include <format>
using namespace std;

int main()
{
	setlocale(LC_ALL, "fr_CA.UTF-8");
	//Exercice 1
	// Pour chaque réponse, résoudre étape par étapes les conditions suivantes en booléens comme il a été fait en classe afin de 
	// trouver la valeur de chaque booléen.Résoudre à chaque étape seulement le prochain booléen le plus prioritaire
	// int x = 50;

	// int y = 100;
	// bool exemple = ((x > 10) && (y <= 10 || x < y));



	// ((x > 10) && (y <= 10 || x < y)) 

	// 

	// 1) (true && (y <= 10 || x < y)) 

	// 2) (true && (false || x < y)) 

	// 3) (true && (false || true)) 

	// 4) (true && true) 

	// 5) true 



	/// Copier le code suivant dans Visual Studio et décortiquer chaque réponse comme l’exemple précédent.

	bool reponseA = 10 > 5 || (45 <= 40 && "a" != "b");

	// 10 > 5 || (45 <= 40 && "a" != "b"); 
	// 
	// 1) ... 

	int a = 20;
	int b = 30;
	int c = 50;
	bool reponseB = c == a + b && (b - 30 > 0 || b - a > 0);
	// ( 50 == 20 + 30 && (30 - 30 > 0 || 30 - 20 > 0)
	// ( 50 == 20 + 30 && (0 > 0 || 30 - 20 > 0)
	// ( 50 == 20 + 30 && (0 > 0 || 10 > 0)
	// ( 50 == 20 + 30 && (false || true)
	// ( 50 == 20 + 30 && (true)
	// ( 50 == 50 && (true)
	// ( true && (true)
	// true


	int d = -10;
	int e = 100;
	int f = -55;
	bool reponseC = (d > 0 || e > 0) && (d > e || (e > 0 || f > 0));
	// ( -10 > 0 || 100 > 0) && (-10 > 100 || (100 > 0 || -55 > 0));
	// ( false || 100 > 0) && (-10 > 100 || (100 > 0 || -55 > 0));
	// ( false || true ) && (-10 > 100 || (100 > 0 || -55 > 0));
	// ( true ) && (-10 > 100 || (100 > 0 || -55 > 0));
	// ( true ) && (false || (100 > 0 || -55 > 0));
	// ( true ) && (false || (true || -55 > 0));
	// ( true ) && (false || (true || false));
	// ( true ) && (false || (true));
	// ( true ) && (true);
	// true;

	double g = -10.0;
	int h = 100;
	string i = "i";
	bool reponseD = ((g == -10.0 && h == g) || i == "I" || (h > g && i == "i"));
	// ((-10.0 == -10.0 && 100 == -10.0) || i == i || ( 100 > -10.0 && i == i))
	// ((true && 100 == -10.0) || i == i || ( 100 > -10.0 && i == i))
	// ((true && false) || i == i || ( 100 > -10.0 && i == i))
	// (false || i == i || ( 100 > -10.0 && i == i))
	// (false || true || ( 100 > -10.0 && i == i))
	// (false || true || ( 100 > -10.0 && true))
	// (false || true || ( true && true))
	// (false || true || true)
	// (true || true)
	// true

	// Affichage des réponses finales pour vous aider à valider partiellement 

	cout << format("Réponse finale A : {}\n", reponseA);
	cout << format("Réponse finale B : {}\n", reponseB);
	cout << format("Réponse finale C : {}\n", reponseC);
	cout << format("Réponse finale D : {}\n", reponseD);

	// Exercice 2 

	cout << "Entrer le total de la facture :";
	double totalFacture;
	cin >> totalFacture;

	cout << "Entrer le nombre de produits achetés :";
	double nombreProduitAchete;
	cin >> nombreProduitAchete;

	cout << "Entrer le type de membre (or, argent, bronze) :";
	string typeMembre;
	cin >> typeMembre;


	double rabais = totalFacture * 0.25;

	double total = totalFacture - rabais;
	// Variables

	// Calculs
	if (typeMembre == "or")
	{
		if (totalFacture >= 30)
		{
			cout << format(" *** rabais ***\n");
			cout << format("Membre : {}\n", typeMembre);
			cout << format("Nombre de produits : {}\n", nombreProduitAchete);
			cout << format("Sous-total : {:.2f}\n\n", totalFacture);
			cout << format("Rabais (25%) : {:.2f} $\n", rabais);
			cout << format("Total : {:.2f} $\n", total);
		}


	}
	else if (typeMembre == "argent")
	{
		if (totalFacture >= 50 || nombreProduitAchete >= 5)
		{
			cout << format(" *** rabais ***\n");
			cout << format("Membre : {}\n", typeMembre);
			cout << format("Nombre de produits : {}\n", nombreProduitAchete);
			cout << format("Sous-total : {:.2f}\n\n", totalFacture);
			cout << format("Rabais (25%) : {:.2f} $\n", rabais);
			cout << format("Total : {:.2f} $\n", total);
		}
	}
	else if (typeMembre == "bronze")
	{
		if (totalFacture >= 100 && nombreProduitAchete >= 10)
		{
			cout << format(" *** rabais ***\n");
			cout << format("Membre : {}\n", typeMembre);
			cout << format("Nombre de produits : {}\n", nombreProduitAchete);
			cout << format("Sous-total : {:.2f}\n\n", totalFacture);
			cout << format("Rabais (25%) : {:.2f} $\n", rabais);
			cout << format("Total : {:.2f} $\n", total);
		}
	}
	else
	{
		cout << format("Total : {:.2f} $\n", totalFacture);
	}


	// exercice 3

	cout << "Choisire un numero entre 1 et 49  :";
	int numeroLoterie1;
	cin >> numeroLoterie1;

	if (numeroLoterie1 < 1 || numeroLoterie1 > 49)
	{
		cout << format("Erreur : le nombre {} n’est pas entre 1 et 49, achat annulé.\n", numeroLoterie1);
		return 0;
	}


	cout << "Choisire un numero entre 1 et 49  :";
	int numeroLoterie2;
	cin >> numeroLoterie2;

	if (numeroLoterie1 == numeroLoterie2)
	{
		cout << format("Erreur : le nombre {} a déjà été sélectionné, achat annulé.\n", numeroLoterie2);
		return 0;
	}
	if (numeroLoterie2 < 1 || numeroLoterie2 > 49)
	{
		cout << format("Erreur : le nombre {} n’est pas entre 1 et 49, achat annulé.\n", numeroLoterie2);
		return 0;
	}


	cout << "Choisire un numero entre 1 et 49  :";
	int numeroLoterie3;
	cin >> numeroLoterie3;

	if (numeroLoterie2 || numeroLoterie3)
	{
		cout << format("Erreur : le nombre {} a déjà été sélectionné, achat annulé.\n", numeroLoterie2);
		return 0;
	}
	if (numeroLoterie1 == numeroLoterie3)
	{
		cout << format("Erreur : le nombre {} a déjà été sélectionné, achat annulé.\n", numeroLoterie2);
		return 0;
	}
	if (numeroLoterie3 < 1 || numeroLoterie3 > 49)
	{
		cout << format("Erreur : le nombre {} n’est pas entre 1 et 49, achat annulé.\n", numeroLoterie2);
		return 0;
	}

	cout << format("Numero des billets : {} {} {}\n", numeroLoterie1, numeroLoterie2, numeroLoterie3);
}
