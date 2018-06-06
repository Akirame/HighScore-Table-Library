#include <iostream>
#include "HighScoreManager.h"
using namespace std;
using namespace hscore;

void main()
{
	HighScore* scoreTable = new HighScore();	
	
	scoreTable->AddScore("A", 10);
	Data* _data = scoreTable->GetDataFromName("A");
	cout << _data->GetName();
	scoreTable->AddScore("B", 20);
	scoreTable->AddScore("C", 930);
	scoreTable->AddScore("D", 50);
	scoreTable->AddScore("E", 40);
	scoreTable->ShowList();	
	scoreTable->SortByName();
	cout << "-----------" << endl;
	scoreTable->ShowList();
	cout << "------------" << endl;
	scoreTable->SortByScore();
	scoreTable->ShowList();
	delete scoreTable;
}