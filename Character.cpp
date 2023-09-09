#include "Character.h"
#include <string>
#include <map>
using namespace std;

// Functions
int standardModFunc(int scoreVal, int profVal, int level) {
	return (
		(floor(scoreVal / 2.0) - 5) + // ability score bonus
		((floor((level - 1.0) / 4) + 2) * profVal) // proficiency bonus
		);
}

// Constructors
Character::Character() {
	maxHealth = health = armorClass = 10;
	level = 1;
	name = "Generic Character";
	description = "";
	owner = "Nobody";
	initAbilityScores();
	initProficiencies();
	initModifiers();
	updateModifiers();
}

Character::Character(string _name, string _owner, int _maxHealth, int _armorClass, int _level) {
	maxHealth = health = _maxHealth;
	armorClass = _armorClass;
	level = _level;
	name = _name;
	description = "";
	owner = _owner;
	initAbilityScores();
	initProficiencies();
	initModifiers();
	updateModifiers();
}

// Private methods
void Character::initAbilityScores() {
	abilityScores["Strength"] = 10;
	abilityScores["Dexterity"] = 10;
	abilityScores["Constitution"] = 10;
	abilityScores["Intelligence"] = 10;
	abilityScores["Wisdom"] = 10;
	abilityScores["Charisma"] = 10;
}

void Character::initProficiencies() {
	// constant
	proficiencies["NONE"] = 0;
	// ability scores (just zeros for now)
	proficiencies["Strength"] = 0;
	proficiencies["Dexterity"] = 0;
	proficiencies["Constitution"] = 0;
	proficiencies["Intelligence"] = 0;
	proficiencies["Wisdom"] = 0;
	proficiencies["Charisma"] = 0;
	// strength skills
	proficiencies["Athletics"] = 0;
	// dexterity skills
	proficiencies["Acrobatics"] = 0;
	proficiencies["Sleight of Hand"] = 0;
	proficiencies["Stealth"] = 0;
	// intelligence skills
	proficiencies["Arcana"] = 0;
	proficiencies["History"] = 0;
	proficiencies["Investigation"] = 0;
	proficiencies["Nature"] = 0;
	proficiencies["Religion"] = 0;
	// wisdom skills
	proficiencies["Animal Handling"] = 0;
	proficiencies["Insight"] = 0;
	proficiencies["Medicine"] = 0;
	proficiencies["Perception"] = 0;
	proficiencies["Survival"] = 0;
	// charisma skills
	proficiencies["Deception"] = 0;
	proficiencies["Intimidation"] = 0;
	proficiencies["Performance"] = 0;
	proficiencies["Persuasion"] = 0;
}

void Character::initModifiers() {
	// ability scores (just zeros for now)
	modifEqHolder["Strength"] = modifEq(standardModFunc, "Strength");
	modifEqHolder["Dexterity"] = modifEq(standardModFunc, "Dexterity");
	modifEqHolder["Constitution"] = modifEq(standardModFunc, "Constitution");
	modifEqHolder["Intelligence"] = modifEq(standardModFunc, "Intelligence");
	modifEqHolder["Wisdom"] = modifEq(standardModFunc, "Wisdom");
	modifEqHolder["Charisma"] = modifEq(standardModFunc, "Charisma");
	// strength skills
	modifEqHolder["Athletics"] = modifEq(standardModFunc, "Strength");
	// dexterity skills
	modifEqHolder["Acrobatics"] = modifEq(standardModFunc, "Dexterity");
	modifEqHolder["Sleight of Hand"] = modifEq(standardModFunc, "Dexterity");
	modifEqHolder["Stealth"] = modifEq(standardModFunc, "Dexterity");
	// intelligence skills
	modifEqHolder["Arcana"] = modifEq(standardModFunc, "Intelligence");
	modifEqHolder["History"] = modifEq(standardModFunc, "Intelligence");
	modifEqHolder["Investigation"] = modifEq(standardModFunc, "Intelligence");
	modifEqHolder["Nature"] = modifEq(standardModFunc, "Intelligence");
	modifEqHolder["Religion"] = modifEq(standardModFunc, "Intelligence");
	// wisdom skills
	modifEqHolder["Animal Handling"] = modifEq(standardModFunc, "Wisdom");
	modifEqHolder["Insight"] = modifEq(standardModFunc, "Wisdom");
	modifEqHolder["Medicine"] = modifEq(standardModFunc, "Wisdom");
	modifEqHolder["Perception"] = modifEq(standardModFunc, "Wisdom");
	modifEqHolder["Survival"] = modifEq(standardModFunc, "Wisdom");
	// charisma skills
	modifEqHolder["Deception"] = modifEq(standardModFunc, "Charisma");
	modifEqHolder["Intimidation"] = modifEq(standardModFunc, "Charisma");
	modifEqHolder["Performance"] = modifEq(standardModFunc, "Charisma");
	modifEqHolder["Persuasion"] = modifEq(standardModFunc, "Charisma");
}


void Character::updateModifiers() {
	for (map<string, modifEq>::iterator it = modifEqHolder.begin(); it != modifEqHolder.end(); it++) {
		(*it->second.funcPtr)(
			abilityScores[it->second.scoreName], 
			proficiencies[it->first],
			level
			);
	}
}

// Public Methods
void Character::SetHealth(int newHealth) {
	health = min(max(newHealth, 0), maxHealth); // force between 0 and maxhealth (inclusive)
}
int Character::GetHealth() {
	return health;
}

void Character::SetMaxHealth(int newMaxHealth) {
	maxHealth = max(newMaxHealth, 1); // force higher than 0
}
int Character::GetMaxHealth() {
	return maxHealth;
}

void Character::SetArmorClass(int newArmorClass) {
	armorClass = newArmorClass;
}
int Character::GetArmorClass() {
	return armorClass;
}

string Character::GetName() {
	return name;
}

void Character::SetStat(string statName, int newStat) {
	abilityScores[statName] = max(newStat, 1);
}
int Character::GetStat(string statName) {
	map<string, int>::iterator it = abilityScores.find(statName);
	if (it == abilityScores.end()) {
		return 0; // 0 means stat doesn't exist
	}
	return it->second;
}
bool Character::DelStat(string statName) {
	map<string, int>::iterator it = abilityScores.find(statName);
	if (it == abilityScores.end()) {
		return false;
	}
	abilityScores.erase(it);
	return true;
}