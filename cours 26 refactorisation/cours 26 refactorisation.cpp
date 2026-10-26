/*
    Auteur : Xavier Blanchette
    Date : 2026-10-26
    Description : Refactorisation d'un programme à l'aide de fonctions et fichiers
*/

// *** Refactorisation ***
// - Refactorisation est l'art de rendre notre code plus beau en conservant le meme comportement
// - Rend le programme plus facile à comprendre et donc à maintenir à long terme
// 
//
// Étapes d'écriture d'un programme :
// - 1. Écrire un programme sans fonctions, ni constantes et tester que le programme est fonctionnel
// - 2. Refactoriser le programme en ajoutant des constantes pour les nombres magiques
// - 3. Refactoriser le programme en créant des fonctions avant le main() (menu, choix switch, etc.)
// - 4. Déplacer les constantes dans un fichier (ex. 'Constantes.h') et l'inclure avant le main()
// - 5. Créer des déclarations pour chaque fonction
// - 6. Déplacer les déclarations dans un fichier (ex. 'Fonctions.h') et l'inclure avant le main()
// - 7. Déplacer le code des fonctions (définition) dans un fichier (ex. 'Fonctions.cpp')
// - 8. Créer des fonctions supplémentaires pour les fonctions trop longues ou blocs de code qui se répètent
//      Fonction ne devrait pas faire plus qu'un écran et demi (environ 50 - 100 lignes)
//
// Ne pas oublier de tester après chaque étape que le programme est encore fonctionnel

#include <format>
#include <iostream>
#include <string>
#include "Fonctions.h"
#include "Constantes.h"

using namespace std;

enum ChoixMenu
{
    Cinema = 1,
    Bowling = 2,
    Musee = 3,
    Achat = 4,
    Annuler = 5,
    Quitter = 9,
};


int main()
{
    int choix = 0;

    int quantiteTotale = 0;
    double sousTotal = 0;
    string billetsImpression = "";

    while (true)
    {
        // Afficher menu de la billeterie
        afficherMenu();

        // Lire le choix du menu de l'utilisateur
        cout << "Entrer votre choix : ";
        cin >> choix;

        switch (choix)
        {
        case ChoixMenu::Cinema: {
            cout << "\n--- Achat de billets de cinema ---\n\n";

            sousTotal = acheterBilletsCinema(sousTotal, quantiteTotale, billetsImpression);
            break;

        case ChoixMenu::Bowling:
        {
            sousTotal = acheterBilletsBowling(sousTotal, quantiteTotale, billetsImpression);
        }
        break;

        case ChoixMenu::Musee:
        {
            cout << "\n--- Achat de billets de musee ---\n\n";

            // Lire le nombre de billets à ajouter à l'achat en cours
            cout << "Entrer le nobre d'adultes : ";
            int quantiteAdulte;
            cin >> quantiteAdulte;

            // Lire le nombre de billets à ajouter à l'achat en cours
            cout << "Entrer le nombre d'enfants : ";
            int quantiteEnfants;
            cin >> quantiteEnfants;

            // Mettre à jour le sous-total avec le cout des billets
            sousTotal += quantiteAdulte * PRIX_BILLER_MUSEE_ADULTE;

            // Generer les billets pour l'impression apres l'achat
            for (int i = 0; i < quantiteAdulte; i++)
            {
                ++quantiteTotale;
                billetsImpression += format("{}. Billet de musee adulte ({:.2f}$)\n", quantiteTotale, PRIX_BILLER_CINEMA);
            }

            for (int i = 0; i < quantiteEnfants; i++)
            {
                ++quantiteTotale;
                billetsImpression += format("{}. Billet de musee enfant (gratuit)\n", quantiteTotale);
            }

            // Afficher un message à l'utilisateur avec la quantite de billets totale et le sous-total avant taxes
            cout << "\n----------------------------------\n";
            cout << format("Nombre de billets : {}\n", quantiteTotale);
            cout << format("Sous-total : {:.2f}$\n", sousTotal);
            cout << "----------------------------------\n";
        }
        break;

        case ChoixMenu::Achat:
        {
            effectuerAchatBillets(sousTotal, quantiteTotale, billetsImpression);
            effacerInformationsBillets(sousTotal, quantiteTotale, billetsImpression);
        }
        break;

        case ChoixMenu::Annuler:
        {
            cout << format("\nAchat de {} billets annule, debut d'un nouvel achat...\n\n", quantiteTotale);
            effacerInformationsBillets(sousTotal, quantiteTotale, billetsImpression);
        }
        break;

        case ChoixMenu::Quitter:
            cout << "\nFermeture de la billetterie\n\n";
            system("pause");
            return 0;

        default:
            cout << format("\nChoix invalide '{}', entrer un nouveau choix...\n\n", choix);
            break;
        }
        }
    }

}