#pragma once
class Modifier
{
	int (*modifEq)(int abilityScore, int proficiency, int charLevel);
	int modifValue;
	int *abilityScorePtr, *proficiencyPtr, *charLevelPtr;
	bool abilityScoreIsFromPtr, proficiencyIsFromPtr, charLevelIsFromPtr;
	void copyFrom(const Modifier &old);
public:
	Modifier();
	Modifier(int& _abilityScoreValue, int& _proficiencyValue, int& _charLevel);
	Modifier(int* _abilityScorePtr, int* _proficiencyPtr, int* _charLevel);

	Modifier(const Modifier &old);
	Modifier& operator=(const Modifier& old);
	~Modifier();

	void SetAbilityScoreBySource(int* _abilityScorePtr);
	void SetAbilityScoreByValue(int& _abilityScoreValue);
	int GetAbilityScoreReference();

	void SetProficiencyBySource(int* _proficiencyPtr);
	void SetProficiencyByValue(int& _abilityScoreValue);
	int GetProficiencyReference();

	void SetCharLevelBySource(int* _charLevelPtr);
	void SetCharLevelByValue(int& _charLevelValue);
	int& GetCharLevelReference();

	void SetModifEq(int (*_modifEq)(int abilityScore, int proficiency, int charLevel));
	void ForceCalculate();

	int GetModifValue();
};

