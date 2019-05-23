#include <iostream>
#include "user_functions.h"

using namespace std;

int main() {
	
	WelcomePrompt();
	double user_weight = GetUserWeight();
	int weight_loss_choice = GetUserLossOption();
	CalculateUserCalories(weight_loss_choice, user_weight);

	return 0;
}