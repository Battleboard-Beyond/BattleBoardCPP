#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
using namespace std;

// Just some starter script to get things going.

int main()	
{
	string word;
	word = "hahaha text";

	Character bill("bill cosby", "Ethan", 23, 14, 1);

	cout << bill.GetName() << endl;
	cout << bill.GetHealth() << endl;
	bill.SetHealth(100);
	cout << bill.GetHealth() << "/" << bill.GetMaxHealth() << endl;

	cout << "Hello world!" << endl;
	cout << "Orbie!" << endl;

	return 0;
}