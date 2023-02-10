#include "food_questionnaire.h"

FoodQuestionnaire::FoodQuestionnaire(Food *arr)
{
    for(int i=0; i<19; i++){
        food[i]=arr[i];
    }
}
