// This is where you define your function prototypes
#pragma once


//defining constants
const int calorie_per_fat = 9;
const int calorie_per_carb = 4;
const int calorie_per_protein = 4;

enum ScaleTranslations {
	LOSE = 14,
	MAINTAIN = 15,
	GAIN = 16
};

//function prototypes
void WelcomePrompt();
double GetUserWeight();
int GetUserLossOption();
ScaleTranslations GetScaleForWeight();
void CalculateUserCalories(int choice, double weight);
void GetUserDailyMacros(double weight);

/*
Constants needed:
	const for totCal for fat
	const for totCal for carbs
	const for totCal for protein

Functions needed:
output to a file function
get weight
get options (losing, maintaining, gaining)
get fatCal
get carbCal
get proteinCal
get scaleIntensity

*/

