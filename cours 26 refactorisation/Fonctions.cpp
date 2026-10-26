#include <format>
#include <iostream>
#include <string>
#include "Fonctions.h"
#include "Constantes.h"

using namespace std;


void afficherMenu()
{
    cout << "****************** BILLETTERIE ******************\n";
    cout << "\n";
    cout << format("1. Cinema  ({:.2f} $ par billet)\n", PRIX_BILLER_CINEMA);
    cout << format("2. Bowling ({:.2f} $ par billet)\n", PRIX_BILLER_BOWLING);
    cout << format("3. Musee   ({:.2f} $ par adultes, gratuit pour enfants)\n", PRIX_BILLER_MUSEE_ADULTE);
    cout << "\n";
    cout << "4. Payer\n";
    cout << "5. Annuler achat\n";
    cout << "\n";
    cout << "9. Quitter\n";
    cout << "\n";
}

double acheterBilletsCinema(double sousTotal, int& quantiteTotale, string& billetsImpression)
{
    // Lire le nombre de billets à ajouter à l'achat en cours
    cout << "Entrer le nombre de billets : ";
    int quantite = 0;
    cin >> quantite;

    // Mettre à jour le sous-total avec le cout des billets
    sousTotal += quantite * PRIX_BILLER_CINEMA;

    // Generer les billets pour l'impression apres l'achat
    for (int i = 0; i < quantite; i++)
    {
        ++quantiteTotale;
        billetsImpression += format("{}. Billet de cinema ({:.2f}$)\n", quantiteTotale, PRIX_BILLER_CINEMA);
    }

    // Afficher un message à l'utilisateur avec la quantite de billets totale et le sous-total avant taxes
    cout << "\n----------------------------------\n";
    cout << format("Nombre de billets : {}\n", quantiteTotale);
    cout << format("Sous-total : {:.2f}$\n", sousTotal);
    cout << "----------------------------------\n";

    return sousTotal;
}
double acheterBilletsBowling(double sousTotal, int& quantiteTotale, string& billetsImpression)
{
    cout << "\n--- Achat de billets de bowling ---\n\n";

    // Lire le nombre de billets à ajouter à l'achat en cours
    cout << "Entrer le nombre de billets : ";
    int quantite = 0;
    cin >> quantite;

    // Mettre à jour le sous-total avec le cout des billets
    sousTotal += quantite * PRIX_BILLER_BOWLING;

    // Generer les billets pour l'impression apres l'achat
    for (int i = 0; i < quantite; i++)
    {
        ++quantiteTotale;
        billetsImpression += format("{}. Billet de bowling ({:.2f}$)\n", quantiteTotale, PRIX_BILLER_BOWLING);
    }

    // Afficher un message à l'utilisateur avec la quantite de billets totale et le sous-total avant taxes
    cout << "\n----------------------------------\n";
    cout << format("Nombre de billets : {}\n", quantiteTotale);
    cout << format("Sous-total : {:.2f}$\n", sousTotal);
    cout << "----------------------------------\n";

    return sousTotal;
}
double acheterBilletsMusee(double sousTotal, int& quantiteTotale, string& billetsImpression)
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

        // Afficher un message à l'utilisateur avec la quantite de billets totale et le sous-total avant taxes
        cout << "\n----------------------------------\n";
        cout << format("Nombre de billets : {}\n", quantiteTotale);
        cout << format("Sous-total : {:.2f}$\n", sousTotal);
        cout << "----------------------------------\n";
    }
    return sousTotal;
}
void effectuerAchatBillets(double sousTotal, int quantiteTotale, string billetsImpression)
{
    // Calculer la taxe sur le sous-total
    double taxe = sousTotal * TAUX_TAXE;
    double total = sousTotal + taxe;

    // Afficher les informations de la transaction suivi des billets
    cout << "\n--- Confirmation achat ---\n\n";
    cout << format("Nombre de billets : {}\n", quantiteTotale);
    cout << format("Sous-total        : {:.2f}$\n", sousTotal);
    cout << format("Taxe              : {:.2f}$\n", taxe);
    cout << format("Total             : {:.2f}$\n", total);

    cout << "\n--- Impression des billets ---\n\n";
    cout << billetsImpression;

    cout << "\nFin de la transaction, debut d'un nouvel achat...\n\n";

}
void effacerInformationsBillets(double& sousTotal, int& quantiteTotale, string& billetsImpression)
{
    // Effacer les informations des billets afin de démarrer un nouvel achat sans aucun billets
    quantiteTotale = 0;
    sousTotal = 0;
    billetsImpression = "";
}