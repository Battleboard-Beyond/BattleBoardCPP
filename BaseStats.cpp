#include "BaseStats.h"
using namespace std;

void BaseStats::InitMaps() {
	baseAbiScores = {
		// Just to ensure neutral term
		{"NULL", 10},
		// Ability Scores
		{"Strength", 10},
		{"Dexterity", 10},
		{"Constitution", 10},
		{"Intelligence", 10},
		{"Wisdom", 10},
		{"Charisma", 10}
	};
	baseProfics = {
		// Just to ensure neutral term.
		{"NULL", 0},
		// Ability Score Saving Throws
		{"Strength_Save", 0},
		{"Dexterity_Save", 0},
		{"Constitution_Save", 0},
		{"Intelligence_Save", 0},
		{"Wisdom_Save", 0},
		{"Charisma_Save", 0},
		// Strength Skills
		{"Athletics", 0},
		// Dexterity Skills
		{"Acrobatics", 0},
		{"Sleight_of_Hand", 0},
		{"Stealth", 0},
		// Intelligence Skills
		{"Arcana", 0},
		{"History", 0},
		{"Investigation", 0},
		{"Nature", 0},
		{"Religion", 0},
		// Wisdom Skills
		{"Animal_Handling", 0},
		{"Insight", 0},
		{"Medicine", 0},
		{"Perception", 0},
		{"Survival", 0},
		// Charisma Skills
		{"Deception", 0},
		{"Intimidation", 0},
		{"Performance", 0},
		{"Persuasion", 0}
	};
	baseModifs = {
		// Just to ensure neutral term
		{"NULL", Modifier()},
		// Ability Score Saving Throws
		{"Strength_Save", Modifier(&baseAbiScores["Strength_Save"], &baseProfics["Strength"], levelPtr)},
		{"Dexterity_Save", Modifier(&baseAbiScores["Dexterity_Save"], &baseProfics["Dexterity"], levelPtr)},
		{"Constitution_Save", Modifier(&baseAbiScores["Constitution_Save"], &baseProfics["Constitution"], levelPtr)},
		{"Intelligence_Save", Modifier(&baseAbiScores["Intelligence_Save"], &baseProfics["Intelligence"], levelPtr)},
		{"Wisdom_Save", Modifier(&baseAbiScores["Wisdom_Save"], &baseProfics["Wisdom"], levelPtr)},
		{"Charisma_Save", Modifier(&baseAbiScores["Charisma_Save"], &baseProfics["Charisma"], levelPtr)},
		// Strength Skills
		{"Athletics", Modifier(&baseAbiScores["Athletics"], &baseProfics["Strength"], levelPtr)},
		// Dexterity Skills
		{"Acrobatics", Modifier(&baseAbiScores["Acrobatics"], &baseProfics["Dexterity"], levelPtr)},
		{"Sleight_of_Hand", Modifier(&baseAbiScores["Sleight_of_Hand"], &baseProfics["Dexterity"], levelPtr)},
		{"Stealth", Modifier(&baseAbiScores["Stealth"], &baseProfics["Dexterity"], levelPtr)},
		// Intelligence Skills
		{"Arcana", Modifier(&baseAbiScores["Arcana"], &baseProfics["Intelligence"], levelPtr)},
		{"History", Modifier(&baseAbiScores["History"], &baseProfics["Intelligence"], levelPtr)},
		{"Investigation", Modifier(&baseAbiScores["Investigation"], &baseProfics["Intelligence"], levelPtr)},
		{"Nature", Modifier(&baseAbiScores["Nature"], &baseProfics["Intelligence"], levelPtr)},
		{"Religion", Modifier(&baseAbiScores["Religion"], &baseProfics["Intelligence"], levelPtr)},
		// Wisdom Skills
		{"Animal_Handling", Modifier(&baseAbiScores["Animal_Handling"], &baseProfics["Wisdom"], levelPtr)},
		{"Insight", Modifier(&baseAbiScores["Insight"], &baseProfics["Wisdom"], levelPtr)},
		{"Medicine", Modifier(&baseAbiScores["Medicine"], &baseProfics["Wisdom"], levelPtr)},
		{"Perception", Modifier(&baseAbiScores["Perception"], &baseProfics["Wisdom"], levelPtr)},
		{"Survival", Modifier(&baseAbiScores["Survival"], &baseProfics["Wisdom"], levelPtr)},
		// Charisma Skills
		{"Deception", Modifier(&baseAbiScores["Deception"], &baseProfics["Charisma"], levelPtr)},
		{"Intimidation", Modifier(&baseAbiScores["Intimidation"], &baseProfics["Charisma"], levelPtr)},
		{"Performance", Modifier(&baseAbiScores["Performance"], &baseProfics["Charisma"], levelPtr)},
		{"Persuasion", Modifier(&baseAbiScores["Persuasion"], &baseProfics["Charisma"], levelPtr)},
	};
}

BaseStats::BaseStats() {
	levelPtr = &levelOne; // Mostly to avoid dealing with dynamic values
	InitMaps();
}

BaseStats::BaseStats(int* _levelPtr) {
	levelPtr = _levelPtr; 
	InitMaps();
}