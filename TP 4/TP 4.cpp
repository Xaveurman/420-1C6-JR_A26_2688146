//	Auteur : Xavier Blanchete
//	Date : 2026-11-16
//	Description : TP 4 BIBLIOTHÈQUE

#include <ctime>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Chaine.h"
#include "Constantes.h"
#include "Emprunt.h"
#include "Fichier.h"
#include "Livre.h"
#include "Membre.h"
#include "Reservation.h"
#include "Structs.h"

void afficherMenu(string& message);
using namespace std;

int main()
{
	string message = "";
	setlocale(LC_ALL, "fr_CA.UTF-8");
	afficherMenu(message);
}