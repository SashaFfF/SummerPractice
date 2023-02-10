#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <testwindow.h>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_startTestButton_clicked();

    void on_aboutButton_clicked();

private:
    Ui::MainWindow *ui;
    TestWindow *firstTestWindow;
    void setInterfaceStyle();

};
#endif // MAINWINDOW_H
