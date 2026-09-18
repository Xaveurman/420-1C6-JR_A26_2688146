// cours07.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

/*
	Auteur : Xavier Blanchete
	Date : 2026-08-24
	Description : Introduction conditionnelle switch
*/

#include <iostream>
#include <string>
#include <format>

    using namespace std;

    int main()
    {
        // Configuration de la console en Unicode pour les accents
        setlocale(LC_ALL, "fr_CA.UTF-8");

        // Affichage de l'en-tête
        cout << "--- Cours 07 - Switch ---\n";

#pragma region Switch
        // *** Switch ***
        // - Instruction conditionnelles afin de sélectionner un travail à faire parmis plusieurs
        //      - Vérifie seulement une seule variable à plusieurs valeurs
        //      - Équivalent de comparer plusieurs la variable fois avec l'opérateur d'égalité (==)
        //      - Génère en arrière-plan le code if() équivalent lors de la compilation
        // - Par convention
        //      - Difficile avec switch de se tromper de variable ou d'opérateur
        //      - Préférer au if() si on vérifie une seule variable (int ou char) avec l'opérateur d'égalité (==)
        //      - Très utile pour les menu à la Console avec un choix utilisateur
        //
        // switch (variable)
        // {
        // case 0:
        //     // Travail si la valeur est 0
        // 
        //     break; // Termine le switch à l'emplacement de l'accolade fermante 
        // 
        // case 1:
        //     // Travail si la valeur est 1
        // 
        //     break; // Termine le switch à l'emplacement de l'accolade fermante 
        // 
        // default:
        //     // Travail par défaut si la valeur est aucun des autres cas définis
        //     // Toujours mettre le default à la fin par convention
        // 
        //     break; // Termine le switch à l'emplacement de l'accolade fermante 
        // }

        // *** Switch avec entier (int) ***
        // - Choix de travail à faire selon nombre entré (ex. afficher un message)

        cout << "\n--- Entiers (int) ---\n";

        cout << "Entrer un nombre : ";
        int nombre;
        cin >> nombre;

        // Version avec if et conditions sur un entier (int)
        if (nombre == 0)
        {
            cout << "If - Message seulement pour 0\n";
        }
        else if (nombre == 1 || nombre == 2)
        {
            cout << "If - Message pour 1 ou 2\n";
        }
        else
        {
            cout << "If - Message par défaut pour tous les autres cas\n";
        }

        // Version avec switch équivalent sur un entier (int)
        switch (nombre)
        {
        case 0:
            cout << "Switch - Message seulement pour 0\n";
            break;

        case 1:
        case 2:
            cout << "Switch - Message pour 1 ou 2\n";
            break;

        default:
            cout << "Switch - Message par défaut pour tous les autres cas\n";
            break;
        }


        // *** Switch avec un caractère (char) ***
        // - Choix de travail à faire selon le caractère entré (ex. afficher un message)

        cout << "\n--- Caractere (char) ---\n";

        cout << "Entrer un caractère : ";
        char caractere;
        cin >> caractere;

        // Version avec if avec choix sur un caractère (char)
        if (caractere == 'a'
            || caractere == 'e'
            || caractere == 'i'
            || caractere == 'o'
            || caractere == 'u')
        {
            cout << format("If - {} est une voyelle\n", caractere);
        }
        else if (caractere == ' ')
        {
            cout << format("If - {} est un espace\n", caractere);
        }
        else if (caractere == '0'
            || caractere == '1'
            || caractere == '2'
            || caractere == '3'
            || caractere == '4'
            || caractere == '5'
            || caractere == '6'
            || caractere == '7'
            || caractere == '8'
            || caractere == '9')
        {
            cout << format("If - {} est un chiffre\n", caractere);

            if (caractere == '0')
            {
                cout << format("If - {} est le chiffre z�ro\n", caractere);
            }
        }
        else if (caractere >= 'a' && caractere <= 'z')
        {
            cout << format("If - {} est une consonne\n", caractere);
        }
        else
        {
            cout << format("If - {} est un caract�re sp�cial\n", caractere);
        }

        // Version avec switch équivalent sur un caract�re (char)
        // - Plus aéré et facile à lire que la version if
        switch (caractere)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << format("Switch - {} est une voyelle\n", caractere);
            break;

        case ' ':
            cout << format("Switch - {} est un espace\n", caractere);
            break;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            cout << format("Switch - {} est un chiffre\n", caractere);

            if (caractere == '0')
            {
                cout << format("Switch - {} est le chiffre zéro\n", caractere);
            }
            break;

        default:
            // Cases permettent seulement les opérateurs d'égalité (==) 
            if (caractere >= 'a' && caractere <= 'z')
            {
                cout << format("Switch - {} est une consonne\n", caractere);
            }
            else
            {
                cout << format("Switch - {} est un caractère spécial\n", caractere);
            }
            break;
        }

        // *** Exemple de switch ***
        // Afficher le menu de conversion de température
        cout << "\n --- Conversion de température ---\n\n";
        cout << "c) Celsius => Farenheit\n";
        cout << "f) Farenheit => Celsius\n";

        // Lire le choix de conversion de l'utilisateur à la Console
        cout << "\nEntre le format de la température : ";
        char choixTemperature;
        cin >> choixTemperature;

        // TODO: Convertir la température du 'nombre' selon le choix de l'utilisateur en minuscule ou majuscule

        switch (choixTemperature)
        {
        case 'c': // 99
        case 'C': // 67
            cout << format("Celsius {} => Farenheit {}\n", nombre, nombre * 9.0 / 5.0 + 32);
            break;

        case 'f': //102
        case 'F': // 70
            cout << format("Farenheit {} => Celsius {}\n", nombre, (nombre - 32) * 5.0 / 9.0);
            break;

        default:
            // TODO: Afficher une erreur si le choix n'est pas dans le menu
            cout << format("Erreur : le choix de conversion \"{}\" n'est pas valide.\n", choixTemperature);
            break;
        }

       


        cout << "\n--- Erreurs ---\n";

        // *** Erreurs ***
        // 1) Switch avec string impossible en C++, mais permis en C# et JavaScript
        //string chaine = "abc";
        //switch (chaine)
        //{
        //case "abc":
        //    break;
        //default:
        //    break;
        //}

        // 2) Erreurs de syntaxe avec instruction 'case'
        //
        // E0052: ':' attendu
        //switch (nombre)
        //{
        //case 0 // Erreur, point virgule manquant
        //    break;
        //default:
        //    break;
        //}
        //
        // E0029: expression attendue
        //switch (nombre)
        //{
        //case: 0 // Erreur, deux-points mal positionné
        //    break;
        //default:
        //    break;
        //}
        //
        // E1578: la valeur de l'étiquette case apparait déjà dans ce commutateur
        //switch (nombre)
        //{
        //case 0:
        //    break;
        //case 0: // Erreur, 2 fois le même case
        //    break;
        //default:
        //    break;
        //}

        // 3) Erreur de logique avec 'break' manquant
        // C26819: Il existe un fallthrough non annoté entre les étiquettes de Switch
        switch (nombre)
        {
        case 0:
            cout << "Erreur de break manquant (case 0)\n";
            // break; manquant, continue au prochain case
        case 1:
            cout << "Erreur de break manquant (case 1)\n";
            // break; manquant, continue au prochain case
        default:
            cout << "Erreur de break manquant (default)\n";
            // break; manquant, techniquement non nécessaire car on est déjà à la fin
        }

#pragma endregion

#pragma region Scope
        // *** Scope ***
        // Accolades ouvrantes et fermantes {} définissent un 'Scope'
        // - main() {}
        // - if () {}
        // - else if () {}
        // - else {}
        // - switch() {}
        // 
        // Scope
        // - Ensemble de variables en mémoire qui peuvent être utilisées
        // - Mémoire et noms des variables sont reservés
        // 
        // Stack (pile)
        // - Façon principale d'attribution de la mémoire avec le Heap (amas)
        // - Ouverture d'un scope {
        //      - Réserve l'espace mémoire pour toutes les variables comprises
        //      - Réserve les noms des variables
        // - Fermeture d'un scope }
        //      - Libère l'espace mémoire de toutes les variables comprises
        //      - Libère les noms des variables

        // TODO: Faire un dessin du Stack suivant avec Scope

        // Variable définie pour toute la fonction main()
        int a = 10;

        // Début du Scope
        {
            // int a = 20; // Erreur, défini dans le Scope main()

            // Variables définies pour le Scope seulement
            int b = 20;
            int c = 30;

            // Variables du Scope main() peuvent être utilisées
            b = a + 100;

            // Variables du Scope main() peuvent être modifiées
            a = b + c;
        }
        // Fin du Scope

        cout << format("Valeur de 'a' après le Scope\n", a);

        // erreur, variables du scope ont été libérées
        //cout << format("valeur de 'b' apres le scope : {}\n", b);
        //cout << format("valeur de 'c' apres le scope : {}\n", c);

        // *** switch avec scope ***
        // - attention que l'instruction switch() par défaut ouvre un seul scope
        //      - variables avec le même ne peuvent pas être définies plusieurs fois
        // - variable 'resultat' est définie 3 fois dans le même scope
        //      - c2374 : 'resultat' redéfinition
        // - de plus, c++ empêche les définitions de variables directement dans un switch
        //      - c2361 : l'initialisation de 'resultat' est ignorée par l'étiquette 'default'
        //      - c2360 : l'initialisation de 'resultat' est ignorée par l'étiquette 'case'
        //      - c2361 : l'initialisation de 'bonus' est ignorée par l'étiquette 'default'
        switch (nombre)
        {
        case 0:
        {
            int resultat = nombre + 100;
            cout << format("Resultat pour le nombre {} : {}\n", nombre, resultat);
        }
        break;
        case 1:
        {
            int resultat = nombre * 10 + 2000;
            int bonus = 10000;
            cout << format("Resultat pour le nombre {} : {}\n", nombre + bonus, resultat);
        }
        break;
        default:
        {
        int resultat = nombre + 1000;
        cout << format("Resultat pour le nombre {} : {}\n", nombre, resultat);
        }
            break;
        }

        // TODO: Fixer l'erreur en ajoutant un Scope par case

        int resultat = 0;

        switch (nombre)
        {
        case 0:
            resultat = nombre + 100;
            break;
        case 1:
            resultat = nombre * 10 + 2000;
            nombre += 10000;
            break;
        default:
            resultat = nombre + 1000;
            break;
        }

        cout << format("Resultat pour le nombre {} : {}\n", nombre, resultat);

        // TODO: Fixer l'erreur en déclarant une variable avant le switch et message après switch



#pragma endregion
    }

    // TODO: Créer un nouveau projet et faire les exercices

