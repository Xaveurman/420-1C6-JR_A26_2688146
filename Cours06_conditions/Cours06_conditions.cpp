// Cours 06

/*
	Auteur : Xavier Blanchete
	Date : 2026-08-24
	Description : coours 06
*/

// TODO: Vérifier les devoir, revoir ensemble l'Exercice 1

// TODO: Avant de créer le Projet, faire un 'git clone' ou un 'git pull' si dossier Git est déjà présent

// Inclusion des librairies
// TODO: Modifier la version du Projet à C++20 pour la librairie <format>
// TODO: Compiler le code pour le tester et sauvegarder sur Git local et puis sur GitHub
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "fr_CA.UTF-8");

	// Affichage de l'en-tête
	cout << "--- Cours 06 - Conditions avancées ---\n";

#pragma region Theorie
	// *** Opérateurs logiques ***
	// 
	// Opérateur &&
	// - ET (AND)
	// - 2 conditions doivent etre vraie (true) afinb d'être vrai (true)
	// 
	//   &&  | false | true
	// ----------------------
	// false | false | false
	//  true | false | true
	// 
	// Opérateur ||
	// - OU (OR)
	// - Au moins une des 2 condition doit etre vraie (true) afin d'être vrai (true)
	// 
	//   ||  | false | true
	// ---------------------
	// false | false | true
	//  true | true  | true
	// 
	// Opérateur !
	// - NON (NOT)
	// - Inverse la variable ou condition qui suit :
	//		- !variable booléene
	//		- !( condition avec opérateur )
	// 
	// !true	= false
	// !(true)	= false
	// !false	= true
	// !(false)	= true

	cout << "Nombre : ";
	int nombre;
	cin >> nombre;

	// Exemples opérateur && (ET)
	// 
	// nombre > 10 && nombre < 20
	// 
	// nombre = 15            | nombre = 0              | nombre = 100
	// -----------------------------------------------------------------------
	// 15 > 10 && 15 < 20     | 0 > 10 && 0 < 20        | 100 > 10 && 100 < 20
	// true && true           | false && true           | true && false
	// true                   | false                   | false
	bool estNombreEntre10Et20 = nombre > 10 && nombre < 20;

	// Exemple opérateur || (OU)
	// 
	// nombre > 10 || nombre < 20
	// 
	// nombre = 15            | nombre = 0              | nombre = 100
	// -----------------------------------------------------------------------
	// 15 > 10 || 15 < 20     | 0 > 10 || 0 < 20        | 100 > 10 || 100 < 20
	// true || true           | false || true           | true || false
	// true                   | true                    | true
	//
	// Toujours vrai, car essentiellement la condition est :
	// - (> 10) 'nombre positif' (||) OU (< 20) 'nombre négatif' 
	// - Impossible d'avoir un nombre qui ne respecte pas au moins une de 2 conditions
	bool estNombrePlusGrand10OuPlusPetit20 = nombre > 10 || nombre < 20;

	// Exemple opérateur ! (NON)
	// 
	// !(nombre > 10 && nombre < 20)
	// 
	// nombre = 15            | nombre = 0              | nombre = 100
	// -----------------------------------------------------------------------
	// !(15 > 10 && 15 < 20)  |  !(0 > 10 && 0 < 20)    | !(100 > 10 || 100 < 20)
	// !(true && true)        |  !(false && true)       | !(true || false)
	// !true                  |  !(false)               | !(false)
	// false				  |  true                   | true
	bool nestPasNombreEntre10Et20 = !(nombre > 10 && nombre < 20);

	// Lire une lettre au clavier
	cout << "Entrer une lettre : ";
	char lettre;
	cin >> lettre;

	// TODO: Afficher si la lettre est une voyelle (a, e, i, o, u) ou une consonne
	if (lettre == 'a' || lettre == 'e' || lettre == 'i' || lettre == 'o' || lettre == 'u'||
		lettre == 'A' || lettre == 'E' || lettre == 'I' || lettre == 'O' || lettre == 'U')
	{
		cout << format("La lettre {} est une voyelle \n", lettre);
	}
	else
	{
		cout << format("La lettre {} est une consonne \n", lettre);
	}
	// *** Erreurs ***

	// Erreur 1) Oublier de répéter la variable à comparer avec un opérateur de comparaison
	// Condition est toujours vraie (true)
	// lettre == 'x' || (bool)'y' || (bool)'z'
	// lettre == 'x' || true || true
	// false || true || true
	// true
	if (lettre == 'x' || 'y' || 'z') // Erreur
	{
		cout << format("Lettre est 'x', 'y' ou 'z'\n");
	}

	// TODO: Version corrigée


	// Erreur 2) Utiliser le mauvais opérateur logique && ||
	// - Impossible d'être 'x' et 'y' en même temps
	// - lettre == 'x' && lettre == 'y' ...
	// - true && false ...
	// - false
	if (lettre == 'x' && lettre == 'y' && lettre == 'z') // Erreur
	{
		cout << format("Lettre est 'x' ET 'y' ET 'z'\n");
	}

	// TODO: Version corrigée


	// TODO: Vérifier le nombre entré afin d'afficher les messages suivants selon le nombre :
	// 'bien' : 10, 20, entre 100 et 200
	// 'moyen' : 50, 70, plus petit que 0
	// 'secret' : lettre 'a', nombre 1000
	// 'mal' : dans les autres cas

	if (nombre == 10
		|| nombre == 20
		|| (nombre >= 100 && nombre <= 200))
	{
		cout << "Bien\n";

	}

	else if (nombre == 50 || nombre == 70 || nombre < 0);

	{
		cout << "Moyen\n";
	}
	else if (lettre == 'a' && nombre == 1000);
	{
		cout << "Secret\n";
	}
	else
	{
		cout << "mal\n";
	}

	// *** Résolution d'une condition logique ***
	// Priorité des opérations à partir de la gauche
	// - Parenthèses
	// - Casts ()
	// - Division / Multiplication
	// - Addition / Soustraction
	// - ! Non
	// - && Et
	// - || Ou

	// TODO: Exemple de condition logique
	// 
	// A = true
	// B = false
	// C = false
	// D = true
	// 
	// (A && B) || !(C || D)
	// 
	// 1) (true && false) || !(false || true)
	// 2) false || !(false || true)
	// 3) false || !true
	// 4) false || false
	// 5) false
	// 6) 
	// 7) 
	// 8) 
	// 9) 

	// Optimisation pour l'opérateur ET (&&) :
	// - Si la première condition fausse (false) 
	//		- Impossible que la réponse du ET (&&) soit vraie (true)
	//		- false && ... && ... = false
	//      - Retourne faux (false) immédiatement
	// - Prochaines conditions ne sont pas évaluées
	// - Très utile pour éviter les crash dans les prochains cours de Programmation 2 et 3

	// TODO: Exemple de condition opérateur 
	// 
	// A = true;
	// B = false;
	// C = false;
	// D = true;
	// E = false;
	// F = true;
	// 
	// A && B && C && (D || E) || F
	// 
	// 1) A && B && C && (D || E) || F
	// 2) false && false && C && (D || E) || F
	// 3) false || true
	// 4) true
	// 5) 
	// 
	// Conditions C, D et E
	// - Reliées ensemble à A et B par des opérateurs ET (&&) ne seront jamais évaluées, car B est faux (false)
	// 
	// Condition F
	// - Reliée par un opérateur || (OU) avec le reste doit quand même être évaluée

	int a = 5;
	int b = 15;
	int c = -20;

	// TODO: Exemple 1
	bool estConditionExemple1 = (a + b > c) || !((b > 100) && !(c - a > 0)) || !(a - c > b);

	// 1) (5 + 15 > -20) || !((15 > 100) && !(-20 - 5 > 0)) || !(5 - -20 > 15)
	// 2) (20 > -20) || !((15 > 100) && !(-20 - 5 > 0)) || !(5 - -20 > 15)
	// 3) true || !((15 > 100) && !(-20 - 5 > 0)) || !(5 - -20 > 15)	
	// 4) true || !(false && !(-20 - 5 > 0)) || !(5 - -20 > 15)	
	// 5) true || !(false && !(-25 > 0)) || !(5 - -20 > 15)	
	// 6) true || !(false && !false) || !(5 - -20 > 15)	
	// 7) true || !(false && true) || !(5 - -20 > 15)	
	// 8) true || !false || !(5 - -20 > 15)	
	// 9) true || true || !(5 - -20 > 15)	
	// 10) true || !(5 - -20 > 15)	
	// 11) true || !(25 > 15)	
	// 12) true || !true	
	// 13) true || false
	// 14) true
 
	// TODO: Exemple 2
	bool estConditionExemple2 = (a - 5 <= c + 20) && !(c > b) || ((a + b + c > b - c) && (c > 0 || b > 0));
	// erreur  - 20 a la place de - - 20										ici

	// 1) (5 - 5 <= -20 + 20) && !(-20 > 15) || ((5 + 15 + -20 > 15 - 20) && (-20 > 0 || 15 > 0))
	// 2) (0 <= -20 + 20) && !(-20 > 15) || ((5 + 15 + -20 > 15 - 20) && (-20 > 0 || 15 > 0))
	// 3) (0 <= 0) && !(-20 > 15) || ((5 + 15 + -20 > 15 - 20) && (-20 > 0 || 15 > 0))
	// 4) true && !(-20 > 15) || ((5 + 15 + -20 > 15 - 20) && (-20 > 0 || 15 > 0))
	// 5) true && !false || ((5 + 15 + -20 > 15 - 20) && (-20 > 0 || 15 > 0))
	// 6) true && true || ((5 + 15 + -20 > 15 - 20) && (-20 > 0 || 15 > 0))
	// 7) true || ((5 + 15 + -20 > 15 - 20) && (-20 > 0 || 15 > 0))
	// 8) true || ((0 > 15 - 20) && (-20 > 0 || 15 > 0))
	// 9) true || ((0 > -5) && (-20 > 0 || 15 > 0))
	// 10) true || (true && (-20 > 0 || 15 > 0))
	// 11) true || (true && (false || 15 > 0))
	// 12) true || (true && (false || true))
	// 13) true || (true && true)
	// 14) true || true
	// 15) true
	cout << format("Exemple 1 : {}\n", estConditionExemple1);
	cout << format("Exemple 2 : {}\n", estConditionExemple2);

#pragma endregion
}
