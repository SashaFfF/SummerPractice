#include "stylehelper.h"


QString StyleHelper::getStartButtonsStyle(QString color, QString press_color, QString hover_color)
{
    return "QPushButton{"
           "  border:none;"
           "  background:none;"
           "  background-color: " + color+
           "  border-radius:19px;"
           "}"
    "QPushButton::hover{"
    "background-color: " + hover_color +
    "}"
    "QPushButton::pressed{"
    "background-color:" + press_color +
            "}";
}

QString StyleHelper::getSmallButtonsStyle(QString background_color, QString border_color)
{
    return "QPushButton{"
            "  background-color: " + background_color +
            "  border-style: outset;"
            "  border-width: 2px;"
            "  border-radius: 15px;"
            "  border-color: " + border_color +
           "}";

}

QString StyleHelper::getStartLineEditStyle(QString color)
{
    return "QLineEdit{"
           "  border: 2px solid gray;"
           "  border-radius: 10px;"
           "  padding: 0 8px;"
           "  background:"+color+
           "}";

}

QString StyleHelper::getStartTextEditStyle(QString color)
{
    return "QTextEdit{"
           "  border: 2px solid gray;"
           "  border-radius: 10px;"
           "  padding: 0 8px;"
           "  background:"+color+
           "}";

}

