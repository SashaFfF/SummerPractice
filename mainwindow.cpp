#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stylehelper.h"
#include <QStyleOption>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap(":/pract/background.png");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);
    firstTestWindow = new TestWindow();
    ui->about->setVisible(false);
    setInterfaceStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    //инициализация объекта через метод initForm
    opt.initFrom(this);
    QPainter p(this);
    //drawPrimitive отвечает за прорисовку нашего widget
    //при рисовании widget учитываются стиливые особенности
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
    QWidget::paintEvent(event);

}

void MainWindow::on_startTestButton_clicked()
{
    firstTestWindow->show();
    this->close();
}

void MainWindow::setInterfaceStyle()
{
    QString color = "qlineargradient(spread:pad, x1:0, y1:0.074, x2:0, y2:1, stop:0 rgba(21, 236, 9, 255), stop:1 rgba(255, 255, 0, 255));";
    QString press_color = "qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(83, 201, 76, 255), stop:1 rgba(255, 255, 66, 255));";
    QString hover_color = "qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(18, 201, 8, 255), stop:1 rgba(255, 255, 0, 255));";
    //this->setStyleSheet(StyleHelper::getMainWidgetsStyle("background-image: url(:/pract/new_background.png);"));
    ui->startTestButton->setStyleSheet(StyleHelper::getStartButtonsStyle(color, press_color, hover_color));
    ui->aboutButton->setStyleSheet(StyleHelper::getStartButtonsStyle(color, press_color, hover_color));

}


void MainWindow::on_aboutButton_clicked()
{
    ui->name->setVisible(false);
    ui->about->setVisible(true);
    ui->about->setText("Здравствуйте! Наш тест создан для того, чтобы дать Вам рекомендацию по важнейшим составляющим жизни человека. По таким, как сон, употребление воды, рацион питания, физическая активность. Также тест подсчитает Вашу дневную норму калорий как для поддержания веса, так и для похудения в ограниченный срок. Любите и берегите себя!");

}

