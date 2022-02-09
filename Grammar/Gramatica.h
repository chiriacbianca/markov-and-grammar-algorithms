#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>

using namespace std;

class Gramatica
{
public:
	int citireFisier = 0;
	string vN;
	string vT;
	char simbolStart;
	vector<string> sirProductii;
	vector<string> sirStanga;
	vector<string> sirDreapta;

	Gramatica();

	void citire(const char* numeFisier);
	void afisare();
	void generare();
};