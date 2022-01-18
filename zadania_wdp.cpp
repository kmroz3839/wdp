#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <cstdlib>

using namespace std;

void wypisz(int w)
{
	cout << w << endl;
}
void wypisz(vector<int> tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		cout << tab[i] << ", ";
	}
}
void wypisz(map<int, int> m)
{
	for (auto item : m)
	{
		cout << item.first << "->" << item.second << endl;
	}
}

bool czyNalezy(vector<int> tab, int element)
{
	for (int i = 0; i < tab.size(); i++)
	{
		if (tab[i] == element)
		{
			return true;
		}
	}
	return false;
}
bool czyZawiera(vector<int> tab, vector<int> tab1)
{
	for (int i = 0; i < tab1.size(); i++)
	{
		if (!czyNalezy(tab, tab1[i]))
		{
			return false;
		}
	}
	return true;
}
vector<int> unikalnosc(vector<int> tab)
{
	vector<int>wynik;
	for (int i = 0; i < tab.size(); i++)
	{
		if (!czyNalezy(wynik, tab[1]))
		{
			wynik.push_back(tab[i]);
		}
	}
	return wynik;
}

bool czyNalezyKlucz(map<int, int> m, int element)
{
	for (auto item : m)
	{
		if (item.first == element)
		{
			return true;
		}
	}
	return false;
}
map<int, int> czestosc(vector<int> tab)
{
	map<int, int>wynik;
	for (int i = 0; i < tab.size(); i++)
	{
		if (!czyNalezyKlucz(wynik, tab[i]))
		{
			wynik.insert({ tab[i],1 });
		}
		else
		{
			wynik[tab[i]]++;
		}
	}
	return wynik;
}
int min(vector<int> tab)
{
	int wynik = tab[0];
	for (int i = 0; i < tab.size(); i++)
	{
		if (wynik > tab[i])
		{
			wynik = tab[i];
		}
	}
	return wynik;
}
vector<int> podzielnosc(vector<int> tab, int dzielnik, int reszta = 0)
{
	vector<int> wynik;
	for (int i = 0; i < tab.size(); i++)
	{
		if (tab[i] % dzielnik == reszta)
		{
			wynik.push_back(tab[i]);
		}

	}
	return wynik;
}
vector<int> generuj(int ilosc, int max, int min)
{
	vector<int> wynik;
	for (int i = 0; i < ilosc; i++)
	{
		wynik.push_back(rand() % (max - min) + min);
	}
	return wynik;
}

bool palindrom(vector<int> tab){
	int argc = tab.size()/2;
	for (int x = 0; x != argc; x++){
		if (tab[x] != tab[tab.size()-1-x]){
			return false;
		}
	}
	return true;
}