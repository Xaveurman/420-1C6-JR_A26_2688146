#include <format>
#include <iostream>
#include <string>
#include "Fonctions.h"
#include "Constantes.h"

using namespace std;

void afficherMenu(string& message)
{
	// Affichage de l'en-tête
	cout << "\n***********************************************************\n";
	cout << "*                     Imprimerie CSTJ                     *\n";
	cout << "*           Par Votre Xavier Blanchette (2688146)         *\n";
	cout << "***********************************************************\n";

	if (message != "")
	{
		cout << format("{}\n", message);
		message = "";
	}

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


}
double calculeAddition(double resultat, string& message)
{
	// Lire un nombre valide
	double nombre = 0;
	cout << "Entrer un nombre : ";
	cin >> nombre;

	while (cin.fail()) //true => erreur de lecture
	{
		cin.clear(); // cin.fail() = false
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Erreur : entrer un nombre entier.\n";

		cout << "Entrer un nombre : ";
		cin >> nombre;
	}

	// Calculer le nouveau résultat avec le nombre valide
	char symbole = '+';
	double ancienResultat = resultat;

	resultat += nombre;
	message = format("Opération : {} {} {}\nRésultat : {}\n", ancienResultat, symbole, nombre, resultat);

	return resultat;
}
double calculeSoustraction(double resultat, string& message)
{
	double nombre = 0;
	cout << "Entrer un nombre : ";
	cin >> nombre;
	while (cin.fail()) //true => erreur de lecture
	{
		cin.clear(); // cin.fail() = false
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Erreur : entrer un nombre entier.\n";

		cout << "Entrer un nombre : ";
		cin >> nombre;
	}

	char symbole = '-';
	double ancienResultat = resultat;

	ancienResultat = resultat;
	resultat -= nombre;
	message = format("Opération : {} {} {}\nRésultat : {}\n", ancienResultat, symbole, nombre, resultat);

	return resultat;
}
double calculeMultiplication(double resultat, string& message)
{
		double nombre = 0;
		cout << "Entrer un nombre : ";
		cin >> nombre;

		while (cin.fail()) //true => erreur de lecture
		{
			cin.clear(); // cin.fail() = false
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Erreur : entrer un nombre entier.\n";

			cout << "Entrer un nombre : ";
			cin >> nombre;
		}
		char symbole = '*';

		double ancienResultat = resultat;

		resultat *= nombre;
		message = format("Opération : {} {} {}\nRésultat : {}\n", ancienResultat, symbole, nombre, resultat);

		return resultat;
}
double calculeDivision(double resultat, string& message, bool& doitRecommencerChoix)
{
	
		double nombre = 0;
		cout << "Entrer un nombre : ";
		while (cin.fail()) //true => erreur de lecture
		{
			cin.clear(); // cin.fail() = false
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Erreur : entrer un nombre entier.\n";

			cout << "Entrer un nombre : ";
			cin >> nombre;
		}
		cin >> nombre;
		if (nombre == 0 || resultat == 0)
		{

			cout << "Erreur\n";
			doitRecommencerChoix = true;
		}
		else
		{
			char symbole = '/';
			double ancienResultat = resultat;
			resultat /= nombre;
			message = format("Opération : {} {} {}\nRésultat : {}\n", ancienResultat, symbole, nombre, resultat);
		}
		return resultat;
	
}
double calculeExposant(double resultat, string& message, char& choixMenu, bool& doitRecommencerChoix)
{

	{
		// Lecture du nombre entier a utiliser pour l'exposant
		int nombreEntierExposant = 0;
		bool estExposantInvalide = true;
		while (estExposantInvalide)
		{
			// Afficher le message d'entree selon l'operation a effectuer
			cout << "Entrer l'exposant : ";
			cin >> nombreEntierExposant;

			// Afficher les erreurs de l'entree du nombre selon l'operation a effectuer
			estExposantInvalide = cin.fail();

			if (estExposantInvalide)
			{
				cout << "Erreur : exposant invalide, doit etre un entier !\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		// Annuler l'operation pour 0 avec une puissance negative (1/0^1 = 1/0 = undefined)
		if (resultat == 0 && nombreEntierExposant < 0)
		{
			message = "Operation annulee : impossible pour 0 d'avoir un exposant negatif !\n";
			doitRecommencerChoix = true;
		}

		// Calculer l'exposant selon les cas qui donnent toujours 1, positif ou negatif
		double ancienResultat;
		if (nombreEntierExposant == 0)
		{
			// Retourner toujours la valeur 1 pour un exposant 0
			// Ex. 0^0 = 1, 1^0 = 1, 2^0 = 1, etc.
			ancienResultat = 1;
		}
		else if (nombreEntierExposant > 0)
		{
			// Calculer l'exposant positif a partir du resultat actuel de la calculatrice
			// Ex. x ^ 1, x ^ 2, x ^ 3, ... x ^ n

			// Debuter avec un exposant 1, donc le resultat actuel de la calculatrice
			ancienResultat = resultat;

			// Calculer les exposant restants a partir de 2
			for (int i = 2; i <= nombreEntierExposant; i++)
			{
				double resultatMultiplication = ancienResultat * resultat;
				message += format("{} * {} = {}\n", ancienResultat, resultat, resultatMultiplication);
				ancienResultat = resultatMultiplication;
			}
		}
		else
		{
			// Calculer l'exposant negatif a partir du resultat actuel de la calculatrice
			// Ex. 1 / (x ^ 1), 1 / (x ^ 2), ... 1 / (x ^ n)

			// Debuter avec un exposant -1, donc une fraction de 1 divise par le resultat actuel de la calculatrice
			ancienResultat = 1 / resultat;

			// Calculer les exposant restants a partir de -2
			double diviseur = resultat;
			for (int i = -2; i >= nombreEntierExposant; i--)
			{
				message += format("1 / {} * 1 / {} = 1 / {}\n", diviseur, resultat, diviseur * resultat);
				ancienResultat *= 1 / resultat;
				diviseur *= resultat;
			}
		}

		// Afficher les calculs a la Console si l'exposant n'est pas : 0, 1 ou -1
		if (nombreEntierExposant != 0
			&& nombreEntierExposant != 1
			&& nombreEntierExposant != -1)
		{
			message = "\nCalculs : \n" + message;
		}

		// Afficher l'operation a l'aide des nombres et du symbole de l'operateur
		message = format("Operation : {} {} {} = {}\n{}",
			resultat, choixMenu, nombreEntierExposant, ancienResultat,
			message);

		// Mettre a jour le resultat avec le nouveau resultat de l'exposant
		resultat = ancienResultat;
		return resultat;
	}

}
double calculeFactorielle(double resultat, string& message)
{
	{
		// Lecture du nombre a utiliser avec l'operateur
		double nombre = 0;
		bool estNombreInvalide = true;
		while (estNombreInvalide)
		{
			cout << "Entrer la factorielle : ";
			cin >> nombre;
			estNombreInvalide = cin.fail();

			// Afficher les erreurs de l'entree du nombre selon l'operation a effectuer
			if (estNombreInvalide || nombre != (int)nombre || nombre < 0)
			{
				estNombreInvalide = true;
				cout << "Erreur : factorielle invalide, doit etre un entier positif !\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		// Debuter le calcul du factoriel a 1 pour 0! et 1!
		// 0! = 1
		// 1! = 1
		double nouveauResultat = 1;

		// Ne pas afficher de calculs pour 0! et 1!
		if (nombre != 0 && nombre != 1)
		{
			// Multiplier le resultat par chaque nombre entier en decrementant jusqu'a 1
			message += "\nCalculs : \n";
			for (int i = (int)nombre; i > 0; i--)
			{
				double resultatMultiplication = nouveauResultat * i;
				message += format("{} * {} = {}\n", nouveauResultat, i, resultatMultiplication);
				nouveauResultat = resultatMultiplication;
			}
		}
		// Afficher les calculs de l'operation factorielle
		message = format("Operation : {}! = {}\n{}\n\n Résultats : {}\n",
			nombre, nouveauResultat,
			message, nouveauResultat);

		// Mettre a jour du resultat avec le nouveau resultat
		resultat = nouveauResultat;
	}
	return resultat;
}
double calculeSerieTaylor(double resultat, string& message)
{

	{
		// Lire la variable x de la serie Taylor a la Console
		double x = 0;
		while (true)
		{
			cout << "Entrer le x de la serie de Taylor : ";
			cin >> x;

			if (!cin.fail())
				break;

			cout << "Erreur : x invalide doit etre un nombre a virgule !\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		// Lire la variable n de la serie Taylor a la Console
		int n = 0;
		while (true)
		{
			cout << "Entrer le n de la serie de Taylor : ";
			cin >> n;

			if (!cin.fail() && n >= 0)
				break;

			cout << "Erreur : n invalide, doit etre un nombre entier positif !\n";

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		// Calculer la serie de Taylor
		// Ex. 1 + (x^1 / 1!) + (x^2 / 2!) + (x^3 / 3!) + ... + (x^n / n!)

		// Conserver les differents affichages dans des chaines separees pour les concatener ensemble apres les calculs
		string affichageSerie = "Serie de Taylor : 1";
		string affichageCalculs = "Calculs : 1";
		string affichageValeurs = "Valeurs : 1";

		double nouveauResultat = 1;
		for (int termeSerie = 1; termeSerie <= n; termeSerie++)
		{
			// Calculer le numerateur serie de Taylor : (x ^ n)
			double numerateur = x;
			for (int exposant = 2; exposant <= termeSerie; exposant++)
			{
				numerateur *= x;
			}

			// Calculer le denominateur serie de Taylor : n!
			// Debuter avec le factoriel 1! = 1
			int denominateur = 1;

			// Calculer les autres factoriels jusqu'a n! 
			// Ex. 1 * 5! = 1 * 5 * 4 * 3 * 2
			for (int factoriel = termeSerie; factoriel >= 2; factoriel--)
			{
				denominateur *= factoriel;
			}

			// Faire le calcul de la fraction serie de Taylor : (x ^ n) / n!
			double fractionTaylor = numerateur / denominateur;
			nouveauResultat += fractionTaylor;

			// Afficher les calculs de la serie de Taylor
			// Limiter l'affichage a 3 nombres apres la virgule
			affichageSerie += format(" + ({}^{} / {}!)", x, termeSerie, termeSerie);
			affichageCalculs += format(" + {} / {}", numerateur, denominateur);
			affichageValeurs += format(" + {}", fractionTaylor);
		}

		// Affectuer le resultat de la serie de Taylor a la calculatrice
		resultat = nouveauResultat;

		// Concatener ensemble les 3 chaines d'affichages de la serie de Taylor
		message = format("{}\n{}\n{}\n\nRésultat : {}\n", affichageSerie, affichageCalculs, affichageValeurs, resultat);
	}
	return resultat;
}
void calculeRectangle()
{
}
void calculeTriangle()
{
}
void defaultErreur(bool doitRecommencerChoix, string chaine)
{
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
		cout << "Erreur!\n";
		doitRecommencerChoix = true;
	}
}
