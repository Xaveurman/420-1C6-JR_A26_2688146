// TODO: Ajouter un en-tête

#include <iostream>

int main()
{
    std::cout << "--- Cours 02 - Git ---\n";

    // *** Region ***
    // - Englobe une partie de code de plusieurs lignes ensemble
    // - Réduire le code avec la flèche à gauche
    // - Commenter rapidement une fois réduit avec Ctrl+K,C ou Ctrl+K,U
    //      - Fonctionne mieux en sélectionnant aussi la ligne après pour décommenter
    // - Pour créer une région utiliser le snippet de code prédéfini
    //		- Écrire 'region' puis faire Tab

#pragma region Theorie

#pragma region Ordinateur
    // *** Fonctionnement d'un ordinateur ***
    // Binaire
    // - Bits : 0 ou 1
    // - Hexadécimal (Base 16) : 0 1 2 3 4 5 6 7 8 9 A B C D E F
    //      - 0xF = 1111 en binaire = 15 en décimal
    // - Pièces d'un ordinateur fonctionnent uniquement en binaire
    // - Nombres, texte, images, etc. sont encodés en binaire
    // 
    // Processeur
    // - Exécuter les opérations des programmes en mémoire
    // - Faire les demandes de lecture et écriture de fichier au système d'exploitation
    // - Taille très petite d'espaces (8 registres)
    // 
    // Mémoire
    // - Contenir les programmes et les résultats des programmes
    // - Perdu lorsque l'ordinateur est éteint
    // - Taille moyenne d'espace (32 GB = 32 000 000 000 bits)
    // 
    // Disque dur
    // - Conserver les programmes et les résultats des programmes à long terme
    // - Conservé lorsque l'ordinateur est éteint
    // - Taille large d'espace (1 TB = 1 000 000 000 000 bits)
#pragma endregion

#pragma region Compilation
    // *** Fonctionnement de la compilation d'un programme ***
    // 1) Code source (C++)
    //    - Instructions écrites en texte selon la syntaxe du langage de programmation
    // 
    // 2) Compilation
    //    - Instructions machines (x86, x64)
    //          - Processeurs on une table d'instruction possible avec des codes binaires associés (opcode)
    //          - Windows
    //              - https://en.wikipedia.org/wiki/X86_instruction_listings
    //              - x64 : 64 bits
    //              - x86 : 32 bits (rarement utilisé de nos jours)
    //    - Transformation du code source en code compilé (instruction machines binaires)
    //          - 5 + 10
    //              - Transformation en assembleur
    //                  - mov eax, 5        // Déplacer 5 dans le registre EAX
    //                  - mov ebx, 10       // Déplacer 10 dans el registre EBX
    //                  - add eax, ebx      // Additionner les registre EAX et EBX
    //                  - mov 0x1234 eax    // Écrire en mémoire la réponse contenu dans le registre EAX
    //              - Transformer en binaire sur la table d'instruction de la platforme (ex. x64)
    //                  - Peut maintenant être contenu sur le disque dur, en mémoire et envoyé au processeur
    //                  - Uniquement fonctionnel les processeurs de cette platforme (ex. x64)
    //    - Erreurs de syntaxe
    //          - Code ne peut être traduit en instructions machines
    //          - Exemble 1) 100 $ 20;
    //              - $ n'est pas une instruction machine existante
    //          - Eexemple 2) 10 +;
    //              - Instruction machine pour l'addition + (ADD) demande 2 nombres à additionner ensemble
    // 
    // 3) Édition de liens (Linking)
    //    - Remplacer les notes vers librairies et autres symboles avec des instructions machines (binaire)
    //    - Programme et librairies sont compilés dans plusieurs fichiers différents pour l'instant
    //          - Notes dont ajoutés pour remplacer plus tard les appels
    //          - Ex. std::cout
    //    - Liaison statique
    //          - Liens sont remplacés par le code compilé des fichiers précédents (ex. code compilé des librairies)
    //          - Un seul fichier éxécutable (.exe) est créé
    //    - Liaison dynamique
    //          - Librairies sont compilées dans un fichier de libraries dynamique en instructions machines
    //          - Liens sont remplacés par un appel au bon endroit aux instructions machines du fichier dynamique
    //          - Un fichier exécutables (.exe) et une ou plusieurs fichiers Dynamic-link library (.dll)
    //    - Erreurs de linking
    //          - Liens manquants vers certains éléments utilisés (ex. librairies, fonctions, etc.)
    // 
    // 4) Exécutable (.exe)
    //    - Programme complet entièrement en instructions machines (binaire)
#pragma endregion

#pragma region FichiersVisualStudio
    // TODO: Ouvrir le dossier du projer et regarder les fichiers

    // *** Solution ***
    // .sln             : Contient des liens vers différents fichiers de projet
    // .vs/             : (Généré automatiquement) 
    //                    Contient la base de données des configurations des projets de la Solution
    //                    Contient la base de données des configurations des projets de la Solution
    // x64/Debug/       : (Généré automatiquement)
    //                    Exécutables des projets compilés (.exe)
    //                    Fichiers de débogage (.pdb)


    // *** Projet ***
    // .vcxproj         : Configuration du projet
    // .vcxproj.filters : Ajout des fichiers au projet
    // .vcxproj.user    : (Généré automatiquement)
    //                    Configuration locale Visual Studio de l'utilisateur pour l'édition du projet
    // .cpp             : Code source C++ du programme
    // 
    // x64/Debug/       : (Généré automatiquement) 
    //                    Fichiers compilés du programme afin de créer l'exécutable du projet (artefacts)
    //                    Parfois, ces fichiers contiennent des informations erronées et il faut les supprimer
    // x64/Debug/.obj   : Code source compilé avec des bouts de code non liés (manquant)
    // x64/Debug/.idb   : Base de données incrémentale de code source compilé afin les réutiliser et de compiler plus rapidement
    // x64/Debug/.ilk   : Base de données incrémentale de bouts de code source à lier 
    //                    Ex. std::cout de <iostream>
    // x64/Debug/.pdb   : Base de données des éléments du programme (symboles) afin de pouvoir utiliser le débogueur

    // TODO: Supprimer les fichiers générés automatiquement et recompiler
#pragma endregion

#pragma region Git
    // *** Git ***
    // Gestionnaire de code source (Source Code Manager SCM)
    // - Base de données permettant d'enregistrer des changements à des fichiers en plusieurs versions
    // - Similaire à OneDrive, mais plus de puissance
    // 
    // Avantages
    // - Décider quels fichiers envoyer, pas tous en même temps
    // - Décider quand les sauvegarder, pas tout le temps
    // - Travailler à plusieurs en même temps et gérer les conflits (Voir Cours 3)

    // *** Composantes de Git ***
    // Répertoire (Repository)
    // - Base de données contenant différentes versions incrémentales des fichiers dans des commits
    // 
    // Commit
    // - Différences de plusieurs fichiers englobées ensemble
    // - Point de sauvegarde qui permet de retourner à cette version des fichiers
    // - Identifiant SHA-1 généré automatiquement
    //      - a7de54f235..., 35ef4bg741..., etc.
    // - Commentaire descriptif saisi par le programmeur pour expliquer le contenu du commit
    // 
    // Diff
    // - Différence incrémentale d'un fichier avec la dernière version du fichier
    // - Chaque fichier modifié d'un commit a un diff avec la version précédente du fichier
    // - Fonctionne 
    //      - Bien avec les fichiers textes (.txt, .sln, .vcxproj, .cpp, etc.)
    //      - Mal pas avec fichiers binaires ou encodés (.exe, images, Word, Excel, etc.)
    //          - Trouver les différences est impossible
    //          - Contenu entier du fichier doit être enregistré dans le commit (lourd!)
    //          - Existe d'autres gestionnaire de source plus adapté pour ce type de fichiers (ex. Perforce)

    // *** Zones Git ***
    // Zone Locale (sur votre ordinateur)
    // 1) Local repository
    // - Base de données locale contenant les versions des différents fichiers en commits
    //      - Dossier caché /.git à la racine du dossier principal
    // - Souvent appelé 'main' ou 'master'
    // - Permet de revenir à une des versions antérieure en spécifiant l'identifiant d'un commit
    // 
    // 2) Workspace (Working Directory)
    // - Modifications locales encore non enregistrées dans Git
    // - Fichiers actuels sur le disque du de l'ordinateur avec les modifications
    // 
    // 3) Staging Area (Index)
    // - Modifications locales sélectionnées pour le prochain commit local
    // - Permet de sélectionner seulement certaines au lieu d'être forcer de tout ajouter au prochain commit
    // - Vidée automatiquement après un commit
    // 
    // Zone Remote (sur le serveur GitHub)
    // 1) Remote repository (Upstream Repository)
    // - Base de données locale contenant les versions des différents fichiers en commits
    // - Souvent appelé 'origin/main' ou 'origin/master'
    // - Enregistré sur un serveur (souvent GitHub) avec le même contenu que le répertoire de la Zone locale
    //          - Dossier caché /.git avec la base de données Git
    //          - Version des fichiers du dernier commit
    // - Peut faire une copie locale (clone) de la base de données Git et des fichiers 

    // *** Exemples de fonctionnement Git ***
    // https://git-school.github.io/visualizing-git/#free-remote

    // *** Concepts plus avancés ***
    // Branche
    // - Permet de travailler de façon parallèle sur des changements, par exemple à plusieurs
    // - Concept ne sera pas utilisé dans le cours pour simplicité (Voir Cours 3)
    //      - Seules branches utilisées 'main' (locale) et 'origin/main' (remote)
    // 
    // HEAD
    // - Raccourci pour désigner le commit le plus récent d'une branche
    // - main/HEAD (ou HEAD)
    //      - Commit le plus récent sur le répertoire local
    // - origin/main/HEAD (ou origin/HEAD)
    //      - Commit le plus récent sur le répertoire du serveur GitHub
#pragma endregion

#pragma region GitHub
    // *** GitHub ***
    // Serveur qui permet d'héberger des répertoires Git en ligne de façon gratuite
    // 
    // TODO: Créer un répertoire Git sur GitHub pour les exercices du cours et les Travaux Pratiques (TP)
    // https://github.com/
    // 
    // 1) Repository name   : 1C6-A25-groupe-matricule
    // 
    // 2) Visibility type   : Private
    // - Empêche les autres utilisateurs d'avoir accès par défaut à votre répertoire
    // - Gratuit tant que les projets ne sont pas trop gros ou avec trop d'utilisateurs
    // 
    // 3) Add .gitignore   : Visual Studio
    // - Permet de ne pas envoyer des fichiers régénérés autoamtiquement par Visual Studio à partir du code source
    // - Évite d'enregistrer des fichiers inutiles dans la base de données Git
    // - Évite les conflits pour des fichiers qui changent tout le temps (ex. exécutables .exe)
#pragma endregion

#pragma region GitBash
    // *** Git Bash ***
    // Ligne de commandes permettant d'effectuer les diverses opérations Git
    // 
    // TODO: Installation de Git et Git Bash sur Windows
    // https://gitforwindows.org/
    // 
    // Ouvrir une fenêtre Console Git Bash
    //  - Explorateurs de fichiers Windows > Clic droit > Plus d'options > Open Git Bash here
    // 
    // Changer la taille par défaut du texte
    // - Clic droit sur la barre en haut > Options... > Text > Select... > Size > Ok > Save
    // 
    // Environnement Linux 
    // - Minimalist GNU for Windows 64-bits (MinG64)
    // - Description de la ligne de commandes
    //      - utilisateur@pc MING64 dossier (branche)
    // - Commandes Linux (voir cours Ordinateurs et systèmes d'exploitations)
    //      - ls, cd, etc.
    //      - Fonctionnent des commandes avec le concept de paramètres
    //          - Chaque espace délimite 
    //          - Ne pas oublier les espaces et les guillemets !
    //      - Exemple avec la commande pour créer des dossiers (mkdir)
    //          - mkdir a b c
    //              - Commande 'mkdir' avec 3 paramètres : 'a', 'b' et 'c'
    //              - Crée les dossiers 'a', 'b' et 'c'
    //          - mkdir "a b c"
    //              - Commande 'mkdir' 1 seul paramètre : "a b c"
    //              - Créer le dossier "a b c" avec des espace dans le nom du dossier
    //          - mkdira bc
    //              - Commande 'mkdira' avec 1 paramètre : 'bc'
    //              - Erreur : commande 'mkdira' n'existe pas
    //                  - bash: mkdira: command not found
#pragma endregion

#pragma region CommandesGit
    // *** Commandes Git ***
    // - Tous les outils (même graphiques) exécutent commandes en arrière-plan sur la base de données /.git
    // - Travailler sur n'importe quel outil est équivalent, même base de données /.git
    // 
    // Documentation avec toutes les commandes Git et les différentes Zones Git
    // - https://ndpsoftware.com/git-cheatsheet.html
    // - Cliquer sur Avancé > Procéder quand même...
    //
    // TODO: Exercices faire un exercice avec chaque commande Git
    // 
    // git --help
    // - Afficher les commandes de base avec des courtes descriptions
    // 
    // git clone <url-repertoire-github>
    // - Créer une copie locale du répertoire sur GitHub dans le dossier actuel
    //      - Trouver le URL sur GitHub sous le bouton Code
    //      - Endroit du disque dur qui n'est pas dans OneDrive (D:\<matricule>)
    //      - Faire une seule fois
    //      - Première fois seulement, ajouter le code du projet dans le dossier pour ajouter à Git
    //      - Possible de renommer ou déplacer le dossier au complet avec la base de données Git /.git
    // - Si Git est brisé
    //      - Faire simplement une nouveau clone du répertoire GitHub
    //      - Copier à la main les changements effectués dans le .cpp
    // 
    // git status
    // - Afficher l’état actuel du répertoire Git local
    // - Modifications courantes locales par rapport au dernier commit local
    // - Éléments du Staging Area (index) qui seront envoyés avec le prochain commit local
    // 
    // git diff
    // git diff --staged        (seulement fichiers du Staging Area)
    // - Afficher les changements entre la version actuelle des fichiers et leur dernier commit
    // - En-tête identifie le fichier et les lignes modifiées
    //      - @@ <ligne-debut>,<nombre-lignes-modifiées> @@ <nom-fichier>
    //      - Ex. @@ -15,2 +15,7 @@ main.cpp
    // - Lignes identifiées avec un symboles selon le type de changement
    //      + (Ajout)
    //      - (Suppression)
    // 
    // git log
    // - Afficher les derniers commits du répertoire Git local
    // 
    // git add <fichier-ou-dossier>
    // git add .                        (tous les fichiers du dossier actuel)
    // - Ajouter les fichiers dans le Staging Area (index) 
    // - Exemples
    //      - Ajouter seulement le fichier 'main.cpp'
    //          - git add main.cpp
    //      - Ajouter seulement les fichiers du dossier 'code'
    //          - git add code
    //      - Ajouter seulement les fichiers .cpp du dossier 'code'
    //          - git add code/*.cpp
    // 
    // git commit -m "Message" (ne pas oublier les guillemets!)
    // - Ajoute un nouveau commit local avec les changements courant contenu dans le Staging area (index)
    // - Commentaire descriptif saisi par le programmeur pour expliquer le contenu du commit
    //      - Verbe action + sujet
    //      - Ajouter XYZ, Supprimer XYZ, Déplacer XYZ, Remplacer XYZ, etc.
    // - Après avoir effectué un commit
    //      - git status
    //          - Commit de la branche locale a changé
    //          - Changements n’apparaissent plus comme temporaires dans le Workspace et le Stating Area
    //      - GitHub
    //          - Serveur Remote(origin) sur GitHub n’a pas les changements
    //          - Commit est seulement local pour l’instant
    // 
    // git push
    // - Envoyer les commits locaux manquants sur le serveur Remote (origin) GitHub
    // - Toujours vérifier sur GitHub que les changements sont bien présents
    // 
    // git pull
    // - Récupérer et appliquer les changements du serveur Remote (origin) GitHub dans la branche locale
    // - Toujours effectuer la commande avant de commencer à travailler
    //      - Ne peut être effectué si des changements locaux sont présents
    //      - Conflits si des commit locaux différents du serveur ont été ajoutés
    // 
    // 
    // git reset --hard
    // - Revient à l'état exact des fichiers du dernier commit local
    //      - Retire tous les éléments du Staging Area (index)
    //      - Annule tous les changements des fichiers
    //      - Note : aucun effet sur les fichiers qui n'étaient pas dans la base de données Git
    // - Utile pour annuler les modifications des fichiers effectuées sans le vouloir
    // - Utile pour éviter les conflits avant de faire un git pull
    //
    // git clean -fd
    // git clean -fdx       (aussi les éléments ignorés, ex. fichiers compilés)
    // - Supprime les éléments qui ne sont pas enregistrés dans la base de données Git
#pragma endregion

#pragma endregion

#pragma region Exercice
    // Effectuer les commandes Git nécessaires pour effectuer le sopérations suivantes
    // Coller (Ctrl+V) et mettre en commentaire (Ctrl+K,C) la commande sous chaque TODO

    // TODO: Afficher le statut des fichiers Git pour s'assurer qu'il n'y a pas de modifications actuelles


    // TODO: Ajouter dans le programme une écriture du message à la Console (cout) avec le texte "Modification 1"


    // TODO: Afficher le statut des fichiers Git pour s'assurer que seul le fichier cpp a changé (en rouge)


    // TODO: Ajouter tous les fichiers dans le Staging Area de Git


    // TODO: Afficher le statut des fichiers Git pour s'assurer que le fichier est bien dans le Staging Area de Git (en vert)


    // TODO: Enregistrer la modification dans la base de données locale de Git avec le message "Cours 02 - Git - Ajout de la Modification 1"


    // TODO: Afficher le status de Git pour vérifier que les fichiers ne sont plus en attente d'envoi dans le Staging Area


    // TODO: Vérifier sur GitHub que la modification n'a pas encore été envoyée sur le serveur GitHub


    // TODO: Pousser la modification sur GitHub


    // TODO: Vérifier sur GitHub que la modification n'a pas encore été envoyée sur le serveur GitHub


    // TODO: Supprimer l'en-tête et la théorie du document actuel


    // TODO: Afficher le status de Git pour vérifier que les fichiers ne sont plus en attente d'envoi dans le Staging Area


    // TODO: Revenir à la dernière version du Git enregistrée localement


    // TODO: Accepter le rechargement du fichier par Visual Studio et vérifier que l'en-tête et la théorie sont réapparus


    // TODO: Écrire le message à la Console "Modification 2" (cout) et l'envoyer sur GitHub avec le message "Cours 02 - Git - Ajout de la Modification 2"

#pragma endregion

    // TODO: Faire le Devoir à la maison
}