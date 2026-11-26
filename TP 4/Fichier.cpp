
#include <format>
#include <iostream>
#include <string>

using namespace std;

void afficherMenu(string& message)
{
	
		cout << "**************************************************************\n";
		cout << "*              Systeme de gestion de bibliotheque            *\n";
		cout << "*              Par Votre nom (Votre matricule)               *\n";
		cout << "**************************************************************\n\n";

		cout << "Date : 2026 / 11 / 26 (Jour 330) # Programme débute toujours au jour 330\n\n";

		cout << "// Affichage des messages d’erreurs lors de la lecture des fichiers\n\n";

		cout << "Contenu de la Bibliotheque :\n";
		cout << "-### livres\n";
		cout << "- ### membres\n";
		cout << "- ### emprunts actifs\n";
		cout << "- ### reservations actives\n\n";

		cout << "-- - Menu principal-- -\n\n";

		cout << "1) Gestion des livres\n";
		cout << "2) Gestion des membres\n";
		cout << "3) Emprunts et reservations\n\n";

		cout << "0) Sauvegarder et quitter\n\n";

		cout << "Entrer votre choix :";
}