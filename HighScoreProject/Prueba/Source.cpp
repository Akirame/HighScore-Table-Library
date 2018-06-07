#include <iostream>
#include "HighScoreManager.h"
using namespace std;
using namespace hscore;

void main()
{
	HighScore* scoreTable = new HighScore();	
	
	scoreTable->AddScore("a", 10);
	Data* _data = scoreTable->GetDataFromName("A");	
	scoreTable->AddScore("B", 20);
	scoreTable->AddScore("C", 930);
	scoreTable->AddScore("D", 50);
	scoreTable->AddScore("e", 40);	
	int pos = scoreTable->GetPositionFromScore(930);
	cout << pos;
	delete scoreTable;
}