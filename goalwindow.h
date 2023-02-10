#ifndef GOALWINDOW_H
#define GOALWINDOW_H

#include <QWidget>

#include "stylehelper.h"
#include "basic_questionnaire.h"
#include "food_questionnaire.h"
#include "physical_questionnaire.h"
#include "sleep_questionnaire.h"
#include "water_questionnaire.h"
#include "goals_questionnaire.h"
#include "recommendation.h"
#include "recommendationwindow.h"
#include <qvalidator.h>

namespace Ui {
class GoalWindow;
}

class GoalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GoalWindow(QWidget *parent = nullptr);
    ~GoalWindow();
    Questionnaire *basicQuestionnaire;
    PhysicalQuestionnaire *physicQuestionnaire;
    FoodQuestionnaire *foodQuestionnaire;
    SleepQuestionnaire * sleepQuestionnaire;
    WaterQuestionnaire *waterQuestionnaire;

private slots:
    void on_seeResultsButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::GoalWindow *ui;
    void setInterfaceStyle();
    GoalsQuestionnaire *goalQuestionnaire;
    RecommendationWindow *recommendationWindow;
    Recommendation *recommendation;

};

#endif // GOALWINDOW_H
