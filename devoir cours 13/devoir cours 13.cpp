//	Auteur : Xavier Blanchete
//	Date : 2026-09-18
//	Description : Devoir cours 013



#include <iostream>
#include <string>
#include <format>
using namespace std;

int main()
{
	setlocale(LC_ALL, "fr_CA.UTF-8");

	// Exercice 1
	if (true)
	{
	int nombre = -1; // pas 0
	int compteurNombresValides = 0;

	while (nombre != 0)
	{
		cout << "Entrer un nombre (0 pour quitter) : ";
		cin >> nombre;
		cout << format("nombre {} entré !\n\n",nombre);
		compteurNombresValides = compteurNombresValides + 1;
	} 

	cout << format("Fin de la lecture des nombres ({} nombres lus) ! ",compteurNombresValides - 1);
}











}