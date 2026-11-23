/*
	Auteur		: Xavier Blanchette
	Date		: 2026-11-23
	Description	: Introduction à la lecture et écriture dans des fichiers textes
*/

#include <ctime>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "etudiant.h"

using namespace std;

// Toujours créer des constantes pour les noms des fichiers
const string FICHIER_ETUDIANTS_LECTURE = "etudiants.csv";
const string FICHIER_ETUDIANTS_VALIDES_ECRITURE = "etudiants_valides.txt";

// TODO: Déplacer vers un fichier "Etudiant.h"


bool tryParseInt(const string& chaine, int& entier);
bool tryParseDouble(const string& chaine, double& nombreVirgule);

vector<string> split(const string& chaine, char delimiteur);

void testerConversionEntier(const string& chaine);
void testerConversionDouble(const string& chaine);

vector<Etudiant> lireFichierEtudiants(const string& nomFichier);
void sauvegarderFichierEtudiantsValides(const string& nomFichier, const vector<Etudiant>& etudiants);

int main(int argc, char* argv[])
{
	std::cout << "--- Cours 37 - Fichiers textes ---\n";

	// *** Lecture des ligne ***
	// - Permet de lire une ligne complète depuis un flux d'entrée (console, fichier, etc.)
	// - Permet de traiter la ligne complète, y compris les espaces
	// - Délimiteur est supprimé de la chaîne de caractères lue (ex. '\n')
	// 
	// getline(stream, variable); // '\n' comme délimiteur par défaut
	// getline(stream, variable, delimiteur);

	if (false)
	{
		string ligneTexte;
		cout << "Entrer une ligne de texte ('\\n' comme delimiteur) : ";
		getline(cin, ligneTexte);
		cout << format("Texte : {}\n", ligneTexte);

		string texteAvantDelimiteur;
		cout << "Entrer une ligne de texte (',' comme delimiteur) : ";
		getline(cin, texteAvantDelimiteur, ',');
		cout << format("Texte jusqu'au delimiteur ',' : {}\n", texteAvantDelimiteur);

		string texteApresDelimiteur;
		getline(cin, texteApresDelimiteur);
		cout << format("Texte apres le delimiteur ',' jusqu'au '\\n' : {}\n", texteApresDelimiteur);
	}

	// *** Fichiers textes ***
	// - Permettent de sauvegarder des données de façon permanente sur le disque dur
	//      - #include <fstream>
	//		- ifstream : input file stream (lecture)
	// 		- ofstream : output file stream (écriture)
	// - Formats textes de base avec des séparateurs simples
	//		- .txt : Fichier texte brut
	//		- .csv : Comma-Separated Values (valeurs séparées par des virgules ',')
	// - Format de fichiers avancés qui demandent des librairies de parsing supplémentaires pour lecture et écriture
	//		- .json : JavaScript Object Notation
	//		- .xml : eXtensible Markup Language
	//		- .yaml : YAML Ain't Markup Language

	// TODO: Tenter d'ouvrir un fichier 'lecture.txt' qui n'existe pas cause une erreur
	// TODO: Créer le fichier 'lecture.txt' avec le contenu et l'ajouter au 'Fichiers de ressources' du projet
	// - Alice Smith,alice.smith@exemple.com,5551234567
	// - Bob Johnson,bob.j@exemple.com,5559876543
	// - Charlie Brown,charlie.b@exemple.com,5555555555
	if (false)
	{
		// Ouvrir le fichier en mode lecture seulement (ifstream, ios::in)
		// - Reserve le fichier au niveau du système d'exploitation pour la lecture seulement
		// - N'empêche pas la lecture par les autres processus
		ifstream fichierEntree;
		fichierEntree.open("lecture.txt", ios::in);

		// Vérifier si l'ouverture du fichier a réussi avant de lire le contenu avec 'is_open()'
		if (!fichierEntree.is_open())
		{
			cout << "Erreur : Impossible d'ouvrir le fichier 'lecture.txt' en lecture.\n";
		}
		else
		{
			cout << "Contenu du fichier 'lecture.txt' :\n";

			// Lire chaque ligne du fichier jusqu'à la fin avec 'getline()' qui retourne 'false' à la fin du fichier au dernier '\n'
			string ligne;
			while (getline(fichierEntree, ligne))
			{
				cout << ligne << "\n";
			}

			// Fermer le fichier après la lecture afin de ne pas bloquer l'accès au fichier par d'autres processus
			fichierEntree.close();
		}
	}

	// *** Modes d'ouverture des fichiers en écriture ***
	// - fichierSortie.open("ecriture.txt", ios::out);
	// 		- Ouvrir le curseur d'écriture 'out' au début du fichier
	// 		- Supprimer le contenu entier du fichier dès l'ouverture
	// - fichierSortie.open("ecriture.txt", ios::app);
	// 		- Ouvrir le curseur d'écriture 'append' à la fin du fichier
	//		- Conserver le contenu existant du fichier

	if (false)
	{
		ofstream fichierSortie;
		fichierSortie.open("ecriture.txt", ios::out); // ios::out ou ios::app

		// TODO: Vérifier que le fichier est ouvert avant d'écrire du contenu

		if (!fichierSortie.is_open())
		{
			cout << "Erreur : Impossible d'ouvrir le fichier 'ecriture.txt' en ecriture.\n";
		}

		else
		{
			cout << "Ecriture dans le fichier 'ecriture.txt'.\n";

			// TODO: Écrire des lignes de texte dans le fichier
			fichierSortie << "Hello word!\n";
			fichierSortie << "yo\n";
			fichierSortie << "Okidoki\n";

			fichierSortie << format("Bonjour utulisateur {} !\n", "xavier");

			// TODO: Fermer le fichier après la lecture afin de ne pas bloquer l'accès au fichier par d'autres processus
			fichierSortie.close();
			// - Important pour les fichiers en écriture qui bloquent l'accès aux autres processus

			// TODO: Comparer les 2 modes 'ios::out' et 'ios::app'
			// - ios::out : Écrase le contenu du fichier au complet
			// - ios::app : Écrit à la fin du fichier
		}



		

		
	}

	// *** Convertir des string ***
	// - C++11 et plus 
	//		- Fonctions sto...() afin de convertir des string en types numériques (int, double, float, long, etc.)
	//			- int stoi(chaine) : string to int
	// 			- double stod(chaine) : string to double
	//			- etc.
	//		- Lance une exception lors de l'échec de conversion (throw) qu'il faut gérer avec un bloc try/catch
	// - C#
	//		- Fonctions TryParse() qui contiennent déjà un try/catch et retournent un bool si la conversion réussit
	//			- bool int.TryParse(chaine, out int entier)
	//			- bool double.TryParse(chaine, out double nombreVirgule)
	//			- etc.
	//		- Fonctions 'tryParseInt' et 'tryParseDouble' fournies effectuent le même travail

	if (false)
	{
		cout << "\n--- Conversion avec stoi() et stod() ---\n\n";

		string chaineEntier = "12345";
		int entier = stoi(chaineEntier);

		string chaineDouble = "3.1416";
		double nombreVirgule = stod(chaineDouble);

		cout << format("Entier converti avec 'stoi()' : {}\n", entier);
		cout << format("Double converti avec 'stod()' : {}\n", nombreVirgule);

		// TODO: Crash lors d'un échec de conversion (ex. convertir "abc" en double)
		//double nombreVirguleErreur = stod("abc");

		// Englober la conversion dans un bloc try/catch pour recevoir l'exception
		//try
		//{
		//	double nombreVirguleErreur = stod("abc");
		//}
		//catch (const exception&) 
		//{
		//    cout << "Erreur : "abc" ne peut etre converti en double";
		//}

		// Utiliser les fonctions 'tryParseInt' et 'tryParseDouble' fournies qui contiennent déjà un try/catch
		// - Même syntaxe et fonctionnement que C# : Int.TryParse() et Double.TryParse()
		cout << "\n--- Fonction fournie tryParseEntier() ---\n\n";

		testerConversionEntier("12345");
		testerConversionEntier("3.1416");
		testerConversionEntier("abc");
		testerConversionEntier("abc12345");
		testerConversionEntier("abc3.1416");
		testerConversionEntier("12345abc");
		testerConversionEntier("3.1416abc");

		cout << "\n--- Fonction fournie tryParseDouble() ---\n\n";

		testerConversionDouble("12345");
		testerConversionDouble("3.1416");
		testerConversionDouble("abc");
		testerConversionDouble("abc12345");
		testerConversionDouble("abc3.1416");
		testerConversionDouble("12345abc");
		testerConversionDouble("3.1416abc");

		// Utiliser 'getline()' au lieu de 'cin <<' afin de convertir la ligne complète en int
		while (true)
		{
			cout << "\nEntrez un entier (q pour quitter) : ";
			string ligne;
			getline(cin, ligne);

			if (ligne == "q" || ligne == "Q") // Utiliser toLower()
				break;

			testerConversionEntier(ligne);
		}

		// Utiliser 'getline()' au lieu de 'cin <<' afin de convertir la ligne complète en double
		while (true)
		{
			cout << "\nEntrez un nombre a virgule (q pour quitter) : ";
			string ligne;
			getline(cin, ligne);

			if (ligne == "q" || ligne == "Q") // Utiliser toLower()
				break;

			testerConversionDouble(ligne);
		}

		// TODO: Déplacer les fonctions "tryParse..." vers une librairie "Chaine.h/Chaine.cpp"
	}

	// *** Lire structures depuis un fichier texte ***
	// - Ajouter un fichier 'etudiants.csv' au 'Fichiers de ressources' du projet avec le contenu suivant :
	//Gabrielle,Tremblay,19,78.50
	//Samuel,Gagnon,18,82.25
	//Emilie,Bouchard,20,91.40
	//Jean-Philippe,Lavoie,22,67.80
	//Melodie,Gauthier,19,74
	//Alexandre,Cote,21,85.10
	//Lea,Pelletier,18,88.75
	//Olivier,Belanger,23,59.90
	//Rosalie,Fortin,19,93.20
	//Maxime,Levesque,20,71.35
	//Frederic,Gagne,25,64.60
	//Oceane,Roy,18,79.95
	//Antoine,Bergeron,21,70.00
	//Eve,Morin,19,86.45
	//Zachary,Ouellet,20,62.30
	//Sarah-Jade,Lapointe,22,90.15
	//Charles-Antoine,L'Heureux,17,76.80
	//# Exemples d'erreurs 
	//
	//Vincent,Lacroix
	//Justine,Caron,19
	//,Berthiaume,21,75.50
	//Karine,,20,81.20
	//Andre,Langlois,,68.90
	//Roxanne,Dube,abc,84.30
	//Louis,Armand,20x,77.40
	//Mathieu,Lavoie,20,abcdef
	//Pauline,Durocher,19,78,50
	//Hugo,Bernier,21,85.50,informations,de,trop
	//Jacques,Lemieux,oops,22,68.50
	//oops,Isabelle,Morin,19,72.30

	if (true)
	{
		cout << "\n--- Lire structures depuis un fichier texte ---\n\n";

		// TODO: Lire le fichier CSV et convertir les lignes en Etudiants "etudiants.csv"
		vector<Etudiant> etudiants = lireFichierEtudiants(FICHIER_ETUDIANTS_LECTURE);

		// Afficher les étudiants valides qui ont pu être lus depuis le fichier
		cout << format("\n{} etudiants valides lus depuis le fichier 'etudiants.csv' :\n", etudiants.size());

		for (size_t i = 0; i < etudiants.size(); i++)
		{
			cout << format("etudiants[{}] - Prenom: {}, Nom: {}, Age: {}, Moyenne: {}\n",
				i,
				etudiants[i].prenom,
				etudiants[i].nom,
				etudiants[i].age,
				etudiants[i].moyenne);
		}

		for (int i = 0; i < etudiants.size(); i++)
		{
			etudiants[i].moyenne += 5;

			if (etudiants[i].moyenne > 100)
				etudiants[i].moyenne = 100;
			
		}

		// TODO: Sauvegarder un nouveau fichier texte qui contient uniquement les étudiants valides "etudiants_valides.txt"
		sauvegarderFichierEtudiantsValides(FICHIER_ETUDIANTS_VALIDES_ECRITURE, etudiants);
	}

	return 0;
}

bool tryParseInt(const string& chaine, int& entier)
{
	try
	{
		if (!chaine.empty())
		{
			size_t indexConversion = 0;
			int entierTemporaire = stoi(chaine, &indexConversion);

			// Vérifier si toute la chaîne a été convertie
			if (indexConversion == chaine.size())
			{
				entier = entierTemporaire;
				return true;
			}
		}
	}
	catch (const exception&) {}

	return false;
}

bool tryParseDouble(const string& chaine, double& nombreVirgule)
{
	try
	{
		if (!chaine.empty())
		{
			size_t indexConversion = 0;
			double nombreVirguleTemporaire = stod(chaine, &indexConversion);

			// Vérifier si toute la chaîne a été convertie
			if (indexConversion == chaine.size())
			{
				nombreVirgule = nombreVirguleTemporaire;
				return true;
			}
		}
	}
	catch (const exception&) {}

	return false;
}

void testerConversionEntier(const string& chaine)
{
	int entier = 0;

	if (tryParseInt(chaine, entier))
	{
		cout << format("Conversion entiere reussie de '{}' : {}\n", chaine, entier);
	}
	else
	{
		cout << format("Erreur : Echec de la conversion entiere de '{}'\n", chaine);
	}
}

void testerConversionDouble(const string& chaine)
{
	double nombreVirgule = 0.0;

	if (tryParseDouble(chaine, nombreVirgule))
	{
		cout << format("Conversion double reussie de '{}' : {}\n", chaine, nombreVirgule);
	}
	else
	{
		cout << format("Erreur : Echec de la conversion double de '{}'\n", chaine);
	}
}

vector<string> split(const string& chaine, char delimiteur)
{
	vector<string> tokens;

	// Retourner un vecteur vide si la chaîne est vide
	if (chaine.empty())
		return tokens;

	// Ajouter les tokens jusqu'au dernier delimiteur
	size_t indexDebut = 0;
	size_t indexDelimiteur = chaine.find(delimiteur);
	while (indexDelimiteur != string::npos)
	{
		string token = chaine.substr(indexDebut, indexDelimiteur - indexDebut);
		tokens.push_back(token);

		indexDebut = indexDelimiteur + 1;
		indexDelimiteur = chaine.find(delimiteur, indexDebut);
	}

	// Ajouter le reste de la chaine apres le dernier delimiteur jusqu'à la fin
	string token = chaine.substr(indexDebut);
	tokens.push_back(token);

	return tokens;
}

vector<Etudiant> lireFichierEtudiants(const string& nomFichier)
{
	// Créer un vecteur vide afin d'ajouter chaque ligne de données
	vector<Etudiant> etudiants;

	// TODO: Ouvrir le fichier en lecture 
	ifstream fichierEtudiants;
	fichierEtudiants.open(nomFichier, ios::in);


	// TODO: Vérifier que le fichier existe et est bien ouvert, sinon retourner un vecteur vide
	if (!fichierEtudiants.is_open()) {
		cout << format("Erreur : impossible d'ouvrir le fichier {} en lecture.\n", nomFichier);
		return etudiants;
	}

	//cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en lecture.\n", nomFichier);

	// Lire chaque ligne du fichier et tenter de convertir le texte en une instance de la struct 'Etudiant'
	int compteurLigne = 0;
	string ligne;
	while (getline(fichierEtudiants, ligne))
	{
		++compteurLigne;

		// Séparer la ligne en tokens avec la fonction 'split()' en utilisant la virgule comme délimiteur ','
		// TODO: Déplacer la fonction split dans la librairie "Chain.h/Chaine.cpp"
		vector<string> tokens = split(ligne, ',');

		//  Vérifier le nombre de tokens correspond au nombre de tokens attendus et rejeter la ligne contenant l'étudiant
		// - Erreur : s'il y a trop de tokens (informations de trop ou des virgules de trop)
		// - Erreur : s'il n'y a pas assez de tokens (informations manquantes ou des virgules manquantes)
		if (tokens.size() != 4)
		{
			cout << format("Erreur : Ligne {} - Nombre delimiteurs invalide: {} - {}\n", compteurLigne, tokens.size(), ligne);
			continue;
		}

		// Créer une instance de 'Etudiant'
		Etudiant etudiant;

		// Pour les champs 'string', vérifier qu'ils ne sont pas vides avant de les assigner
		// - Note : il serait une bonne idée d'utiliser aussi une fonction 'trim()' pour enlever les espaces non significatifs
		etudiant.prenom = tokens[0];
		if (etudiant.prenom.empty())
		{
			cout << format("Erreur : Ligne {} - Prenom de l'etudiant vide.\n", compteurLigne);
			continue;
		}

		// TODO: Lire et valider le nom de l'étudiant
		etudiant.nom = tokens[1];
		if (etudiant.nom.empty())
		{
			cout << format("Erreur : Ligne {} - Nom de l'etudiant vide.\n", compteurLigne);
			continue;
		}
		

		// TODO: Lire et valider l'age et le moyenne de l'étudiant
		// - Pour les champs 'int' et 'double', utiliser les fonctions 'tryParse' pour convertir les chaînes en nombres
		if (!tryParseInt(tokens[2], etudiant.age))
		{
			cout << format("Erreur : Ligne {} - Age de l'etudiant '{}' n'est pas un entier.\n", compteurLigne, tokens[2]);
			continue;
		}
		if (!tryParseDouble(tokens[2], etudiant.moyenne))
		{
			cout << format("Erreur : Ligne {} - Moyenne de l'etudiant '{}' n'est pas un double.\n", compteurLigne, tokens[3]);
			continue;
		}



		// TODO: Ajouter l'étudiant au vecteur des étudiants valides
		etudiants.push_back(etudiant);

	}

	// TODO: Fermer le fichier après la lecture des étudiants comme bonne pratique
	// - Empeche le fichier d'etre en utilisation jusqu'a la fermeture du programme
	fichierEtudiants.close();

	return etudiants;
}

void sauvegarderFichierEtudiantsValides(const string& nomFichier, const vector<Etudiant>& etudiants)
{
	// Écrire les étudiants valides dans un nouveau fichier texte
	ofstream fichierEtudiantsValides;

	// TODO: Ouvrir le fichier texte en écriture qui écrase le contenu
	fichierEtudiantsValides.open(nomFichier, ios::out);
	// TODO: Vérifier que le fichier est bien ouvert en écriture, sinon arrêter l'écriture
	if (!fichierEtudiantsValides.is_open())
	{
		cout << format("Erreur : Impossible d'ouvrir le fichier '{}' en ecriture.\n", nomFichier);
		return;
	}
	//

	cout << format("\nEcriture des {} etudiants valides dans le fichier '{}' separes par des ';'\n", etudiants.size(), nomFichier);

	// TODO: Écrire dans le fichier les étudiants valides séparés par des points-virgules ';'

	for (int i = 0; i < etudiants.size(); i++)
	{
		if (i != 0)
		{
			//TODO: Sauter une ligne sauf pour le premier etudiant
			cout << "\n";
		}
	cout << format("{};{};{};{}",
 		etudiants[i].prenom,
 		etudiants[i].nom,
 		etudiants[i].age,
 		etudiants[i].moyenne);


	
	}


	// TODO: Fermer le fichier après la lecture des étudiants comme bonne pratique
	// - Empeche le fichier d'etre en utilisation jusqu'a la fermeture du programme
	fichierEtudiantsValides.close();

}