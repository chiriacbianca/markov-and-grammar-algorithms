#include "Markov.h"
#include <iostream>
#include <string>
#include<fstream>
#include <conio.h>

using namespace std;

int main()
{
	string cuvant;
	

	Markov algoritmMarkov;

	int alegere = 1;
	algoritmMarkov.citire("markov.txt");

	while (alegere == 1)
	{
		cout << "introduceti cuvantul/fraza: " << endl;
		getline(cin, cuvant);
		algoritmMarkov.derivareCuvant(cuvant);
		cout << "\nDoriti sa mai derivati un cuvant? Apasati 1 pentru Da, orice alt numar pentru Nu" << endl;
		cin >> alegere;
	}
}
