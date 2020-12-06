#include "pushbutton.h"

PushButton::PushButton(const QString &text, QWidget *parent = nullptr):QPushButton(text, parent) {
}

void PushButton::showEnabled() {

    QPushButton::setDisabled(false);

    setStyleSheet(
        "QPushButton{"
            "background-color: #79a3b1;"
            "border-style: solid;"
            "border-color: #fcf8ec;"
            "border-width: 2px;"
            "border-radius: 7px;"
            "color: #efefee;"
            "font: 18pt 'Roboto';"
            "font-weight: bold; "
        "}"
        "QPushButton:hover{"
            "background-color: #fcf8ec;"
            "border-style: solid;"
            "border-color: #fcf8ec;"
            "border-width: 2px;"
            "border-radius: 7px;"
            "color: #456268;"
            "font: 18pt 'Roboto';"
            "font-weight: bold;"
        "}"
    );

    show();
}

void PushButton::showDisabled() {

    QPushButton::setDisabled(true);

    setStyleSheet(
        "QPushButton{"
            "background-color: #fcf8ec;"
            "border-style: solid;"
            "border-color: #d0e8f2;"
            "border-width: 2px;"
            "border-radius: 7px;"
            "color: #d0e8f2;"
            "font: 18pt 'Roboto';"
            "font-weight: bold; "
        "}"
    );

    show();
}

void PushButton::hide() {

    hide();
}
