#include "testwindow2.h"
#include "ui_testwindow2.h"
#include <QMessageBox>

TestWindow2::TestWindow2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWindow2)
{
    ui->setupUi(this);
    QWidget::setAttribute(Qt::WA_DeleteOnClose, true);
    thirdTestWindow = new TestWindow3();
    setInterfaceStyle();
}

TestWindow2::~TestWindow2()
{
    delete ui;
}

void TestWindow2::on_nextPageButton_clicked()
{
    if ( ui->radioButton->isChecked()==false &&  ui->radioButton_2->isChecked()==false &&  ui->radioButton_3->isChecked()==false &&  ui->radioButton_4->isChecked()==false &&  ui->radioButton_5->isChecked()==false) QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля!");
    else {
    double PAC;
    if(ui->radioButton->isChecked()){
        PAC = 1.2;
    }
    else if(ui->radioButton_2->isChecked()){
        PAC = 1.375;
    }
    else if(ui->radioButton_3->isChecked()){
        PAC = 1.55;
    }
    else if(ui->radioButton_4->isChecked()){
        PAC = 1.7;
    }
    else{
        PAC = 1.9;
    }    
    physicQuestionnaire = new PhysicalQuestionnaire(PAC);
    thirdTestWindow->basicQuestionnaire=this->basicQuestionnaire;
    thirdTestWindow->physicQuestionnaire=this->physicQuestionnaire;
    thirdTestWindow->show();
    this->close();
    }
}

void TestWindow2::setInterfaceStyle()
{
    QPixmap pixmap(":/pract/backgroundTest2.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);

    QString color = "qlineargradient(spread:pad, x1:0, y1:0, x2:0.015, y2:1, stop:0 rgba(0, 33, 122, 255), stop:1 rgba(9, 9, 227, 255));";
    QString press_color =  "qlineargradient(spread:pad, x1:0, y1:0, x2:0.015, y2:1, stop:0 rgba(0, 33, 122, 255), stop:1 rgba(9, 9, 227, 255));";
    QString hover_color = "qlineargradient(spread:pad, x1:0, y1:0, x2:0.015, y2:1, stop:0 rgba(47, 55, 189, 255), stop:1 rgba(80, 80, 227, 255));";
    ui->nextPageButton->setStyleSheet(StyleHelper::getStartButtonsStyle(color, press_color, hover_color));

    QString background_color ="rgb(255, 255, 255);";
    QString border_color = "blue;";
    ui->pushButton->setStyleSheet(StyleHelper::getSmallButtonsStyle(background_color, border_color));
    ui->pushButton_2->setStyleSheet(StyleHelper::getSmallButtonsStyle(background_color, border_color));
    ui->pushButton_3->setStyleSheet(StyleHelper::getSmallButtonsStyle(background_color, border_color));
    ui->pushButton_4->setStyleSheet(StyleHelper::getSmallButtonsStyle(background_color, border_color));
    ui->pushButton_5->setStyleSheet(StyleHelper::getSmallButtonsStyle(background_color, border_color));

    //    ui->pushButton->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    //    "    <table width=\"25\"><tr><td width=\"25\">ghb</td></tr>\n"
    //    "    <tr><td width=\"25\">a ea ea ea ea ea ea ea ea ea ea ea ea ea ea ea ea e</td></tr>\n"
    //    "    </table>\n"
    //    "    </html>", 0));

//        ui->pushButton->setToolTip("Минимальная — у вас сидячая работа и нет физических нагрузок.");
//        ui->pushButton_2->setToolTip("Низкая — вы изредка тренируетесь и достаточно активны в быту.");
//        ui->pushButton_3->setToolTip("Средняя — вы тренируетесь 3–5 раз в неделю (легкие упражнения не менее 20 минут) или работа средней тяжести.");
//        ui->pushButton_4->setToolTip("Высокая — вы тренируетесь 6–7 раз в неделю (интенсивные упражнения от 30 до 60 минут).");
//        ui->pushButton_5->setToolTip("Очень высокая — вы тренируетесь 6 и более раз в неделю. Также сюда относятся профессии, связанные с физической работой - строительные работы, сельское хозяйство, ландшафтные работы.");


    ui->pushButton->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Минимальная — у вас сидячая работа и нет физических нагрузок.</td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
    ui->pushButton_2->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Низкая — вы изредка тренируетесь и достаточно активны в быту.</td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
    ui->pushButton_3->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Средняя — вы тренируетесь 3–5 раз в неделю (легкие упражнения не менее 20 минут) или работа средней тяжести.</td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
    ui->pushButton_4->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Высокая — вы тренируетесь 6–7 раз в неделю (интенсивные упражнения от 30 до 60 минут).</td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
    ui->pushButton_5->setToolTip(QApplication::translate("MainWindow", "    <html>\n"
    "    <table width=\"200\"><tr><td width=\"200\">Очень высокая — вы тренируетесь 6 и более раз в неделю.</td></tr>\n"
    "    <tr><td width=\"200\">Также сюда относятся профессии, связанные с физической работой - строительные работы, сельское хозяйство, ландшафтные работы.</td></tr>\n"
    "    </table>\n"
    "    </html>", 0));
}

