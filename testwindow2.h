#ifndef TESTWINDOW2_H
#define TESTWINDOW2_H

#include <QWidget>
#include "testwindow3.h"
#include "basic_questionnaire.h"
#include "physical_questionnaire.h"

namespace Ui {
class TestWindow2;
}

class TestWindow2 : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow2(QWidget *parent = nullptr);
    ~TestWindow2();
    Questionnaire *basicQuestionnaire;

private slots:
    void on_nextPageButton_clicked();

private:
    Ui::TestWindow2 *ui;
    void setInterfaceStyle();
    TestWindow3 *thirdTestWindow;
    PhysicalQuestionnaire *physicQuestionnaire;
};

#endif // TESTWINDOW2_H
