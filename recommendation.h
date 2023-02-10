#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H
#include "basic_questionnaire.h"
#include "physical_questionnaire.h"
#include "food_questionnaire.h"
#include "sleep_questionnaire.h"
#include "water_questionnaire.h"
#include "goals_questionnaire.h"
#include <QString>
#include <QFile>
#include <QTextStream>

class Recommendation
{
    int caloriesNorm;
    Questionnaire *basicQuestionnaire;
    PhysicalQuestionnaire *physicQuestionnaire;
    FoodQuestionnaire *foodQuestionnaire;
    SleepQuestionnaire *sleepQuestionnaire;
    WaterQuestionnaire *waterQuestionnaire;

public:
    Recommendation(Questionnaire *bQ, PhysicalQuestionnaire *pQ, FoodQuestionnaire *fQ, SleepQuestionnaire *sQ, WaterQuestionnaire *wQ, GoalsQuestionnaire *gQ);
    int calculateNorm();
    double calculateBodyMassIndex();
    int calculateCaloriesForSlowLoss();
    int calculateCaloriesForFastLoss();
    double calculateWaterNorm();
    QString getBodyMassIndexRecommendation();
    QString getWaterRecommendation();
    QString getPhActivityRecommendation();
    QString getFoodRecommedation();
    QString getSleepRecommendation();
    Goal getGoal();
    int getAmountOfDays(bool slow, int countKg);
    GoalsQuestionnaire *goalQuestionnaire;
    QString getFoodRecommendation();

};

#endif // RECOMMENDATION_H
