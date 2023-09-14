#pragma once
#include "Modifier.h"
#include <string>
#include <map>
using namespace std;

class BaseStats {
	int levelOne = 1;
	int* levelPtr;
	void InitMaps();
public:
	map<string, int> baseAbiScores;
	map<string, int> baseProfics;
	map<string, Modifier> baseModifs;
	BaseStats();
	BaseStats(int* _levelPtr);
};


// 