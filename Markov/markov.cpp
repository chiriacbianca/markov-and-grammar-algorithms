#include "Markov.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <conio.h>

using namespace std;

Markov::Markov()
{
}

void Markov::citire(const char* numeFisier)
{
	if (citireFisier == 0)
	{
		ifstream fis(numeFisier);
		if (fis.is_open())
		{
			getline(fis, alfabetV, '\n');
			size_t f = alfabetV.find_first_of(",");
			while (f != string::npos)
			{
				alfabetV.erase(f, 1);
				f = alfabetV.find_first_of(",", f);
				numarCaractereAlfabet = (int)alfabetV.size();
			}
			string regulaMarkov;
			
			while (!fis.eof())
			{
				getline(fis, regulaMarkov, '\n');
				sirReguli.push_back(regulaMarkov);
				size_t separator = regulaMarkov.find_first_of("-");
				sirStanga.push_back(regulaMarkov.substr(0, separator));
				sirDreapta.push_back(regulaMarkov.substr(separator+2));
			}
		}
	}
	citireFisier = 1;
}

void Markov::afisare()
{
	for (int i = 0; i < numarCaractereAlfabet-1; i++)
	{
		cout << alfabetV[i] << ", ";
	}
	cout << alfabetV[numarCaractereAlfabet - 1];
}

bool Markov::verificareCuvant(string cuvant)
{
	int apartineAlfabetului;
	for (int i = 0; i < size(cuvant); i++)
	{
		apartineAlfabetului = 0;
		for (int j = 0; j < numarCaractereAlfabet; j++)
		{
			if (cuvant[i] == alfabetV[j])
				apartineAlfabetului = 1;
		}
		if (apartineAlfabetului == 0)
			return false;
	}
	return true;

}

void Markov::derivareCuvant(string cuvant)
{
	if (verificareCuvant(cuvant))
	{
		cout << cuvant << "|-";
		bool derivabil = true;
		while (derivabil==true)
		{
			for (int i = 0; i < sirStanga.size(); i++)
			{
				if (cuvant.find(sirStanga[i]) != string::npos)
				{
					int pozitieStart = cuvant.find(sirStanga[i]);
					cuvant.replace(pozitieStart, sirStanga[i].length(), sirDreapta[i]);
					cout << " (regula:" << i + 1 << ") " << cuvant;
					derivabil = true;
					break;
				}
				else
					derivabil = false;
			}
		}
		
	}
	//pentru lamda am nu am pus nimic dupa -> in fisierul de citire, deci se sterge subsirul, astfel fiind element neutru
}

