#include "testwindow4.h"
#include "ui_testwindow4.h"

TestWindow4::TestWindow4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWindow4)
{
    ui->setupUi(this);
    QWidget::setAttribute(Qt::WA_DeleteOnClose, true);
    fifthWindow = new TestWindow5();
    setInterfaceStyle();
}

TestWindow4::~TestWindow4()
{
    delete ui;
}

void TestWindow4::on_nextPageButton_clicked()
{
    static bool flag=true;
    double amount;
    if ( ui->radioButton->isChecked()==false &&  ui->radioButton_2->isChecked()==false &&  ui->radioButton_3->isChecked()==false &&  ui->radioButton_4->isChecked()==false &&  ui->radioButton_5->isChecked()==false || ui->radioButton_6->isChecked()==false &&  ui->radioButton_7->isChecked()==false &&  ui->radioButton_8->isChecked()==false &&  ui->radioButton_9->isChecked()==false &&  ui->radioButton_10->isChecked()==false &&  ui->radioButton_11->isChecked()==false &&  ui->radioButton_12->isChecked()==false) QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите варианты ответов!");
    else {
    if(ui->radioButton->isChecked()){
        amount = 9.5;
    }
    else if(ui->radioButton_2->isChecked()){
        amount = 8.5;
    }
    else if(ui->radioButton_3->isChecked()){
        amount = 7.5;
    }
    else if(ui->radioButton_4->isChecked()){
        amount = 6.5;
    }
    else{
        amount = 5.5;
    }
    bool good_time;
    if(ui->radioButton_6->isChecked()){
       good_time=true;
    }
    else if(ui->radioButton_7->isChecked()){
        good_time = true;
    }
    else if(ui->radioButton_8->isChecked()){
        good_time = true;
    }
    else if(ui->radioButton_9->isChecked()){
        good_time = false;
    }
    else if(ui->radioButton_10->isChecked()){
        good_time = false;
    }
    else if(ui->radioButton_11->isChecked()){
        good_time = false;
    }
    else{
        good_time = false;
    }
    if (flag){
        sleepQuestionnaire = new SleepQuestionnaire(amount, good_time);
        fifthWindow->sleepQuestionnaire = this->sleepQuestionnaire;
        fifthWindow->basicQuestionnaire = this->basicQuestionnaire;
        fifthWindow->physicQuestionnaire = this->physicQuestionnaire;
        fifthWindow->foodQuestionnaire = this->foodQuestionnaire;
        fifthWindow->show();
        this->close();
    }
    }
}

void TestWindow4::setInterfaceStyle()
{
    QPixmap pixmap(":/pract/backgroundTest4.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);

    QString color = "qlineargradient(spread:pad, x1:0.51739, y1:1, x2:0.483, y2:0, stop:0 rgba(198, 33, 168, 255), stop:1 rgba(103, 214, 255, 255));";
    QString press_color =  "qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(198, 82, 188, 255), stop:1 rgba(189, 237, 255, 255));";
    QString hover_color = "qlineargradient(spread:pad, x1:0.51739, y1:1, x2:0.483, y2:0, stop:0 rgba(255, 89, 175, 255), stop:1 rgba(103, 214, 255, 255));";
    ui->nextPageButton->setStyleSheet(StyleHelper::getStartButtonsStyle(color, press_color, hover_color));
}

