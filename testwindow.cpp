#include "testwindow.h"
#include "qvalidator.h"
#include "ui_testwindow.h"
#include <QMessageBox>

TestWindow::TestWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    QWidget::setAttribute(Qt::WA_DeleteOnClose, true);//это строка необходима для того, чтобы после вызова метода close() окно не просто закрывалось, но и в дальнейшем удалялось
    secondTestWindow = new TestWindow2();
    ui->ageLineEdit->setReadOnly(true);
    ui->heightLineEdit->setMaxLength(3);
    ui->weightLineEdit->setMaxLength(3);
    ui->heightLineEdit->setValidator(new QDoubleValidator());
    ui->weightLineEdit->setValidator(new QDoubleValidator());
    ui->warningLineEdit->setVisible(false);
    setInterfaceStyle();
}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::setInterfaceStyle()
{
    QPixmap pixmap(":/pract/backgroundTest.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
    QString color = " qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(144, 15, 34, 255), stop:0.985366 rgba(255, 101, 101, 255), stop:1 rgba(255, 255, 255, 255));";
    QString press_color = " qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(118, 31, 39, 255), stop:0.985366 rgba(227, 90, 90, 255), stop:1 rgba(255, 255, 255, 255));";
    QString hover_color = " qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(163, 42, 54, 255), stop:0.985366 rgba(255, 101, 101, 255), stop:1 rgba(255, 255, 255, 255));";
    ui->nextPageButton->setStyleSheet(StyleHelper::getStartButtonsStyle(color, press_color, hover_color));
    QString lineEditColor = "qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(208, 57, 57, 252), stop:0.965854 rgba(226, 99, 41, 244), stop:1 rgba(255, 255, 255, 255))";
    ui->ageLineEdit->setStyleSheet(StyleHelper::getStartLineEditStyle(lineEditColor));
    ui->heightLineEdit->setStyleSheet(StyleHelper::getStartLineEditStyle(lineEditColor));
    ui->weightLineEdit->setStyleSheet(StyleHelper::getStartLineEditStyle(lineEditColor));
    ui->warningLineEdit->setStyleSheet(StyleHelper::getStartLineEditStyle("white;"));
}


void TestWindow::on_ageHorizontalSlider_valueChanged(int value)
{
    ui->ageLineEdit->setText(QString::number(value));

}


void TestWindow::on_nextPageButton_clicked()
{
    if (ui->weightLineEdit->text()=="" || ui->heightLineEdit->text()=="" || ui->ageLineEdit->text()=="" || (ui->maleRadioButton->isChecked()==false && ui->femaleRadioButton->isChecked()==false) )
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля!");
    else
        if(ui->heightLineEdit->text().toInt()<100 || ui->heightLineEdit->text().toInt()>250 || ui->heightLineEdit->text().contains("e")){
        ui->warningLineEdit->setVisible(true);
        ui->warningLineEdit->setText("НЕкорректный рост");
    } else
            if(ui->weightLineEdit->text().toInt()<40 || ui->weightLineEdit->text().toInt()>300 || ui->weightLineEdit->text().contains("e")){
    ui->warningLineEdit->setVisible(true);
    ui->warningLineEdit->setText("НЕкорректный вес");
} else {int w  = (ui->weightLineEdit->text()).toInt();
    int h = (ui->heightLineEdit->text()).toInt();
    Gender g = ui->femaleRadioButton->isChecked()?female:male;
    int a = ui->ageHorizontalSlider->value();
    basicQuestionnaire = new Questionnaire(w,h,a,g);
    secondTestWindow->basicQuestionnaire = this->basicQuestionnaire;
    secondTestWindow->show();
    this->close();
    }

    //this->~TestWindow();

}

