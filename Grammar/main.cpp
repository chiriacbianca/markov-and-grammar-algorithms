#include "Gramatica.h"
#include <iostream>
#include <string>
#include<fstream>
#include <conio.h>

using namespace std;

int main()
{

	Gramatica gramatica;
	int alegere=1;

	gramatica.citire("gramatica.txt");
	while (alegere == 1)
	{
		gramatica.generare();
		cout << "\nDoriti sa mai generati un cuvant? Apasati 1 pentru Da, orice alt numar pentru Nu" << endl;
		cin >> alegere;
	}
	
	
}