/*
    Auteur : Xavier Blanchette
    Date : 2026-10-30
    Description : TP2 - Calculatrice - Version enseignant
*/

#include <cmath>
#include <format>
#include <iostream>
#include <string>

using namespace std;

const char SYMBOLE_FORMES = '*';

enum Operation
{
    Invalide = '\0',

    Addition = '+',
    Soustraction = '-',
    Multiplication = '*',
    Division = '/',
    Exposant = '^',
    Factorielle = '!',
    SerieTaylor = 's',
    Rectangle = 'r',
    TriangleRectangleIsocele = 't',
    Quitter = 'q',
};

int main()
{
    // Configurer la Console en Anlgais US pour les accents et écriture de nombres à virgule avec un point (3.1416)
    setlocale(LC_ALL, "en_US.UTF-8");

    cout << format("VERSION FINALE\n");
    cout << format("CETTE VERSION A ÉTÉ TESTÉE ET EST LA VERSION A ATTEINDRE POUR CETTE ANNÉE\n");

    // Conserver le résultat des opérations de la calculatrice entre chaque opération
    double resultat = 0;

    // Conserver le message à afficher selon l'opération effectuée au réaffichage du menu de la calculatrice
    string affichageOperation = "";

    // Boucle principale du programme qui continue tant que l'utilisateur ne choisit pas de quitter
    while (true)
    {
        // Afficher l'en-tête du programme
        cout << format("\n");
        cout << format("***********************************************************\n");
        cout << format("*                       Calculatrice                      *\n");
        cout << format("*                Par Mael Perreault (10037)               *\n");
        cout << format("***********************************************************\n");
        cout << format("\n");

        // Afficher les opérations fait lors du dernier choix d'opération dans le menu
        if (affichageOperation != "")
        {
            cout << format("{}\n", affichageOperation);
            affichageOperation = "";
        }

        // Afficher le résultat actuel de la Calculatrice
        cout << format("Résultat : {}\n", resultat);
        cout << "\n";

        // Afficher le menu des opérations
        cout << "--- Opérations ---\n";
        cout << "\n";

        // Opérations qui utilisent le résultat dans le calcul et écrasent le résultat
        cout << "+) Addition\n";
        cout << "-) Soustraction\n";
        cout << "*) Multiplication\n";
        cout << "/) Division\n";
        cout << "^) Exposant\n";
        cout << "\n";

        // Opérations qui écrasent le résultat avec le calcul de l'opération sans l'utiliser dans le calcul
        cout << "!) Factorielle\n";      // 5! = 5 * 4 * 3 * 2 * 1
        cout << "s) Série de Taylor\n";  // 1 + (x^1 / 1!) + (x^2 / 2!) + (x^3 / 3!) + ... + (x^n / n!)
        cout << "\n";

        // Opérations qui n'utilisent pas et ne changent pas le résultat
        cout << "r) Rectangle\n";
        cout << "t) Triangle\n";
        cout << "\n";

        cout << "q) Quitter\n";
        cout << "\n";

        // Effectuer une opération du menu ou changer le résultat avant de réafficher le menu principal
        bool estOperationValide = false;
        while (!estOperationValide)
        {
            // Présumer que l'opération entrée sera valide pour simplifier de ne pas ajouter dans chaque opération
            estOperationValide = true;

            // Lire le choix de l'opération en chaine de caractère pour supporter les choix de menu (char) et nouveau résultat (double)
            cout << format("Choisir une opération ou entrer un nouveau resultat : ");
            string operationChaine;
            cin >> operationChaine;

            // Extraire le premier caractere comme operation si un seul caractere a ete saisi
            // "+" => '+'
            // "abc" = > '\0'
            char operation = operationChaine.length() == 1
                ? operationChaine[0]
                : Operation::Invalide;

            // Effectuer l'operation entree par l'utilisateur, sinon tenter de convertir l'entree en double pour nouveau resultat
            switch (operation)
            {
            case Operation::Addition:
            case Operation::Soustraction:
            case Operation::Multiplication:
            case Operation::Division:
            {
                // Lire un nombre a virgule valide a utiliser avec le resultat de la calculatrice et l'operateur
                double nombreVirgule = 0;
                bool estNombreVirguleInvalide = true;
                while (estNombreVirguleInvalide)
                {
                    // Lire un nombre a la Console
                    cout << "Entrer un nombre : ";
                    cin >> nombreVirgule;

                    // Verifier que le nombre est un nombre a virgule valide
                    estNombreVirguleInvalide = cin.fail();

                    // Afficher une erreur et redemander un nombre a la Console
                    if (estNombreVirguleInvalide)
                    {
                        cout << "Erreur : nombre invalide, doit etre un nombre a virgule !\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                // Empecher les divisions par 0
                // Annuler l'operation afin de revenir au menu principal et afficher un message d'erreur dans le menu principal
                if (operation == Operation::Division
                    && nombreVirgule == 0)
                {
                    affichageOperation = "Operation annulee : impossible de diviser par 0 !\n";
                    break;
                }

                // Calculer le nouveau résultat de la calculatrice avec le résultat actuel et le nombre entré
                double nouveauResultat = resultat;
                switch (operation)
                {
                case Operation::Addition:
                    nouveauResultat += nombreVirgule;
                    break;
                case Operation::Soustraction:
                    nouveauResultat -= nombreVirgule;
                    break;
                case Operation::Multiplication:
                    nouveauResultat *= nombreVirgule;
                    break;
                case Operation::Division:
                    nouveauResultat /= nombreVirgule;
                    break;
                }

                // Afficher l'opération à l'aide des nombres et du symbole de l'operateur
                affichageOperation = format("Operation : {} {} {} = {}\n{}",
                    resultat, operation, nombreVirgule, nouveauResultat,
                    affichageOperation);

                // Mettre a jour du resultat avec le nouveau resultat
                resultat = nouveauResultat;
            }
            break;

            case Operation::Exposant:
            {
                // Lecture du nombre entier a utiliser pour l'exposant
                int nombreEntierExposant = 0;
                bool estExposantInvalide = true;
                while (estExposantInvalide)
                {
                    // Afficher le message d'entree selon l'operation a effectuer
                    cout << "Entrer l'exposant : ";
                    cin >> nombreEntierExposant;

                    // Afficher les erreurs de l'entree du nombre selon l'operation a effectuer
                    estExposantInvalide = cin.fail();

                    if (estExposantInvalide)
                    {
                        cout << "Erreur : exposant invalide, doit etre un entier !\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                // Annuler l'operation pour 0 avec une puissance negative (1/0^1 = 1/0 = undefined)
                if (resultat == 0 && nombreEntierExposant < 0)
                {
                    affichageOperation = "Operation annulee : impossible pour 0 d'avoir un exposant negatif !\n";
                    break;
                }

                // Calculer l'exposant selon les cas qui donnent toujours 1, positif ou negatif
                double nouveauResultat;
                if (nombreEntierExposant == 0)
                {
                    // Retourner toujours la valeur 1 pour un exposant 0
                    // Ex. 0^0 = 1, 1^0 = 1, 2^0 = 1, etc.
                    nouveauResultat = 1;
                }
                else if (nombreEntierExposant > 0)
                {
                    // Calculer l'exposant positif a partir du resultat actuel de la calculatrice
                    // Ex. x ^ 1, x ^ 2, x ^ 3, ... x ^ n

                    // Debuter avec un exposant 1, donc le resultat actuel de la calculatrice
                    nouveauResultat = resultat;

                    // Calculer les exposant restants a partir de 2
                    for (int i = 2; i <= nombreEntierExposant; i++)
                    {
                        double resultatMultiplication = nouveauResultat * resultat;
                        affichageOperation += format("{} * {} = {}\n", nouveauResultat, resultat, resultatMultiplication);
                        nouveauResultat = resultatMultiplication;
                    }
                }
                else
                {
                    // Calculer l'exposant negatif a partir du resultat actuel de la calculatrice
                    // Ex. 1 / (x ^ 1), 1 / (x ^ 2), ... 1 / (x ^ n)

                    // Debuter avec un exposant -1, donc une fraction de 1 divise par le resultat actuel de la calculatrice
                    nouveauResultat = 1 / resultat;

                    // Calculer les exposant restants a partir de -2
                    double diviseur = resultat;
                    for (int i = -2; i >= nombreEntierExposant; i--)
                    {
                        affichageOperation += format("1 / {} * 1 / {} = 1 / {}\n", diviseur, resultat, diviseur * resultat);
                        nouveauResultat *= 1 / resultat;
                        diviseur *= resultat;
                    }
                }

                // Afficher les calculs a la Console si l'exposant n'est pas : 0, 1 ou -1
                if (nombreEntierExposant != 0
                    && nombreEntierExposant != 1
                    && nombreEntierExposant != -1)
                {
                    affichageOperation = "\nCalculs : \n" + affichageOperation;
                }

                // Afficher l'operation a l'aide des nombres et du symbole de l'operateur
                affichageOperation = format("Operation : {} {} {} = {}\n{}",
                    resultat, operation, nombreEntierExposant, nouveauResultat,
                    affichageOperation);

                // Mettre a jour le resultat avec le nouveau resultat de l'exposant
                resultat = nouveauResultat;

            }
            break;

            case Operation::Factorielle:
            {
                // Lecture du nombre a utiliser avec l'operateur
                double nombre = 0;
                bool estNombreInvalide = true;
                while (estNombreInvalide)
                {
                    cout << "Entrer la factorielle : ";
                    cin >> nombre;
                    estNombreInvalide = cin.fail();

                    // Afficher les erreurs de l'entree du nombre selon l'operation a effectuer
                    if (estNombreInvalide || nombre != (int)nombre || nombre < 0)
                    {
                        estNombreInvalide = true;
                        cout << "Erreur : factorielle invalide, doit etre un entier positif !\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                // Debuter le calcul du factoriel a 1 pour 0! et 1!
                // 0! = 1
                // 1! = 1
                double nouveauResultat = 1;

                // Ne pas afficher de calculs pour 0! et 1!
                if (nombre != 0 && nombre != 1)
                {
                    // Multiplier le resultat par chaque nombre entier en decrementant jusqu'a 1
                    affichageOperation += "\nCalculs : \n";
                    for (int i = (int)nombre; i > 0; i--)
                    {
                        double resultatMultiplication = nouveauResultat * i;
                        affichageOperation += format("{} * {} = {}\n", nouveauResultat, i, resultatMultiplication);
                        nouveauResultat = resultatMultiplication;
                    }
                }
                // Afficher les calculs de l'operation factorielle
                affichageOperation = format("Operation : {}! = {}\n{}",
                    nombre, nouveauResultat,
                    affichageOperation);

                // Mettre a jour du resultat avec le nouveau resultat
                resultat = nouveauResultat;
            }
            break;

            case Operation::SerieTaylor:
            {
                // Lire la variable x de la serie Taylor a la Console
                double x = 0;
                while (true)
                {
                    cout << "Entrer le x de la serie de Taylor : ";
                    cin >> x;

                    if (!cin.fail())
                        break;

                    cout << "Erreur : x invalide doit etre un nombre a virgule !\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                // Lire la variable n de la serie Taylor a la Console
                int n = 0;
                while (true)
                {
                    cout << "Entrer le n de la serie de Taylor : ";
                    cin >> n;

                    if (!cin.fail() && n >= 0)
                        break;

                    cout << "Erreur : n invalide, doit etre un nombre entier positif !\n";

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                // Calculer la serie de Taylor
                // Ex. 1 + (x^1 / 1!) + (x^2 / 2!) + (x^3 / 3!) + ... + (x^n / n!)

                // Conserver les differents affichages dans des chaines separees pour les concatener ensemble apres les calculs
                string affichageSerie = "Serie de Taylor : 1";
                string affichageCalculs = "Calculs : 1";
                string affichageValeurs = "Valeurs : 1";

                double nouveauResultat = 1;
                for (int termeSerie = 1; termeSerie <= n; termeSerie++)
                {
                    // Calculer le numerateur serie de Taylor : (x ^ n)
                    double numerateur = x;
                    for (int exposant = 2; exposant <= termeSerie; exposant++)
                    {
                        numerateur *= x;
                    }

                    // Calculer le denominateur serie de Taylor : n!
                    // Debuter avec le factoriel 1! = 1
                    int denominateur = 1;

                    // Calculer les autres factoriels jusqu'a n! 
                    // Ex. 1 * 5! = 1 * 5 * 4 * 3 * 2
                    for (int factoriel = termeSerie; factoriel >= 2; factoriel--)
                    {
                        denominateur *= factoriel;
                    }

                    // Faire le calcul de la fraction serie de Taylor : (x ^ n) / n!
                    double fractionTaylor = numerateur / denominateur;
                    nouveauResultat += fractionTaylor;

                    // Afficher les calculs de la serie de Taylor
                    // Limiter l'affichage a 3 nombres apres la virgule
                    affichageSerie += format(" + ({}^{} / {}!)", x, termeSerie, termeSerie);
                    affichageCalculs += format(" + {} / {}", numerateur, denominateur);
                    affichageValeurs += format(" + {}", fractionTaylor);
                }

                // Affectuer le resultat de la serie de Taylor a la calculatrice
                resultat = nouveauResultat;

                // Concatener ensemble les 3 chaines d'affichages de la serie de Taylor
                affichageOperation = format("{}\n{}\n{}\n", affichageSerie, affichageCalculs, affichageValeurs);
            }
            break;

            case Operation::Rectangle:
            case Operation::TriangleRectangleIsocele:
            {
                // Lire la hauteur de la forme a la Console
                double hauteur = 0;
                while (hauteur <= 0)
                {
                    cout << "Entrer une hauteur : ";
                    cin >> hauteur;

                    if (cin.fail())
                    {
                        cout << format("Erreur : hauteur doit etre un nombre a virgule !\n");
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }

                    if (hauteur <= 0)
                        cout << format("Erreur : hauteur doit etre plus grand que 0 !\n");
                }

                // Lire la largeur a la Console
                double largeur = 0;
                if (operation == 'r')
                {
                    while (largeur <= 0)
                    {
                        cout << "Entrer une largeur : ";
                        cin >> largeur;

                        if (cin.fail())
                        {
                            cout << format("Erreur : largeur doit etre un nombre a virgule !\n");
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }

                        if (largeur <= 0)
                            cout << format("Erreur : largeur doit etre plus grand que 0 !\n");
                    }
                }
                else
                {
                    // Assigner pour un triangle rectangle isocele hauteur et largeur a la meme valeur
                    largeur = hauteur;
                }

                switch (operation)
                {
                case Operation::Rectangle:
                {
                    // Afficher le rectangle
                    for (int ligne = 0; ligne < hauteur; ligne++)
                    {
                        for (int symbole = 0; symbole < largeur; symbole++)
                        {
                            // Afficher aussi un espace car les lignes espacement des lignes est plus que l'espacement des caracteres
                            cout << "*";
                            cout << " ";
                        }

                        cout << "\n";
                    }

                    double aire = hauteur * largeur;
                    double perimetre = hauteur * 2 + largeur * 2;

                    cout << "\n";
                    cout << format("Aire      : {:.3f}\n", aire);
                    cout << format("Perimetre : {:.3f}\n", perimetre);
                    cout << "\n";
                }
                break;

                case Operation::TriangleRectangleIsocele:
                {
                    // Afficher le triangle rectangle
                    for (int ligne = 0; ligne < hauteur; ligne++)
                    {
                        // Toujours arrondir vers le haut le nombre de symboles a afficher
                        int nombreSymboles = ligne + 1;

                        // Afficher les caracteres pour la ligne selon le pourcentage de la largeur
                        for (int symbole = 0; symbole < nombreSymboles; symbole++)
                        {
                            // Afficher aussi un espace car les lignes espacement des lignes est plus que l'espacement des caracteres
                            cout << SYMBOLE_FORMES;
                            cout << " ";
                        }

                        cout << "\n";
                    }

                    double aire = (hauteur * largeur) / 2;
                    double hypothenuse = sqrt(hauteur * hauteur + largeur * largeur);
                    double perimetre = hauteur + largeur + hypothenuse;

                    cout << "\n";
                    cout << format("Aire       : {:.3f}\n", aire);
                    cout << format("Hypotenuse : {:.3f}\n", hypothenuse);
                    cout << format("Perimetre  : {:.3f}\n", perimetre);
                    cout << "\n";
                }
                break;

                default: break;
                }

                system("pause");
            }
            break;

            case Operation::Quitter:
            {
                // Demander une lecture de touche afin de quitter pour ne pas terminer immediatement un executable compile (.exe)
                cout << "\n";
                system("pause");

                // Terminer le programme au lieu de repartir le programme du debut
                return 0;
            }

            default:
            {
                // Verifier si l'element entre est un nombre ou une operation invalide
                try
                {
                    // Convertir l'entree de l'utilisateur en nombre a virgule
                    // stod(chaine, &nombre) : string to double
                    size_t nombreCaracteresConvertis;
                    double nouveauResultat = stod(operationChaine, &nombreCaracteresConvertis);

                    // Lancer une erreur si la chaine au complet n'a pas pu etre convertie en nombre a virgule 
                    // Execution du code passe alors au catch() du try { ... } catch () { ... }
                    if (nombreCaracteresConvertis < operationChaine.length())
                    {
                        throw exception();
                    }

                    // Changer le resultat de la calculatrice pour le nombre a virgule entre
                    resultat = nouveauResultat;
                }
                catch (...)
                {
                    // Afficher une erreur pour une operation invalide ou conversion en nombre invalide
                    cout << "Erreur : l'operation ou le nombre est invalide.\n";

                    // Redemander un nouvelle choix ou resultat a l'utilisateur sans reafficher le menu principal
                    estOperationValide = false;
                }
            }
            break;
            } // switch(operation)
        } // while(!estOperationValide)
    } // while(true)
} // main()
