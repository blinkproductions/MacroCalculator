// This is where you define your function prototypes
#pragma once
#pragma warning(disable:4996)

//defining constants
const int calorie_per_fat = 9;
const int calorie_per_carb = 4;
const int calorie_per_protein = 4;
const int shred_factor = 600;

enum ScaleTranslations {
	LOSE = 14,
	MAINTAIN = 15,
	GAIN = 16
};
void PrintDate();
void WelcomePrompt();
int GetUserWeight();
int GetUserLossOption();
double ProteinMultiplier();
double FatMultiplier();
int CalculateCarbIntake(int calories_in_protein, int calories_in_fat, int calorie_intake);
void CalculateUserCalories(int choice, int weight);
void GetUserDailyMacros(int weight, int calorie_intake, int choice);



