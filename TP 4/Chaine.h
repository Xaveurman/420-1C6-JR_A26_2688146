#pragma once

#include <string>
#include <vector>

using namespace std;

string toLower(string chaineCopie);
string toUpper(string chaineCopie);
string trim(const string& chaine);

vector<string> split(const string& chaine, char delimiteur);

bool tryParseInt(const string& chaine, int& entier);
bool tryParseLongLong(const string& chaine, long long& nombreLong);
bool tryParseDouble(const string& chaine, double& nombreVirgule);