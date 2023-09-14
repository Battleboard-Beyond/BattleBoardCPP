#include "Modifier.h"
#include <iostream>
using namespace std;

/*
I notice that the functions tend to have a lot of similar code, but I am having trouble
figuring out how to deal with the bools in a way that I can compress it. Don't want to
make a smaller class to use in this class.

In addition, this class does make use of dynamic memory, so it needs to be tested for
memory leaks. I did make sure it still builds, but this class has no calls as of 9/13/2023.
*/

// === Declarations ===

int defaultModifEq(int, int, int);

// === Functions ===

int defaultModifEq(int abilityScore, int proficiency, int charLevel) {
	return (
		(floor(abilityScore / 2.0) - 5) + // ability score bonus
		((floor((charLevel - 1.0) / 4) + 2) * proficiency) // proficiency bonus
		);
}

// ======= CONSTRUCTORS =======

Modifier::Modifier() {
	abilityScorePtr = new int(10);
	proficiencyPtr = new int(0);
	charLevelPtr = new int(1);
	abilityScoreIsFromPtr = proficiencyIsFromPtr = charLevelIsFromPtr = false;
	modifEq = *defaultModifEq;
	modifValue = 0;
	ForceCalculate();
}

Modifier::Modifier(int& _abilityScoreValue, int& _proficiencyValue, int& _charLevelValue) {
	abilityScorePtr = new int(_abilityScoreValue);
	proficiencyPtr = new int(_proficiencyValue);
	charLevelPtr = new int(_charLevelValue);
	abilityScoreIsFromPtr = proficiencyIsFromPtr = charLevelIsFromPtr = false;
	modifEq = *defaultModifEq;
	modifValue = 0;
	ForceCalculate();
}

Modifier::Modifier(int* _abilityScorePtr, int* _proficiencyPtr, int* _charLevelPtr) {
	abilityScorePtr = _abilityScorePtr;
	proficiencyPtr = _proficiencyPtr;
	charLevelPtr = _charLevelPtr;
	abilityScoreIsFromPtr = proficiencyIsFromPtr = charLevelIsFromPtr = true;
	modifEq = *defaultModifEq;
	modifValue = 0;
	ForceCalculate();
}

// === Copy Constructor ===
Modifier::Modifier(const Modifier &old) {
	copyFrom(old);
}

// === Copy Assignment Operator ===
Modifier& Modifier::operator=(const Modifier& old) {
	copyFrom(old);
	return *this;
}

// === Destructor ===
Modifier::~Modifier() {
	if (!abilityScoreIsFromPtr) {
		delete abilityScorePtr;
	}
	if (!proficiencyIsFromPtr) {
		delete proficiencyPtr;
	}
	if (!charLevelIsFromPtr) {
		delete charLevelPtr;
	}
}

// ======= PRIVATE METHODS =======

void Modifier::copyFrom(const Modifier &old) {
	modifEq = old.modifEq;
	abilityScoreIsFromPtr = old.abilityScoreIsFromPtr;
	proficiencyIsFromPtr = old.proficiencyIsFromPtr;
	charLevelIsFromPtr = old.charLevelIsFromPtr;
	if (old.abilityScoreIsFromPtr) {
		abilityScorePtr = old.abilityScorePtr;
	}
	else {
		abilityScorePtr = new int(*old.abilityScorePtr);
	}
	if (!old.proficiencyIsFromPtr) {
		proficiencyPtr = old.proficiencyPtr;
	}
	else {
		proficiencyPtr = new int(*old.proficiencyPtr);
	}
	if (!old.charLevelIsFromPtr) {
		charLevelPtr = old.charLevelPtr;
	}
	else {
		charLevelPtr = new int(*old.charLevelPtr);
	}
	ForceCalculate();
}

// ======= PUBLIC METHODS =======

// === Ability Score ===
void Modifier::SetAbilityScoreBySource(int* _abilityScorePtr) {
	if (!abilityScoreIsFromPtr) {
		delete abilityScorePtr;
	}
	abilityScorePtr = _abilityScorePtr;
	abilityScoreIsFromPtr = true;
	ForceCalculate();
}
void Modifier::SetAbilityScoreByValue(int& _abilityScoreValue) {
	if (!abilityScoreIsFromPtr) {
		delete abilityScorePtr;
	}
	abilityScorePtr = new int(_abilityScoreValue);
	abilityScoreIsFromPtr = false;
	ForceCalculate();
}
int Modifier::GetAbilityScoreReference() {
	return *abilityScorePtr;
}

// === Proficiency ===
void Modifier::SetProficiencyBySource(int* _proficiencyPtr) {
	if (!proficiencyIsFromPtr) {
		delete proficiencyPtr;
	}
	proficiencyPtr = _proficiencyPtr;
	proficiencyIsFromPtr = true;
	ForceCalculate();
}
void Modifier::SetProficiencyByValue(int& _proficiencyValue) {
	if (!proficiencyIsFromPtr) {
		delete proficiencyPtr;
	}
	proficiencyPtr = new int(_proficiencyValue);
	proficiencyIsFromPtr = false;
	ForceCalculate();
}
int Modifier::GetProficiencyReference() {
	return *proficiencyPtr;
}

// === CharLevel ===
void Modifier::SetCharLevelBySource(int* _charLevelPtr) {
	if (!charLevelIsFromPtr) {
		delete charLevelPtr;
	}
	charLevelPtr = _charLevelPtr;
	charLevelIsFromPtr = true;
	ForceCalculate();
}
void Modifier::SetCharLevelByValue(int& _charLevelValue) {
	if (!charLevelIsFromPtr) {
		delete charLevelPtr;
	}
	charLevelPtr = new int(_charLevelValue);
	charLevelIsFromPtr = false;
	ForceCalculate();
}
int& Modifier::GetCharLevelReference() {
	return *charLevelPtr;
}

// === ModifEq ===
void Modifier::SetModifEq(int (*_modifEq)(int abilityScore, int proficiency, int _charLevel)) {
	modifEq = _modifEq;
}
void Modifier::ForceCalculate() {
	modifValue = modifEq(*abilityScorePtr, *proficiencyPtr, *charLevelPtr);
}

// === ModifValue ===
int Modifier::GetModifValue() {
	return modifValue;
}