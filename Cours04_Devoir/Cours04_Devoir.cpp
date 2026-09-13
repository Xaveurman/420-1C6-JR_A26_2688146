/*
	Auteur : Xavier Blanchete
	Date : 2026-08-24
	Description : Devoir 04 entrées et sorties
*/


#include <iostream>

#include <string>

#include <format>

using namespace std;

int main()
{
	std::cout << "Devoir 04\n";

	// Exercice 1

	double a = 10.0 + 12 / 8.0;                        // 11.5 
	double b = 27.00 + 3 / 14.00;                      // 27.21 
	double c = (10 + 20.0000 + 30 + 40 + 50) / 11.0000;    // 13.6363... 
	int d = (int)c;                               // 13 
	double e = (180.00000000 / 7) + c / 2;                   // 32.2142... 
	double f = d / 15.0000;                           // 0.8666... 

	// Ex. ne donne pas la valeur attendue 11.5 

	cout << format("A = {:.2f}\n", a);
	cout << format("B = {:.4f}\n", b);
	cout << format("C = {:.3f}\n", c);
	cout << format("D = {}\n", d);
	cout << format("E = {:.8f}\n", e);
	cout << format("F = {:.4f}\n", f);


	// Exercice 2

	cout << "Entrer la valeur A : ";
	double aCalcule;
	cin >> aCalcule;

	cout << "Entrer la valeur B : ";
	double bCalcule;
	cin >> bCalcule;

	cout << "Entrer la valeur C : ";
	double cCalcule;
	cin >> cCalcule;

	double formule = (aCalcule * aCalcule * aCalcule) + (bCalcule * bCalcule) + cCalcule;

	cout << format("resultats formule {:.1f}^3 + {:.1f}^2 + {:.1f} = {:.2f}\n", aCalcule, bCalcule, cCalcule, formule);

	// Exercice 3

	cout << "Entrer le Numero de facture :";
	int numeroFacture;
	cin >> numeroFacture;

	cout << "Entrer le Nom du client :";
	string nomclient;
	cin >> nomclient;

	cout << "Entrer le Nom de l'article 1 :";
	string nomArticle1;
	cin >> nomArticle1;

	cout << "Entrer le Cout de l'article 1 :";
	double coutArticle1;
	cin >> coutArticle1;

	cout << "Entrer la Quantite de l'article 1 :";
	double quantiteArticle1;
	cin >> quantiteArticle1;

	cout << "Entrer le Nom de l'article 2 :";
	string nomArticle2;
	cin >> nomArticle2;

	cout << "Entrer le Cout de l'article 2 :";
	double coutArticle2;
	cin >> coutArticle2;

	cout << "Entrer la Quantite de l'article 2 :";
	double quantiteArticle2;
	cin >> quantiteArticle2;

	cout << "Entrer le Nom de l'article 3 :";
	string nomArticle3;
	cin >> nomArticle3;

	cout << "Entrer le Cout de l'article 3 :";
	double coutArticle3;
	cin >> coutArticle3;

	cout << "Entrer la Quantite de l'article 3 :";
	double quantiteArticle3;
	cin >> quantiteArticle3;

	cout << format("\n\nNumero de facture : {} \n", numeroFacture);
	cout << format("Nom du client : {} \n\n\n", nomclient);
	
	double sousTotalArticle1 = coutArticle1 * quantiteArticle1;
	double sousTotalArticle2 = coutArticle2 * quantiteArticle2;
	double sousTotalArticle3 = coutArticle3 * quantiteArticle3;

	cout << format("Nom de l'article	Cout		Quantite	sous-total \n");
	cout << format("{}			{:.2f} $	  {}		{:.2f} \n\n", nomArticle1, coutArticle1, quantiteArticle1, sousTotalArticle1);
	cout << format("{}			{:.2f} $	  {}		{:.2f} \n\n", nomArticle2, coutArticle2, quantiteArticle2, sousTotalArticle2);
	cout << format("{}			{:.2f} $	  {}		{:.2f} \n\n", nomArticle3, coutArticle3, quantiteArticle3, sousTotalArticle3);

	double sousTotal = sousTotalArticle1 + sousTotalArticle2 + sousTotalArticle3;

	cout << format("sous-total {:.2f}$ \n\n\n", sousTotal);

	double tps = sousTotal * 0.05;
	double tvq = sousTotal * 0.09975;

	cout << format("TPS :9.975 %		{:.2f} $\n", tps);
	cout << format("TVQ :5.000 %		{:.2f} $\n\n\n", tvq);

	double total = tps + tvq + sousTotal;
	
	cout << format("Total {:.2f} $ \n\n\n", total);

}
