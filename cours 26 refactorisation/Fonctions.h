#pragma once

#include <string>

using namespace std;


void afficherMenu();
double acheterBilletsCinema(double sousTotal, int& quantiteTotale, string& billetsImpression);
double acheterBilletsBowling(double sousTotal, int& quantiteTotale, string& billetsImpression);
double acheterBilletsMusee(double sousTotal, int& quantiteTotale, string& billetsImpression);
void effectuerAchatBillets(double sousTotal, int quantiteTotale, string billetsImpression);
void effacerInformationsBillets(double& sousTotal, int& quantiteTotale, string& billetsImpression);