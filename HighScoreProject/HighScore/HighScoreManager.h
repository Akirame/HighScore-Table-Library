#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H
#include <iostream>
#include <list>
#include <string>
#include "Data.h"

using namespace std;
using namespace data;

namespace hscore
{
	class HighScore
	{
	private:
		list<Data*>* scoreList;
		list<Data*>::iterator iter;
		void ToUpper(string& word);
	public:
		HighScore();
		~HighScore();
		void AddScore(string name, int points);
		Data* GetDataFromName(string name);
		void ClearList();
		void ShowList();
		void SortByName();
		void SortByScore();
	};
}
#endif
