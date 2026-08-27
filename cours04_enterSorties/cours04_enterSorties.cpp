// TODO: Avant de créer le Projet, faire un 'git clone' ou un 'git pull' si dossier Git est déjà présent


// TODO: Ajouter un en-tête

/*
	Auteur : Xavier Blanchete
	Date : 2026-08-24
	Description : Entrée et Sorties
*/

// TODO: Sauvegarder le code sur le Git local et envoyer sur GitHub

// *** Librairie <iostream> ***
// Inclure les éléments de lecture et d'écriture à la Console
// - std::cout << ... ;	(Console Output)
// - std::cin >> ... ;	(Console Input)
#include <iostream>

// *** Librairie <string> ***
// - Permet d'utiliser le type de données std::string pour les chaînes de caractères
#include <string>

// *** Librairie <format> ***
// - Permet d'utiliser la fonction format() pour mettre en forme des valeurs dans une chaîne de caractères
// - Fonctionne uniquement sous la version C++20 et plus récente
// - Explorateur de Solution > Clic droit sur le Projet > Propriétés ­> Norme du langage C++ > Norme ISO C++20 (/std:c++20)
#include <format>

// *** Namespace ***
// - Essaie de trouver les éléments des librairies dans le namespace Standard (std::) par défaut
//		- Écrire cout		=> Par défaut utiliser std::cout
//		- Écrire cin		=> Par défaut utiliser std::cin
//		- Écrire format		=> Par défaut utiliser std::format
//		- Écrire string		=> Par défaut utiliser std::string
// - Bonne pratique uniquement pour apprendre le langage 
//		- Pas une bonne pratique dans du code commercial C++
//		- Par exemple
//			- Si on programme une librairie avec un objet qui s'appelle 'cout'
//			- Visual Studio utilisera 'std::cout' au lieu de notre 'cout' pour l'ensemble du projet
using namespace std;

// Alternative pour ne pas avoir à spécifier
// - Spécifier les éléments d'utiliser certains éléments seulement
// - Ne cause pas de problèmes inconnus avec nos librairies personnalisées
// - Pour le cours, utiliser simplement 'using namespace std;'
//using std::cin;
//using std::cout;
//using std::format;
//using std::string;

int main()
{
	// TODO: Rajouter la configuration de la locale ici pour fixer les caractère du titre


	cout << "--- Cours 04 - Entrées et sorties ---\n";

#pragma region Theorie

#pragma region Locales
	// *** Locales ***
	// Configurer la table de caractères à utiliser pour la Console
	// - Toujours configurer au début du projet pour les prochaines lignes à la Console
	// 
	// - ASCII
	//		- Utilisée par défaut si rien n'est configué
	//		- N'affiche pas très bien les caractères accentués
	// 
	// - Unicode Transformation Format 8-bits (UTF-8)
	//		- Tables configurées par langages pour bien afficher les accents

	cout << "\n--- Locales ---\n";

	string accents = "à, é, è, ç, ...";
	cout << "Par défaut du système d'exploitation (ASCII) : " << accents << "\n";

	// Forcer la locale à celle configurée par défaut dans le système d'exploitation
	setlocale(LC_ALL, "");
	cout << "Unicode selon système d'exploitation : " << accents << "\n";

	// Forcer la locale à la table UTF-8 Anglais (US) avec accents
	setlocale(LC_ALL, "en_US.UTF-8");
	cout << "Anglais US Unicode (en_US.UTF-8) : " << accents << "\n";

	// Forcer la locale à la table UTF-8 Français (Canada) avec accents
	// - Préférable, le programme uniforme peut importe le locale de Windows configurée (ex. Anglais, Espagnol, etc.)
	setlocale(LC_ALL, "fr_CA.UTF-8");
	cout << "Français Canada Unicode (fr_CA.UTF-16) : " << accents << "\n";
#pragma endregion

#pragma region String
	// *** Chaînes de caractères ***
	// - Ensembles successifs de caractères (char)
	//	 https://search.brave.com/images?q=happy%20birthday%20banner&spellcheck=0
	// - En mémoire
	//		- Se terminent automatiquement par un caractère spécial de fin de chaîne '\0' (valeur 0)
	//		- Symbole indique d'arrêter la lecture, car la suite en mémoire contient d'autres données

	cout << "\n--- String ---\n";

	// "Bonjour" = 'B'   'o'   'n'   'j'   'o'   'u'   'r'   '\0'
	string message = "Bonjour";

	// "1 2 3..." = '1'   ' '   '2'   ' '   '3'   '.'   '.'   '.'   '\0'
	string nombres = "1 2 3...";

	// "" = '\0'
	string chaineVide = "";

	int entier = 10;
	double nombreReel = 1.23456;
	char caractere = 'a';

	// Contenu en mémoire des 6 variables précédentes
	// ... 'B' 'o' 'n' 'j' 'o' 'u' 'r' '\0' '1' ' ' '2' ' ' '3' '.' '.' '.' '\0' '\0' 10 1.23456 'a' ...

	// tilisation d'une chaîne de caractères la lecture s'arrête la fin de chaîne (\0) est atteint
	// Lecture effectuée en mémoire : 'B' 'o' 'n' 'j' 'o' 'u' 'r' '\0'
	cout << "Message est : " << message << "\n";

	// Lecture effectuée en mémoire: '1' ' ' '2' ' ' '3' '.' '.' '.' '\0'
	cout << "Nombres sont : " << nombres << "\n";

	// Lecture effectuée : '\0'
	cout << "Chaine vide : " << chaineVide << "\n";

	// TODO: Forcer la lecture à s'arrêter avant la fin de la chaîne avec un caractère de fin de chaîne (\0)
	cout << "Arrêt d'une chaine de caractères avec un caractère de fin de chaine\n";

	// *** Caractères réservés ***
	// \0 : Fin de chaîne
	// \n : Nouvelle ligne (new line)
	//		Aussi équivalent à std::cout << endl;
	// \r : Retour de ligne Windows (carriage return)
	// \t : Tabulation

	// *** Échappement de caractères ***
	// Pour ajouter des caractères réservés, précéder d'un caractère d'échappement (\)
	// "	: Caractère d'ouverture ou fermeture de chaîne (string)
	// \"	: Caractère texte de guillemet '"' (valeur 34)
	// 
	// \	: Caractère d'échappement
	// \\	: Caractère texte backslash '\' (valeur 92)
	// 
	// \0	: Caractère de fin de chaîne (string) (valeur 0)
	// \\0	: '\'0 => '\' '0'
	//		  Caractère texte de backslash '\' (valeur 92)
	//        Caractère texte '0' (valeur 48)
	// 
	// \u   : Caractère Unicode 8-bit
	//        \u0041 = 'A' (65)
	//		  \u03A9 = 'Ω (non supporté à la Console)
	// 
	//cout << "Message avec erreurs : \0 "Allo" \Bonjour\  \u0041 \u0042 \u0043 \u03A9 \n";
	cout << "Message avec échappements : \\0 \"Allo\" \\Bonjour\\ \u0041 \u0042 \u0043 \u0010 \u03A9 \n";

	// *** Erreurs ***
	// Erreur 1) E0020: indicateur "string" non défini
	// - Inclure la librairie <string>
	// - Écrire std::string ou utiliser using namespace std;
	//string stringErreur1 = "Allo";

	// Erreur 2) E0415: il n'existe aucun constructeur approprié pour la conversion de "int" en "std::basic_string..."
	// Attention à bien utiliser les guillemets doubles "" pour les chaînes de caractères et non les simples ''
	//string stringErreur2 = 'Allo';

	// Erreur 3) E0020: indicateur ... non défini
	// Attention à bien utiliser les guillemets doubles "" pour les chaînes de caractère et ne pas les oublier
	//string stringErreur3 = Allo;
#pragma endregion

#pragma region Format
	cout << "\n--- Formats ---\n";

	// *** Formattage ***
	// Affichage de chaînes de caractères contenant plusieurs types de données (int, double, string)

	// Méthode 1
	// - Imprimer les éléments un à un avec cout avec des éléments séparés
	// - Possible, mais très spécifique à C++, formats sont plus difficiles à faire par élément
	cout << "Format 1 avec cout : " << message << "\n";
	cout << "Format 2 avec cout : " << message << " " << entier << " " << nombreReel << " " << caractere << "\n";

	// Méthode 2
	// - Utiliser la fonction de formattage printf()
	// - Plus vieux, similaire au code C
	// - Attention d'utiliser c_str() pour les chaînes de caractères avec printf()
	printf("Format 1 avec printf() : %s \n", message.c_str());
	printf("Format 2 avec printf() : %s %d %f %.0f %.1f %.2f %.3f\n",
		message.c_str(), entier, nombreReel, nombreReel, nombreReel, nombreReel, nombreReel);

	// Méthode 3 (Suggérée)
	// - Utiliser la fonction de formattage format()
	// - Plus récent, le nouveau standard en C++, ressemble plus aux autres langages modernes
	// - Requiert de configurer le Projet Visual Studio en C++ 20 et inclure la librairie <format>
	cout << format("Format 1 avec format() : {}\n", message);
	cout << format("Format 2 avec format() : {} {} {} {:.0f} {:.1f} {:.2f} {:.3f}\n",
		message, entier, nombreReel, nombreReel, nombreReel, nombreReel, nombreReel);

	// *** Erreurs ***
	// Erreurs de syntaxe avec format() sont très dures à déboguer à cause des messages d'erreurs
	// 
	// - Ne pas oublier les virgules
	// cout << format("Erreur de virgules {}" message);
	// 
	// - Ne pas oublier le même nombre d'élément à formatter {} que de variables
	// cout << format("Erreur nombre de variables", message);
	// 
	// - Respecter la syntaxe du format de snombres à virgules {:.#f}
	// cout << format("Erreur de format {.2:}", message);
	// 
	// - Ne pas formatter les virgules d'un nombre sans partie décimale (int, string, char)
	// cout << format("Erreur de format {:.2f}", entier);
	// cout << format("Erreur de format {:.2f}", message);	
	// cout << format("Erreur de format {:.2f}", caractere);

	// TODO: Afficher le message sous le format suivant avec format()
	double note1 = 15.005;
	double note2 = 12.345;
	double note3 = 18.789;
	double moyenneNotes = (note1 + note2 + note3) / 3;
	double maximumNotes = 20.0;
	double pourcentageNotes = (moyenneNotes / maximumNotes) * 100;

	// Notes: 15.01, 12.35, 18.79
	// Moyenne: 15 / 20
	// Pourcentage: 76.9 %
	cout << format("Note :{:.2f}, {:.2f}, {:.2f}\n ", note1 , note2 , note3);
	cout << format("moyenne :{:.0f} / {:.0f}\n ", moyenneNotes, maximumNotes);
	cout << format("Pourcentage :{:.1f} %\n ", pourcentageNotes);


	// Méthode 3 conserver le format() dans une variable avant l'affichage
	// - Utile pour accumuler du texte et afficher une seule fois plus tard dans le programme
	// - Découpler la détection des erreurs et l'affichage des erreurs
	//		- Ex. trouvers toutes les erreurs et les afficher en un seul message à la fin
	cout << "\n *** Message initial avec format ***\n";

	string messageFormatModifie = format("Format dans une variable avec format() : {} {} {} {:.0f} {:.1f} {:.2f} {:.3f}\n",
		message, entier, nombreReel, nombreReel, nombreReel, nombreReel, nombreReel);

	cout << messageFormatModifie;

	// *** Opérateurs string ***
	// Possible d'ajouter des chaînes supplémentaires au début et à la fin
	cout << "\n *** Message modifié avec les opérateurs + et += ***\n";

	// TODO: Ajouter du texte au début du message (texte = "ajout" + texte)
	messageFormatModifie = "DEBUT" + messageFormatModifie;

	// TODO: Ajout du texte à la fin (texte += "ajout")
	messageFormatModifie += "FIN";

	// TODO: Ajouter 3 lignes vides à la fin
	messageFormatModifie += "\n";
	messageFormatModifie += "\n";
	messageFormatModifie += "\n";

	cout << messageFormatModifie;

#pragma endregion

#pragma region EntreesConsole
	// *** Entrées au clavier à la Console ***
	// - Attendre que l'utilisateur saisisse la valeur au clavier avant de continuer le programme
	// - Programme bloque à l'instruction 'cin >> ...' jusqu'à ce que l'utilisateur appuie sur Entrée
	cout << "\n--- Entrées au clavier à la Console ---\n";

	// Saisie d'un nom à la Console
	// - Afficher un texte à l'utilisateur pour qu'il comprennen qu'il doit faire une saisie
	// - Déclarer une variable pour entreposer la valeur lue
	//		- Variable est non initialisée
	//		- Valeur aléatoire sera écrasée par la saisie au clavier de l'utilisateur
	//		- Possible aussi d'initialiser avec une valeur par défaut
	// - Ne jamais utiliser la variable non initialisée avant la lecture au clavier
	// - Attention, pas de validation au niveau des lecture effectuées par cin
	// - Valeur par défaut (0) est attribuées si la lecture échoue (ex. saisir "abc" si on demande un entier)
	cout << "Entrer votre nom : ";
	string nom; // Variable non initialisée
	cin >> nom; // Initialise la variable avec la valeur saisie par l'utilisateur

	// TODO: Ajouter une saisie pour l'age à la Console
	cout << "Entrer votre age : ";
	int age;
	cin >> age;

	// TODO: Ajouter une entrée pour la hauteur à la Console
	cout << "Entrer votre taille : ";
	double hauteur;
	cin >> hauteur;

	// TODO: Afficher un message formatté à l'écran : Bonjour ###, vous avez ### ans et mesurez ###.## mètres !
	cout << format("Bonjour {}, vous avez {} ans et mesurez {:.2f} mètres !", nom, age, hauteur );

	// *** Attendre une touche ***
	// TODO: Attendre que l'utilisateur appuie sur Entrée avant de continuer le programme
	// - Empêche exécutable compilé (.exe) de se fermer automatiquement une fois le programme terminé
	std::cout << "\nAttendre que l'utiliser appuie sur une toucher avec system(\"pause\");\n";
	system("pause");
	// TODO: Ouvrir l'exécutable compilé (.exe) pour vérifier qu'il ne se ferme plus de façon instantanée

	// TODO: Effacer l'écran de la Console (Clear Screen)
	// - Remarquer que le message ne s'affichera plus, car il est rapidement effacé de la Console
	std::cout << "\Effacer l'écran de la Console avec system(\"cls\");\n";
	system("cls");
#pragma endregion

#pragma region TroncationCast
	std::cout << "\n--- Troncation et cast ---\n";

	// *** Troncation ***
	// Sauvegarder en mémoire au moins la partie entière des calcul
	// - Pas de place en mémoire dans l'encodage d'un entier (int) pour enregistrer la partie décimale
	// - Divisions effectuées sur des entiers (int) implique que la partie décimale est perdue

	// Calculs avec entiers seulement
	// (int) / (int) = (int)
	int resultatEntiersDansEntier = 10 / 3;    // 3 reste 1, la partie décimale est tronquée
	std::cout << "10 (int) / 3 (int) avec resultat dans un int : " << resultatEntiersDansEntier << "\n";

	double resultatEntiersDansDouble = 10 / 3; // 3 reste 1, la partie décimale est tronquée avant l'enregistrement dans le double
	std::cout << "10 (int) / 3 (int) avec resultat dans un double : " << resultatEntiersDansDouble << "\n\n";

	// Calculs avec nombres à virgule seulement
	// (double) / (double) = (double)
	double resultatDoublesDansDouble = 10.0 / 3.0;
	std::cout << "10.0 (double) / 3.0 (double) avec resultat dans un double : " << resultatDoublesDansDouble << "\n\n";

	// Calculs avec au moins un nombres à virgule
	// - Autre entier (int) est converti automatiquement en double afin de faire le calcul
	// - Résultat du calcul est un double
	// 	
	// TODO: (double) / (int) = (double)
	double resultatDoublesDansDouble1 = 0;
	std::cout << "10.0 (double) / 3 (int) avec resultat dans un double : " << resultatDoublesDansDouble1 << "\n";
	// 
	// TODO: (int) / (double) = (double)
	double resultatDoublesDansDouble2 = 0;
	std::cout << "10.0 (double) / 3 (int) avec resultat dans un double : " << resultatDoublesDansDouble2 << "\n\n";

	// *** Cast ***
	// Troncation lorsqu'on utilise 2 variables entières même si le résultat est enregistré dans un double
	// - Calcul est effectué avant l'affectation à la variable double
	// - Résultat du calcul est donc comme précédemment un entier
	int entier1 = 10;
	int entier2 = 3;

	// Ne pas effectuer de cast tronque la partie à virgule
	// (int) / (int) = (int)
	double resultatSansCast = entier1 / entier2;
	cout << format("{} (int) / {} (int) avec résultat dans un double : {}\n", entier1, entier2, resultatSansCast);

	// Caster au moins un des 2 entiers afin d'avoir une réponse à virgule (double)
	// (double) / (int) = (double)
	double resultatCastDouble1 = (double)entier1 / entier2;
	cout << format("{} (double) / {} (int) avec résultat dans un double : {}\n", (double)entier1, entier2, resultatCastDouble1);
	// 
	// (int) / (double) = (double)
	double resultatCastDouble2 = entier1 / (double)entier2;
	cout << format("{} (int) / {} (double) avec résultat dans un double : {}\n", entier1, (double)entier2, resultatCastDouble2);

	// *** Priorité du cast ***
	// - Cast est prioritaire aux opérations normales (+, -, *, /), mais non priotaire aux parenthèses ()
	//		- Priorité des opérations en parant de la gauche (P C MD AS)
	//		- Parenthèse Cast Multiplication/Division Addition/Soustraction
	// 
	// - Cast peut servir pour 'enlever' la partie à virgule d'un nombre
	//		- Englober le calcul complet avec des parenthèses () afin qu'il s'effectue avant le cast
	//		- Caster la réponse en entier avec (int)

	// TODO: Exemple de cast sans parenthèses
	// - Affecte uniquement le nombre qui suit le cast
	// 
	// (int)1.75 * 2 + 5.5
	// 
	// 1) 
	// 2) 
	// 3) 
	std::cout << format("(int)1.75 * 2 + 5.5 = {}\n", (int)1.75 * 2 + 5.5);

	// TODO: Exemple de cast avec parenthèses
	// - Résoud la parenthèse en premier et affecte le résultat complet
	// 
	// (int)(1.75 * 2 + 5.5)
	// 
	// 1) (int)(3.5 + 5.5)
	// 2) (int)(9.0)
	// 3) 9
	std::cout << format("(int)(1.75 * 2 + 5) = {}\n", (int)(1.75 * 2 + 5.5));

#pragma endregion

	// TODO: Faire le Devoir et remettre avant la date de remise sur Léa


} // Fin de la fonction main(), ne pas supprimer
