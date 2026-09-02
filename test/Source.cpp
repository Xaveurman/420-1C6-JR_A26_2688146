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





cout << "Nombre de billets achetes : ";
double personne;
cin >> personne;

double coutBillet = personne * 29.99;

if (personne < 20)
{
	cout << format("Aucun rabais\n\n");
	double rabais = 0;
	double total = coutBillet + rabais;

	cout << format("Sous-total : {:.2f} $\n", coutBillet);
	cout << format("Rabais : 0%\n", rabais);
	cout << format("Rabais : {:.2f} $\n", total);
}
else if (personne > 50)
{
	cout << format("25 % de rabais\n\n");

	double rabais = coutBillet * 0.25;
	double total = coutBillet + rabais;


	cout << format("Sous-total : {:.2f} $\n", coutBillet);
	cout << format("Rabais : 25%\n", rabais);
	cout << format("Rabais : {:.2f} $\n",total );
}

else if (personne > 20)
{
	cout << format("10 % de rabais\n\n");
	double rabais = coutBillet * 0.50;
	double total = coutBillet + rabais;

	cout << format("Sous-total : {:.2f} $\n", coutBillet);
	cout << format("Rabais : 10%\n", rabais);
	cout << format("Rabais : {:.2f} $\n", total);
}






}