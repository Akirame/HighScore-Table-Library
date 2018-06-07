#include "HighScoreManager.h"

namespace hscore
{
	HighScore::HighScore()
	{
		scoreList = new list<Data*>();
	}
	HighScore::~HighScore()
	{
		scoreList->clear();
		delete scoreList;
	}

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

	Data* HighScore::GetDataFromScore(int score)
	{		
		for (iter = scoreList->begin(); iter != scoreList->end(); iter++)
		{
			if ((*iter)->GetScore() == score)
			{
				return (*iter);
			}
		}
		return NULL;
	}
	Data* HighScore::GetDataFromPosition(int position)
	{
		if (position >= 0 && position < scoreList->size())
		{						
			iter = scoreList->begin();
			for (int i = 0; i < position; i++)
				iter++;			
			return *iter;
		}
		return NULL;
	}
	int HighScore::GetPositionFromScore(int score)
	{
		int pos = 0;
		for (iter = scoreList->begin(); iter != scoreList->end(); iter++)
		{
			if ((*iter)->GetScore() == score)
				return pos;
			else
				pos++;
		}
		return -1;
	}
	int HighScore::GetPositionFromName(string name)
	{
		ToUpper(name);
		int pos = 0;
		for (iter = scoreList->begin(); iter != scoreList->end(); iter++)
		{
			if ((*iter)->GetName() == name)
				return pos;
			else
				pos++;
		}
		return -1;
	}
	void HighScore::ShowListInConsole()
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