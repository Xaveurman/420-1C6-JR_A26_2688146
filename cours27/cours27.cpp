/*
	Auteur		:
	Date		:
	Description	: Introduction à l'opérateur Modulo (%), timestamps et nombres aléatoires
*/

#include <format>
#include <iostream>
#include <string>

// Inclure les librairies afin de générer des nombres aléatoires (C/C++)
#include <cstdlib>	// srand(###), rand()
#include <ctime>	// time(###)

// Inclure la librairie afin d'ajouter des pauses au programme (Sleep())
#include <windows.h>

using namespace std;

void afficherTheorieModulo();
void afficherTheorieTimestamp();
void afficherTheorieNombresAleatoires();

int main()
{
	setlocale(LC_ALL, "en_US");

	std::cout << "--- Cours 25 - Modulo ---\n";

	afficherTheorieModulo();
	//afficherTheorieTimestamp();
	//afficherTheorieNombresAleatoires();

	if (true)

	{
		cout << format("\n--- Generation de nombres aleatoires [10, 50[ ---\n\n");

		const int MIN = 10; // 0.0
		const int MAX = INT_MAX; // 1.0

		for (int i = 0; i < 100; i++)
		{
			// 0 ... 32000
			// 0.0 1.0
			double ratioAleatoire = rand() / (double)RAND_MAX;
			int nombreAleatoire = MIN + ((long long)MAX - MIN + 1) * ratioAleatoire;
			cout << format("Nombre aleatoire {} : {}\n", i, nombreAleatoire);
		}
	}
}

void afficherTheorieModulo()
{
	// *** Opérateur Modulo (%) ***
	// - Opérateur mathématique qui retourne le reste d'une division entière
	// - Syntaxe : a % b
	//		- a : dividende (nombre à diviser)
	//		- b : diviseur (nombre par lequel on divise)
	// - Exemple
	//		- 10 % 3 = 1	(10 / 3 = 3 reste 1)
	//		- 15 % 4 = 3	(15 / 4 = 3 reste 3)
	//		- 20 % 6 = 2	(20 / 6 = 3 reste 2)
	//		- 25 % 5 = 0	(25 / 5 = 5 reste 0)
	// - Utilisations courantes de l'opérateur modulo
	//		- Vérifier si un nombre est pair ou impair
	//			- n % 2 == 0 -> n est pair
	//			- n % 2 == 1 -> n est impair
	//		- Boucler dans un tableau circulaire
	//			- index = (index + 1) % tailleTableau
	//		- Calculer des cycles ou des intervalles réguliers
	//			- Exemples : jours de la semaine, mois de l'année, etc.

	cout << "\n--- Modulo ---\n\n";

	if (false)
	{
		cout << format("10 % 3 = {} (10 / 3 = 3 reste 1)\n", 10 % 3);
		cout << format("15 % 4 = {} (15 / 4 = 3 reste 3)\n", 15 % 4);
		cout << format("20 % 6 = {} (20 / 6 = 3 reste 2)\n", 20 % 6);
		cout << format("25 % 5 = {} (25 / 5 = 5 reste 0)\n", 25 % 5);
	}

	// *** Extraire des parties de nombre ***
	// - Division supprime la partie décimale d'une division (fin du nombre)
	// - Ex. Diviser par 1000 (10^3) supprimer les 3 derniers chiffres du nombre
	// 
	//     1 2 3 4 5 6 7 8 9
	//   /           1 0 0 0
	//                 X X X
	//   --------------------
	//     1 2 3 4 5 6
	// 
	// - Modulo retourne le reste d'une division entière (début du nombre)
	// - Ex. Modulo 1000 (10^3) retourne les 3 derniers chiffres du nombre
	// 
	//     1 2 3 4 5 6 7 8 9
	//   %           1 0 0 0
	//     X X X X X X
	//   --------------------
	//                 7 8 9

	if (false)
	{
		int nombre = 123456789;

		// TODO: Extraire les chiffres au début d'un nombre en utilisant une division entière
		int premierChiffre = 123456789;			// (int)1.23456789 = 1
		int troisPremiersChiffres = 123456789;	// (int)123.456789 = 123

		// TODO: Extraires les chiffres à la fin d'un nombre en utilisant un modulo pour le reste de la division
		int dernierChiffre = 123456789;				// 10 ^ 1 => 1 dernier
		int troisDerniersChiffres = 123456789;		// 10 ^ 3 => 3 derniers

		cout << format("\n--- Nombre : {} ---\n", nombre);
		cout << "\n";
		cout << format("Premier chiffre : {}\n", premierChiffre);
		cout << format("Dernier chiffre : {}\n", dernierChiffre);
		cout << "\n";
		cout << format("3 premiers chiffres : {}\n", troisPremiersChiffres);
		cout << format("3 derniers chiffres : {}\n", troisDerniersChiffres);
	}

	// *** Vérifier un diviseur ***
	// TODO: Vérifier si un nombre est pair ou impair (divisible par 2)
	//  - Pair : divisible par 2 sans reste (reste 0)
	//		- 2 / 2 = 1 (reste 0)		2 % 2 = 0 (reste)
	//		- 4 / 2 = 2 (reste 0)		4 % 2 = 0 (reste)
	//		- 6 / 2 = 3 (reste 0)		6 % 2 = 0 (reste)
	//  - Impair : non divisible par 2 sans reste (reste 1)
	//		- 1 / 2 = 1 (reste 1)		2 % 2 = 1 (reste)
	//		- 3 / 2 = 2 (reste 1)		3 % 2 = 1 (reste)
	//		- 5 / 2 = 3 (reste 1)		5 % 2 = 1 (reste)
	if (false)
	{
		for (int i = 0; i < 10; i++)
		{
			int nombre = i + 1;
			int reste = nombre % 2;
			if (reste == 0)
			{
				cout << format("Nombre {} est pair\n", nombre);
			}
			else
			{
				cout << format("Nombre {} est impair\n", nombre);
			}
			
		}
	}

	// *** Alterner travail ***
	// TODO: Afficher 20 éléments qui alternent entre 0 et 1
	// 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
	if (false)
	{
		for (int i = 0; i < 20; i++)
		{
			int nombre = 0;
			cout << nombre << " ";
		}
	}

	// TODO: Afficher 20 éléments qui alternent entre 0, 1 et 2
	// 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 (2 non affiché car 20 éléments)
	if (false)
	{
		for (int i = 0; i < 20; i++)
		{
			int nombre = 0;
			cout << nombre << " ";
		}
	}

	// TODO: Sauter une ligne à chaque 5 nombres affichés
	// 0 1 0 1 0
	// 1 0 1 0 1
	// 0 1 0 1 0
	// 1 0 1 0 1
	if (false)
	{
		// TODO: Méthode 1 avec 2 boucles 'for' et 1 modulo (%)
		cout << "--- Methode 1 avec 2 boucles 'for' ---\n\n";

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int nombre = 0;
				cout << nombre << " ";
			}

			cout << "\n";
		}

		// TODO: Méthode 2 avec 1 boucle 'for' et 2 modulos (%)
		cout << "--- Methode 2 avec 2 modulo (%) ---\n\n";

		for (int i = 0; i < 20; i++)
		{
			int nombre = 0;
			cout << nombre << " ";
		}
	}
}

void afficherTheorieTimestamp()
{
	// *** Timestamp ***
	// - Date sur un ordinateur sont enregistrés dans un 'timestamp'
	// - Existe plusieurs type de format de timestamp, la plupart sont basés sur le Unix Epoch
	// - Unix Epoch
	//		- Plusieurs systèmes informatiques utilisent le 1er janvier 1970 à 00:00:00 UTC comme point de départ
	//		- Nombre de secondes (s) depuis le 1er janvier 1970
	//			- 0				= 1970-01-01 00:00:00
	//			- 1				= 1970-01-01 00:00:01
	//		    - 1316615272	= 2011-09-21 10:27:52
	//			- 1735707600	= 2025-01-01 00:00:00
	//			- 1761946225	= 2025-10-31 17:30:25
	//		- Nombre de millisecondes (ms) depuis le 1er janvier 1970
	//			- 0				= 1970-01-01 00:00:00.000
	//			- 1				= 1970-01-01 00:00:00.001
	//			- 1316615272000	= 2011-09-21 10:27:52.000
	//			- 1735707600000	= 2025-01-01 00:00:00.000
	//			- 1761946225000	= 2025-10-31 17:30:25.000
	//			- 1761946225123	= 2025-10-31 17:30:25.123
	// - C/C++
	//		- #include <ctime>
	//		- unsigned int timestamp = time(0);
	//			- Nombre de secondes (s) depuis le 1er janvier 1970
	// - Autres formats de timestamp
	//		- Existent d'autres formats timestamp basées sur des chaines de caractères
	//		- ISO 8601
	//			- Aussi appelé 'format UTC' ou 'format international'
	//			- "YYYY-MM-DDTHH:MM:SSZ"
	//			- "1970-01-01T00:00:00Z"
	//			- "2025-10-31T17:30:25Z"
	//		- RFC 3339
	//			- Variante du format 'ISO 8601' avec les fuseaux horaires
	//			- "YYYY-MM-DDTHH:MM:SS±HH:MM"
	//			- "1970-01-01T00:00:00+00:00"
	//			- "2025-10-31T17:30:25-04:00"

	cout << "\n--- Timestamp ---\n\n";

	unsigned long long timestamp = time(0);
	cout << format("Timestamp : {}\n\n", timestamp);

	// Attendre 1 seconde et ré-afficher le timestamp
	for (int i = 0; i < 5; i++)
	{
		Sleep(1000); // 1000 ms = 1 seconde

		unsigned long long timestampActuel = time(0);

		// Extraire les secondes, minutes et heures d'un timestamp
		// Attention, ne gère pas les cas compliqué de gestion de date (leap years, leap second, fuseaux horaires, etc.)
		unsigned int secondes = timestampActuel % 60;
		unsigned int minutes = (timestampActuel / 60) % 60;
		unsigned int heures = (timestampActuel / 3600) % 24; // Non fonctionnel à cause des cas compliqués !
		cout << format("Heure actuelle : {:02}:{:02}:{:02}\n", heures, minutes, secondes);
	}
}

void afficherTheorieNombresAleatoires()
{
	// *** Génération de nombres alétoires ***
	// - Utile pour plusieurs applications de générer des nombres au hasard
	//		- Permet de générer des situation imprévisibles (jeux vidéos, simulations, etc.)
	//		- Permet de tester des programme en générant des données aléatoires
	//		- Plupart des langages de programmation ont une librairie pour générer des nombres aléatoires
	// - Méthodes de génération
	//		- Table de nombre aléatoires
	//			- Ancienne méthode de génération de nombres aléatoires
	//			- Tables pré-générées en mémoire de nombres aléatoires
	//			- Fonctionnement
	//				- Débute à un certain endroit dans la table
	//				- Générer un nombre aléatoire en lisant le prochain nombre dans la table
	//				- Avancer dans la table pour la prochaine génération de nombre aléatoire
	//		- Formule mathématique
	//			- Nouvelle méthode de génération de nombres aléatoires
	//			- Utilise des formules mathématiques pour générer des nombres aléatoires
	//				- Linear Congruential Generator (LCG)
	//					- Utilisé dans la fonction rand() de C/C++
	//				- Mersenne Twister
	//				- Xorshift
	//			- Fonctionnement
	//				- Débuter avec un certain nombre de départ (seed)
	//				- Générer un nombre aléatoire en appliquant la formule mathématique
	//				- Utiliser le nombre généré comme nouveau nombre départ pour la prochaine génération
	// - Génération de nombre aléatoire est souvent appelée 'pseudo-aléatoire'
	//		- Connaitre la 'seed' et la méthode de génération permet de prédire tous les nombres générés
	//		- Danger pour certains domaines ou programmes
	//				- Jeux de hasard
	//				- Sécurité et cryptographie
	//				- etc.
	// - C/C++
	//		- Génération de nombres aléatoires entre [0, RAND_MAX[
	// 		- Linear Congruential Generator (LCG)
	//			- Formule mathématique
	//				- Xn = (a * Xn-1 + c) % m
	//			- Variables
	//				- X  	: prochain nombre aléatoire à générer
	//				- Xn-1	: dernier nombre aléatoire courant généré (sinon générer un dernier nombre avec la 'seed')
	//				- a		: multiplicateur constant (ex. 1103515245)
	//				- c		: incrément constant (ex. 12345)
	//				- m		: modulo du nombre maximal à générer (ex. RAND_MAX = 32767)
	//  	    - Formule réelle rand() est similaire à la formule suivante
	//				- Xn = (1103515245 * Xn-1 + 12345) % 32767
	//		
	//		#include <cstdlib>
	//		#include <ctime>
	// 
	//		srand((unsigned int)time(0));
	// 
	//		// [0, max[
	//      int valeur = (rand() / (double)RAND_MAX) % max;			
	// 
	// 		// [min, max[	
	//		int valeur = min + (rand() / (double)RAND_MAX) % (max - min);

	cout << "\n--- Nombres aleatoires ---\n";

	if (true)
	{
		cout << format("\nGeneration de nombres aleatoires : [0, {}[\n", RAND_MAX);

		// Initialiser la 'seed' pour la génération de nombres aléatoires à un nombre fixe '0'
		// Note : normalement fait une seule fois au tout début du programme
		{
			cout << format("\n--- Generation aleatoire srand(0) ---\n\n");

			srand(0);

			// Générer 5 nombres aléatoires toujours identiques au lancement du programme
			for (int i = 0; i < 5; i++)
			{
				int entierAleatoire = rand();
				cout << format("Nombre aleatoire {}: {}\n", i, entierAleatoire);
			}
		}

		// Initialiser la 'seed' pour la génération de nombres aléatoires à un nombre fixe '12345678'
		// Générer 5 nombres aléatoires toujours identiques au lancement du programme
		{
			cout << format("\n--- Generation aleatoire srand(12345678) ---\n\n");

			srand(12345678);

			for (int i = 0; i < 5; i++)
			{
				int entierAleatoire = rand();
				cout << format("Nombre aleatoire {}: {}\n", i, entierAleatoire);
			}
		}

		// Initialiser la 'seed' pour la génération de nombres aléatoires au temps actuel
		unsigned long long seed = time(0);

		// Générer 5 nombres aléatoires toujours identiques au lancement du programme
		{

			srand((unsigned int)seed);

			// Habituellement initialisé en une seule ligne
			// srand(time(0));

			cout << format("\n--- Generation aleatoire srand({}) ---\n\n", seed);

			for (int i = 0; i < 5; i++)
			{
				int entierAleatoire = rand();
				cout << format("Nombre aleatoire {} : {}\n", i, entierAleatoire);
			}
		}

		// Initialiser la 'seed' pour la génération de nombres aléatoires au temps actuel + 1
		// Note : remarquer que les nombres générés sont très différents malgré un différentce de seulement 1 pour la 'seed'
		{
			srand((unsigned int)seed + 1);

			cout << format("\n--- Generation aleatoire srand({}) ---\n\n", seed + 1);

			// Générer 5 nombres aléatoires toujours identiques au lancement du programme
			for (int i = 0; i < 5; i++)
			{
				int entierAleatoire = rand();
				cout << format("Nombre aleatoire {} : {}\n", i, entierAleatoire);
			}
		}
	}

	// Initialiser la 'seed' une seule fois pour la génération de nombres aléatoires au temps actuel de l'ordinateur
	// Normalement, au début du main()
	srand((unsigned int)time(0));

	// TODO: Modifier afin de générer des nombres aléatoires entre [10, 50[ exclusivement
	// TODO: Modifier afin de générer des nombres aléatoires entre [10, 50] inclusivement
	if (true)

	{
		cout << format("\n--- Generation de nombres aleatoires [10, 50[ ---\n\n");

		const int MIN = 10; // 0.0
		const int MAX = INT_MAX; // 1.0

		for (int i = 0; i < 100; i++)
		{
			// 0 ... 32000
			// 0.0 1.0
			double ratioAleatoire = rand() / (double)RAND_MAX;
			int nombreAleatoire = MIN + ((long long)MAX - MIN + 1) * ratioAleatoire;
			cout << format("Nombre aleatoire {} : {}\n", i, nombreAleatoire);
		}
	}

	// TODO: MAX + 1 peut briser le calcul si MAX est égal à la valeur maximale d'un int (INT_MAX + 1 = INT_MIN)
	//       Utiliser un cast vers un (long long) afin de fixer le problème ((long long)INT_MAX + 1)

}