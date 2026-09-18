


//	Auteur : Xavier Blanchete
//	Date : 2026-08-24
//	Description : Devoir 06



#include <iostream>
#include <string>
#include <format>
using namespace std;

int main()
{
    setlocale(LC_ALL, "fr_CA.UTF-8");

    cout << "Entrer une note finale [A, B, C, D, F] :\n";
    char choixNote;
    cin >> choixNote;

    switch (choixNote)
    {
    case 'A':
    case 'a':
        cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.\n", 90, 100);
        break;

    case 'B':
    case 'b':
        cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.\n", 80, 89);
        break;

    case 'C':
    case 'c':
        cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.\n", 70, 79);
        break;

    case 'D':
    case 'd':
        cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.\n", 60, 69);
        break;

    case 'F':
    case 'f':
        cout << format("La note de l’étudiant était entre {} et {} à la fin du cours.\n", 0, 59);
        break;

    default:
        cout << "La note finale {} est invalide, entrer une note finale : A, B, C, D ou F. \n", choixNote;
        break;
    }
}