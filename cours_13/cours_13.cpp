//	Auteur : Xavier Blanchete
//	Date : 2026-09-18
//	Description : cours 13


// Inclusion des librairies
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	// Configuration de la console en Unicode pour les accents
	setlocale(LC_ALL, "fr_CA.UTF - 8");

	// Affichage de l'en-tête
	cout << "--- Cours 13 - While ---\n\n";

	// *** While ***
	// - Instruction de boucle qui permet de faire plusieurs fois un même travail
	// - Permet de 'remonter' dans le code afin de rexécuter une partie de code
	// 
	// while ( condition )
	// {
	//		// Travail à exécuter
	//		// Attention : Travail doit changer la condition du while(), sinon boucle infinie
	// }

	// TODO: Dessin avec if() et while() avec conditions true/false

	// TODO: Programmer une boucle infinie qui affiche Hello world!
	if (false)
	{
		cout << "--- Hello world sans fin ---\n\n";

		// Hello world!
		// Hello world!
		// Hello world!
		// ...

		
		string choixArret = "";
		while (choixArret != "stop")
		{
			cout << "Hello word\n";

			cout << "Entrer stop pour arreter : ";
		
			cin >> choixArret;
		}

		cout << "Fin de la boucle infinie Hello world !\n\n";
	}

	// Boucle pour la lecture au clavier
	// - Déclarer une variable avant la boucle while() afin de pouvoir l'utiliser dans la condition

	// TODO: Programmer une boucle qui arrête lorsque l'utilisateur entre "stop" à la Console
	if (false)
	{
		cout << "--- Hello world avec fin ---\n\n";



		cout << "Fin de la boucle avec fin Hello world !\n\n";
	}

	// *** Scope ***
	// - Scope de la boucle while est détruit à la fin de chaque boucle
	//		- Début du Scope : Espace mémoire est réservé à chaque définition de variable (int, double, etc.)
	//		- Fin du Scope : Variables du Scope while sont détruites en mémoire
	// 
	// - Pour conserver une valeur à travers plusieurs itérations de la boucle while()
	//		- Déclarer la variable à l'extérieur du while() avant le while()
	//		- Ne pas redéfinir de nouvelle valeur avant le while
	if (false)
	{
		cout << "--- Addition ---\n\n";

		double addition = 0;
		cout << format("Valeur addition avant le while() : {}\n\n", addition);

		while (addition < 100)
		{
			cout << format("Valeur addition au debut du while() : {}\n", addition);
			addition += 20;
			cout << format("Valeur addition a la fin du while() : {}\n\n", addition);
		}

		cout << format("Valeur addition apres le while() : {}\n\n", addition);
	}

	// *** Erreur ***
	// - Attention, C++ est un peu traitre, il vous laisse vous tirer dans le pied
	// - Possible de déclarer une variable avec le même nom en C++ qui cache l'autre variable
	if (false)
	{
		cout << "--- Addition avec boucle infinie ---\n\n";

		double addition = 0;
		cout << format("Valeur addition avant le while() : {}\n\n", addition);

		while (addition < 100)
		{
			// Erreur, définition d'une 2ème variable qui est supprimée à la fin de chaque boucle
			double addition = 0;

			cout << format("Valeur addition au debut du while() : {}\n", addition);
			addition += 20;
			cout << format("Valeur addition a la fin du while() : {}\n\n", addition);
		}

		cout << format("Valeur addition apres le while() : {}\n\n", addition);
	}

			// Initialiser les variables afin d'entrer dans la boucle
				int compteurNombresValides = 0;
				int nombre = 0;
	// TODO: Exemple de boucle avec condition complexe sur 2 éléments distinct
	while (compteurNombresValides = 0)
	{
		if (false)
			{
				cout << "--- 10 nombres ---\n";
		
	
		
				// Lire et comptabiliser jusqu'à 10 nombres à la Console tant que l'utilisateur n'entre pas un nombre négatif
		
				// Lire un nombre à la Console
				cout << format("Entrer le nombre {} : ", compteurNombresValides + 1);
				cin >> nombre;
		
				// TODO: Vérifier si le nombre doit être comptabilisé ou écrire une erreur à l'écran
				if (nombre > 1000)
				{
					cout << format("Erreur : Nombre {} est trop grand, maximum 1000.\n", nombre);
		
				}
				else
				{
					compteurNombresValides += 1;
				}
				// TODO: Incrémenter le compte de nombres valides
		
			cout << "Fin du programme qui lit 10 nombres !\n";
			}
		}
		

	// *** do {} while(); ***
	// - Différence entre les 2 types de boucles
	//		- while() {} : exécuté 0 fois ou plus
	//		- do {} while(); : exécuté 1 fois ou plus
	// - while()
	//		- Généralement plus utilisé (disponible dans tous les langages)
	//		- Simplement initialiser la condition afin de rentrer au moins 1 fois dans la boucle
	//
	// do
	// {
	//		// Travail à effectuer au moins une fois
	//		// Attention : Travail doit changer la condition du while(), sinon boucle infinie
	// } while ( condition ) ;

	// *** Erreur ***
	// - Point-virgule manquant à la fin du while(); pour indiquer qu'il n'y aura pas d'accolades {}
	//do
	//{
	//	cout << "Erreur de point-virgule manquant\n";
	//} while (true) // Erreur

	// TODO: Programmer Hello world avec une boucle do ... while
	if (false)
	{
		cout << "--- Hello world au moins une fois ---\n";


	
		cout << "Fin du Hello world au moins une fois !\n";
	}

	// TODO: Ajouter une condition de fin au Hello World lorsque l'utilisateur entre la valeur 10
	if (false)
	{
		cout << "--- Hello world avec do ... while() ---\n";

		do
			{
			cout << "hello\n";
				cout << "Enter 10 pour arreter\n";
				cin >> nombre;
			} while (nombre != 10);

		cout << "Fin du Hello world avec do ... while() !\n";
	}

	// *** Valider les entrées au clavier ***
	// 
	// cin.fail()
	// - Retourne 'true' ou 'false' qui indique si la dernière lecture cin >> ... a échouée ou réussie
	// - Lors de la lecture d'un entier avec cin >> ...
	//		- Utilisateur entre '12345'
	//				- cin.fail() => retourne 'false'
	//		- Utilisateur entre 'abcde' 
	//				- cin.fail() => retourne 'true'
	//				- variable après le cin vaut 0
	// 
	// cin.clear()
	// cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	// - Vider le contenu entier du contenu des lectures de cin (buffer) qui n'a pas encore été utilisé
	// - Lors de la lecture d'un entier avec cin >> ...
	//		- Utilisateur entre 'abc def ghi'
	//		- cin >> ...
	//				- Essaie de transformer la partie jusqu'à l'espace en entier 'abc'
	//				- cin.fail() est 'true' car 'abc' ne peut pas être transformé en entier
	//				- Reste 'def ghi' à traiter dans le prochain cin >> ... sans que l'utilisateur appuie sur une touche
	//		- cin.clear() et cin.ignore()
	//				- Suppriment 'def ghi' restant
	//				- Prochain cin >> ... attend que l'utilisateur entre des nouveaux caractère

	// TODO: Lire un nombre entier et arrêter lorsque le nombre entré est un entier valide
	if (false)
	{
		cout << "--- Lire un nombre ---\n\n";

		cout << "Entter un nombre :";
		int nombre;
		cin >> nombre;
		while (cin.fail()) //true => erreur de lecture
		{
			cout << "Entrer un nombre :";
			cin >> nombre;


			if (cin.fail())
			{


				cin.clear(); // cin.fail() = false
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				cout << "Erreur : entrer un nombre entier.\n";
			}

		}

		cout << "Fin de lecture du nombre !\n";
	}

	if (true)
	{
		int nombre = 0;
		bool estNombreErreur = true;

		while (estNombreErreur) //true => erreur de lecture
		{
			cout << "Entrer un nombre :";
			cin >> nombre;
			
			estNombreErreur = cin.fail(); 

			if (estNombreErreur)
			{
			cin.clear(); // cin.fail() = false
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Erreur : entrer un nombre entier.\n";
			}
			
		}

		cout << "Fin de lecture du nombre !\n";
	}
}
