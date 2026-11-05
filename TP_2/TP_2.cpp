//	Auteur : Xavier Blanchete
//	Date : 2026-09-28
//	Description : TP 2 Calculatrice



// Inclusion des librairies
#include <format>
#include <iostream>
#include <string>
#include "Constantes.h"
#include "Fonctions.h"
#include "OperationNouveau.h"

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
double calculeRectangleTriangle(double resultat, string& message, char& choixMenu);

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
						resultat = calculeRectangleTriangle(resultat, message, choixMenu);
					doitRecommencerChoix = false;
					break;
				
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

