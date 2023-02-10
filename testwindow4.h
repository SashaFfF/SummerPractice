#ifndef TESTWINDOW4_H
#define TESTWINDOW4_H

#include <QWidget>
#include<QMessageBox>
#include "testwindow5.h"
#include "stylehelper.h"
#include "basic_questionnaire.h"
#include "food_questionnaire.h"
#include "physical_questionnaire.h"
#include "sleep_questionnaire.h"

namespace Ui {
class TestWindow4;
}

class TestWindow4 : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow4(QWidget *parent = nullptr);
    ~TestWindow4();
    Questionnaire *basicQuestionnaire;
    PhysicalQuestionnaire *physicQuestionnaire;
    FoodQuestionnaire *foodQuestionnaire;

private slots:
    void on_nextPageButton_clicked();

private:
    Ui::TestWindow4 *ui;
    void setInterfaceStyle();
    SleepQuestionnaire *sleepQuestionnaire;
    TestWindow5 *fifthWindow;
};

#endif // TESTWINDOW4_H
