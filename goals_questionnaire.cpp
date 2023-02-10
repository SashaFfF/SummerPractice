#include "goals_questionnaire.h"

GoalsQuestionnaire::GoalsQuestionnaire(Goal g, int w)
{
    goal = g;
    weight_difference = w;
}

int GoalsQuestionnaire::getWeightDifferent()
{
    return weight_difference;
}
