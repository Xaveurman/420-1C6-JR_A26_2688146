/*
	Auteur		: Xavier Blanchette
	Date		: 2026 - 11 -19
	Description : Fonctions avancées sur les chaînes de caractères
*/

#include <format>
#include <iostream>
#include <string>

using namespace std;

void afficherChaineParCopie(string chaine);
void afficherChaineParReference(string& chaine);

int main()
{
	std::cout << "--- Cours 35 - String ---\n\n";

	// *** String ***
	// - Simplement un vector<char> avec quelques fonctionnalités supplémentaires
	// 	   - Tableau de caractères dans le heap (char[])
	//		- Capacité (capacity)
	//		- Taille actuelle (length)
	// - Ajout à la chaîne de caractères
	//		- Créer une nouvelle chaîne de caractères si la capacité actuelle est dépassée
	//		- Copie les anciens caractères dans la nouvelle chaîne
	//		- Ajouter les nouveaux caractères
	// - Tableau de caractères (char[])
	//		 - Normalement
	//				- Tableau de caractères est créé sur le Heap (char[])
	//		 - SSO (Small String Optimization)
	//				- Tableaux de caractères créé directement dans l'objet string sur la Stack (char[])
	//				- Chaines courtes varient selon le compilateur
	//					- Ex. 16 caractères dans Visual Studio
	if (false)
	{
		// Chaîne initiale créée sur le Heap (plus de 16 caractères)
		string chaine = "Bonjour 123456789 123456789 123456789";

		// TODO : Exemple de SSO sur le Stack avec 16 caractères, ajout un caractère défini sur le Heap
		//string chaine = "123456789123456";

		cout << format("Adresse de la chaine string      : {}\n", (const void*)(&chaine));
		cout << format("Adresse du tableau de caracteres : {}\n", (const void*)(chaine.c_str()));
		cout << format("Taille actuelle   : {}\n", chaine.size());
		cout << format("Capacite actuelle : {}\n\n", chaine.capacity());

		// Capacity dépassée, nouveau tableau sur le Heap
		chaine += " tout le monde";

		cout << format("Adresse de la chaine string      : {}\n", (const void*)(&chaine));
		cout << format("Adresse du tableau de caracteres : {}\n", (const void*)(chaine.c_str()));
		cout << format("Taille actuelle   : {}\n", chaine.size());
		cout << format("Capacite actuelle : {}\n\n", chaine.capacity());

		// Capacity encore disponible pas de nouveau tableau sur le Heap
		chaine += " et bienvenue";

		cout << format("Adresse de la chaine string      : {}\n", (const void*)(&chaine));
		cout << format("Adresse du tableau de caracteres : {}\n", (const void*)(chaine.c_str()));
		cout << format("Taille actuelle   : {}\n", chaine.size());
		cout << format("Capacite actuelle : {}\n\n", chaine.capacity());

		// Capacity dépassée, nouveau tableau sur le Heap
		chaine += " au programme de chaines de caractere !";

		cout << format("Adresse de la chaine string      : {}\n", (const void*)(&chaine));
		cout << format("Adresse du tableau de caracteres : {}\n", (const void*)(chaine.c_str()));
		cout << format("Taille actuelle   : {}\n", chaine.size());
		cout << format("Capacite actuelle : {}\n\n", chaine.capacity());
	}

	// *** Paramètre de fonctions ***
	// - Fonctionnement identique aux vector<T>
	// - Paramètre par copie
	//		- void fonction(string chaine)
	//		- Crée une une nouveau tableau de caractères (char[]) sur le Heap
	//		- Copie les caractères dans le nouveau tableau
	// - Paramètre par référence (&)
	//		- void fonction(const string& chaine)
	//		- Pointeur sur l'objet original 'string'
	//		- Utilise le tableau original de caractères (char[])
	if (false)
	{
		string chaine = "Bonjour tout le monde";

		cout << format("--- Chaine originale ---\n");
		cout << format("Adresse de la chaine : {:#x}\n", (unsigned long long) & chaine);
		cout << format("Capacity             : {}\n", chaine.capacity());
		cout << format("Size                 : {}\n", chaine.size());

		if (chaine.size() > 0)
		{
			cout << format("Adresse du tableau   : {:#x}\n", (unsigned long long) & chaine[0]);
			cout << format("Index [0] - [{}] : ", chaine.size() - 1);

			for (int i = 0; i < chaine.size(); i++)
			{
				char caractere = chaine[i];
				cout << format("{} ", caractere);
			}
		}

		cout << "\n\n";

		afficherChaineParCopie(chaine);
		afficherChaineParReference(chaine);
	}

	// *** Fonctions ***
	// Plusieurs fonctions intégrées pour manipuler les chaînes de caractères
	// 
	// * Informations *
	// .size()		: retourne la taille actuelle des caractères du tableau de la chaîne
	// .capacity()	: retourne la capacité actuelle du tableau de la chaîne
	// .c_str()		: retourne un pointeur vers le tableau de caractères C-style (char[])
	//				  Arduino : très commun d'utiliser cette fonction pour utiliser des librairies C
	//
	// * Accès aux données *
	// [index]						: accéder à un caractère spécifique par son index
	// .substr(index)				: retourne une nouvelle 'string' à partir d'un index jusqu'à la fin de la chaîne
	// .substr(index, length)		: retourne une nouvelle 'string' à partir d'un index et d'une longueur spécifique
	// 
	// * Modifications *
	// += chaine						: ajoute une chaîne à la fin
	// .insert(index, chaine)			: insère une chaîne à une position spécifique en décalant les autres caractères
	// .erase(index, length)			: supprime une partie de la chaîne à partir de l'index en décalant les autres caractères
	// .replace(index, length, chaine)	: supprimer une partie de la chaîne et la remplacer par une nouvelle chaîne
	// .clear()							: vide la chaîne au complet
	//
	// * Recherches * (retourne un index 'size_t' ou 'string::npos' si non trouvé)
	// .find(chaine)			: trouver l'index de la première occurrence d'une sous-chaîne
	// .find(chaine, index)		: trouver l'index de la première occurrence d'une sous-chaîne à partir d'un index spécifique 
	// .find(char)				: trouver l'index du premier caractère parmi une liste de caractères
	// .find(char, index)		: trouver l'index du premier caractère parmi une liste de caractères à partir d'un index spécifique

	if (false)
	{
		cout << "\n--- Fonctions string ---\n\n";

		string chaine = "Bonjour tout le monde";
		for (size_t i = 0; i < chaine.size(); i++)
		{
			cout << format("Chaine originale : '{}'\n", i, chaine[i]);
		}
		

		// TODO: Afficher chaque caractère de la chaîne avec une boucle sur 'size()' et '[]'
		//cout << format("chaine[{}] : {}\n", i, caractere);

		// TODO: Utiliser un pointer vers le tableau de caractères du Heap avec 'c_str()' afin d'appeler une fonction C comme 'printf()'
		printf("Affichage printf avec string (erreur) : %s\n", chaine); // Erreur

		//cout << format("Pointeur vers le tableau de caracteres : {:#x}\n", (unsigned long long) );
		//printf("Affichage printf avec pointeur (const char*) 'c_str()' : %s\n", );

		

		// TODO: Modifier un caractère spécifique dans la chaîne avec '[]
		// - 'tout' => 'Tout'
		// - 'monde' => 'Monde'
		chaine[8] = 'T';
		chaine[16] = 'M';

		cout << format("\nChaine modifiee avec [] : '{}'\n", chaine);

		// TODO: Inverser 2 caractères spécifiques dans la chaîne avec '[]'  et une variable temporaire
		// 'Bonjour' -> 'jonBour'
		char temporaire = chaine[0];
		chaine[0] = chaine[3];
		chaine[3] = temporaire;


		cout << format("Chaine avec caracteres inverses : '{}'\n", chaine);

		// TODO: Extraire 3 sous-chaines avec 'substr(index, longueur)'
		// - 1) "Tout"
		// - 2) "Monde"
		// - 3) Toute la chaîne jusqu'à la fin à partir de "Bour"

		string sousChaine1 = chaine.substr(8, 4);
		cout << format("Sous-chaine extraite 1 : '{}'\n", sousChaine1);
		
		string sousChaine2 = chaine.substr(16,5);
		cout << format("Sous-chaine extraite 2 : '{}'\n", sousChaine2);
		
		string sousChaine3 = chaine.substr(3);
		cout << format("Sous-chaine extraite 3 : '{}'\n", sousChaine3);

		// TODO: Insérer une valeur avec 'insert(index, chaine)'
		// - Insérer "Hey" au début de la chaîne
		// - Insérer "super" avant "Monde"
		// - Insérer "!!!" à la fin de la chaîne

		chaine.insert(0, "Hey");
		chaine.insert(19, "super");
		chaine.insert(chaine.size(), "!!!!"); //chaine += "!!!!";

		cout << format("Chaine modifiee avec insert : '{}'\n", chaine);

		// TODO: Effacer une partie de la chaîne avec 'erase(index, longueur)'
		// - Effacer "Monde"

		chaine.erase(24, 5);

		cout << format("Chaine modifiee avec erase : '{}'\n", chaine);

		// TODO: Remplacer une partie de la chaîne avec 'replace(index, longueur, chaine)'
		// - Remplacer 'super' par 'ultra'
		
		chaine.replace(19, 5, "ultra");

		cout << format("Chaine modifiee avec replace : '{}'\n", chaine);
	}

	if (true)
	{
		cout << "\n--- Fonctions recherche ---\n\n";

		string chaine = "Le ciel est bleu. La mer est bleue.";
		cout << format("Chaine originale : '{}'\n", chaine);

		// Trouver la première sous-chaine 'bleu' avec 'find(chaine)'
		size_t indexChaineBleu1 = chaine.find("bleu");
		cout << format("Sous-chaine 'bleu' 1 trouvee a l'index : {}\n", indexChaineBleu1);

		// Trouver la deuxième occurrence de la sous-chaine 'bleu' avec 'find(chaine, indexDepart)'
		size_t indexChaineBleu2 = chaine.find("bleu", indexChaineBleu1 + 1);
		cout << format("Sous-chaine 'bleu' 2 trouvee a l'index : {}\n", indexChaineBleu2);

		// Trouver le premier caractère 'e' avec 'find(charactere)'
		size_t indexPremierE = chaine.find('e');
		cout << format("Caractere 'e' trouve a l'index : {}\n", indexPremierE);

		// Trouver le premier caractère 'w' inexisant avec 'find(charactere)'
		size_t indexCaractereInexistant = chaine.find('w');
		if (indexCaractereInexistant != string::npos)
		{
			cout << format("Caractere w' trouve a l'index : {}\n", indexCaractereInexistant);
		}
		else
		{
			cout << "Caractere 'w' non trouve.\n";
		}

		// Trouver tous les caractères 'e' dans la chaîne avec une boucle et 'find(charactere, indexDepart)'
		int compteurCaracteresE = 0;
		size_t indexChararacteE = chaine.find('e');
		while (indexChararacteE != string::npos)
		{
			++compteurCaracteresE;

			cout << format("Caractere 'e' #{} trouve a l'index : {}\n", compteurCaracteresE, indexChararacteE);
			indexChararacteE = chaine.find('e', indexChararacteE + 1);
		}

		// TODO: Utiliser 'find()' pour localiser une sous-chaine et la remplacer avec 'replace(index, longueur, nouveauString)'
		// - Remplacer 'ciel' par 'bateau'

		size_t indexCiel = chaine.find("ciel");
		chaine.replace(indexCiel, 4, "bateau");


		cout << format("Chaine modifiee avec find + replace : '{}'\n", chaine);

		// TODO: Utiliser 'find()' pour localiser l'index d'une sous-chaine et l'effacer avec 'erase(index, longueur)'
		// - Effacer 'La'

		size_t indexLa = chaine.find("La");
		chaine.erase(indexLa, 2);

		cout << format("Chaine modifiee avec find + erase : '{}'\n", chaine);

		// Attention, vérifier que l'index retourné par 'find()' n'est pas 'string::npos' avant d'utiliser l'index
		// Ex. remplacer le texte "inexistant" par "boom"

		const string CHAINE_REMPLACEMENT = "inexistant";

		size_t indexInexistant = chaine.find(CHAINE_REMPLACEMENT);

		if (indexInexistant != string::npos)
		{
			chaine.replace(indexInexistant, CHAINE_REMPLACEMENT.size(), "boom");
		}

		else
		{
			cout << format("Sous-chaine '{}' non trouvee, impossible a effacer.\n", CHAINE_REMPLACEMENT);
		}

		//cout << format("Sous-chaine '{}' non trouvee, impossible a effacer.\n", CHAINE_REMPLACEMENT);
	}

	// *** Fonctions caractères <cctype> ***
	// isalpha(charactere)	: vérifier si le caractère est une lettre [A-Za-z]
	// isdigit(charactere)	: vérifier si le caractère est un chiffre [0-9]
	// isspace(charactere)	: vérifier si le caractère est un espace blanc (espace ' ', tabulation '\t', saut de ligne '\n', etc.)
	//
	// tolower(charactere)	: convertit un caractère*** majuscule en minuscule (pas la chaine au complet)
	// toupper(charactere)	: convertit un caractère*** minuscule en majuscule (pas la chaine au complet)
	if (false)
	{
		// Utiliser les fonctions existantes pour valider les caractères
		cout << "\n--- Fonctions de validation des caracteres ---\n\n";

		cout << format("isalpha('a') : {} = (bool){}\n", isalpha('a'), (bool)isalpha('a'));
		cout << format("isalpha('z') : {} = (bool){}\n", isalpha('z'), (bool)isalpha('z'));
		cout << format("isalpha('A') : {} = (bool){}\n", isalpha('A'), (bool)isalpha('A'));
		cout << format("isalpha('Z') : {} = (bool){}\n", isalpha('Z'), (bool)isalpha('Z'));
		cout << format("isalpha('0') : {} = (bool){}\n", isalpha('0'), (bool)isalpha('0'));
		cout << format("isalpha('#') : {} = (bool){}\n", isalpha('#'), (bool)isalpha('#'));

		cout << format("\n");

		cout << format("isdigit('0') : {} = (bool){}\n", isdigit('0'), (bool)isdigit('0'));
		cout << format("isdigit('9') : {} = (bool){}\n", isdigit('9'), (bool)isdigit('9'));
		cout << format("isdigit('a') : {} = (bool){}\n", isdigit('a'), (bool)isdigit('a'));
		cout << format("isdigit('Z') : {} = (bool){}\n", isdigit('Z'), (bool)isdigit('Z'));
		cout << format("isdigit('#') : {} = (bool){}\n", isdigit('#'), (bool)isdigit('#'));

		cout << format("\n");

		cout << format("isspace(' ')  : {} = (bool){}\n", isspace(' '), (bool)isspace(' '));
		cout << format("isspace('\\t') : {} = (bool){}\n", isspace('\t'), (bool)isspace('\t'));
		cout << format("isspace('\\n') : {} = (bool){}\n", isspace('\n'), (bool)isspace('\n'));
		cout << format("isspace('a')  : {} = (bool){}\n", isspace('a'), (bool)isspace('a'));
		cout << format("isspace('Z')  : {} = (bool){}\n", isspace('Z'), (bool)isspace('Z'));
		cout << format("isspace('0')  : {} = (bool){}\n", isspace('0'), (bool)isspace('0'));
		cout << format("isspace('#')  : {} = (bool){}\n", isspace('#'), (bool)isspace('#'));

		// Attention, caractères accentués non supportés et causent des crash
		//cout << format("isalpha('é') : {} = (bool){}\n", isalpha('é'), (bool)isalpha('é')); // Crash
		//cout << format("isalpha('À') : {} = (bool){}\n", isalpha('À'), (bool)isalpha('À')); // Crash	

		// Utiliser les fonctions existantes pour modifier la casse des caractères
		cout << "\n--- Fonctions de modification de la casse des caracteres ---\n\n";
		string chaine = "Bonjour Tout Le Monde";

		// TODO: Créer 2 copies de la chaîne et transformer en minuscules et en majuscules avec 'tolower()' et 'toupper()'
		string chaineMinuscules;


		string chaineMajuscules;


		cout << format("Chaine originale : '{}'\n", chaine);
		cout << format("Chaine en minuscules : '{}'\n", chaineMinuscules);
		cout << format("Chaine en majuscules : '{}'\n", chaineMajuscules);
	}

	return 0;
}

void afficherChaineParCopie(string chaine)
{
	cout << format("--- Chaine par copie ---\n");
	cout << format("Adresse de la chaine : {:#x}\n", (unsigned long long) & chaine);
	cout << format("Capacity             : {}\n", chaine.capacity());
	cout << format("Size                 : {}\n", chaine.size());

	if (chaine.size() > 0)
	{
		cout << format("Adresse du tableau   : {:#x}\n", (unsigned long long) & chaine[0]);
		cout << format("Index [0] - [{}] : ", chaine.size() - 1);

		for (int i = 0; i < chaine.size(); i++)
		{
			char caractere = chaine[i];
			cout << format("{} ", caractere);
		}
	}

	cout << "\n\n";
}

void afficherChaineParReference(string& chaine)
{
	cout << format("--- Chaine par reference (&) ---\n");
	cout << format("Adresse de la chaine : {:#x}\n", (unsigned long long) & chaine);
	cout << format("Capacity             : {}\n", chaine.capacity());
	cout << format("Size                 : {}\n", chaine.size());

	if (chaine.size() > 0)
	{
		cout << format("Adresse du tableau   : {:#x}\n", (unsigned long long) & chaine[0]);
		cout << format("Tableau [0] - [{}] : ", chaine.size() - 1);

		for (int i = 0; i < chaine.size(); i++)
		{
			char caractere = chaine[i];
			cout << format("{} ", caractere);
		}
	}

	cout << "\n\n";
}