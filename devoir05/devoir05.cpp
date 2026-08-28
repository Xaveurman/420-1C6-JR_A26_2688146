/*
	Auteur : Xavier Blanchete
	Date : 2026-08-24
	Description : Devoir 05 
*/

#include <iostream>
#include <string>
#include <format>

using namespace std;


int main()
{
	cout << "Entrer la largeur du rectangle : "
		int largeurRectangle;
	cin << largeur;

	cout << "Entrer la hauteur du rectangle : ";
	string haut_rectangle;
	cin >> haut_rectangle;

	if (largeurRectangle <= 0)
	{
		cout << "Erreur : largeur ne peut être 0 ou négative.";
	}
	else (haut_rectangle <= 0)
	{
		cout "Erreur : hauteur ne peut être 0 ou négative.";


else if (largeurRectangle == haut_rectangle)
{
	cout << format("Carré {} par {}\n", largeurRectangle);
}
else if (largeurRectangle > haut_rectangle) {
	cout << format("Rectangle {} par {}\n, largeurRectangle haut_rectangle); 

		double ratioHauteur = largeurRectangle / haut_rectangle;


	cout << format("{:3.f} % plus large que haut\n", ratioHauteur);

}
else
cout << format("Rectangle {} par {}\n", largeurRectangle, haut_rectangle);
cout << "Plus haut que large\n";


Ratio = haut_rectangle / largeur;


cout << format("{:.3f} % plus haut que large\n", Ratio);
	}

	double a = largeurRectangle * haut_rectangle;
	double PERIMÈTRE = 2 * (largeurRectangle + haut_rectangle)


		cout << format("Aire : {:.2f}\n", a);
	cout << format("Perimètre : {:.2f}\n", PERIMÈTRE);

	system("pause"); 			system("cls";
}
