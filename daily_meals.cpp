#include "daily_meals.h"


using namespace std;


    Meal *head_ptr;
    Meal *tail_ptr;
    int num_meals;

    // // Returns true if list is empty, false if not
    // bool DailyMeals::day_empty(){
    //     return (num_meals == 0);
    // }

    // Returns Meal pointer to target
    Meal* DailyMeals::search_meal(string target){
        Meal *cursor = head_ptr;
        while(cursor != NULL){
            if(cursor->get_name() == target)
                return cursor;
            cursor = cursor->next;
        }
        cout << "Meal not Found" << endl;
        return NULL;
    }

    // Add meal to a daily list (adds at the end)
    void DailyMeals::add_meal() {
        // Do NOT need to check for duplicates since peopple can ahve the same meal multiple
        // times in a day
        string m_name;
        int m_cal, m_prot;

        cout << "\nEnter Meal Name, Calories, Protein: " ;
        cin >> m_name >> m_cal >> m_prot;
       

        Meal *newMeal = new Meal(m_name, m_cal, m_prot);
        if(head_ptr == NULL){
            head_ptr = newMeal;
            tail_ptr = head_ptr;
            newMeal->next = NULL;

            num_meals++;

            return;
        }
        
        // Generate case adding to the end
        tail_ptr->next = newMeal;
        tail_ptr = newMeal;
        newMeal->next = NULL;
        num_meals++;

        cout << m_name << " has been added!" << endl;
        
    }

    // Remove meal from day
    bool DailyMeals::remove_meal(){
        string delete_meal;
        cout << "Meal to remove: ";
        cin >> delete_meal;

        Meal* temp = search_meal(delete_meal);

        // Meal not found
        if(temp == NULL)
            return false;

        // Case: Deleting head_ptr
        if(temp == head_ptr){
            delete temp;

            head_ptr = NULL;
            tail_ptr = NULL;
            num_meals = 0;

            return true;
        }

        // Prev is pointer before target
        Meal* prev = head_ptr;
        while(prev->next != temp){
            prev = prev->next;
        }

        // Case deleting end
        if(temp == tail_ptr)
            tail_ptr = prev;

        // Adjust pointers
        prev->next = temp->next;
        delete temp;
        
        // Successfully removed
        return true;
    }

    

    // Prints the meals logged in the week + calories and protein information
    void DailyMeals::display_daily_meals() {
        Meal *current = head_ptr;

        while (current != NULL) {
            cout << "--> " << current->get_name() << " (" << current->get_protein() << "g protein, "<< current->get_calories() << " calories)" << endl;
            current = current->next;
        }
    }

    // Go through the list and return the total grams of protein for the day
    int DailyMeals::total_daily_protein(){
        if(day_empty())
            return 0;
        // To be returned
        int total_protein = 0;

        Meal *cursor = head_ptr;
        while(cursor != NULL)
        {
            total_protein += cursor->get_protein();
        }

        return total_protein;
    }
    
    // Go through the list and return the total calories for the day
    int DailyMeals::total_daily_calories(){
        if(day_empty())
            return 0;
        // To be returned
        int total_calories = 0;

        Meal *cursor = head_ptr;
        while(cursor != NULL)
        {
            total_calories += cursor->get_protein();
        }

        return total_calories;
    }

    //
    void DailyMeals::check_goals(int pgoal, int climit){
        // Checking relative to calorie limit ______________________
        int c_difference = climit - total_daily_calories();
        if(c_difference == 0){
            cout << "Hit Calorie Limit" << endl;
        }
        else if(c_difference < 0){
            cout<< "Exceeded  Calorie Limit" << endl;
        }
        else{
            cout << c_difference << " Calroies Available" << endl;
        }

        // Checking relative to protein goal ________________________
        int p_difference = pgoal - total_daily_protein();
        if(p_difference >= 0){
            cout << "Hit Protein Goal" << endl;
        }
        else{
            cout << p_difference << "g Below Protein Goal" << endl;
        }

    }
    // Return meal in the day with the HIGHEST protein
    //Meal* most_protein(){};


  

