#include <string>
#pragma once
using namespace std;

class Character
{
	private:
		int maxHealth, health, armorClass, level;
		int strength, dexterity, constitution, intelligence, wisdom, charisma;
		string name, description, owner;
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

		void SetStat(string statName, int newStat);
		int GetStat(string statName);
};

