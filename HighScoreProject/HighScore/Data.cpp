#include "Data.h"

namespace data
{
	void Data::SetName(string _name) 
	{
		name = _name;
	}
	void Data::SetScore(int _score)
	{
		score = _score;
	}
	string Data::GetName() const
	{
		return name;
	}
	int Data::GetScore() const
	{
		return score;
	}
}
