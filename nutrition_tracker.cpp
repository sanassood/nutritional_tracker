#include <iostream>
#include <string>
#include "daily_meals.h"

// Not using this currently
enum Day {
    MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
    //   1         2          3         4        5        6        7
};

using namespace std;
// // Meal class - nodes of each daily list
// // *************************************************************************************
// //                                        MEAL CLASS                                   *
// // *************************************************************************************
// class Meal {
//     private:
//         string name;
//         int calories;
//         // For protein uinit will be grams
//         int protein;

//     public:
//         Meal* next;

//         // Default constructor for Meal
//         Meal(){
//             name = "unknown";
//             calories = 0;
//             protein = 0;
//             next = NULL;
//         }

//         Meal(const std::string& name, int calories, int pro) : name(name), calories(calories), next(NULL), protein(pro) {
//             // this is the constructor for when the user gives input
//         }
//         // Accessor and mutator functions
//         void change_calories(int new_cal){
// 		    calories = new_cal;
//         }
//         void change_name(string new_name){
// 		    name = new_name;
// 	    }
//         void change_protein(int new_protein){
// 		    protein = new_protein;
// 	    }

//         int get_calories(){return calories;}
//         string get_name(){return name;}
//         int get_protein(){return protein;}
// };

// // DailyMeals - Linked lists made of meals
// // *************************************************************************************
// //                                    DAILY LIST CLASS                                 *
// // *************************************************************************************
// class DailyMeals {
// public:
//     Meal *head_ptr;
//     Meal *tail_ptr;
//     int num_meals;

//     DailyMeals() : head_ptr(NULL), num_meals(0) {
//         // List constructor for DailyMeals !!
//     }

//     // Free all allocated memory (have this out of habit, may not use it)
//     // ~DailyMeals() {
//     //     Meal* cursor = head_ptr;
//     //     while (cursor != NULL) {
//     //         Meal *temp = cursor;
//     //         cursor = cursor->next;
//     //         delete temp;
//     //     }
//     // }

//     // Returns true if list is empty, false if not
//     bool day_empty(){
//         return (num_meals == 0);
//     }

//     // Add meal to a daily list (adds at the end)
//     void add_meal() {
//         // Do NOT need to check for duplicates since peopple can ahve the same meal multiple
//         // times in a day
//         string m_name;
//         int m_cal, m_prot;

//         cout << "\nEnter Meal Name, Calories, Protein: " ;
//         cin >> m_name >> m_cal >> m_prot;
       

//         Meal *newMeal = new Meal(m_name, m_cal, m_prot);
//         if(head_ptr == NULL){
//             head_ptr = newMeal;
//             tail_ptr = head_ptr;
//             newMeal->next = NULL;

//             num_meals++;

//             return;
//         }
        
//         // Generate case adding to the end
//         tail_ptr->next = newMeal;
//         tail_ptr = newMeal;
//         newMeal->next = NULL;
//         num_meals++;

//         cout << m_name << " has been added!" << endl;
        
//     }

//     // Remove meal from day
//     bool remove_meal(){
//         string delete_meal;
//         cout << "Meal to remove: ";
//         cin >> delete_meal;

//         Meal* temp = search_meal(delete_meal);

//         // Meal not found
//         if(temp == NULL)
//             return false;

//         // Case: Deleting head_ptr
//         if(temp == head_ptr){
//             delete temp;

//             head_ptr = NULL;
//             tail_ptr = NULL;
//             num_meals = 0;

//             return true;
//         }

//         // Prev is pointer before target
//         Meal* prev = head_ptr;
//         while(prev->next != temp){
//             prev = prev->next;
//         }

//         // Case deleting end
//         if(temp == tail_ptr)
//             tail_ptr = prev;

//         // Adjust pointers
//         prev->next = temp->next;
//         delete temp;
        
//         // Successfully removed
//         return true;
//     }

    

//     // Prints the meals logged in the week + calories and protein information
//     void display_daily_meals() {
//         Meal *current = head_ptr;

//         while (current != NULL) {
//             cout << "--> " << current->get_name() << " (" << current->get_protein() << "g protein, "<< current->get_calories() << " calories)" << endl;
//             current = current->next;
//         }
//     }
    
//     // Returns Meal pointer to target
//     Meal* search_meal(string target){
//         Meal *cursor = head_ptr;
//         while(cursor != NULL){
//             if(cursor->get_name() == target)
//                 return cursor;
//             cursor = cursor->next;
//         }
//         cout << "Meal not Found" << endl;
//         return NULL;
//     }

//     // Go through the list and return the total grams of protein for the day
//     int total_daily_protein(){
//         if(day_empty())
//             return 0;
//         // To be returned
//         int total_protein = 0;

//         Meal *cursor = head_ptr;
//         while(cursor != NULL)
//         {
//             total_protein += cursor->get_protein();
//         }

//         return total_protein;
//     }
    
//     // Go through the list and return the total calories for the day
//     int total_daily_calories(){
//         if(day_empty())
//             return 0;
//         // To be returned
//         int total_calories = 0;

//         Meal *cursor = head_ptr;
//         while(cursor != NULL)
//         {
//             total_calories += cursor->get_protein();
//         }

//         return total_calories;
//     }

//     //
//     void check_goals(int pgoal, int climit){
//         // Checking relative to calorie limit ______________________
//         int c_difference = climit - total_daily_calories();
//         if(c_difference == 0){
//             cout << "Hit Calorie Limit" << endl;
//         }
//         else if(c_difference < 0){
//             cout<< "Exceeded  Calorie Limit" << endl;
//         }
//         else{
//             cout << c_difference << " Calroies Available" << endl;
//         }

//         // Checking relative to protein goal ________________________
//         int p_difference = pgoal - total_daily_protein();
//         if(p_difference >= 0){
//             cout << "Hit Protein Goal" << endl;
//         }
//         else{
//             cout << p_difference << "g Below Protein Goal" << endl;
//         }

//     }
//     // Return meal in the day with the HIGHEST protein
//     //Meal* most_protein(){};

//     // Sorts Meals by protein (highest to lowest)
//     void sort_meals(){
//         if(num_meals == 0)
//             return;
        

//     }

  
// };

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
        cout<< "\nWelcome to your weekly nutritional tracker !!\n" << "[1] Add Meal\n" << "[2] Remove Meal\n" << "[3] Display Week\n" << "[4] Review Goals\n" << "[5] Check Progress\n" << "[6] Exit Program" << endl;
        
        // User input for menu selection
        cout << "Selection: ";
        cin >> input;

        // Switch statement that operates on user input
        switch(input) {
        //**************************************** ADD A MEAL ****************************************
        case 1:
            cout << "Let's Add a Meal !!\n"<< "Which day are we adding to? : " <<  endl;
            cin >> day;

            weekMeals[day-1]->DailyMeals::add_meal();

            break;
        //**************************************** REMOVE A MEAL ****************************************
        case 2:
            cout << "Which day are we removing from? : " << endl;
            cin >> day;

            // If no meals have been logged for that day yet
            if(weekMeals[day-1]->day_empty()){
                cout << "Day is empty, no meals to remove :(" << endl;
                break;
            }

            weekMeals[day-1]->DailyMeals::remove_meal();

            break;
        //**************************************** DISPLAY THE WEEK ****************************************
        case 3:
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
        case 4:
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
        case 5:
            cout << "Check Progress !! " << endl;

            for(int i = 0; i < 7; i++){
                cout << days_of_the_week[i] << endl;
                cout << "================\n" << endl;
                weekMeals[i]->DailyMeals::check_goals(calorie_limit, protein_goal);
                cout << "\n";
            }
            break;
        //**************************************** EXIT PROGRAM ****************************************
        case 6:
            cout << "Exiting Program !!" << endl;
            return 1;
        default:
            cout << "Invalid option. Please select a value between 1 to 6" << endl;
            break;
    }
    
    }
}

