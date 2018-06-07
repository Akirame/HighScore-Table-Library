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
		Data* GetDataFromScore(int score);
		Data* GetDataFromPosition(int position);
		int GetPositionFromScore(int score);
		int GetPositionFromName(string name);
		void ClearList();
		void ShowListInConsole();
		void SortByName();
		void SortByScore();
	};
}
#endif
