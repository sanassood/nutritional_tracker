
#include <iostream>
#include <string>
#include <cctype>
#include "daily_meals.h"

// Not using this currently
enum Day {
    MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
    //   1         2          3         4        5        6        7
};

using namespace std;

// *************************************************************************************
//                                    MAIN FUNCTION                                    *
// *************************************************************************************

int main() {
    // Important variables needed for the main
    string days_of_the_week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    DailyMeals *weekMeals[7];

    bool in_program = true;
    int input;
    int day;
    int protein_goal = 0;
    int calorie_limit = 0;
    string meal_name;

    // Initialize array of head_ptrs for the week
    for (int i = 0; i < 7; ++i) {
        // Each item in the array is a default Meal (head of each list)
        weekMeals[i] = new DailyMeals();
    }

// ******************************************     MENU + SWTICH STATEMENT     ************************************************
    while(in_program){
        // Menu output
        cout<< "\nWelcome to your weekly nutritional tracker !!\n" << "[1] Add Meal\n" << "[2] Remove Meal\n" << "[3] Change Meal Info\n" << "[4] Display Week\n" << "[5] Review Goals\n" << "[6] Check Progress\n" << "[7] Exit Program " << "\n\nReference: [1 2 3 4 5 6] -> [M T W Th F S Su] (use ints)\n" << endl;
        
        // User input for menu selection
        cout << "Selection: ";
        cin >> input;

        // Switch statement that operates on user input
        switch(input) {
        //**************************************** ADD A MEAL ****************************************
        case 1:
            cout << "Let's Add a Meal !!\n"<< "Which day are we adding to? : " <<  endl;
            cin >> day;

            if(day < 0 || day > 6){
                cout << "Invalid date !!\n" << endl;
                break;
            }

            weekMeals[day-1]->DailyMeals::add_meal();

            break;
        //**************************************** REMOVE A MEAL ****************************************
        case 2:
            cout << "Which day are we removing from? : " << endl;
            cin >> day;

            if(day < 0 || day > 6){
                cout << "Invalid Input :(" << endl;
                break;
            }

            // If no meals have been logged for that day yet
            if(weekMeals[day-1]->day_empty()){
                cout << "Day is empty, no meals to remove :(" << endl;
                break;
            }

            weekMeals[day-1]->DailyMeals::remove_meal();

            break;

        //**************************************** CHANGE MEAL INFO ****************************************   
        case 3:
            cout << "[1] Change meal name \n[2] Change protein and calories for specific meal" << endl;
            int option, day;
            cin >> option;

            cout << "Which Day does the meal belong to: ";
            cin >> day;
            cout << "\n";
            cout << day << endl;
            if(day < 0 || day > 6){
                cout << "Invalid Input :(" << endl;
                break;
            }

            if (option == 1) {
                if(weekMeals[day-1]->change_meal_name())
                    cout << "Meal name changed!!\n";
                break;
            }
            else {
                int n_pro, n_cal;
                if(weekMeals[day-1]->change_meal_stats())
                    cout << "Meal stats changed!!\n";
                break;
            }

            break;

        //**************************************** DISPLAY THE WEEK ****************************************
        case 4:
            cout << "Printing meals: " << endl;
            // Call function to print meals

            for(int i = 0; i < 7; i++){
                cout << days_of_the_week[i] << endl;
                cout << "================\n" << endl;
                weekMeals[i]->DailyMeals::display_daily_meals();
                cout << "\n";
            }

            break;
        //**************************************** SET GOALS ****************************************
        case 5:
            cout << "Let's set some goals!" << endl;
            // Call function to print meals
            char user_input;
            int new_climit, new_pgoal;
            cout << "Current Goals" << endl;
            cout << "Calorie Limit: " << calorie_limit << " Daily Protein Goal: " << protein_goal << endl;  

            cout << "Yould you like to change your goals? [Y] [N] : ";
            cin >> user_input;
            // Maybe add soemthing to switch to upper case so user can input y or n

            if(user_input == 'N')
                break;
            
            if(user_input == 'Y'){
                cout << "NEW calorie Limit: ";
                cin >> calorie_limit;
                cout << "NEW protein goal: ";
                cin >> protein_goal;

                cout << "\nGOALS HAVE BEEN UPDATED !!" << endl;
                break;
            }

            break;
        //**************************************** CHECK PROGRESS ****************************************
        case 6:
            cout << "Check Progress !! " << endl;

            for(int i = 0; i < 7; i++){
                cout << days_of_the_week[i] << endl;
                cout << "================\n" << endl;
                weekMeals[i]->DailyMeals::check_goals(calorie_limit, protein_goal);
                cout << "\n";
            }
            break;
        //**************************************** EXIT PROGRAM ****************************************
        case 7:
            cout << "Exiting Program !!" << endl;
            return 1;

        //**************************************** INVALID INPUT ****************************************
        default:
            cout << "Invalid option. Please select a value between 1 to 6" << endl;
            break;
    }
    
    }
}
