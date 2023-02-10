#ifndef STYLEHELPER_H
#define STYLEHELPER_H
#include <QString>


class StyleHelper
{
public:
    static QString getStartButtonsStyle(QString color, QString press_color, QString hover_color);
    static QString getSmallButtonsStyle(QString background_color, QString border_color);
    static QString getStartLineEditStyle(QString color);
    static QString getStartTextEditStyle(QString color);
};

#endif // STYLEHELPER_H
