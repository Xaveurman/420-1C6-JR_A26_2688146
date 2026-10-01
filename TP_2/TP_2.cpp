//	Auteur : Xavier Blanchete
//	Date : 2026-09-28
//	Description : TP 2 Calculatrice



// Inclusion des librairies
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "fr_CA.UTF-8");
	double nombre = 0;
	double resultat = 0;

		
	while (resultat != 'q')
	{
		// Affichage de l'en-tête
		cout << "\n***********************************************************\n";
		cout << "*                     Imprimerie CSTJ                     *\n";
		cout << "*           Par Votre Xavier Blanchette (2688146)         *\n";
		cout << "***********************************************************\n";

		cout << format("Résultat : {} \n\n", resultat);

		cout << "+) Addition\n";
		cout << "-) Soustraction\n";
		cout << "*) Multiplication\n";
		cout << "/) Division\n";
		cout << "^) Exposant\n\n";

		cout << "!) Factorielle\n";
		cout << "s) Série de Taylor\n\n";

		cout << "r) Rectangle\n";
		cout << "t) Triangle\n\n";

		cout << "q) Quitter\n\n";

		bool doitRecommencerChoix = true;
		while (doitRecommencerChoix == true) //
		{
			// Lire une chaîne au clavier qui peut contenir un nombre ou un caractère
			cout << "Choisir une opération ou entrer un nouveau résultat : ";
			string chaine; // "abc" "+" "10.25"
			cin >> chaine;

			// Extraire le premier caractère de la chaîne pour le choix du menu
			// Ex. "+" => '+'
			// Ex. "1" => '1'
			// Ex. "abcde" => '\0'
			// Ex. "12345" => '\0'
			char choixMenu = chaine.length() == 1 ? chaine[0] : '\0';

			// TODO: Ajouter un switch pour traiter les choix avec le caractère 'choixMenu'
			// Ex. '+', '-', etc.
			
			switch (choixMenu)
			{
			case '+':
				cout << "Entrer un nombre : ";
				cin >> nombre;
				resultat += nombre;
				doitRecommencerChoix = false;
				break;

			case '-':
				doitRecommencerChoix = false;
				break;
				
			case '*':
				doitRecommencerChoix = false;
				break;

			case '/':
				doitRecommencerChoix = false;
				break;

			case '^':
				doitRecommencerChoix = false;
				break;

			case '!':
				doitRecommencerChoix = false;
				break;

			case 's':
			case 'S':
				doitRecommencerChoix = false;
			
				break;

			case 'r':
			case 'R':
				doitRecommencerChoix = false;
				break;

			case 't':
			case 'T':
				doitRecommencerChoix = false;
				break;

			case 'q':
			case 'Q':
			
				resultat = 'q';
				break;


			// TODO: ajouter les autres cases

			default: // "abc" "10.25"

				// TODO: Dans le default du switch, quand il ne s’agit pas d’un choix du menu valide
				// Tenter de convertir la chaîne de caractère en nombre à virgule pour un résultat
				// Instruction try {} catch() {} : similaire à un if / else
				try
				{
					// Convertir la chaîne de caractères en nombre à virgule
					// stod() : fonction string to double
					size_t nombreCaracteresConvertis;
					double nombreVirgule = stod(chaine, &nombreCaracteresConvertis);

					// Lancer une erreur (exception) si la chaîne au complet n'a pas pu être convertie
					// Ex. "10abc123" réussi à convertir "10" => 10, mais il reste "abc123"
					if (nombreCaracteresConvertis < chaine.length())
					{
						// Exécution du code passe au catch() du bloc try { ... } catch () { ... }
						throw exception();
					}

					// *** Partie if – nombre est valide ***
					// TODO : Nombre peut être utilisé ici pour l’affecter comme nouveau résultat 
					// resultat = nombreVirgule
					cout << format("La chaine convertie en nombre à virgule : {}\n", nombreVirgule);
			
				}
				catch (...)
				{
					// *** Partie else – nombre est valide ***
					// TODO: Chaine n’a pas pu être convertie en nombre
					cout << "Erreur!";
					doitRecommencerChoix = true;
				}

				break;

			} // switch
		} // while recommencer choix
	} // while menu principal
} // main