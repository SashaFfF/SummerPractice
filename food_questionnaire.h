#ifndef FOOD_QUESTIONNAIRE_H
#define FOOD_QUESTIONNAIRE_H


enum Food
{
    nothing,
    meat,
    butter,
    bird,
    eggs,
    fish,
    dairy,
    oils,
    beans,
    nuts,
    citrus,
    berries,
    vegetables,
    fruits,
    dried_fruits,
    bread,
    rice,
    cereals,
    pasta
};

class FoodQuestionnaire
{
    Food food[19];

public:
    FoodQuestionnaire(Food *arr);
    friend class Recommendation;
};

#endif // FOOD_QUESTIONNAIRE_H
