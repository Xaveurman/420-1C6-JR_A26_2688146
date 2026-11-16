/*
	Auteur		: Xavier Blanchette
	Date		: 2026-11-16
	Description	: Introduction aux collections génériques avec vector<T>
*/

#include <format>
#include <iostream>
#include <string>

// Pour accès au type de données vector<T> et les fonctions vector (ex. push_back())
#include <vector> 

// Pour accès à la fonction sort() afin de trier le contenu d'un vecteur
#include <algorithm>

using namespace std;

void afficherVecteurParCopie(vector<int> vecteur, string nom);
void afficherVecteurParReference(vector<int>& vecteur, string nom);
void modifierValeurParCopie(vector<int> vecteur, int valeur);
void modifierValeurParReference(vector<int>& vecteur, int valeur);
void testerRedimensionnementVecteur(int tailleReservationVecteur, int nombreAjouts);

vector<int> retournerNouveauVecteur();

int main()
{
	cout << "--- Cours 34 - Vecteurs ---\n\n";

	// *** Collections génériques ***
	// - Conteneurs qui peuvent contenir plusieurs types de données selon un type générique spécifié
	//		- <T> (type)			: <int>, <double>, <string>, <CustomStruct>, etc.
	//		- <K, V> (key, value)	: <int, string>, <int, CustomStruct>, etc.
	// - Fournissent des fonctionnalités avancées pour la gestion des collections
	// 
	// C++ Standard Template Library (STL) | C#                          | JavaScript
	// ---------------------------------------------------------------------------------
	// std::vector<T>                      | List<T>			         | Array
	// std::unordered_map<K, V>            | Dictionary<K, V>            | Map
	// std::queue<T>                       | Queue<T>                    | Queue
	// std::stack<T>                       | Stack<T>                    | Stack
	// std::set<T>                         | HashSet<T>                  | Set
	// ...

	// *** Tableau dynamique (std::vector<T>) ***
	// - Conteneur qui peut redimensionner automatiquement les éléments afin d'en ajouter et d'en supprimer
	// - Tableau continu en mémoire du type de données spécifié
	//		- vector<int>	 : contient un tableau int[] en mémoire
	//		- vector<string> : contient un tableau string[] en mémoire
	//		- etc.
	// - Gère automatiquement la mémoire du tableau (allocation, libération, redimensionnement)
	//		- Définition
	//			- Allocation dynamique de mémoire d'un tableau sur le tas (heap)
	//				- Taille définie lors de la définition
	//				- Taille par défaut de 10 éléments si non spécifiée lors de la définition du vecteur
	//					- C++ : tableau de taille 0 par défaut
	//					- C#  : tableau de taille 10 par défaut (List<T>)
	//          - Informations conservées
	//				- Pointeur vers un tableau dynamique en mémoire sur le tas (heap)
	//				- Nombre d'éléments actuellement utilisés (.size())
	// 				- Capacité actuelle du tableau (.capacity())
	//		- Ajout d'un élément
	//			- Tableau ne contient pas le maximum d'élément
	//				- Ajout de l'élément au premier index libre
	//			- Tableau contient le maximum d'éléments
	//				- Allocation d'un nouveau tableau avec une capacité doublée sur le tas (heap)
	//					- C++ : capacité +25%
	//					- C#  : capacité x2 (List<T>)
	//				- Copie de chaque élément de l'ancien tableau vers le nouveau tableau
	//				- Changement du pointeur vers le nouveau tableau
	//				- Libération de l'ancien tableau en mémoire
	//		- Suppression d'un élément
	//			- Éléments du tableau doivent toujours rester contigu en mémoire
	//				- Permet un accès par index []
	//				- Permet de connaitre le nombre d'éléments avec .size()
	//			- Déplacement des éléments lors de l'ajout ou de la suppression
	//				- Supprimer premier élément (0)
	//					- Tous les éléments suivants doivent être décalés d'un index vers le début
	// 				- Supprimer dernier élément (size() - 1)
	// 					- Aucun déplacement nécessaire

	if (false)
	{
		cout << "--- Redimensionnement automatique ---\n\n";

		const int NOMBRE_AJOUTS = 100;

		// Créer un vecteur sans tableau initial (beaucoup de redimensionnement)
		testerRedimensionnementVecteur(0, NOMBRE_AJOUTS);
		system("pause");

		// Créer un vecteur avec tableau de taille initiale égale au nombre d'éléments à ajouter
		const int NOMBRE_INITIAL = 100;

		testerRedimensionnementVecteur(NOMBRE_INITIAL, NOMBRE_AJOUTS);
		system("pause");
	}

	// *** Syntaxe ***
	// #include <vector>
	// 
	// // Tableau prédéfini avec taille par défaut (10 éléments)
	// vector<type> nomVecteur;	
	// 
	// // Tableau avec taille personnalisée
	// vector<type> nomVecteur(tailleInitiale);
	// vector<type> nomVecteur(tailleInitiale, valeurInitiale);
	// 
	// // Initialisation avec des valeurs
	// vector<type> nomVecteur = { valeur1, valeur2, valeur3, ... };
	//

	// TODO: Dessin de la mémoire d'un vecteur (pointeur, capacity, size, tableau)

	if (false)
	{
		cout << "--- Declaration des vecteurs ---\n\n";

		// *** Déclaration des vecteurs ***
		// - Plusieurs façons de déclarer un vecteur
		// - Différences entre capacity (taille du tableau en mémoire) et size (nombre d'éléments utilisés)

		// Déclaration d'un vecteur avec un tableau par défaut vide
		// Capacity		: 0
		// Size			: 0
		// Tableau		: 
		vector<int> vecteurVide;

		// Déclarer un vecteur sans aucun élément, mais 20 espaces en mémoire
		// Capacity		: 20
		// Size			: 0
		// Tableau		: 
		// Note : Rare, seulement pour optimisation de ne pas avoir à agrandir le tableau
		vector<int> vecteurVidePredefini;
		vecteurVidePredefini.reserve(20);

		// Déclarer un vecteur avec 5 valeurs, donc 5 espaces en mémoire
		// Capacity		: 5
		// Size			: 5
		// Tableau		: 10, 20, 30, 40, 50
		vector<int> vecteurValeurs = { 10, 20, 30, 40, 50 };

		// Vecteur avec un tableau par défaut de 20 éléments initialisé à une valeur
		// Capacity		: 20
		// Size			: 20
		// Tableau		: 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5
		vector<int> vecteurValeurPredefinie1(20, 5);
		vector<int> vecteurValeurPredefinie2 = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };

		// Erreur de syntaxe
		//vector<int> vecteurValeurPredefinie2(20) = {5}; 
		
	}

	// *** Utilisation des vecteurs ***
	// - Créer un vecteur
	//		- vector<int> vecteur;
	// - Ajouter des éléments à la fin du tableau avec push_back()
	//		- vecteur.push_back(valeur);
	// - Accéder aux éléments avec une boucle for sur le nombre d'éléments du tableau 'size()' et l'opérateur '[]'
	//		for (int i = 0; i < vecteur.size(); i++)
	//		{
	//			cout << vecteur[i];
	//		}
	// - C#
	//		- List<int> nomListe = new List<int>();
	//		- Fonctions similaires : 
	//			- Add(), Remove(), Insert(), Clear(), Count, Capacity, etc.
	// - JavaScript
	//		- let nomTableau = [];
	//		- Fonctions similaires :
	//			- push(), pop(), splice(), length, etc.
	//		- Tout est une chaine de caractères ou un objet, donc possible de mélanger les types dans un même tableau
	//
	// *** Méthodes courantes de std::vector ***
	// * Initilisation *
	// - .reserve(tailleTableau): Réserver un tableau en mémoire de la taille spécifiée dans le 'heap'
	//
	// * Informations *
	// - .size()				: Retourner le nombre d'éléments dans le vecteur
	// - .capacity()			: Retourner la capacité actuelle du tableau (taille du tableau alloué en mémoire)
	// - .empty()				: Vérifier si le vecteur est vide (raccourci de .size() == 0)	
	// 
	// * Ajout / Insertion *
	// - .push_back(valeur)	
	//		- Ajouter un élément à la fin du tableau au premier index libre
	//		- Tableau plein cause le redimensionnement automatique avec copie de chaque élément
	// 
	// - .insert(.begin() + index, valeur)	    
	//     - Insèrer une valeur à la position spécifiée en déplace les autres éléments du tableau
	//	   - Tableau plein cause le redimensionnement automatique avec copie de chaque élément
	// 
	// * Obtenir des éléments * 
	// - .front()					: Obtenir le premier élément du vecteur
	// - .back()					: Obtenir le dernier élément du vecteur
	// - [index]	
	//		- Accèder à l'élément à l'index spécifié sans vérification des limites
	//		- Crash si l'index est hors limites [0, .size() - 1]
	// 
	// * Supprimer des éléments *
	// - .clear()					: Supprimer tous les éléments
	// - .pop_back()				: Supprimer le dernier élément du vecteur
	// - .erase(.begin() + index)   : Supprimer l'élément à l'index spécifié à partir du début du vecteur (.begin())
	//
	// * Trier * 
	// - #include <algorithm>
	// - sort(.begin(), .end()) : Trier les éléments en ordre croissant

	if (false)
	{
		cout << "--- Utilisation des vecteurs ---\n\n";

		// TODO: Créer un vecteur vide
		vector<int> nombres;

		// TODO: Ajouter les valeurs à la fin du vecteur avec .push_back() : 10, 20, 30, 40, 50
		nombres.push_back(10);
		nombres.push_back(20);
		nombres.push_back(30);
		nombres.push_back(40);
		nombres.push_back(50);
	
		// Lire une valeur à ajouter à la Console
		int valeurAjoutee;
		cout << "Entrer une valeur a ajouter 3 fois a la fin du vecteur : ";
		cin >> valeurAjoutee;

		// TODO: Ajouter 3 fois la valeur lue à la Console à la fin du vecteur
		for (int i = 0; i < 3; i++)
		{
			nombres.push_back(valeurAjoutee);
		}

		// Afficher les valeurs à la main en utilisant l'opérateur []
		cout << format("Premier element   [0] : {}\n", nombres[0]);
		cout << format("Deuxieme element  [1] : {}\n", nombres[1]);
		cout << format("Troisieme element [2] : {}\n", nombres[2]);
		cout << format("Quatrieme element [3] : {}\n", nombres[3]);
		cout << format("Cinquieme element [4] : {}\n", nombres[4]);
		cout << format("Sixieme element   [5] : {}\n", nombres[5]);
		cout << format("Septieme element  [6] : {}\n", nombres[6]);
		cout << format("Huitieme element  [7] : {}\n", nombres[7]);

		// TODO: Montrer un crash avec un mauvais index du vecteur
		// Utiliser le bouton 'Recommencer' et la 'Pile d'appels' pour identifier la ligne du crash
		//cout << format("Avant debut tableau  [-1] : {}\n", vecteur[-1]); // Crash
		//cout << format("Apres fin tableau     [8] : {}\n", vecteur[8]);  // Crash

		// TODO: Afficher le nombre d'éléments du vecteur et les valeurs avec une boucle for avec 'size()' et l'opérateur '[]'
		cout << format("\nNombre d'elements : {}\n", nombres.size());

		for (int i = 0; i < nombres.size(); i++)
		{
			cout << format("vecteur[{}] : {}\n", i, nombres[i]);
		}

		// TODO: Modifier la valeur du 3ème et 5ème élément à 123 et 456 avec l'opérateur '[]'
		nombres[2] = 123;
		nombres[4] = 456;

		// TODO: Insérer la valeur 777 à la fin du vecteur avec 'push_back()'
		nombres.push_back(777);

		// TODO: Insérer la valeur 999 au début du vecteur avec 'insert(vecteur.begin() + index, valeur)'
		nombres.insert(nombres.begin(), 999);

		// TODO: Insérer la valeur 888 à l'avant-dernier index du vecteur and utilisant 'insert(vecteur.begin() + index, valeur)'
		nombres.insert(nombres.begin() + nombres.size() - 1, 888);

		// TODO: Réafficher les valeurs en utilisant la boucle for d'affichage précédente
			cout << format("\nNombre d'elements : {}\n", nombres.size());

		for (int i = 0; i < nombres.size(); i++)
		{
			cout << format("vecteur[{}] : {}\n", i, nombres[i]);
		}

		// TODO: Récupérer la valeur et retirer le dernier élément du vecteur avec 'pop_back()'
		int nombres = nombres.back();
		nombres.pop_back();

		// TODO: Récupérer la valeur et supprimer le premier élément du vecteur (index 0) avec 'erase(vecteur.begin() + index)'
		int nombre2 = nombres.back();
		nombres.erase(nombres.begin() + nombres.size() - 1);

		// TODO: Récupérer la valeur du 4ème élément du vecteur (index 3) avec l'opérateur '[]'
		// - Ensuite supprimer l'élément avec 'erase(vecteur.begin() + index)'
		int nombre3 = nombres[3];
		nombres.erase(nombres.begin() + 3);
		// TODO: Réafficher les valeurs en utilisant la boucle for d'affichage précédente
		cout << format("\nNombre d'elements : {}\n", nombres.size());

		for (int i = 0; i < nombres.size(); i++)
		{
			cout << format("vecteur[{}] : {}\n", i, nombres[i]);
		}

		// TODO: Trier le vecteur en ordre croissant avec l'algorithme 'sort(vecteur.begin(), vecteur.end())'
		sort(nombres.begin(), nombres.end()); 

		// TODO: Réafficher les valeurs en utilisant la boucle for d'affichage précédente

		cout << format("\nNombre d'elements : {}\n", nombres.size());

		for (int i = 0; i < nombres.size(); i++)
		{
			cout << format("vecteur[{}] : {}\n", i, nombres[i]);
		}

	}

	// *** Recherche et suppression ***
	// - Pour supprimer des éléments par leur valeur, trouver l'index de l'élément
	// - Utiliser la fonction 'erase(vecteur.begin() + index)' pour supprimer l'élément à l'index trouvé
	// - Utiliser une boucle négative (forr) pour supprimer plusieurs éléments

	// TODO: Supprimer la première valeur 30 du vecteur (for)
	// - Utiliser break pour arrêter après la première suppression
	// - Débuter avec		: 0			(premier élément)
	// - Terminer i à		: size() 	(après premier)
	// - Incrémentation i	: i++
	if (true)
	{
		vector<int> vecteur = { 10, 20, 30, 10, 20, 30, 10, 10, 10, 20, 30, 30, 30, 10, 20, 20, 20, 30, 30, 30 };

		for (int i = 0; i < vecteur.size(); i++)
		{
			if (vecteur[i] == 30)
			{
				vecteur.erase(vecteur.begin() + i);
				break;
			}
		}

		afficherVecteurParReference(vecteur, "vecteur sans premier 30 (for positif)");
	}

	// TODO: Supprimer la dernière valeur 30 du vecteur (forr)
	// - Utiliser break pour arrêter après la première suppression
	// - Débuter avec		: size() - 1	(dernier élément)
	// - Terminer i à		: 0				(premier élément)
	// - Incrémentation i	: i--
	if (true)
	{
		vector<int> vecteur = { 10, 20, 30, 10, 20, 30, 10, 10, 10, 20, 30, 30, 30, 10, 20, 20, 20, 30, 30, 30 };

		for (int i = vecteur.size() - 1; i >= 0; i--)
		{
			if (vecteur[i] == 30)
			{
				vecteur.erase(vecteur.begin() + i);
				break;
			}
		}


		afficherVecteurParReference(vecteur, "Vecteur sans dernier 30 (forr negatif)");
	}

	// TODO: Supprimer toutes les valeurs '30' du vecteur avec une boucle positive (for)
	// - Attention, erreur avec une boucle for positive du a la suppression et au decalage des elements
	// - Ex. erreur de suppression avec 2 valeurs 30 de suite
	//      [10] 20  30  30  40   i = 0
	// 
	//       10 [20] 30  30  40   i = 1
	// 
	//       10  20 [30]<30<<40   i = 2 (30 est supprimé et les valeur 30 et 40 sont décalées vers la gauche)
	//       10  20 [30] 40             (besoin de retraiter l'index i = 2, nouvelle valeur 30)
	// 
	//		 10  20 [30]<40       i = 2 (30 est supprimé et les valeur 30 et 40 sont décalées vers la gauche)
	//       10  20 [40]                (besoin de retraiter l'index i = 2, nouvelle valeur 40)
	// 
	//       10  20 [40]          i = 2
	//
	// Erreur : utiliser vecteur.size(), car la taille peut changer pour éviter les crash
	// - size() initiale = 5
	//		- 10  20  30  30  40 = 5
	//		- 10  20  30  40     = 4 (après suppression d'un 30)
	//		- 10  20  40         = 3 (après suppression d'un autre 30)
	// - size() finale = 3
	//		- [3]/[4] crash car index hors limites [0] ... [2]
	// 
	if (false)
	{
		vector<int> vecteur = { 10, 20, 30, 10, 20, 30, 10, 10, 10, 20, 30, 30, 30, 10, 20, 20, 20, 30, 30, 30 };

		// TODO: Exemple de crash
		// int tailleInitiale = vecteur.size();
		// for (int i = 0; i < tailleInitiale; i++) // Crash (Ex. [19] n'existe plus avec les suppressions)

		for (int i = 0; i < vecteur.size(); i++) // [0] ... [19]
		{
			if (vecteur[i] == 30)
			{
				// Erreur !
				// - Supprimer un élément décale les éléments suivant vers la gauche d'un index - 1
				// - Saute par dessus le prochain élément à cause du i++
				vecteur.erase(vecteur.begin() + i);

				// TODO: Fixer le problème
				// - Reculer l'index de 1 pour compenser le décalage vers la gauche des éléments
				// - Forcer de retraiter l'index actuel, car un nouvel élément y est maintenant présent
				i--;
			}
		}

		afficherVecteurParReference(vecteur, "Vecteur sans 30 (for positif)");
	}

	// TODO: Supprimer toutes les valeurs 30 du vecteur avec une boucle négative (forr)
	// - Rien à corriger, les éléments qui sont décalés ont déjà été traités
	// - Ex. fonctionnement correct peu importe le nombre de valeurs 30 de suite
	//		 10   20   30  30 [10]  i = 4 
	// 
	//		 10   20   30 [30]<10   i = 3 (supprimer 30, 10 décalé vers la gauche)
	//       10   20   30 [10]            (pas besoin de retraiter 10, passer à i = 2)
	// 
	//       10   20  [30]<10       i = 2 (supprimer 30, 10 décalé vers la gauche)
	//       10   20  [10]                (pas besoin de retraiter 10, passer à i = 1)
	// 
	//       10  [20]  10			i = 1
	// 
	//      [10]  20   10			i = 0
	if (false)
	{
		vector<int> vecteur = { 10, 20, 30, 10, 20, 30, 10, 10, 10, 20, 30, 30, 30, 10, 20, 20, 20, 30, 30, 30 };

		for (int i = vecteur.size() - 1; i >= 0; i--)
		{
			if (vecteur[i] == 30)
			{
				vecteur.erase(vecteur.begin() + i);
			}
		}

		afficherVecteurParReference(vecteur, "Vecteur sans 30 (forr negatif)");
	}

	// *** Fonctions avec des vecteurs ***
	// - Passer un vecteur en paramètre
	//		- Crée une copie du vecteur et une copie du tableau en mémoire
	//		- Modifications dans la fonction n'affectent pas le vecteur original
	//		- void fonction(vector<int> vecteur) { ... }
	// - Passer un vecteur par référence (&)
	//		- Évite la copie du vecteur et du tableau en mémoire
	//		- Modifications dans la fonction affectent le vecteur original
	//		- void fonction(vector<int>& vecteur) { ... }
	// - Préférer utiliser le mot clé 'const' lorsqu'un vecteur n'a pas besoin d'être modifié dans la fonction
	//		- Évite les erreurs du à des modifications accidentelles
	//		- void fonction(const vector<int>& vecteur) { ... }
	if (true)
	{
		// Initialiser un vecteur original avec des valeurs dans main()
		vector<int> vecteur;
		vecteur.reserve(100);

		vecteur.push_back(10);
		vecteur.push_back(20);
		vecteur.push_back(30);
		vecteur.push_back(40);
		vecteur.push_back(50);

		// Afficher les informations du vecteur original
		cout << "--- Vecteur original (main()) ----\n";
		cout << format("Adresse du vecteur : {:#x}\n", (unsigned long long) & vecteur);
		cout << format("Capacity           : {}\n", vecteur.capacity());
		cout << format("Size               : {}\n", vecteur.size());
		cout << format("Adresse du tableau : {:#x}\n", (unsigned long long) & vecteur[0]);
		cout << format("Index [0] - [{}]  : ", vecteur.size() - 1);

		for (int i = 0; i < vecteur.size(); i++)
		{
			cout << format("{} ", vecteur[i]);
		}

		cout << "\n\n";

		// Tester un affichage par copie et par référence
		afficherVecteurParCopie(vecteur, "Vecteur par copie");
		afficherVecteurParReference(vecteur, "Vecteur par reference (&)");

		// Tester une modification par copie et par référence
		modifierValeurParCopie(vecteur, 555);
		afficherVecteurParReference(vecteur, "Vecteur original apres modification par copie");

		modifierValeurParReference(vecteur, 999);
		afficherVecteurParReference(vecteur, "Vecteur original apres modification par reference (&)");

		// Tester le retour d'un nouveau vecteur depuis une fonction
		vector<int> nouveauVecteur = retournerNouveauVecteur();
		afficherVecteurParReference(nouveauVecteur, "Nouveau vecteur apres retour par fonction");
	}

	return 0;
}

void testerRedimensionnementVecteur(int tailleReservationVecteur, int nombreAjouts)
{
	// Déclaration d'un vecteur vide sans tableau alloué en mémoire
	vector<int> vecteur;

	// Créer un tableau en mémoire pour les éléments afin d'éviter les redimensionnements
	vecteur.reserve(tailleReservationVecteur);

	// Ajouter des valeurs dans le vecteur (ex. 100 valeurs => 10, 20, 30 ... 1000) 
	int compteurRedimensionnement = 0;
	int ancienneCapacity = vecteur.capacity();

	for (int i = 0; i < nombreAjouts; i++)
	{
		int valeur = (i + 1) * 10; // 10, 20, 30, ... 1000
		vecteur.push_back(valeur);

		// Afficher la nouvelle capacité lors le vecteur change de tableau en mémoire en mémoire
		if (vecteur.capacity() != ancienneCapacity)
		{
			ancienneCapacity = vecteur.capacity();
			++compteurRedimensionnement;

			string nomVecteur = format("Vecteur (tableau #{})", compteurRedimensionnement + 1);
			afficherVecteurParReference(vecteur, nomVecteur);
		}
	}

	// Afficher le nombre total de redimmensionnements du vecteur afin de faire l'ajout des éléments
	string nomVecteur = format("Vecteur final (tableau #{})", compteurRedimensionnement + 1);
	afficherVecteurParReference(vecteur, nomVecteur);
}

void afficherVecteurParCopie(vector<int> vecteur, string nom)
{
	cout << format("--- {} ---\n", nom);
	cout << format("Adresse du vecteur : {:#x}\n", (unsigned long long) & vecteur);
	cout << format("Capacity           : {}\n", vecteur.capacity());
	cout << format("Size               : {}\n", vecteur.size());

	if (vecteur.size() > 0)
	{
		cout << format("Adresse du tableau : {:#x}\n", (unsigned long long) & vecteur[0]);
		cout << format("Index [0] - [{}]  : ", vecteur.size() - 1);

		for (int i = 0; i < vecteur.size(); i++)
		{
			cout << format("{} ", vecteur[i]);
		}
	}

	cout << "\n\n";
}

void afficherVecteurParReference(vector<int>& vecteur, string nom)
{
	cout << format("--- {} ---\n", nom);
	cout << format("Adresse du vecteur : {:#x}\n", (unsigned long long) & vecteur);
	cout << format("Capacity           : {}\n", vecteur.capacity());
	cout << format("Size               : {}\n", vecteur.size());

	if (vecteur.size() > 0)
	{
		cout << format("Adresse du tableau : {:#x}\n", (unsigned long long) & vecteur[0]);
		cout << format("Tableau [0] - [{}] : ", vecteur.size() - 1);

		for (int i = 0; i < vecteur.size(); i++)
		{
			cout << format("{} ", vecteur[i]);
		}
	}

	cout << "\n\n";
}

void modifierValeurParCopie(vector<int> vecteur, int valeur)
{
	// Bonne pratique de toujours vérifier que l'index existe avant d'y accéder pour éviter les crash
	if (vecteur.size() <= 0)
		return;

	vecteur[0] = valeur;
}

void modifierValeurParReference(vector<int>& vecteur, int valeur)
{
	// Bonne pratique de toujours vérifier que l'index existe avant d'y accéder pour éviter les crash
	if (vecteur.size() <= 0)
		return;

	vecteur[0] = valeur;
}

vector<int> retournerNouveauVecteur()
{
	vector<int> vecteur;

	for (int i = 0; i < 10; i++)
	{
		vecteur.push_back(i);
	}

	afficherVecteurParReference(vecteur, "Vecteur dans fonction");

	return vecteur;
}
