#ifndef TESTWINDOW5_H
#define TESTWINDOW5_H

#include <QWidget>
#include "stylehelper.h"
#include "basic_questionnaire.h"
#include "food_questionnaire.h"
#include "physical_questionnaire.h"
#include "sleep_questionnaire.h"
#include "water_questionnaire.h"
#include "goalwindow.h"

namespace Ui {
class TestWindow5;
}

class TestWindow5 : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow5(QWidget *parent = nullptr);
    ~TestWindow5();
    Questionnaire *basicQuestionnaire;
    PhysicalQuestionnaire *physicQuestionnaire;
    FoodQuestionnaire *foodQuestionnaire;
    SleepQuestionnaire * sleepQuestionnaire;

private slots:
    void on_nextPageButton_clicked();

private:
    Ui::TestWindow5 *ui;
    WaterQuestionnaire * waterQuestionnaire;
    void setInterfaceStyle();
    GoalWindow *goalWindow;

};

#endif // TESTWINDOW5_H
