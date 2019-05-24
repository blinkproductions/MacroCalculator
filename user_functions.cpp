#include "user_functions.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <iomanip>
#include <ctime>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace std::this_thread;		// sleep_for,
using namespace std::chrono_literals;	//ns, us, ms, s, h, etc.


void PrintDate() {
	// current date/time based on current system
	time_t now = time(0);

	// convert now to string form
	char* dt = ctime(&now);

	cout << dt << endl;

};

void WelcomePrompt() {
	cout << "Hello! Welcome to my macro calculator! Let me start by asking a few questions ";
	sleep_for(500ms);
	cout << ". ";
	sleep_for(500ms);
	cout << ". ";
	sleep_for(500ms);
	cout << ". ";
	cout << endl;
};

int GetUserWeight() {
	int user_weight = 0;
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

double ProteinMultiplier() {
	int user_answer = 0;
	cout << "\n\nWhich one do you consider yourself as?\n";
	cout << "\t1.) Excess fat, overweight, unhealthy, or higher body fat percentage\n"; // .75
	cout << "\t2.) Slightly fit, somewhat normal\n"; // 1
	cout << "\t3.) I'm fit, I go to the gym often\n"; // 1.25

	cin >> user_answer;

	switch (user_answer)
	{
	case 1:
		return .75;
		break;
	case 2:
		return 1;
		break;
	case 3:
		return 1.25;
		break;

	default:
		cout << "This is a default arguement for the protein_multipler, something went wrong. Please try again.\n";
		return 0;
		break;
	}
};

double FatMultiplier() {
	int user_answer = 0;
	cout << "\n\nHow do you like your fats?\n";
	cout << "\t1.) I love carbs. Carbs are life, so you can make my fats less\n"; // .3
	cout << "\t2.) Whatever\n"; // .35
	cout << "\t3.) Love fatty foods, love eating nuts\n"; // .4

	cin >> user_answer;

	switch (user_answer)
	{
	case 1:
		return .3;
		break;
	case 2:
		return .35;
		break;
	case 3:
		return .4;
		break;

	default:
		cout << "This is a default arguement for the fat_multipler, something went wrong. Please try again.\n";
		return 0;
		break;
	}
};

int CalculateCarbIntake(int protein_grams, int fat_grams, int calorie_intake) {
	int calories_in_protein = protein_grams * calorie_per_protein;
	int calories_in_fat = fat_grams * calorie_per_fat;
	int sum_of_protein_and_fat = calories_in_protein + calories_in_fat;

	int carbs_needed = 0;

	carbs_needed = (calorie_intake - sum_of_protein_and_fat) / calorie_per_carb;
	
	return carbs_needed;
};

void GetUserDailyMacros(int weight, int calorie_intake, int choice) {
	int needed_fat = int(weight * FatMultiplier());
	int needed_protein = int(weight * ProteinMultiplier());
	int needed_carb = CalculateCarbIntake(needed_protein, needed_fat, calorie_intake);
	
	cout << endl << endl;
	PrintDate();
	cout << "Your daily caloric intake is: " << calorie_intake << endl;
	cout << "Your daily macro needs are: \n";
	cout << "Fats:" << std::setw(19) << std::right << needed_fat << " grams\n";
	cout << "Carbohydrates:" << std::setw(10) << needed_carb << " grams\n";
	cout << "Proteins:" << std::setw(15) << needed_protein << " grams\n";
};

void CalculateUserCalories(int choice, int weight) {

	int calorie_intake = 0;

	switch (choice)
	{
	case 1:	//Lose Weight
		calorie_intake = (weight * LOSE) - shred_factor;
		GetUserDailyMacros(weight, calorie_intake, choice);
		break;

	case 2: //Maintain Weight
		calorie_intake = weight * MAINTAIN;
		GetUserDailyMacros(weight, calorie_intake, choice);
		break;

	case 3: //Gain Weight
		calorie_intake = weight * GAIN;
		GetUserDailyMacros(weight, calorie_intake, choice);
		break;

	default:
		cout << "There may have been an error in the software. Please Try Again.\n";
		break;
	}
};