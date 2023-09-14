#include "Character.h"
#include <string>
#include <map>
using namespace std;

// Functions


// Constructors
Character::Character() {
	maxHealth = health = armorClass = 10;
	level = 1;
	name = "Generic Character";
	description = "";
	owner = "Nobody";
	initAbilityScores();
	initProficiencies();
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
}

// Private methods
void Character::initAbilityScores() {
	abilityScores["NONE"] = 10; // Constant (NEVER CHANGE)
	abilityScores["Strength"] = 10;
	abilityScores["Dexterity"] = 10;
	abilityScores["Constitution"] = 10;
	abilityScores["Intelligence"] = 10;
	abilityScores["Wisdom"] = 10;
	abilityScores["Charisma"] = 10;
}

void Character::initProficiencies() {
	// constants NEVER CHANGE
	proficiencies["NONE"] = 0; 
	proficiencies["Strength"] = 0;
	proficiencies["Dexterity"] = 0;
	proficiencies["Constitution"] = 0;
	proficiencies["Intelligence"] = 0;
	proficiencies["Wisdom"] = 0;
	proficiencies["Charisma"] = 0;
	// ability scores (just zeros for now)
	proficiencies["Strength_Save"] = 0;
	proficiencies["Dexterity_Save"] = 0;
	proficiencies["Constitution_Save"] = 0;
	proficiencies["Intelligence_Save"] = 0;
	proficiencies["Wisdom_Save"] = 0;
	proficiencies["Charisma_Save"] = 0;
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

void Character::SetProficiency(string profName, int newValue) {
	proficiencies[profName] = newValue;
}
int Character::GetProficiency(string profName) {
	map<string, int>::iterator it = proficiencies.find(profName);
	if (it == proficiencies.end()) {
		return -1; // -1 means stat doesn't exist
	}
	return it->second;
}