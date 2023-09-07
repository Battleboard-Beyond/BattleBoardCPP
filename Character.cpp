#include "Character.h"
#include <string>
using namespace std;

Character::Character() {
	maxHealth = health = armorClass = 10;
	level = 1;
	name = "Generic Character";
	description = "";
	owner = "Nobody";
	strength = dexterity = constitution = intelligence = wisdom = charisma = 10;
}

Character::Character(string _name, string _owner, int _maxHealth, int _armorClass, int _level) {
	maxHealth = health = _maxHealth;
	armorClass = _armorClass;
	level = _level;
	name = _name;
	description = "";
	owner = _owner;
	strength = dexterity = constitution = intelligence = wisdom = charisma = 10;
}

void Character::SetHealth(int newHealth) {
	health = newHealth;
}
int Character::GetHealth() {
	return health;
}

void Character::SetMaxHealth(int newMaxHealth) {
	maxHealth = newMaxHealth;
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
	if (statName == "STR") {
		strength = newStat;
	}
	else if (statName == "DEX") {
		dexterity = newStat;
	}
	else if (statName == "CON") {
		constitution = newStat;
	}
	else if (statName == "INT") {
		intelligence = newStat;
	}
	else if (statName == "WIS") {
		wisdom = newStat;
	}
	else if (statName == "CHA") {
		charisma = newStat;
	}
}
int Character::GetStat(string statName) {
	if (statName == "STR") {
		return strength;
	}
	else if (statName == "DEX") {
		return dexterity;
	}
	else if (statName == "CON") {
		return constitution;
	}
	else if (statName == "INT") {
		return intelligence;
	}
	else if (statName == "WIS") {
		return wisdom;
	}
	else if (statName == "CHA") {
		return charisma;
	}
	else {
		return -1;
	}
}