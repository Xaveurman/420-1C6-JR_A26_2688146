//	Auteur : Xavier Blanchete
//	Date : 2026-09-10
//	Description : TP 1 - IMPRIMERIE



#include <iostream>
#include <string>
#include <format>
using namespace std;

int main()
{
	setlocale(LC_ALL, "fr_CA.UTF-8");

	// En tête du programe

	cout << ("***********************************************************\n");
	cout << ("*                     Imprimerie CSTJ                     *\n");
	cout << ("*              Par Votre Nom (Votre Matricule)            *\n");
	cout << ("***********************************************************\n");

	// Entrer le Matricule
	cout << ("--- Numéro client ---\n\n");
	cout << "Entrer votre matricule ou numéro d’employé : ";
	int identification;
	cin >> identification;

	if (identification > 100000 && identification > 9999999)
	{
		cout <<format("Commande pour l'étudiant {}.\n\n",identification);
	}
	else if (identification > 10000 && identification > 20000)
	{
		cout <<format("Commande pour l'enseignant {}.\n\n",identification);
	}
	else if (identification > 3000 && identification > 5000)
	{
		cout <<format("Commande pour l'administrateur {}.\n\n",identification);
	}
	else
	{
		cout << format("Erreur : {} est un matricule ou numéro d’employé invalide, impression annulée.\n", identification);
		system("pause");
		return 0;
	}

	//Pages demander

	cout << ("--- Pages ---\n\n");
	cout << "Entrer le nombre de pages :" ;
	int nombrePage;
	cin >> nombrePage;
	if (nombrePage <= 0)
	{
		cout << format("Erreur : {} n’est pas un nombre de pages valide, impression annulée.\n\n", nombrePage);
		system("pause");
		return 0;
	}

	// Exemplaire
	cout << ("--- Exemplaires ---\n\n");
	cout << "Entrer le nombre d’exemplaires : ";
	int nombreExemplaire;
	cin >> nombreExemplaire;
	if (nombreExemplaire <= 0)
	{
		cout << format("Erreur : {} n’est pas un nombre de pages valide, impression annulée.\n", nombreExemplaire);
		system("pause");
		return 0;
	}

	// choix du type de papier

	cout << ("--- Papier --\n\n");

	cout << ("1) Lettre (8 1/2 x 11) (0.11 $ $ par page)\n");
	cout << ("2) Légal(8 1 / 2 x 14)  (0.13 $ par page)\n");
	cout << ("3) Photo               (1.24 $ par page)\n\n");

	cout << "Entrer le choix de papier : ";
	char choixPapier;
	cin >> choixPapier;

	double prixFeuille1;
	double prixFeuille2;
	double prixFeuille3;

	switch (choixPapier)
	{
	case '1':
		double prixFeuille1 = 0.11;
	break;

	case '2':
		double prixFeuille2 = 0.13;
	break;

	case '3':
		double prixFeuille3 = 1.24;
	break;

	default:
	cout << ("Erreur : {} n’est pas un choix de papier valide, impression annulée.\n", choixPapier);
	break;
	}


	cout << format("prix de la feuille {}",prixFeuille);
} // Fin du programme