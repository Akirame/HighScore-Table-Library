#ifndef DATA_H
#define DATA_H
#include <string>
using namespace std;

namespace data
{
	class Data
	{
	private:
		string name;
		int score;
	public:
		void SetName(string _name);
		void SetScore(int _score);
		string GetName() const;
		int GetScore() const;
	};
}
#endif

