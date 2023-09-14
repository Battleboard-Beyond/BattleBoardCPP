#pragma once
#include "BaseStats.h"
#include <iostream>
class StatPrint
{
	
	BaseStats* myStat;
public:
	StatPrint();
	StatPrint(BaseStats* myBaseStats);
	void SetBaseStats(BaseStats* myBaseStats); 

};

