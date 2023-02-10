#ifndef TESTWINDOW3_H
#define TESTWINDOW3_H

#include <QWidget>
#include "testwindow4.h"
#include "stylehelper.h"
#include "basic_questionnaire.h"
#include "physical_questionnaire.h"
#include "food_questionnaire.h"

namespace Ui {
class TestWindow3;
}

class TestWindow3 : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow3(QWidget *parent = nullptr);
    ~TestWindow3();
    Questionnaire *basicQuestionnaire;
    PhysicalQuestionnaire *physicQuestionnaire;

private slots:
    void on_nextPageButton_clicked();

private:
    Ui::TestWindow3 *ui;
    void setInterfaceStyle();
    FoodQuestionnaire *foodQuestionnaire;
    TestWindow4 *fourthWindow;
};

#endif // TESTWINDOW3_H
