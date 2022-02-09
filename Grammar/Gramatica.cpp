#include "Gramatica.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <conio.h>
#include <time.h>

Gramatica::Gramatica()
{
	srand(time(0));
}

void Gramatica::citire(const char* numeFisier)
{
	if (citireFisier == 0)
	{
		ifstream fis(numeFisier);
		if (fis.is_open())
		{
			getline(fis, vN, '\n');
			size_t f = vN.find_first_of(",");
			while (f != string::npos)
			{
				vN.erase(f, 1);
				f = vN.find_first_of(",", f);
			}
			string regulaMarkov;

			getline(fis, vT, '\n');
		    f = vT.find_first_of(",");
			while (f != string::npos)
			{
				vT.erase(f, 1);
				f = vT.find_first_of(",", f);
			}

			string intermediar;
			getline(fis, intermediar, '\n');
			simbolStart = intermediar[0];

			string productie;
			while (!fis.eof())
			{
				getline(fis, productie);
				sirProductii.push_back(productie);
				size_t separator = productie.find("-");
				sirStanga.push_back(productie.substr(0, separator));
				sirDreapta.push_back(productie.substr(separator + 2, productie.length()-1));
			}
		}
	}
	citireFisier = 1;
}

void Gramatica::afisare()
{
	for (int i = 0; i < vN.size(); i++)
		cout << "multimea neterminalelor"<<vN[i] << " " << endl;
	for (int i = 0; i < vT.size(); i++)
		cout << "multimea terminalelor" << vT[i] << " " << endl;
	cout << "Simbolul de start: " << simbolStart << endl;
	for (int i = 0; i < sirProductii.size(); i++)
		cout << i << " " << sirProductii[i] << endl;
}

void Gramatica::generare()
{
	vector<int> sirIntermediar;
	cout << simbolStart << "|-";
	string cuvant(1, simbolStart);
	bool derivabil;
	int alegere = INT_MIN;
	do
	{
		derivabil = false;
		for (int i = 0; i < sirStanga.size(); i++)
		{
			if (cuvant.find(sirStanga[i]) != string::npos) 
			{
				derivabil = true;
				sirIntermediar.push_back(i);
			}
		}
		if (derivabil)
		{
			alegere = sirIntermediar[rand() % sirIntermediar.size()];
			int pozitieStart = cuvant.find(sirStanga[alegere]);
			cuvant.replace(pozitieStart, sirStanga[alegere].length(), sirDreapta[alegere]);
			cout << "(regula:" << alegere + 1 << ")" << cuvant << endl;
			sirIntermediar.clear();
		}
		
	} while (derivabil == true);
		
}
