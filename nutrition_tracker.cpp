#include <iostream>
#include <string>

enum Day {
    MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
    //   1         2          3         4        5        6        7
};

using namespace std;
// Meal class - nodes of each daily list
// *************************************************************************************
//                                        MEAL CLASS                                   *
// *************************************************************************************
class Meal {
    private:
        string name;
        int calories;
        // For protein uinit will be grams
        int protein;

    public:
        Meal* next;

        // Default constructor for Meal
        Meal(){
            name = "unknown";
            calories = 0;
            protein = 0;
            next = NULL;
        }

        Meal(const std::string& name, int calories, int pro) : name(name), calories(calories), next(NULL), protein(pro) {
            // this is the constructor for when the user gives input
        }
        // Accessor and mutator functions
        void change_calories(int new_cal){
		calories = new_cal;
        }
        void change_name(string new_name){
		name = new_names;
	    }
        void change_protein(new_protein){
		protein = new_protein;
	    }

        int get_calories(){return calories;}
        string get_name(){return name;}
        int get_protein(){return protein;}
};

// DailyMeals - Linked lists made of meals
// *************************************************************************************
//                                    DAILY LIST CLASS                                 *
// *************************************************************************************
class DailyMeals {
public:
    Meal *head_ptr;
    Meal *tail_ptr;
    int num_meals;

    DailyMeals() : head_ptr(NULL), num_meals(0) {
        // List constructor for DailyMeals !!
    }

    // Free all allocated memory (have this out of habit, may not use it)
    ~DailyMeals() {
        Meal* cursor = head_ptr;
        while (cursor != NULL) {
            Meal *temp = cursor;
            cursor = cursor->next;
            delete temp;
        }
    }

    // Add meal to a daily list (adds at the end)
    void add_meal() {
        // Do NOT need to check for duplicates since peopple can ahve the same meal multiple
        // times in a day
        string m_name;
        int m_cal, m_prot;

        cout << "\nEnter Meal Name: " ;
        cin >> m_name;
        cout << "\nEnter Meal Calories: ";
        cin >> m_cal;
        cout << "\nEnter Meal Protien: ";
        cin >> m_prot;

        Meal *newMeal = new Meal(m_name, m_cal, m_prot);
        if(head_ptr == NULL){
            head_ptr = newMeal;
            tail_ptr = head_ptr;
            newMeal->next = NULL;
            return;
        }
        
        // Generate case adding to the end
        tail_ptr->next = newMeal;
        tail_ptr = newMeal;
        newMeal->next = NULL;
        
    }

    // Remove meal from day
    // return true if meal was found and removed
    //  return false if meal was not found
    bool remove_meal(int day, string meal_remove){};

    bool day_empty(){
        return (num_meals == 0);
    }

    // Prints the meals logged in the week
    void display_daily_meals() {
        Meal *current = head_ptr;

        while (current != NULL) {
            cout << current->get_name() << " (" << current->get_protein() << "g protein, "<< current->get_calories() << " calories)" << endl;
            current = current->next;
        }
    }

    Meal* search_meal(string target){
        Meal *cursor = head_ptr;
        while(cursor != NULL){
            if(cursor->name == target)
                return cursor;
            cursor = cursor->next;
        }
        cout << "Meal not Found" << endl;
        return NULL;
    }

    // ADD THESE FUNCTION

    // Go through the list and return the total protein/calories for the day
    int daily_protein(){};
    int daily_calories(){};

    // Retunr meal in the day with the HIGHEST protein
    Meal* most_protein(){};

  
};

// *************************************************************************************
//                                    DAILY LIST CLASS                                 *
// *************************************************************************************

int main() {
    // Important variables needed for the main
    DailyMeals *weekMeals[7];
    bool in_program = true;
    int input;
    int day;
    string meal_name;

    // Initialize array of head_ptrs for the week
    for (int i = 0; i < 7; ++i) {
        // Each item in the array is a default Meal (head of each list)
        weekMeals[i] = new DailyMeals();
    }

// ******************************************     MENU + SWTICH STATEMENT     ************************************************
    while(in_program){
        // Menu output
        cout<< "Welcome to your weekly nutritional tracker !!\n" << "[1] Add Meal\n" << "[2] Remove Meal\n" << "[3] Display Week\n" << "[4] Set Protein Goal\n" << "[5] Exit Program" << endl;
        
        // User input for menu selection
        cout << "Selection: ";
        cin >> input;

        // Switchs statement that operates on user input
        switch(input) {
        //**************************************** ADD A MEAL ****************************************
        case 1:
            cout << "Let's Add a Meal !!\n"<< "Which day are we adding to? : " <<  endl;
            cin >> day;
            // FINISH IMPLEMENTATION

            weekMeals[day-1]->add_meal();


            break;
        //**************************************** REMOVE A MEAL ****************************************
        case 2:
            std::cout << "Which day are we removing from? : " << endl;
            cin >> day;

            // If no meals have been logged for that day yet
            if(weekMeals[day-1]->day_empty()){
                cout << "Day is empty, no meals to remove :(" << endl;
                break;
            }

            cout << "Which meal are we removing" << endl;
            cin >> meal_name;

            // Check if that day has that meal
            if(weekMeals[day-1]->search_meal(meal_name) == NULL){
                break;
            }
            // FINISH IMPLEMENTATION

            break;
        //**************************************** DISPLAY THE WEEK ****************************************
        case 3:
            std::cout << "Printing meals..." << std::endl;
            // Call function to print meals
            break;
        //**************************************** EXIT PROGRAM ****************************************
        case 5:
            cout << "Exiting Program !!" << endl;
            return 1;
        default:
            std::cout << "Invalid option. Please select 1, 2, or 3." << std::endl;
            break;
    }
    
    }
}

