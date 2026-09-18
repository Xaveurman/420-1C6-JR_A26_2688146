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
<<<<<<< HEAD
		cout <<format("Commande pour l'étudiant {}.\n\n",identification);
	}
	else if (identification > 10000 && identification > 20000)
	{
		cout <<format("Commande pour l'enseignant {}.\n\n",identification);
	}
	else if (identification > 3000 && identification > 5000)
	{
		cout <<format("Commande pour l'administrateur {}.\n\n",identification);
=======
		cout << format("Commande pour l'étudiant {}.\n\n",identification);
	}
	else if (identification > 10000 && identification > 20000)
	{
		cout << format("Commande pour l'enseignant {}.\n\n",identification);
	}
	else if (identification > 3000 && identification > 5000)
	{
		cout << format("Commande pour l'administrateur {}.\n\n",identification);
>>>>>>> f19ea222dca3bcc3090a4f95485dda51c551e78b
	}
	else
	{
		cout << format("Erreur : {} est un matricule ou numéro d’employé invalide, impression annulée.\n", identification);
		system("pause");
		return 0;
	}

	//Pages demander

<<<<<<< HEAD
	cout << ("--- Pages ---\n\n");
=======
	cout << ("\n--- Pages ---\n\n");
>>>>>>> f19ea222dca3bcc3090a4f95485dda51c551e78b
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
<<<<<<< HEAD
	cout << ("--- Exemplaires ---\n\n");
=======
	cout << ("\n--- Exemplaires ---\n\n");
>>>>>>> f19ea222dca3bcc3090a4f95485dda51c551e78b
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

<<<<<<< HEAD
	cout << ("--- Papier --\n\n");
=======
	cout << ("\n--- Papier --\n\n");
>>>>>>> f19ea222dca3bcc3090a4f95485dda51c551e78b

	cout << ("1) Lettre (8 1/2 x 11) (0.11 $ $ par page)\n");
	cout << ("2) Légal(8 1 / 2 x 14)  (0.13 $ par page)\n");
	cout << ("3) Photo               (1.24 $ par page)\n\n");

	cout << "Entrer le choix de papier : ";
	char choixPapier;
	cin >> choixPapier;

<<<<<<< HEAD
	double prixFeuille1;
	double prixFeuille2;
	double prixFeuille3;
=======
	double prixFeuille;

>>>>>>> f19ea222dca3bcc3090a4f95485dda51c551e78b

	switch (choixPapier)
	{
	case '1':
<<<<<<< HEAD
		double prixFeuille1 = 0.11;
	break;

	case '2':
		double prixFeuille2 = 0.13;
	break;

	case '3':
		double prixFeuille3 = 1.24;
=======
		prixFeuille == 0.11;
	break;

	case '2':
		prixFeuille == 0.13;
	break;

	case '3':
		prixFeuille == 1.24;
>>>>>>> f19ea222dca3bcc3090a4f95485dda51c551e78b
	break;

	default:
	cout << ("Erreur : {} n’est pas un choix de papier valide, impression annulée.\n", choixPapier);
	break;
	}

<<<<<<< HEAD

	cout << format("prix de la feuille {}",prixFeuille);
//=======
//teste	cout << format("prix de la feuille {}",prixFeuille);

	cout << ("\n--- Mode d'impression ---)\n\n");

	cout << ("	1) Recto en noir et blanc	(100 %)\n");			// 100 %
	cout << ("	2) Recto - verso en noir et blanc	(200 %, moitié des pages)\n");	// 150 %
	cout << ("	3) Recto en couleur		(300 %)\n");				// 300 %
	cout << ("	4) Recto - verso en couleur		(425 %, moitié des pages)\n");	// 425 %

	cout << "Entrer le mode d’impression : ";
	char modeImpression;
	cin >> modeImpression;

	int pourcent;

	switch (modeImpression)
	{
	case '1':
		pourcent = 100;
		prixFeuille *= 1;
		break;

	case '2':
		pourcent = 150;
		prixFeuille *= 1.5;
		nombrePage /= 2;
		break;

	case '3':
		pourcent = 300;
		prixFeuille *= 3;
		break;

	case '4':
		pourcent = 425;
		prixFeuille *= 4.25;
		nombrePage /= 2; // nombrePage = nombrePage / 2
		break;

	default:
		cout << ("Erreur : {} n’est pas un choix de papier valide, impression annulée.\n", modeImpression);
		break;
	}


	// calcule
	double prixExemplaire = nombrePage * prixFeuille;
	double totalSous = prixExemplaire * nombreExemplaire;

	cout << "\n--- Sous-total ---\n\n";

	cout << format("Pages par exemplaire		: {} pages\n", nombrePage);
	cout << format("Prix par page			: {:.2f} $\n", prixFeuille);
	cout << format("Ratio mode impression		: {} %\n\n", pourcent);

	cout << format("Calcul par exemplaire		: {} pages x {:.2f} $ par page x {} % mode impression\n", nombrePage, prixFeuille, pourcent);
	cout << format("Prix par exemplaire		: {:.2f} $\n\n", prixExemplaire);

	cout << format("Calcul du sous - total		: {:.2f} $ par exemplaire x {} exemplaires\n", prixExemplaire, nombreExemplaire);
	cout << format("Sous - total			: {:.2f} $\n\n", totalSous);

	double rabais = 0;

	





>>>>>>> f19ea222dca3bcc3090a4f95485dda51c551e78b
} // Fin du programme