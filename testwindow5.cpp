#include "testwindow5.h"
#include "ui_testwindow5.h"
#include <QMessageBox>

TestWindow5::TestWindow5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWindow5)
{
    ui->setupUi(this);
    QWidget::setAttribute(Qt::WA_DeleteOnClose, true);
    goalWindow = new GoalWindow();
    setInterfaceStyle();
}

TestWindow5::~TestWindow5()
{
    delete ui;
}

void TestWindow5::setInterfaceStyle()
{
    QPixmap pixmap(":/pract/backgroundTest5.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);

    QString color = "qlineargradient(spread:pad, x1:0, y1:0, x2:0.000121951, y2:1, stop:0 rgba(211, 232, 233, 255), stop:0.995122 rgba(25, 52, 111, 255), stop:1 rgba(255, 255, 255, 255));";
    QString press_color =  "qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(198, 82, 188, 255), stop:1 rgba(189, 237, 255, 255));";
    QString hover_color = "qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(233, 233, 233, 255), stop:0.995122 rgba(94, 104, 255, 255), stop:1 rgba(255, 255, 255, 255));";
    ui->nextPageButton->setStyleSheet(StyleHelper::getStartButtonsStyle(color, press_color, hover_color));

}

void TestWindow5::on_nextPageButton_clicked()
{
    static bool flag=true;
    double amount;
    if(ui->radioButton->isChecked()){
        amount = 0.75;
    }
    else if(ui->radioButton_2->isChecked()){
        amount = 1.25;
    }
    else if(ui->radioButton_3->isChecked()){
        amount = 1.75;
    }
    else if(ui->radioButton_4->isChecked()){
        amount = 2.25;
    }
    else if(ui->radioButton_5->isChecked()){
        amount = 2.75;
    }
    else if(ui->radioButton_6->isChecked()){
        amount = 3.25;
    }
    else{
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля!");
        flag=false;
    }
    if (flag){
    waterQuestionnaire = new WaterQuestionnaire(amount);
    goalWindow->waterQuestionnaire = this->waterQuestionnaire;
    goalWindow->basicQuestionnaire = this->basicQuestionnaire;
    goalWindow->physicQuestionnaire = this->physicQuestionnaire;
    goalWindow->foodQuestionnaire = this->foodQuestionnaire;
    goalWindow->sleepQuestionnaire = this->sleepQuestionnaire;
    goalWindow->show();
    this->close();
    }
    flag=true;
}

