#include "HighScoreManager.h"

namespace hscore
{
	bool CompareScore(const Data* d1,const Data* d2)
	{
		return (d1->GetScore() > d2->GetScore());
	}
	bool CompareName(const Data* d1, const Data* d2)
	{
		return (d1->GetName() > d2->GetName());
	}
	void HighScore::ToUpper(string& word	)
	{		
		for (int i = 0; i < word.length(); i++)
		{
			word[i] = toupper(word[i]);
		}
	}
	HighScore::HighScore()
	{
		scoreList = new list<Data*>();
	}
	HighScore::~HighScore()
	{
		scoreList->clear();
		delete scoreList;
	}
	void HighScore::AddScore(string name, int points)
	{
		Data* _data = new Data();
		ToUpper(name);		
		_data->SetName(name);
		_data->SetScore(points);
		scoreList->push_front(_data);
	}
	void HighScore::ClearList()
	{
		scoreList->clear();
	}
	Data* HighScore::GetDataFromName(string name)
	{		
		ToUpper(name);				
		for (iter = scoreList->begin(); iter != scoreList->end(); iter++)
		{
			if ((*iter)->GetName() == name)
			{
				return (*iter);
			}			
		}
		return NULL;		
	}
	void HighScore::ShowList()
	{
		for (iter = scoreList->begin(); iter != scoreList->end(); iter++)
		{
			cout << "NAME: " << (*iter)->GetName() << " - " << (*iter)->GetScore() << endl;
		}
	}

	void HighScore::SortByName()
	{
		scoreList->sort(CompareName);
	}
	void HighScore::SortByScore()
	{
		scoreList->sort(CompareScore);
	}

}