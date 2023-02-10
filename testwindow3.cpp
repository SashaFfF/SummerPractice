#include "testwindow3.h"
#include "ui_testwindow3.h"
#include <QMessageBox>

TestWindow3::TestWindow3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWindow3)
{
    ui->setupUi(this);
    QWidget::setAttribute(Qt::WA_DeleteOnClose, true);
    fourthWindow = new TestWindow4();
    setInterfaceStyle();
}

TestWindow3::~TestWindow3()
{
    delete ui;
}

void TestWindow3::on_nextPageButton_clicked()
{
    static bool flag=false;
    Food arr[19];
    for(int k=0;k<19;k++){
        arr[k]=nothing;
    }

    if(ui->checkBox->isChecked()){
        arr[0]=meat;

    }
    if(ui->checkBox_2->isChecked()){
        arr[1]=butter;

    }
    if(ui->checkBox_3->isChecked()){
        arr[2]=bird;

    }
    if(ui->checkBox_4->isChecked()){
        arr[3]=eggs;

    }
    if(ui->checkBox_5->isChecked()){
        arr[4]=fish;

    }
    if(ui->checkBox_6->isChecked()){
        arr[5]=dairy;

    }
    if(ui->checkBox_7->isChecked()){
        arr[6]=oils;

    }
    if(ui->checkBox_8->isChecked()){
        arr[7]=beans;

    }
    if(ui->checkBox_9->isChecked()){
        arr[8]=nuts;

    }
    if(ui->checkBox_10->isChecked()){
        arr[9]=citrus;

    }
    if(ui->checkBox_11->isChecked()){
        arr[10]=berries;

    }
    if(ui->checkBox_12->isChecked()){
        arr[11]=vegetables;

    }
    if(ui->checkBox_13->isChecked()){
        arr[12]=fruits;

    }
    if(ui->checkBox_14->isChecked()){
        arr[13]=dried_fruits;

    }
    if(ui->checkBox_15->isChecked()){
        arr[14]=bread;

    }
    if(ui->checkBox_16->isChecked()){
        arr[15]=rice;

    }
    if(ui->checkBox_17->isChecked()){
        arr[16]=cereals;

    }
    if(ui->checkBox_18->isChecked()){
        arr[17]=pasta;

    }
     for(int i = 0; i<19; i++){
         if(arr[i]!= nothing){
             flag=true;
             break;
         }
     }

    if (flag){
        foodQuestionnaire = new FoodQuestionnaire(arr);
        fourthWindow->basicQuestionnaire = this->basicQuestionnaire;
        fourthWindow->physicQuestionnaire = this->physicQuestionnaire;
        fourthWindow->foodQuestionnaire=this->foodQuestionnaire;
        fourthWindow->show();
        this->close();
    }
    else{
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберете поля!");
    }

}

void TestWindow3::setInterfaceStyle()
{
    QPixmap pixmap(":/pract/backgroundTest3.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);

    QString color = "qlineargradient(spread:pad, x1:0, y1:0.068, x2:0, y2:1, stop:0 rgba(28, 160, 172, 255), stop:0.97561 rgba(249, 131, 10, 255), stop:1 rgba(249, 193, 48, 255));";
    QString press_color =  "qlineargradient(spread:pad, x1:0, y1:0.068, x2:0, y2:1, stop:0 rgba(0, 158, 172, 255), stop:0.97561 rgba(249, 126, 0, 255), stop:1 rgba(249, 193, 48, 255));";
    QString hover_color = "qlineargradient(spread:pad, x1:0, y1:0.068, x2:0, y2:1, stop:0 rgba(91, 165, 172, 255), stop:0.97561 rgba(249, 148, 45, 255), stop:1 rgba(249, 193, 48, 255));";
    ui->nextPageButton->setStyleSheet(StyleHelper::getStartButtonsStyle(color, press_color, hover_color));

}


