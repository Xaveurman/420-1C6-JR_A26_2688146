/*
	Auteur : Xavier Blanchete
	Date : 2026-08-24
	Description : Devoir 05
*/

#include <iostream>
#include <string>
#include <format>

using namespace std;


int main()
{

	cout << "Entrer la largeur du rectangle : ";
	int largeurRectangle;
	cin >> largeurRectangle;

	cout << "Entrer la hauteur du rectangle : ";
	int hauteurRectangle;
	cin >> hauteurRectangle;

	if (largeurRectangle <= 0)
	{
		cout << format("Erreur : largeur ne peut être 0 ou négative.");
	}
	else if (hauteurRectangle <= 0)
	{
		cout << format("Erreur : hauteur ne peut être 0 ou négative.");
	}
	else if (largeurRectangle == hauteurRectangle)
	{
		cout << format("Carré {} par {}\n", largeurRectangle, hauteurRectangle);
	}
	else if (largeurRectangle > hauteurRectangle)
	{
		cout << format("Rectangle {} par {}\n", largeurRectangle, hauteurRectangle);

		double ratioHauteur = largeurRectangle / hauteurRectangle;
		cout << format("{:.3f} % plus large que haut\n", ratioHauteur);
	}
	else
	{
		cout << format("Rectangle {} par {}\n", largeurRectangle, hauteurRectangle);
		cout << format("Plus haut que large\n");

		double ratioHauteur = hauteurRectangle / largeurRectangle;
		cout << format("{:.3f} % plus haut que large\n", ratioHauteur);
	}

	double aire = largeurRectangle * hauteurRectangle;
	double Perimetre = 2 * (largeurRectangle + hauteurRectangle);

	cout << format("Aire : {:.2f}\n", aire);
	cout << format("Perimètre : {:.2f}\n", Perimetre);

	system("pause"); 			system("cls");

	cout << "Entrer le premier nombre :";
	double nombre1;
	cin >> nombre1;

	cout << "Entrer le premier nombre :";
	double nombre2;
	cin >> nombre2;

	if (nombre1 == nombre2)
	{
		cout << format("Nombre {:.3f} et {:.3f} sont égaux\n", nombre1, nombre2);
	}
	else if (nombre1 > nombre2)
	{
		double differenceNombre1 = nombre1 - nombre2;
		cout << format("Nombre {:.3f} et {:.3f} sont differents de {:.3f}\n", nombre1, nombre2, differenceNombre1);
	}
	else
	{
		double differenceNombre2 = nombre2 - nombre1;
		cout << format("Nombre {:.3f} et {:.3f} sont differents de {:.3f}\n", nombre1, nombre2, differenceNombre2);
	}


	cout << "Entrer le courriel :";
	double couriel;
	cin >> couriel;

	cout << "Confirmer le courriel";
	double courielConfirme;
	cin >> courielConfirme;

	if (couriel == courielConfirme)
	{
		cout << "Entrer le mot de passe";
		double motDePasse;
		cin >> motDePasse;

		cout << "Confirmer le mot de passe";
		double motDePasseConfirme;
		cin >> motDePasseConfirme;

		if (motDePasseConfirme == motDePasse)
		{
			cout << format("Succès : nouveau compte compte ### a été créé !");
		}
		else if (motDePasseConfirme != motDePasse)
		{
			cout << format("Erreur : mots de passe différents, création du compte annulée.");
		}
	}
	else
	{
		cout << format("Erreur : courriels différents, création du compte annulée.");
	}

	cout << "Nombre de billets achetes : ";
	double personne;
	cin >> personne;

	if (personne >= 0)
	{
		// Ventes de billets
		double coutBillet = personne * 29.99;

		// vairables

		// Calculs
		if (personne < 20)
		{
			cout << format("Aucun rabais\n\n");
			double rabais = 0;
			double total = coutBillet + rabais;

			cout << format("Sous-total : {:.2f} $\n", coutBillet);
			cout << format("Rabais : 0%\n", rabais);
			cout << format("Total : {:.2f} $\n", total);
		}
		else if (personne > 50)
		{
			cout << format("25 % de rabais\n\n");

			double rabais = coutBillet * 0.25;
			double total = coutBillet + rabais;


			cout << format("Sous-total : {:.2f} $\n", coutBillet);
			cout << format("Rabais : 25%\n", rabais);
			cout << format("Total : {:.2f} $\n", total);
		}
		else if (personne > 20)
		{
			cout << format("10 % de rabais\n\n");
			double rabais = coutBillet * 0.50;
			double total = coutBillet + rabais;

			cout << format("Sous-total : {:.2f} $\n", coutBillet);
			cout << format("Rabais : 10%\n", rabais);
			cout << format("Total : {:.2f} $\n", total);
		}

		// Affichage
	}
	else
	{
		// Remboursement de billets
		cout << "Entrer le total de la facture originale  : ";
		double totalFacture;
		cin >> totalFacture;

		cout << "Entrer le nombre de jours avant l’événement :";
		double joursAvantEvent;
		cin >> joursAvantEvent;

		// Variables

		// Calculs
		if (joursAvantEvent < 0)
		{
			cout << format("lil bro n'aura pas son remboursement");
		}
		else if (joursAvantEvent > 7)
		{
			cout << format("remboursement 100 %");
		}
		else if (joursAvantEvent >= 5)
		{
			cout << format("remboursement 50 %");
		}
		else if (joursAvantEvent < 5)
		{
			cout << format("remboursement 10% par jour avant l'événement");
		}

		// Affichages des messages
	}

}