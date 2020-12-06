#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "ui_widget.h"
#include "pushbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_guessButton_clicked();
    void on_startOverButton_clicked();

private:
    void restartGame();
    void endGame();
    Ui::Widget *ui;
    PushButton * guessButton, * startOverButton;
    int secretNumber, guessNumber;

};
#endif // WIDGET_H
