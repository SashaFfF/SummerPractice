#include "recommendationwindow.h"
#include "ui_recommendationwindow.h"

RecommendationWindow::RecommendationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecommendationWindow)
{
    ui->setupUi(this);
    ui->waterTextEdit->setVisible(false);
    ui->activtextEdit->setVisible(false);
    ui->watertextEdit->setVisible(false);
    ui->FoodtextEdit->setVisible(false);
    ui->NormalCcallineEdit->setVisible(false);
    ui->FastCcalLineEdit->setVisible(false);
    ui->ExtrFastLineEdit->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->SleeptextEdit->setVisible(false);
    ui->IMBlineEdit->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->label_9->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);

    ui->waterTextEdit->setReadOnly(true);
    ui->activtextEdit->setReadOnly(true);
    ui->watertextEdit->setReadOnly(true);
    ui->FoodtextEdit->setReadOnly(true);
    ui->NormalCcallineEdit->setReadOnly(true);
    ui->FastCcalLineEdit->setReadOnly(true);
    ui->ExtrFastLineEdit->setReadOnly(true);
    ui->SleeptextEdit->setReadOnly(true);
    ui->IMBlineEdit->setReadOnly(true);
    setInterfaceStyle();
}

RecommendationWindow::~RecommendationWindow()
{
    delete ui;
}

void RecommendationWindow::on_pushButton_clicked()
{
    if (recommendation->getGoal()==lose_weight){
        ui->FastCcalLineEdit->setVisible(true);
        ui->ExtrFastLineEdit->setVisible(true);
        ui->label_3->setVisible(true);
        ui->label_4->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        int dS = recommendation->getAmountOfDays(true, recommendation->goalQuestionnaire->getWeightDifferent());
        ui->FastCcalLineEdit->setText(" " + QString::number(recommendation->calculateCaloriesForSlowLoss()) + " ккал" + "\n"+QString::number(dS) + "дн.");
        int dF = recommendation->getAmountOfDays(false, recommendation->goalQuestionnaire->getWeightDifferent());
        ui->ExtrFastLineEdit->setText(QString::number(recommendation->calculateCaloriesForFastLoss()) + " ккал" + "\n"+QString::number(dF) +"дн.");
    }
    ui->label_2->setVisible(true);
    ui->IMBlineEdit->setVisible(true);
    ui->NormalCcallineEdit->setVisible(true);
    ui->waterTextEdit->setVisible(true);
    ui->activtextEdit->setVisible(true);
    ui->watertextEdit->setVisible(true);
    ui->FoodtextEdit->setVisible(true);
    ui->SleeptextEdit->setVisible(true);
    ui->pushButton->setVisible(false);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_5->setVisible(true);
    ui->pushButton_6->setVisible(true);
    ui->label->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_5->setVisible(true);
    ui->label_6->setVisible(true);
    ui->label_7->setVisible(true);
    ui->label_8->setVisible(true);
    ui->label_9->setVisible(true);





    ui->waterTextEdit->setText(QString::number(recommendation->calculateWaterNorm())+" л");
    ui->IMBlineEdit->setText("Ваш ИМТ: "+QString::number(recommendation->calculateBodyMassIndex())+"  "+recommendation->getBodyMassIndexRecommendation());
    ui->activtextEdit->setText(recommendation->getPhActivityRecommendation());
    ui->watertextEdit->setText(recommendation->getWaterRecommendation());
    ui->FoodtextEdit->setText(recommendation->getFoodRecommedation());
    ui->NormalCcallineEdit->setText("  " + QString::number(recommendation->calculateNorm())+" ккал");
    ui->SleeptextEdit->setText(recommendation->getSleepRecommendation());
    QString background_color ="rgb(255, 255, 255);";
    QString border_color = "blue;";
    ui->pushButton_3->setStyleSheet(StyleHelper::getSmallButtonsStyle(background_color, border_color));
    ui->pushButton_2->setStyleSheet(StyleHelper::getSmallButtonsStyle(background_color, border_color));
    ui->pushButton_2->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Для того, чтобы безопасно и умеренно похудеть на указанный вами вес, вам необходимо придерживаться следующих норм каллорий.Тогда Вы сможите за указанный период времени безопасно сбросить вес. </td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
    ui->pushButton_3->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Для того, чтобы похудеть в ускоренном режиме на указанный вами вес, вам необходимо придерживаться следующих норм каллорий. Тогда Вы сможите за указанный период времени безопасно сбросить вес.</td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
    ui->pushButton_4->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Индекс массы тела (ИМТ) — это величина, демонстрирующая соответствие веса человека его росту. С помощью ИМТ можно сделать приблизительный вывод о комплекции человека: страдает ли он от ожирения, недобирает вес или находится в форме.</td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
    ui->pushButton_5->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Ваша норма воды в день.</td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
    ui->pushButton_6->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Советы для поддержания хорошего сна: 1.	Придерживайтесь регулярного графика сна. Для нормализации режима отдыха нужно каждый день ложиться спать в одно и тоже время, это касается и утренних подъемов. 2.Нейтрализуйте все раздражающие факторы во время сна. Отдыхайте ночью только в темной комнате без какого-либо источника света. 3.Не ешьте перед сном. Поздний прием пищи способствует набору лишнего веса и снижает эффект попыток сбросить лишний вес. 5.	Ложитесь спать рано (22:00-23:00). </td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
        ui->pushButton_6->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
        "    <table width=\"250\"><tr><td width=\"250\">Советы для поддержания хорошего сна: </td></tr>\n"
        "    <tr><td width=\"250\">1.Придерживайтесь регулярного графика сна. Для нормализации режима отдыха нужно каждый день ложиться спать в одно и тоже время, это касается и утренних подъемов. 2.Нейтрализуйте все раздражающие факторы во время сна. Отдыхайте ночью только в темной комнате без какого-либо источника света. 3.Не ешьте перед сном. Поздний прием пищи способствует набору лишнего веса и снижает эффект попыток сбросить лишний вес. 5.Ложитесь спать рано (22:00-23:00).</td></tr>\n"
        "    </table>\n"
        "    </html>", 0));


}

void RecommendationWindow::setInterfaceStyle()
{
    QPixmap pixmap(":/pract/backgroundRecommendation(1).png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);

    QString color = "qlineargradient(spread:pad, x1:0.51739, y1:1, x2:0.483, y2:0, stop:0 rgba(198, 33, 168, 255), stop:1 rgba(103, 214, 255, 255));";
    QString press_color =  "qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(198, 82, 188, 255), stop:1 rgba(189, 237, 255, 255));";
    QString hover_color = "qlineargradient(spread:pad, x1:0.51739, y1:1, x2:0.483, y2:0, stop:0 rgba(255, 89, 175, 255), stop:1 rgba(103, 214, 255, 255));";
    ui->pushButton->setStyleSheet(StyleHelper::getStartButtonsStyle(color, press_color, hover_color));
    QString colorLineEdit = "rgb(255, 96, 181);";
    ui->IMBlineEdit->setStyleSheet(StyleHelper::getStartLineEditStyle(colorLineEdit));
    ui->NormalCcallineEdit->setStyleSheet(StyleHelper::getStartLineEditStyle(colorLineEdit));
    QString colorLineEdit2 = "rgb(203, 219, 255);";
    ui->FastCcalLineEdit->setStyleSheet(StyleHelper::getStartLineEditStyle(colorLineEdit2));
    ui->ExtrFastLineEdit->setStyleSheet(StyleHelper::getStartLineEditStyle(colorLineEdit2));
    QString colorTextEdit = "rgb(213, 255, 212);";
    ui->activtextEdit->setStyleSheet(StyleHelper::getStartTextEditStyle(colorTextEdit));
    QString colorTextEdit2 = "rgb(213, 255, 212);";
    ui->FoodtextEdit->setStyleSheet(StyleHelper::getStartTextEditStyle(colorTextEdit2));
    ui->SleeptextEdit->setStyleSheet(StyleHelper::getStartTextEditStyle(colorTextEdit2));
    QString colorTextEdit3 = "rgb(194, 208, 255);";
    ui->waterTextEdit->setStyleSheet(StyleHelper::getStartTextEditStyle(colorTextEdit3));
    ui->watertextEdit->setStyleSheet(StyleHelper::getStartTextEditStyle(colorTextEdit3));
    ui->pushButton_5->setStyleSheet(StyleHelper::getSmallButtonsStyle("white;", "blue;"));
    ui->pushButton_4->setStyleSheet(StyleHelper::getSmallButtonsStyle("white;", "blue;"));
    ui->pushButton_6->setStyleSheet(StyleHelper::getSmallButtonsStyle("white;", "blue;"));
    QString colorIMT = "rgb(255, 243, 243);";
    ui->IMBlineEdit->setStyleSheet(StyleHelper::getStartTextEditStyle(colorIMT));

}

