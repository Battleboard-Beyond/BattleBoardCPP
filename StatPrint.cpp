#include "StatPrint.h"

StatPrint::StatPrint() {
	myStat = nullptr;
}
StatPrint::StatPrint(BaseStats* myBaseStats) {
	myStat = myBaseStats;
}
void StatPrint::SetBaseStats(BaseStats* myBaseStats) {
	myStat = myBaseStats;
}