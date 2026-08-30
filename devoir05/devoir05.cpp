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

	cout << "Entrer la largeur du rectangle : ";
		int largeurRectangle;
	cin >> largeurRectangle;

	cout << "Entrer la hauteur du rectangle : ";
		int hauteurRectangle;
	cin >> hauteurRectangle;

	if (largeurRectangle <= 0)
	{
		cout << format( "Erreur : largeur ne peut être 0 ou négative.");
	}
	if (hauteurRectangle <= 0)
	{
		cout << format( "Erreur : hauteur ne peut être 0 ou négative.");
	}

else if (largeurRectangle == hauteurRectangle)
{
	cout << format("Carré {} par {}\n", largeurRectangle, hauteurRectangle);
}
else if (largeurRectangle > hauteurRectangle)

{
	cout << format("Rectangle {} par {}\n", largeurRectangle, hauteurRectangle); 

		double ratioHauteur = largeurRectangle / hauteurRectangle;


	cout << format("{:.3f} % plus large que haut\n", ratioHauteur);

}
else
cout << format("Rectangle {} par {}\n", largeurRectangle, hauteurRectangle);
cout << format("Plus haut que large\n");


double ratioHauteur = hauteurRectangle / largeurRectangle ;


cout << format("{:.3f} % plus haut que large\n", ratioHauteur);

	double aire = largeurRectangle * hauteurRectangle;
	double Perimetre = 2 * (largeurRectangle + hauteurRectangle);

		cout << format("Aire : {:.2f}\n", aire);
	cout << format("Perimètre : {:.2f}\n", Perimetre);

	system("pause"); 			system("cls");
}
