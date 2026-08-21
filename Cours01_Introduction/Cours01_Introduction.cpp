// TODO: Ajouter un en-tête (Auteur, Date, Description)
/*
    Auteur : Xavier Blanchette
    Date : 2026-08-20
    Description : Introduction à la programmation
*/

// Commentaire !

/*
    Commentaire
    sur
    plusieurs
    lignes !
*/

// *** Astuces pour bien démarrer dans Visual Studio ***
// 1. Utilisez la fenêtre Explorateur de solutions pour jouter des fichiers et les gérer.
// 2. Utiliser le menu Affichage pour rouvrir les écrans fermés
// 3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
// 4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
// 5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
// 6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

// *** Raccourcis claviers ***
// 1. Déboguer le programme               : F5 ou Déboguer > Démarrer le débogage
// 2. Exécuter le programme               : Ctrl+F5 ou Déboguer > Exécuter sans débogage
// 3. Arrêter le programme                : Shift+F5 ou Déboguer > Arrêter le débogage
// 4. Aligner des éléments                : Tab, Shift+Tab
// 5. Couper, copier et coller            : Ctrl+X Ctrl+C Ctrl+V
// 6. Annuler et rétablir les changements : Ctrl+Z Ctrl+Y
// 7. Sélectionner tout                   : Ctrl+A
// 8. Sauvegarder                         : Ctrl+S Ctrl+Shift+S
// 9. Commenter ou décommenter une ligne  : Ctrl+K,C et Ctrl+K,U
// 10. Déplacer des lignes                : Ctrl+Shift+Up Ctrl+Shift+Down
// 11. Dupliquer une ligne                : Cliquer sur la ligne sans sélectionner et Ctrl+C,Ctrl+V
// 12. Supprimer une ligne                : Cliquer sur la ligne sans sélectionner et Ctrl+X

// Librairie <iostream> avec le code permettant l'utilisation de std::cout pour écriture à la Console
#include <iostream>

// Fonction 'main()' exécutée par défaut au lancement du programme. 
// L'exécution du programme commence au symbole '{' et se termine au symbole '}'.
int main()
{
    // *** Écriture à la Console ***
    // std::cout    Écrire à la Console à l'aide de la librairie contenue dans <iostream> (Console Out)
    // <<           Séparer les différents éléments à écrire à la Console, plusieurs possible
    // ""           Indique le début et la fin d'une chaîne de caractères (couleur orange)
    // \n           Caractère spécial pour sauter à la prochaine ligne de la Console
    // ;            Indique la fin d'une instruction
    std::cout << "--- Cours 01 - Introduction ---\n\n\n\n";

    // Exemple d'écriture d'une 2ème ligne à la Console avec plusieurs éléments
    // Attention
    // - Ajouter un espace après le : afin que le nom ne soit pas collé
    // - Ne pas oublier les guillemets pour chaque éléments (regarder la couleur orange)
    // - Ne pas oublier le point virgule (;) à la fin de la ligne

    // TODO: Ajouter une sortie à la Console avec votre nom
std:: cout << "Mon nom est : Xavier Blanchette\n\n";


    // *** Erreurs de compilation ***
    // Langages de programmation sont comme les langues (français, anglais, etc.) :
    // - Vocabulaire, orthographe (mots clés)
    // - Syntaxe
    // 
    // Ne pas respecter le langage donne une erreur de compilation
    // - Empêche de compiler et d'exécuter le programme
    // - Toujours refuser de démarrer le dernier programme compilé
    // - Régler les erreurs et recompiler le programme
    //
    // Dans Visual Studio
    // - Erreurs apparaissent avec une description dans la fenêtre Affichage > Liste d'erreurs
    // - Soulignement du texte
    //      - Erreurs : Soulignées en rouge
    //      - Avertissements : Souligné en jaune
    // - Corriger tout de même les avertissements comme s'ils étaient des erreurs de compilation
    //
    // Erreur E0007) Texte à l'extérieur de la chaîne de caractères
    //std::cout << "Erreur : Texte a l'exterieur de la chaine de caracteres"; oups \n
    //
    // Erreur E0020) Oublier de définir la librairie standard std:: avant cout
    //cout << "Erreur : pas de std:: avant cout\n";
    //
    // Erreur E0065) Oublier l'opérateur <<
    //std::cout "Erreur : pas d'opérateur <<\n";
    //
    // Erreur E0065) Oublier le point virgule à la fin 
    //std::cout << "Erreur : pas de point virgule\n"


    // TODO: Afficher le résultat du calcul 20 + 5 - 10 * 10 / 5
std::cout <<20 + 5 - 10 * 10 / 5;

    // TODO: Afficher l'équation et le résultat du calcul avec priorité des opérations 20 + ((5 - 10) * 10) / 5
    //       Besoin de 2 opérateurs (<<) pour afficher la chaine de caractère suivi du nombre calculé
std::cout << "\n\n20 + 5 - 10 * 10 / 5 = " << 20 + 5 - 10 * 10 / 5;
}

// TODO: Faire le Devoir à la maison