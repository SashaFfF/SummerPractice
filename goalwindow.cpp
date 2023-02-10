#include "goalwindow.h"
#include "ui_goalwindow.h"
#include <QMessageBox>

GoalWindow::GoalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoalWindow)
{
    ui->setupUi(this);
    QWidget::setAttribute(Qt::WA_DeleteOnClose, true);
    ui->label_2->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->lineEdit->setMaxLength(2);
    ui->lineEdit->setValidator(new QDoubleValidator());
    recommendationWindow = new RecommendationWindow();
    setInterfaceStyle();
}

GoalWindow::~GoalWindow()
{
    delete ui;
}

void GoalWindow::on_seeResultsButton_clicked()
{
    static bool flag=true;
    Goal g;
  int w=0;

    if(ui->radioButton->isChecked()){
        g = lose_weight;
    }
    else if(ui->radioButton_2->isChecked()){
        g = maintain_weight;
        w = (ui->lineEdit->text()).toInt();
                goalQuestionnaire = new GoalsQuestionnaire(g, w);
                recommendation = new Recommendation(basicQuestionnaire, physicQuestionnaire, foodQuestionnaire,
                                                   sleepQuestionnaire, waterQuestionnaire, goalQuestionnaire);

                recommendationWindow->recommendation = this->recommendation;
                recommendationWindow->show();
                this->close();
    }
    else {
        QMessageBox::warning(this, "Ошибка","Пожалуйста, заполните все поля!");
        flag=false;
    }
    if(flag){

    if(g == lose_weight){
        if (ui->lineEdit->text()=="" ||ui->lineEdit->text().contains("e")  ) QMessageBox::warning(this, "Ошибка","Пожалуйста, заполните поле ввода!");
        else if (ui->lineEdit->text().toInt()>0.20*basicQuestionnaire->returnWeight()){
            QMessageBox::warning(this, "Ошибка","Изменение веса на введенное Вами количество может повлиять на ваше здоровье!");
        }
        else { w = (ui->lineEdit->text()).toInt();
        goalQuestionnaire = new GoalsQuestionnaire(g, w);
        recommendation = new Recommendation(basicQuestionnaire, physicQuestionnaire, foodQuestionnaire,
                                           sleepQuestionnaire, waterQuestionnaire, goalQuestionnaire);

        recommendationWindow->recommendation = this->recommendation;
        recommendationWindow->show();
        this->close();
        }
    }

    }
    flag=true;
}

void GoalWindow::setInterfaceStyle()
{
    QPixmap pixmap(":/pract/backgroundGoal.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);

    QString color = "qlineargradient(spread:pad, x1:0, y1:0, x2:0.121707, y2:1, stop:0 rgba(129, 59, 95, 255), stop:1 rgba(230, 187, 62, 255));";
    QString press_color =  "qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(198, 82, 188, 255), stop:1 rgba(189, 237, 255, 255));";
    QString hover_color = " qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(248, 31, 134, 255), stop:1 rgba(230, 187, 62, 255));";
    ui->seeResultsButton->setStyleSheet(StyleHelper::getStartButtonsStyle(color, press_color, hover_color));
    ui->lineEdit->setStyleSheet(StyleHelper::getStartLineEditStyle("rgb(230, 175, 14);"));

}


void GoalWindow::on_radioButton_clicked()
{
        ui->label_2->setVisible(true);
        ui->lineEdit->setVisible(true);
}



void GoalWindow::on_radioButton_2_clicked()
{
    ui->label_2->setVisible(false);
    ui->lineEdit->setVisible(false);
}

