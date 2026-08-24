// TODO: Avant de créer le Projet, faire un 'git pull' si dossier Git est déjà présent

// TODO: Ajouter un en-tête
/*
	Auteur : Xavier Blanchete
	Date : 2026-08-24
	Description : Variables et nomenclature
*/


// TODO: Sauvegarder le code sur le Git local et envoyer sur GitHub

#include <iostream>

int main()
{
	std::cout << "--- Cours 03 - Variables ---\n";

#pragma region Theorie

#pragma region Litteraux
	// *** Littéraux (Litteral en anglais) ***
	// - Valeurs constantes prédéfinies lors de la compilation du programme
	// - Ne font rien par elles mêmes, doivent être utilisées dans des opérations (+, -, *, /, std::cout, etc.)

	// Entier (int)
	100;
	-100;

	// Nombre à virgule (double)
	1.23456789;
	-1.23456789;
	3.123E20;   // 3.123 x 10^20
	100.0;      // Attention, différent de 100 (entier)

	// Nombre à virgule (float)
	1.23456789f;
	-1.23456789f;
	3.123E20f;  // 3.123 x 10^20
	100.0f;     // Attention, différent de 100 (entier)

	// Attention, ne pas utiliser de virgule (,) toujours le point (.)
	// Défini 2 entiers 1 et 2346789 au lieu du double 1.2345656789
	1, 23456789;

	// Charactère (char)
	'a';
	'b';
	'c';
	'1';
	'2';
	'3';

	// Erreurs) Oublier les 2 guillemets simples (')
	//a;
	//'a;
	//a';

	// Chaîne de caractères (string)
	"abc 1234567890 \n \t \0";

	// Erreur) Ne pas utiliser 2 guillemets doubles anglais : Shift+2 (")
	//abc;
	//"abc;
	//"abc";
	//'abc';

	// Erreur) Ne pas englober l'ensemble de la chaîne de caractères entre guillemets (")
	// - Peut survenir lors de l'édition si le curseur est mal positionné lors de l'écriture
	//"abc"def;
	//abc"def";
	//"abc"def";
#pragma endregion

#pragma region TypesVariables
	// *** Variables ***
	// - Définit un espace en mémoire pour enregistrer des données d'une taille en bits prédéfinie 
	//		- 1 octet (1 byte) = 8 bits
	//		- https://learn.microsoft.com/en-us/cpp/cpp/cpp-type-system-modern-cpp?view=msvc-170
	//		- Bits représente des valeurs de façon complètement différentes en mémoire
	// - Pour chaque déclaration de variable
	//		- Boîte est réservée dans la mémoire de l'ordinateur
	//		- Boîtes sont collées les unes avec les autres selon l'ordre de définition des variables

	// *** Entiers ***
	// int : entier signé 32 bits (4 octets)
	// 0 0000000 00000000 00000000 000000001 = 1
	// 0 0000000 00000000 00000000 000000010 = 2
	// 0 0000000 00000000 00000000 000000011 = 3
	// 0 0000000 00000000 00000000 000000100 = 4
	// 0 1111111 11111111 11111111 111111111 = 2147483647 (INT_MAX)
	// 
	// Nombres négatifs sont encodés à l'envers
	// 1 1111111 11111111 11111111 111111111 = -1
	// 1 0000000 00000000 00000000 000000000 = -2147483648 (INT_MIN)

	// Encodage à l'envers permet au processeur de faire rapidement des calculs
	//       1 1111111 11111111 11111111 111111111 (-1)
	// +     0 0000000 00000000 00000000 000000001 (1)
	// -------------------------------------------
	//   (1) 0 0000000 00000000 00000000 000000000 (0)

	int monEntierPositif = 100;
	int monEntierNegatif = -100;

	// *** Limites en mémoire ***
	// - Raccourcis sont programmés pour identifier les valeur minimale et maximales
	// - https://learn.microsoft.com/fr-ca/cpp/cpp/integer-limits?view=msvc-170
	int monEntierMin = INT_MIN;
	int monEntierMax = INT_MAX;

	// Attention, de ne pas dépasser les limites, sinon les réponses deviennent éronnées !
	// Il existe plein de bogues connus à cause de cette erreur classique de dépassement (integer overflow)
	//   0 1111111 11111111 11111111 111111111 (INT_MAX)
	// +                                     1
	// ---------------------------------------
	//   1 0000000 00000000 00000000 000000000 (INT_MIN!!!)
	int monEntierDepassementMax1 = INT_MAX + 1;
	int monEntierDepassementMax2 = 2147483647 + 1;

	//   1 0000000 00000000 00000000 000000000 (INT_MIN)
	// -                                     1
	// ---------------------------------------
	//   0 1111111 11111111 11111111 111111111 (INT_MAX!!!)
	int monEntierDepassementMin1 = INT_MIN - 1;
	int monEntierDepassementMin2 = -2147483648 - 1;

	// unsigned int : entier non signé 32 bits (4 octets)
	unsigned int monEntierNonSigne = 100;
	unsigned int monEntierNonSigneNegatif = -1;

	// short : entier non signé 16 bits (2 octets)
	// - Rarement utilisé de nos jours
	short monEntierCourtMax = SHRT_MAX;
	short monEntierCourtMin = SHRT_MIN;

	// long long : Entier non signé 64 bits (8 octets)
	// - Utilisé pour manipuler de plus gros nombres
	long long monEntieLongMax = LLONG_MAX;
	long long monEntieLongMin = LLONG_MIN;

	// *** Nombres à virgule ***
	// double : nombre à virgule 64 bits (8 octets)
	// Signe (1 bit)    Exposant (11 bits)  Mantisse (52 bits)
	// 0                00000000000         00000000000000000000000000000000000000000000000000000
	// Max :  1.7 × 10 ^ 308
	// Min : -1.7 x 10 ^ 308
	double monNombreVirguleDouble1 = 0.123456789;
	double monNombreVirguleDouble2 = 12345.6789;

	double monNombreVirguleDoubleMax = 1.7E308;
	double monNombreVirguleDoubleMin = -1.7E308;

	// float : Nombre à virgule 32 bits (4 octets)
	// Signe (1 bit)    Exposant (8 bits)   Mantisse (23 bits)
	// 0                00000000            00000000000000000000000
	// Max :  3.4 × 10 ^ 38
	// Min : -3.4 x 10 ^ 38
	float monNombreVirguleFlotant1 = 0.123456789f;
	float monNombreVirguleFlotant2 = 12345.6789f;

	float monNombreVirguleFlotantMax = 3.4E38;
	float monNombreVirguleFlotantMin = -3.4E38;

	// *** Perte de précision ***
	// - Mantisses des nombres à virgule sont limités
	//		- Il n'est pas possible d'enregistrer lse nombres suivants complets dans la Mantisse
	//		- float : Perte de précision plus rapide, car la Mantisse est plus petite
	float monNombreVirguleFlotantPertePrecision = 123456789.123456789123456789f;
	double monNombreVirguleDoublePertePrecision = 123456789.123456789123456789;

	// char : Caractère ASCII 8 bits (1 octet)
	// 00000000 = '\0' (0)
	// 01000001 = 'A'  (64 + 1 = 65)
	// 01100001 = 'a'  (64 + 32 + 1 = 97)
	// 11111111 = 'a'  (255)
	char monCaractereA = 'a'; // 97
	char monCaractereB = 'b'; // 98
	char monCaractereC = 'c'; // 99

	char monCaractereAEntier = 97; // 'a'

	// Attention, ne pas dépasser les valeurs d'un char (8-bits) sinon les valeurs seront tronquées et erronées
	char monCaractereTropGrand1 = 'abc';  // 6382179 => tronqué à 99 'c'
	char monCaractereTropGrand2 = 123456; // 123456 => tronqué à 64 '@'

	// Les caractères majuscules ont des valeurs différentes des minuscules
	char monCaractereAMajuscule = 'A'; // 65
	char monCaractereBMajuscule = 'B'; // 66
	char monCaractereCMajuscule = 'C'; // 67

	// Les caractères spéciaux ont chacun une valeur différente
	char monCaracterePoint = '.';      // 46
	char monCaractereParenthese = '('; // 38

	// Les caractères numériques n'équivalent pas à leur valeur entière !
	char monCaractereChiffre0 = '0'; // 48 et non 0
	char monCaractereChiffre1 = '1'; // 49 et non 1
	char monCaractereChiffre9 = '9'; // 57 et non 9

	// Si on comprend que les caractères sont en fait des nombres entier, on peut faire des maths !
	char monCaractereCalcul1 = 'A' + 25; // 65 + 25 = 90 ('Z')
	char monCaractereCalcul2 = 'a' + 25; // 97 + 25 = 122 ('z')

	// string : Chaîne de caractères
	// Pour entreposer une chaîne de caractères, nous verrons la librairie <string> au prochain cours.
	// std::string maChaineCaracteres = "abc"
#pragma endregion

#pragma region DeclarationVariables
	// *** Déclaration de variables ***
	// Respecter avec les différents éléments avec les espaces
	// type nomVariable = valeurInitiale;

	// TODO: Déclarer une variable de chaque type (100, 5.25, 'Z')
	int entier1 = 100;
	double nombrevirgule1 = 5.25;
	char caracteur = 'Z';

	// Erreur E0020) Espaces manquant entre le type de variable et le nom de variable
	//intmaVariableSansEspace = 10;

	// Erreur E0065) Espaces dans le nom de variable
	//int ma Variable Avec Espaces = 10;

	// Erreur E0084) Utiliser un mot clé du langage comme nom de variable
	// https://learn.microsoft.com/fr-ca/cpp/cpp/keywords-cpp?view=msvc-170
	//int int = 10;
	//double double = 5.123;
	//char char = 'a';

	// Erreur C3872) Utiliser des accents dans les noms de variables
	//int nombreDonnéesCorrigées = 10; // Erreur!
	// Écrire plutôt les noms sans accents avec les caractères : [a-z] [A-Z] [0-9]
	int nombreDonneesCorrigees = 10;

	// Erreur C2374) Définition 2 fois du même nom de variable
	//int maVariableDefiniePlusieursFois = 10;
	//int maVariableDefiniePlusieursFois = 20; // Erreur à la 2ème définition

#pragma endregion

#pragma region NomenclatureVariables
	// *** Nomenclature de variables ***
	// Afin d'avoir du code facilement compréhensible, toujours suivre les règles de nomenclature des variables

	// 1) Utiliser la notation 'camelCase'
	// - 1ère lettre en minuscule
	// - Chaque mot suivant avec 1ère lettre en majuscule
	int monNomVariable = 10;	// camelCase

	// Éviter
	int moNNoMVaRiAble = 10;
	int MonNomVariable = 10;	// PascalCase
	int mon_nom_variable = 10;	// snake_case
	int MON_NOM_VARIABLE = 10;	// UPPER_SNAKE_CASE

	// 2) Utiliser des noms descriptifs
	int exemplairesVendus = 50;
	double prixBillet = 9.99;

	// Éviter
	int x = 10;
	double y = 8.54;
	int valeur = 10;
	int entier = 20;

	// 3) Utiliser des noms sans abbréviations
	int nombreJours = 4;
	int nbJrs = 4; // Éviter

	// 4) Utiliser des noms qui décrivent le plus posisble le contenu de la variable
	int nombre = 1; // Éviter
	int nombreJoursConnexion = 1; // Passable, mais peut porter à confusion
	int nombreJoursDepuisDerniereConnexion = 1; // Excellent

	// 5) Éviter les prépositions
	int lesJours = 4; // Éviter
	int leNombreDeJoursDepuisLaDerniereConnexion = 1; // Éviter

	// TODO: Corriger dans les problèmes suivants les noms de variables afin de respecter la nomenclature

	// TODO: Faire le premier problème ensemble
	//
	// Problème 1 : Achat de billets de cinéma
	// Le prix d’un billet est 12.5 $ et 4 billets ont été vendus au client
	// 
	// double PrixBillet = 12.5;
	double prixCinema = 12.5;

	// int NombreBillet = 4 ;
	int nombreCinema = 4;

	// double LePrixTotalBillet = 50.0;
	double PrixTotalCinema = 50.0;

	// Problème 2 : Moyenne de la température extérieure
	// La température extérieure du matin est 15.2°C, de l'après-midi 23.8°C et du soir 20.5°
	// 
	// double matin = 15.2;
	double teperatureMatin = 15.2;

	// double tempAprem = 23.8;
	double tempatureApresMidi = 23.8;

	// double Temperaturesoir = 20.5;
	double TemperatureSoir = 20.5;

	// double valeurTemperature = 19.8;
	double temperatureMoyenne = 19.8;

	// Problème 2 : Jeu vidéo
	// Un jeu vidéo doit enregistrer les informations du joueur.
	// Le joueur débute avec :
	// - 1000 points avec 3 vies
	// - au niveau 1 sur 10 niveaux
	// - 100 or et 3 potions

	// int Score = 1000;
	int scoreInitial  = 1000;

	// int lesVies = 3;
	int vieJoueur = 3;

	// int NIVEAUACTUEL = 1;
	int niveauActuelJoueur = 1;

	//int lvlMax = 10;
	int niveauMaximumjoueur = 10;

	//int montantDeLor = 100;
	int orJoueur = 100;

	// int p = 3;
	int potionsJoueur = 3;

#pragma endregion

#pragma region Operations
	// *** Opérateurs de base ***
	// +, -, *, / (voir clavier numérique)

	// Afficher un calcul simple avec chaque opérateur avec des entiers
	std::cout << "\nOperateurs de base (+, -, * /)\n";
	std::cout << "5 + 10 = " << 5 + 10 << "\n";
	std::cout << "5 - 10 = " << 5 - 10 << "\n";
	std::cout << "5 * -10 = " << 5 * -10 << "\n";
	std::cout << "5 / 10 = " << 5 / 10 << "\n";

	// Afficher une division entière avec reste 
	// - Ex. 10 divisé par 3 = 3 reste 1
	// - Seule la partie entière (3) est conservée, reste (1) est perdu (voir prochain cours)
	std::cout << "10 / 3 = " << 10 / 3 << "\n";

	// Erreur E3049) Opérateur exposant (^) n'existe pas en C++
	// Symbole utilisé pour une autre opération dans le langage de programmation (XOR binaire)
	//std::cout << 5 ^ 8;

	// Calculer l'exposant à la main pour l'instant (voir boucles plus tard)
	std::cout << "5 ^ 8 = " << 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5 << "\n";

	// *** Ordre des opérations ***
	// Respecte l'ordre normal en mathématique gauche vers la droite (PEMDAS) :
	// 1) Parenthèses
	// 2) Multiplication / Division
	// 3) Addition / Soustraction
	// Il existe aussi des mots clés avec priorité qui sont propres à la programmation (ex. fonctions, cast, etc.)

	// TODO: Exemple de calcul
	// (10 + 2) * (15 + (10 - 20 / 4))
	// 1) 12 * (15 + (10 - 20 / 4))
	// 2) 12 * (15 + (10 - 5))
	// 3) 12 * (15 + 5)
	// 4) 12 * 20
	// 5) 240
	//
	// Afficher la réponse du calcul 1
	std::cout << "Reponse calcul 1 : " << (10 + 2) * (15 + (10 - 20 / 4)) << "\n";

	// TODO: Exercice de calcul
	// (50 - (8 * 5 + 2)) + (9 + 3 * (12 / (14 - 8)))
	// 1) (50 - 40 + 2) + (9 + 3 * (12 / (14 - 8)))
	// 2) (50 - 42) + (9 + 3 * (12 / (14 - 8)))
	// 3) 8 + (9 + 3 * (12 / (14 - 8)))
	// 4) 8 + (9 + 3 * (12 / 6))
	// 5) 8 + (9 + 3 * 2)
	// 6) 8 + (9 + 6)
	// 7) 8 + 15
	// 8) 23

	// TODO: Afficher la réponse du calcul 2
	std::cout << "Reponse calcul 2 : " << (50 - (8 * 5 + 2)) + (9 + 3 * (12 / (14 - 8))) << "\n";

	// *** Utilisation de variables ***
	// - Variable conteient une seule valeur à la fois représenté par l'ensemble des bits
	// - Par défaut, variables ne sont pas initialisées
	//		- Valeur aléatoire selon les bits dans cet espace mémoire la dernière fois qu'il a été utilisé
	//		- Valeur initiale écrase immédiatement la valeur par défaut aléatoire
	// - Affectations
	//		- Chaque autre affectation écrase dans la boîte en mémoire la valeur de la variable
	//      - Ne pas écrire le type lors d'une affectation sinon on définit une nouvelle variable 2 fois (erreur) !

	// TODO: Déclarer une variable sans valeur initiale (valeur aléoire), à éviter le plus possible
	int maVariable1; 
	// TODO: Déclarer une variable avec valeur initiale littérale
	int maVariable2 = 0;
	// TODO: Déclarer une variable qui vaut 10 + (20 * 5) - 5
	// - Calcul complet de la valeur initiale est effectué avant l'affectation de la valeur à la variable
	int maVariable3 = 10 + (20 * 5) - 5;

	// *** Opérations sur les variables ***
	std::cout << "\n--- Opérations sur des variables ---\n";

	int total = 0;          // Variable initialisée à la valeur 0

	// Opération à droite du = (expression) est résolue avant l'affectation de la nouvelle valeur à la variable
	total = total + 2;      // total(0) + 2  => total vaut maintenant 2
	total = total - 1;      // total(2) - 1  => total vaut maintenant 1
	total = total * 10;     // total(1) * 10 => total vaut maintenant 10
	total = total / 2;      // total(10) / 2 => total vaut maintenant 5

	std::cout << "Total en utilisant la variable est : " << total << "\n";

	// TODO: Voir dessin en mémoire des calculs

	// *** Opérateurs d'affectaion combinés (+=, -=, *=, /=) ***
	// - Utiliser afin de ne pas avoir à écrire le nom de la variable à chaque fois
	// - Équivalent du bloc précédent en continuant d'utiliser la même variable

	total = 0;				// Variable réinitialisée à la valeur 0
	//int total = 0;    	// Ne pas écrire int devant total, définit une autre variable avec même nom (erreur!)

	total += 2;             // total(0) + 2  => total vaut maintenant 2
	total -= 1;             // total(2) - 1  => total vaut maintenant 1
	total *= 10;            // total(1) * 10 => total vaut maintenant 10
	total /= 2;             // total(10) / 2 => total vaut maintenant 5

	std::cout << "Total en utilisant les operateurs (+=, -=, *=, /=) : " << total << "\n";

	// Erreur 0029) Ne pas mettre d'espaces entre l'opération (+,-,*,/) et le égal (=)
	//total + = 2;
#pragma endregion

#pragma endregion

	std::cout << "\n--- Exercices ---\n\n";

	// TODO: Faire le premier exercice du Devoir ensemble



	// *** Exercice 01 *** 
	// Moyenne de 3 nombres
	double moyenne3Nombres = (81.42 + -24.2 + 65.142) / 3
		std::cour << "Moyenne des 3 nombres : " << moyenne3Nombres << "\n\n";




	// TODO: Faire le reste du Devoir et remettre avant la date sur Léa








	// Exercice 6 
// Correction d’un programme 

// Calcul du volume du cylindre 
	double r = 5;
	hauteur = 10;
	double vlm_cyl = 3.14159 * r * r * hauteur

		cout << "Le volume du cylindre est : " + vlm_cyl;

	// Calcul du prix total du cylindre par volume 

	double prix = 12, 99;

	total = vlm_cyl * prix;


	std::cout << "Le prix total est : " + total)

	// Conversion de température 
	string farenheit = 75;
	string cel = farenheit - 32) * 5 / 9;

	std::cout << farenheit << ' degrés Fahrenheit équivalent à ' << cel << ' degrés Celsius';

	// Calcul de l'âge en jours 
	int année = 25;
	int MOIS = 3
		jrs = année * 365 + MOIS * 30;

	std::cout << "Age en jours : " jrs;

	// Calcul de l'aire d'un triangle 
	double BaseDuTriangle = 8;
	double HauteurDuTriangle = 6;

	int total = (BaseDuTriangle * HauteurDuTriangle) / 2;

	std::cout << "L'aire du triangle est : " + a)

} // Fin de la fonction main(), attention de ne pas supprimer
