// Text-Based-RPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Char.h"

using namespace std;

int main()
{
	string character = chooseChar();
	cout << "Hello " << character << "!\n";
	cout << "Let's begin our adventure! \n";
	runGame();


    return 0;
}

