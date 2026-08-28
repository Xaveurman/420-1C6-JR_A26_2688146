// TODO: Avant de créer le Projet, faire un 'git clone' ou un 'git pull' si dossier Git est déjà présent

// TODO: Ajouter un en-tête


// Inclusion des librairies
#include <format>
#include <iostream>
#include <string>

// Utilisation du namespace Standard (std::) pour les librairies
using namespace std;

int main()
{
	// Configuration de la console en Français Unicode pour les accents
	setlocale(LC_ALL, "fr_CA.UTF-8");

	// Affichage de l'en-tête
	cout << "--- Cours 05 - If ---\n";

#pragma region Theorie

#pragma region Booleens
	cout << "\n--- Booléens ---\n";

	// *** Booléens ***
	// - Type de données qui permettent d'enregistrer une valeur logique vrai ou fausse
	// - Dans la plupart des langages de programmation
	//		- valeur 0 vaut faux (false)
	//		- reste des valeurs (1, -1, 1234566) valent vrai (true)

	// bool : type de données 8 bits (1 octet)
	bool conditionFausse = false;
	bool conditionVraie = true;

	// Avertissement) 'initialisation': troncation de 'int' à 'bool'
	// - Éviter les valeurs entières, par convention toujours utiliser true ou false
	bool conditionAussiVraie = -1;

	cout << format("Valeurs des booléens : {}, {}, {}\n", conditionFausse, conditionVraie, conditionAussiVraie);

	// *** Nomenclature des variables booléenes ***
	// Utiliser un préfixe afin de distinguer des variables contenant des valeurs (int, double, char, string)
	// - "est..." ("is..." en anglais)
	// - "peut.." ("can..." en anglais)
	bool estNombreVirgule = false;
	bool nombreVirgule = false; // Éviter

	bool peutQuitter = true;
	bool quitter = false;       // Éviter

	// Inscrire des noms sans double négations
	bool estErreur = false;
	bool estPasErreur = true;   // Éviter

	bool estValide = true;
	bool estPasValide = false;  // Éviter

#pragma endregion

#pragma region OperateursComparaison
	cout << "\n--- Opérateurs comparaison ---\n";

	// *** Opérateurs de comparaison ***
	// Expression qui retourne une valeur booléene (true/false)
	// >  : Plus grand
	// <  : Plus petit
	// >= : Plus grand ou égal
	// ­<= : Plus petit ou égal
	// == : Égal (Ne pas confondre avec opérateur d'affectation =)
	// != : N'égale pas, différent de
	int entier = 15;
	bool estPlusGrand10 = entier > 10;
	bool estPlusGrandOuEgal15 = entier >= 15;
	bool estPlusPetit0 = entier < 0;
	bool estPlusPetitOuEgal15 = entier <= 15;
	bool estEgal10 = entier == 10;
	bool estEgal15 = entier == 15;
	bool estDifferent10 = entier != 10;
	bool estDifferent15 = entier != 15;

	cout << format("{} est plus grand que (>) 10          : {}\n", entier, estPlusGrand10);
	cout << format("{} est plus grand ou égal à (>=) 15   : {}\n", entier, estPlusGrandOuEgal15);
	cout << format("{} est plus petit que (<) 0           : {}\n", entier, estPlusPetit0);
	cout << format("{} est plus petit que (<=) 15         : {}\n", entier, estPlusPetitOuEgal15);
	cout << format("{} est égal à (==) 10                 : {}\n", entier, estEgal10);
	cout << format("{} est égal à (==) 15                 : {}\n", entier, estEgal15);
	cout << format("{} n'égale pas / différent de (!=) 10 : {}\n", entier, estDifferent10);
	cout << format("{} n'égale pas / différent de (!=) 15 : {}\n", entier, estDifferent15);

	// Opérateur d'affectation (=) au lieu de l'opérateur d'égalité (==)
	// - Avertissement) Assignation '=' utilisée alors que l'égalité ' == ' est probablement souhaitée.
	// - Écrase la valeur en mémoire de la variable au lieu de comparer les valeurs

	// entier = 0
	//	- Retour toujours faux (false) peu importe la valeur de la variable 'entier'
	//  - Valeur de la variable 'entier' est perdue et assignée à 0
	//  - 0 en booléen vaut faux (false)
	bool estErreurMauvaisOperateurEgal1 = entier = 0;
	cout << format("\n{} est égal à mauvais opérateur (=) 0 : {}\n", entier, estErreurMauvaisOperateurEgal1);
	cout << format("Erreur : variable 'entier' a maintenant la valeur {}\n", entier);

	// entier = 15
	//  - Retour toujours vrai (true) peu importe la valeur de la variable 'entier'
	//  - Valeur de la variable 'entier' est perdue et assignée à 15
	//  - 15 en booléen vaut vrai (true)
	bool estErreurMauvaisOperateurEgal2 = entier = 15;
	cout << format("\n{} est égal à mauvais opérateur (=) 15 : {}\n", entier, estErreurMauvaisOperateurEgal2);
	cout << format("Erreur : variable 'entier' a maintenant la valeur {}\n", entier);

	// 10 = 15
	//  - Erreur, impossible changer de la constante 10 pour qu'elle valle 15
	//bool erreurMauvaisOperateurEgal3 = 10 = 15;

	// TODO: Exemples variables booléenes avec opérateurs de comparaison (>, >=, <, <=, ==, !=)
	int jour = 20;
	int mois = 8;
	int annee = 2025;
	double montant = 19.99;

	bool estJourPlusPetit10 = jour < 10;
	bool estMontantSupetieur20 = montant > 20;
	bool estMoisJuin = mois == 6;

	char caractere = 'c';
	string nom = "Paul";

	bool estAdministrateur = nom == "Admin";
	bool estUtulisateurNormal = nom != "admin";

	// *** Comparaison de types différents ***
	// - Comparer des types de données différents en mémoire compare des valeur encodées différemment
	// - Entier (32 bits) n'est pas enregistré comme un double (64 bits) ou un char (8 bits)
	// - Conversion implicite d'un type à l'autre afin d'effectuer la comparaison
	cout << "\n--- Comparaison types différents ---\n";

	// (int) == (int)
	// - Même type de données donc même encodage en mémoire
	// - Bits sont identiques et peuvent être comparés directement sans conversion
	cout << format("5 == 5 = {}\n", 5 == 5); // true

	// (int) == (double)
	// - 5 (int) converti en 5.0 (double) 
	// - 5.0 == 5.0
	cout << format("5 == 5.0 = {}\n", 5 == 5.0); // true

	// (int) == (char)
	// - 5 == 53 ('5')
	cout << format("5 == '5' ({}) = {}\n", (int)'5', 5 == '5'); // false

	// (int) == (string)
	// - Erreur 0042) : les types d'opérandes sont incompatibles ("int" et "const char *")
	// - Conversion implicite d'un (int) en (string) non permis en C++
	//cout << format("5 == '5' = {}\n", 5 == "5"); 
	// 
	// - Utiliser la fonction to_string() pour convertir l'entier en chaîne de caractères
	// - to_string(5) converti en "5" ('5' '\0')
	// - "5" ('5' '\0') == "5" ('5' '\0')
	cout << format("to_string(5) == \"5\" = {}\n", to_string(5) == "5"); // true

	// (char) == (string)
	// - Erreur 0042) les types d'opérandes sont incompatibles ("char" et "const char *")
	// - Conversion implicite d'un (char) en (string) non permis en C++
	//cout << format("'5' == \"5\"", '5' == "5");
	//
	// - Utiliser la fonction to_string() pour convertir le caractère en chaîne de caractères
	// - to_string('5') converti en "5" ('5' '\0')
	// - '5' '\0' == '5' '\0'
	cout << format("to_string('5') == \"5\" : {}\n\n", to_string('5') == "5");

	// Chaînes de caractères doivent être exactes afin d'être considérées égales (==)
	// - Vérifie les chaînes à partir de la gauche caractère par caractèrs jusqu'à la fin de la chaîne ('\0')
	// - Dès qu'une différence est trouvée, les chaînes ne sont pas considérées égales (identiques)
	//      - Ex. minuscules, majuscules, espaces, etc.
	string message = "bonjour";

	cout << format("\"{}\" == \"bonjour\"  : {}\n", message, message == "bonjour");  // true
	cout << format("\"{}\" == \"Bonjour\"  : {}\n", message, message == "Bonjour");  // false : majuscule             'b'  == 'B'
	cout << format("\"{}\" == \"bonjouR\"  : {}\n", message, message == "bonjouR");  // false : majuscule             'r'  == 'R'
	cout << format("\"{}\" == \"bonjour \" : {}\n", message, message == "bonjour "); // false : espace après          '\0' == ' '
	cout << format("\"{}\" == \" bonjour\" : {}\n", message, message == " bonjour"); // false : espace avant          'b'  == ' '
	cout << format("\"{}\" == \"bon jour\" : {}\n", message, message == "bon jour"); // false : espace au milieu      'n'  == ' '
	cout << format("\"{}\" == \"bonjou\"   : {}\n", message, message == "bonjou");   // false : caractère manquant    'r' == '\0'
#pragma endregion

#pragma region If
	cout << "\n--- If ---\n";

	// *** If ***
	// Sélectionner un seul travail à faire parmis plusieurs selon des conditions booléenes
	// - Conditions
	//      - Évaluées dans l'ordre à partir du if() et ensuite chaque else if() 
	//      - Première condition vrai (true) sera le travail à effectuer
	//      - Autres conditions ne seront pas vérifiées et les autre Travaux ne seront pas effectués
	// - Programme continue son exécution après le bloc complet if () else if () else
	//
	// if (condition) 
	// {
	//      // Travail 1 à effectuer si la condition est vraie (true)
	// } 
	// else if (condition) // Optionnel
	// {
	//      // Travail 2 à effectuer si la condition est vraie (true)
	// } 
	// else if (condition) // Optionnel
	// {
	//      // Travail 3 à effectuer si la condition est vraie (true)
	// } 
	// ...
	// else // Optionnel, il doit y avoir un seul else, sinon erreur
	// {
	//      // Travail par défaut à effectuer si aucune des conditions est vrai (true)
	// }

	// Lire un nombre au clavier et écrire un message selon le nombre saisi par l'utilisateur
	int nombre = 60;
	cout << "Entrer un nombre à évaluer : ";
	cin >> nombre;

	if (nombre > 100)
	{
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	}
	else if (nombre < 0)
	{
		cout << format("Nombre {} est négatif\n", nombre);
	}
	else if (nombre == 0)
	{
		cout << format("Nombre {} est 0\n", nombre);
	}
	else
	{
		cout << format("Nombre {} ne rempli aucune des conditions\n", nombre);
	}

	// Écriture minimale
	// - Instructions else if() et else sont optionnelles
	if (nombre > 100)
	{
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	}

	// *** Erreurs de compilation ***
	// Erreur 1) Parenthèses manquantes ou supplémentaires
	//if nombre > 100
	//{
	//	cout << format("Parenthèses");
	//}

	//if ((nombre > 100)
	//{
	//	cout << format("Parenthèses");
	//}

	// Erreur 2) Accolades manquantes ou supplémentaires
	//if (nombre > 100)
	//// Erreur
	//	cout << format("Accolades");
	//} 
	//{} // Erreur
	//else
	//{
	//	cout << format("Accolades");
	//} } // Erreur

	// Erreur 3) Points-virgules à la fin des instructions if(), else if(), else
	//if (nombre > 100) ; // Erreur
	//{
	//	cout << format("Point-virgule");
	//}
	//else if (nombre < 0) ; // Erreur
	//{
	//	cout << format("Nombre {} est négatif\n", nombre);
	//}
	//else ; // Erreur
	//{
	//	cout << format("Nombre {} ne rempli aucune des conditions\n", nombre);
	//}

	// *** Erreurs de logique ***
	// Erreur 1) Test sans opérateur de comparaison
	// - Opérateur de comparaison manquant (>, >= , <, <=, ==, !=)
	// - Transforme implicite le nombre entier (int) en booléen (bool)
	// - N'importe quel nombre entre dans la condition (true) sauf nombre 0 (false)

	// TODO: Entrer 10 comme nombre afin de voir un message bizarre

	cout << "\n--- Erreur 1 : Opérateur comparaison ---\n";
	if (nombre) // Erreur
	{
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	}

	// Erreur 3) Plusieurs if() de suite
	// - Plusieurs actions seront effectuée : 1 action par if()
	// - Conditions sont habituellement écrite avec else if() afin de choisir un seul travail effectué

	// TODO: Entrer 101 comme nombre afin de voir 3 message au lieu d'un seul
	cout << "\n--- Erreur 3 : if() multiples ---\n";

	if (nombre > 100)
	{
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	}
	if (nombre > 50) // Erreur
	{
		cout << format("Nombre {} est supérieur à 50\n", nombre);
	}
	if (nombre > 0) // Erreur
	{
		cout << format("Nombre {} est supérieur à 0\n", nombre);
	}

	// Erreur 3) Accolades manquantes {}
	// - Accolade ne sont pas strictement nécessaires dans l'écriture d'une instruction if()
	// - Si les accolades ne sont pas présentes, if() ou else exécute uniquement la prochaine instruction
	// - Fortement recommandées de toujours les écrire pour le cours

	// TODO: Entrer -10 comme nombre afin de voir des messages bizarres du aux accolades manquantes

	// Exemple erreur if() sans accolades {}
	cout << "\n--- Erreur 3 : if() sans accolades {}---\n";
	if (nombre > 100)
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	cout << format("Nombre {} est très grand!\n", nombre); // Erreur, toujours exécuté

	// Équivalent au code précédent
	if (nombre > 100)
	{
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	}

	cout << format("Nombre {} est très grand!\n", nombre); // Erreur, toujours exécuté

	// Exemple erreur else sans accolades {}
	cout << "\n--- Erreur 3 : else sans accolades {} ---\n";
	if (nombre > 100)
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	else
		cout << format("Nombre {} est inférieur à 100\n", nombre);
	cout << format("Nombre {} est très petit!\n", nombre); // Erreur, toujours exécuté

	// Équivalent au code précédent
	if (nombre > 100)
	{
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	}
	else
	{
		cout << format("Nombre {} est inférieur à 100\n", nombre);
	}

	cout << format("Nombre {} est très petit!\n", nombre); // Erreur, Toujours exécuté

	// Erreur 4) Opérateur affectation
	//cout << "\n--- Erreur 4 : Opérateur affectation (=) ---\n";
	//if (nombre = 10)
	//{
	//    cout << format("Nombre {} est supérieur à 100\n", nombre);
	//}

	// Erreur 5) Ordre des conditions
	// - Important car les conditions sont évaluées de haut vers le bas
	// - Seule le code contenu dans la première condition vraie (true) est exécuté

	// TODO: Entrer 101 comme nombre afin de voir un mauvais message

	// 1) Mauvais ordre des conditions
	// - Condition #1 du if() empêche toujours d'arriver à la la Condition #2 du else if()
	// - Nombre plus grand que 100 est forcément plus grand que 0
	// - Entre toujours dans le bloc du if(), impossible de rentrer dans le bloc du else if()

	cout << "\n--- Erreur 5 : Mauvais ordre des conditions ---\n";

	if (nombre > 0) // nombre 101 > 0 = true
	{
		cout << format("Nombre {} est supérieur à 0\n", nombre);
	}
	else if (nombre > 100) // nombre 101 : impossible d'arriver ici
	{
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	}
	else
	{
		cout << format("Nombre {} est négatif\n", nombre);
	}

	// 2) Bon ordre des conditions
	// - Condition #1 est un sous-ensemble plus spécifique de la Condition #2
	// - Nombre peut être plus spécifiquement plus grand que 100
	cout << "\n--- Erreur 5 : Bon ordre des conditions ---\n";

	if (nombre > 100) // nombre 101 > 100
	{
		cout << format("Nombre {} est supérieur à 100\n", nombre);
	}
	else if (nombre > 0)
	{
		cout << format("Nombre {} est supérieur à 0\n", nombre);
	}
	else
	{
		cout << format("Nombre {} est négatif\n", nombre);
	}

	// TODO : Exemple avec notes étudiant
	// - Lire une note au clavier [0 - 100]
	// - 90% et plus : "A"
	// - 75% et plus : "B"
	// - 60% et plus : "C"
	// - 59%         : "D"
	// - Moins que 59% : "Échec"

	cout << "\n--- Notes ---\n";

	cout << "Entrer la note ( 0 - 100) :";
	int notePourcentage;
	cin >> notePourcentage;

	if (notePourcentage >= 90)
	{
		cout << "A\n";
	}
	else if (notePourcentage >= 75)
	{
		cout << "B\n";
	}
	else if (notePourcentage >= 60)
	{
		cout << "C\n";
	}
	else if (notePourcentage == 59)
	{
		cout << "D\n";
	}
	else
	{
		cout << "echec\n";
	}

	// *** Imbrication de conditions ***
	// - Peut imbriquer un conditions if dans une autre condition if
	// - Faire un travail uniquement si certaines conditions supplémentaires sont respectées
	double resultat = 0;

	if (nombre > 0)
	{
		resultat = 10 * nombre;

		if (nombre == 1000)
		{
			resultat *= 777;
		}
		else if (nombre <= 10000)
		{
			resultat += 10;
			resultat /= 8;
		}
		else
		{
			resultat += 12345;
			resultat *= nombre;
		}
	}
	else
	{
		resultat = -nombre;

		if (nombre < -5000)
		{
			resultat /= 555;
		}
	}

	cout << "\n--- Conditions imbriqueés ---\n";
	cout << format("Résultat du nombre {} est : {:.2f}\n", nombre, resultat);

#pragma endregion

#pragma endregion
}

// TODO: Faire le Devoir dans un nouveau Projet et remettre avant la date de remise sur Léa
