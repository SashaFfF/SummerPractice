#ifndef RECOMMENDATIONWINDOW_H
#define RECOMMENDATIONWINDOW_H

#include <QWidget>
#include "recommendation.h"
#include "stylehelper.h"

namespace Ui {
class RecommendationWindow;
}

class RecommendationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RecommendationWindow(QWidget *parent = nullptr);
    ~RecommendationWindow();
    Recommendation *recommendation;

private slots:
    void on_pushButton_clicked();

private:
    Ui::RecommendationWindow *ui;
    void setInterfaceStyle();
};

#endif // RECOMMENDATIONWINDOW_H
