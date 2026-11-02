//	Auteur : Xavier Blanchete
//	Date : 2026-09-28
//	Description : TP 2 Calculatrice



// Inclusion des librairies
#include <format>
#include <iostream>
#include <string>
#include "Constantes.h"
#include "Fonctions.h"

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

void afficherMenu(string& message);
double calculeAddition(double resultat, string& message);
double calculeSoustraction(double resultat, string& message);

double calculeMultiplication(double resultat, string& message);
double calculeDivision(double resultat, string& message, bool& doitRecomancerChoix);
double calculeExposant(double resultat, string& message, char& choixMenu, bool& doitRecommencerChoix);
double calculeFactorielle(double resultat, string& message);
double calculeSerieTaylor(double resultat, string& message);
void defaultErreur(bool doitRecommencerChoix, string chaine);

int main()
{
	// main
	setlocale(LC_ALL, "fr_CA.UTF-8");		// Configuration de la console en Unicode pour les accents
	double resultat = 0;
	string message = "";

	while (resultat != 'q')		
	{
		//travail calcule
		afficherMenu(message);
		bool doitRecommencerChoix = true;
		while (doitRecommencerChoix == true) //
		{
			// Lire une chaîne au clavier qui peut contenir un nombre ou un caractère
			cout << "Choisir une opération ou entrer un nouveau résultat : ";
			string chaine; // "abc" "+" "10.25"
			cin >> chaine;
			// Extraire le premier caractère de la chaîne pour le choix du menu
			// Ex. "+" => '+'
			char choixMenu = chaine.length() == 1 ? chaine[0] : '\0';
			
			switch (choixMenu)
			{
				case '+':
					resultat = calculeAddition(resultat, message);
					doitRecommencerChoix = false;
					break;

				case '-':
					resultat = calculeSoustraction(resultat, message);
					doitRecommencerChoix = false;
					break;
					
				case '*':
					resultat = calculeMultiplication(resultat, message);
					doitRecommencerChoix = false;
					break;

				case '/':
					resultat = calculeDivision(resultat, message, doitRecommencerChoix);				
					doitRecommencerChoix = false;			
					break;

				case '^':
					resultat = calculeExposant(resultat, message, choixMenu, doitRecommencerChoix);				
					doitRecommencerChoix = false;
					break;

					case '!':
						resultat = calculeFactorielle(resultat, message);
						doitRecommencerChoix = false;
						break;

					case 's':
						resultat = calculeSerieTaylor(resultat, message);				
					doitRecommencerChoix = false;
					break;

					case 't':		
					case 'r':
				{

					// Lire la hauteur de la forme a la Console
					double hauteur = 0;
					while (hauteur <= 0)
					{
						cout << "Entrer une hauteur : ";
						cin >> hauteur;

						if (cin.fail())
						{
							cout << format("Erreur : hauteur doit etre un nombre a virgule !\n");
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							continue;
						}

						if (hauteur <= 0)
							cout << format("Erreur : hauteur doit etre plus grand que 0 !\n");
					}

					// Lire la largeur a la Console
					double largeur = 0;
					if (choixMenu == 'r')

					{
						while (largeur <= 0)
						{
							cout << "Entrer une largeur : ";
							cin >> largeur;

							if (cin.fail())
							{
								cout << format("Erreur : largeur doit etre un nombre a virgule !\n");
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								continue;
							}

							if (largeur <= 0)
								cout << format("Erreur : largeur doit etre plus grand que 0 !\n");
						}
					}
					else
					{
						// Assigner pour un triangle rectangle isocele hauteur et largeur a la meme valeur
						largeur = hauteur;
					}

					switch (choixMenu)
					{
					case 'r':
					{
						// Afficher le rectangle
						for (int ligne = 0; ligne < hauteur; ligne++)
						{
							for (int symbole = 0; symbole < largeur; symbole++)
							{
								// Afficher aussi un espace car les lignes espacement des lignes est plus que l'espacement des caracteres
								cout << "*";
								cout << " ";
							}

							cout << "\n";
						}

						double aire = hauteur * largeur;
						double perimetre = hauteur * 2 + largeur * 2;

						cout << "\n";
						cout << format("Aire      : {:.3f}\n", aire);
						cout << format("Perimetre : {:.3f}\n", perimetre);
						cout << "\n";
					}
					break;

					case 't':
					{
						// Afficher le triangle rectangle
						for (int ligne = 0; ligne < hauteur; ligne++)
						{
							// Toujours arrondir vers le haut le nombre de symboles a afficher
							int nombreSymboles = ligne + 1;

							// Afficher les caracteres pour la ligne selon le pourcentage de la largeur
							for (int symbole = 0; symbole < nombreSymboles; symbole++)
							{
								// Afficher aussi un espace car les lignes espacement des lignes est plus que l'espacement des caracteres
								cout << SYMBOLE_FORMES;
								cout << " ";
							}

							cout << "\n";
						}

						double aire = (hauteur * largeur) / 2;
						double hypothenuse = sqrt(hauteur * hauteur + largeur * largeur);
						double perimetre = hauteur + largeur + hypothenuse;

						cout << "\n";
						cout << format("Aire       : {:.3f}\n", aire);
						cout << format("Hypotenuse : {:.3f}\n", hypothenuse);
						cout << format("Perimetre  : {:.3f}\n", perimetre);
						cout << "\n";
					}
					}					
					doitRecommencerChoix = false;
					break;
				}
					case 'q':
					case 'Q':
						resultat = 'q';
						break;
					default: // "abc" "10.25"
						defaultErreur(doitRecommencerChoix, chaine);
						break;
			} // switch
		} // while recommencer choix
	} // while menu principal
} // main

