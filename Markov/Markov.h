#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>

using namespace std;

class Markov
{
public:
	int citireFisier = 0;
	int numarCaractereAlfabet;
	string alfabetV;
	vector<string> sirReguli;
	vector<string> sirStanga;
	vector<string> sirDreapta;

	Markov();
	void citire(const char* numeFisier);
	void afisare();
	bool verificareCuvant(string cuvant);
	void derivareCuvant(string cuvant);
};
