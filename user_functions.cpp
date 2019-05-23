#include "user_functions.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace std::this_thread;		// sleep_for,
using namespace std::chrono_literals;	//ns, us, ms, s, h, etc.



void WelcomePrompt() {
	cout << "Hello! Welcome to my macro calculator! Let me start by asking a few questions ";
	sleep_for(500ms);
	cout << ". ";
	sleep_for(500ms);
	cout << ". ";
	sleep_for(500ms);
	cout << ". ";
	cout << endl;
}

double GetUserWeight() {
	double user_weight = 0;
	cout << "\nPlease input your weight: ";
	cin >> user_weight;
	cout << endl;
	return user_weight;
};

int GetUserLossOption() {
	int user_choice = 0;

	cout << "Please select from the menu: \n";
	cout << "\t 1.) Lose Weight\n";
	cout << "\t 2.) Maintain Weight\n";
	cout << "\t 3.) Gain Weight\n";

	cin >> user_choice;
	cout << endl;
	return user_choice;
};

void CalculateUserCalories(int choice, double weight) {
	switch (choice)
	{
	case 1:	//Lose Weight
		GetUserDailyMacros(weight);
		break;

	case 2: //Maintain Weight
		GetUserDailyMacros(weight);
		break;

	case 3: //Gain Weight
		GetUserDailyMacros(weight);
		break;

	default:
		cout << "There may have been an error in the software. Please Try Again.\n";
		break;
	}
};

void GetUserDailyMacros(double weight) {
	int needed_fat = weight * calorie_per_fat;
	int needed_carb = weight * calorie_per_carb;
	int needed_protein = weight * calorie_per_protein;

	cout << "Your daily macro needs are: \n";
	cout << "Fats:" << std::setw(19) << std::right << needed_fat << " grams\n";
	cout << "Carbohydrates:" << std::setw(10) << needed_carb << " grams\n";
	cout << "Proteins:" << std::setw(15) << needed_protein << " grams\n";
};