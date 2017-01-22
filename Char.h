#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int health = 100;
string enemyType = "";
int rounds = 0;

string chooseChar();
void enemy();
void runGame();
void actionMenu();
void battle(int choice);
int percentChance(int percent);

//Determines the name of the player
string chooseChar() {

	string character;

	cout << "Choose a character: \n";

	cout << "Amber\n";
	cout << "Johnny\n";
	cout << "Iva\n";
	cout << "Type in your own!\n";
	cin >> character;

	return character;
}

//Choose what enemy will appear
void enemy() {

	int random = rand() % 4;
	if (random == 1) {
		enemyType = "Skeleton";
	}
	else if (random == 2) {
		enemyType = "Zombie";
	}
	else if (random == 3) {
		enemyType = "Goomba";
	}
	else {
		enemyType = "Your Evil Twin!";
	}

}

//The main method in the header file
void runGame() {
	int choice = 0;
	while (health > 0) {
		enemy();
		cout << "You have encountered a: " << enemyType << "!\n";
		cout << "Choose your path: \n";
		actionMenu();
		cin >> choice;
		while ((choice > 3) || (choice < 1)) {
			cout << "Not a valid choice! Enter again: \n";
			cin >> choice;
		}
		//Chance of events happening.

		battle(choice);
		rounds++;
	}
	cout << "You lost! It was a good run though. \n";
	cout << "You lasted: " << rounds << " rounds. \n";


}

//Simple Menu for user to select their action
void actionMenu() {
	cout << "1. Fight! \n";
	cout << "2. Defend. \n";
	cout << "3. Heal Up! \n";
}

//What happens during the heated battle...
void battle(int choice) {
	int percent = (rand() % 100);
	int decision = percentChance(percent);
	int doubleChance = rand() % 10;
	switch (choice) {
		case 1: 
			if (decision == 1) {
				cout << "Success! You have defeated the " << enemyType << "\n";
				cout << "Current Health: " << health << "\n";
			}
			else {
				cout << "You have been striken by the " << enemyType << "! \n";
				cout << "You have lost 10 health. \n";
				health -= 10;
				cout << "Current Health: " << health << "\n";
			}
			break;
		case 2:
			//This will give the player a higher possibility of defending
			if (decision == 0) {
				if (doubleChance >= 5) {
					decision = 1;
				}
			}
			if (decision == 1) {
				cout << "Success! You have defended against the " << enemyType << "\n";
				cout << "Current Health: " << health << "\n";
			}
			else {
				cout << "You have been striken by the " << enemyType << "! \n";
				cout << "You have lost 10 health. \n";
				health -= 10;
				cout << "Current Health: " << health << "\n";
			}
			break;
		case 3:
			if (decision == 1) {
				cout << "Success! You have healed up! \n";
				health += 20;
				cout << "Current Health: " << health << "\n";
			}
			else {
				cout << "You have been striken by the " << enemyType << "! \n";
				cout << "You have lost 5 health. \n";
				health -= 5;
				cout << "Current Health: " << health << "\n";
			}
			break;
	}

}

int percentChance(int percent) {
	int percent2 = 0;
	if (percent > 70) {
		percent2 = (rand() % 10);
		if (percent2 >= 3) {
			return 1;
		}
	}
	else if (percent > 50) {
		percent2 = (rand() % 100);
		if (percent2 >= 50) {
			return 1;
		}
	}
	else if (percent > 20) {
		percent2 = (rand() % 1000);
		if (percent2 >= 600) {
			return 1;
		}
	}
	else {
		return 0;
	}
	return 0;
}