#pragma once


#include <string>

using namespace std;

struct livre
{
	int identifiantLivre = 0;
	string nomLivre = "";
	string auteur = "";
	int typeLivre = 0;
	int datePublication = 0;
	int nombreCopie = 0;
};