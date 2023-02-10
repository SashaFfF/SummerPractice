#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include "stylehelper.h"
#include "testwindow2.h"
#include "basic_questionnaire.h"

namespace Ui {
class TestWindow;
}

class TestWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = nullptr);
    ~TestWindow();

private slots:

    void on_ageHorizontalSlider_valueChanged(int value);

    void on_nextPageButton_clicked();

private:
    Ui::TestWindow *ui;
    void setInterfaceStyle();
    TestWindow2 *secondTestWindow;
    Questionnaire *basicQuestionnaire;

};

#endif // TESTWINDOW_H
