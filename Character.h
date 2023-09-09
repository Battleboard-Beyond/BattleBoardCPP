#include <string>
#include <map>
#pragma once
using namespace std;

class Character
{
	private:
		struct modifEq {
			int (*funcPtr)(int scoreVal, int profVal, int level);
			string scoreName;
			modifEq() {
				funcPtr = nullptr;
				scoreName = "";
			}
			modifEq(int (*_funcPtr)(int, int, int), string _scoreName) {
				funcPtr = _funcPtr; 
				scoreName = _scoreName;
			}
		};
		int maxHealth, health, armorClass, level;	// Necessary int data
		string name, description, owner;			// Necessary string data
		map<string, int> abilityScores;				// for any ability scores
		map<string, int> proficiencies;				// for any proficiency scores
		map<string, int> modifResults;				// holds the actual modifiers
		map<string, modifEq> modifEqHolder;			// holds modifier equations ('modifEq's)
		map<string, string> blurbs;					// for any text-specific traits
		void initAbilityScores();
		void initProficiencies();
		void initModifiers();
		void updateModifiers();
	public:
		Character();
		Character(
			string name, string owner, int maxHealth, int armorClass, int level
		);

		void SetHealth(int newHealth);
		int GetHealth();
		void SetMaxHealth(int newMaxHealth);
		int GetMaxHealth();
		void SetArmorClass(int newArmorClass);
		int GetArmorClass();

		string GetName();

		void SetStat(string statName, int newValue); 
		int GetStat(string statName);
		bool DelStat(string statName);	// Returns success 

		void SetProficiency(string profName, int newValue);
		int GetProficiency(string profName);

		int GetModifier(string modifName);
};

