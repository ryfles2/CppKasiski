#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <map>
#include <list>

using namespace std;

void main()
{
	//
	//polskie znaki w kosoli
	setlocale(LC_ALL, "");

	fstream f_files;
	fstream t_files;

	string s_from;
	string s_where;
	
	int szyfr = 0;


//	cout << "Nazwa pliku z którego czytamy" << endl;
//	cin >> s_from;
//	cout << "Nazwa pliku do którego zapisujemy" << endl;
//	cin >> s_where;
//	cout << "Podaj długść szyfru" << endl;
//	cin >> szyfr;
	s_from = "bOut.txt";
	s_where = "out6.txt";
	szyfr = 5;
	int l = 6;

	szyfr -= 1;

	f_files.open(s_from);
	t_files.open(s_where, ios::out);

	string t_string;
	string line;

	//zczytywanie linia po lini
	if (f_files.good())
	{
		std::cout << "Uzyskano dostep do pliku!" << std::endl;
		while (getline(f_files, line))
		{
			t_string += line;
		}
	}
	else
	{
		cout << "Dostep do pliku zostal zabroniony!" << endl;
	}
	
	string pom;

	for (auto& i : t_string)
	{
		if (i != 32 && 65 <= i && i <= 90) pom += i;
	}

	t_string = pom;

	map<string, list<int>> map;
	
	int max = 0;
	for (int i = 0; i < t_string.size() - szyfr; i++)
	{
		pom = t_string[i];
		for (int j = 0; j < szyfr; j++)
		{
			pom += t_string[i + j+1];
		}
		//cout << pom << endl;
		map[pom].push_back(i+1);
	}
	
	int licz = 0;
	for (auto& i : map)
	{
		t_files << i.first << " = "; 
		
		for (list<int>::iterator it = i.second.begin(); it != i.second.end(); ++it)
		{
			if (*it % l == 0) licz++;
			//t_files << *it << " ";
		}
		t_files << licz << " ";
		licz = 0;
//		for (list<int>::iterator it = i.second.begin(); it != i.second.end(); ++it)
//		{
//			//if (*it % l == 0) licz++;
//			t_files << *it << " ";
//		}
		t_files << endl;
	}

	f_files.close();
	t_files.close();
}