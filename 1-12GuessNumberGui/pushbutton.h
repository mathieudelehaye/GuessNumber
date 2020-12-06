#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

class PushButton : public QPushButton
{
public:
    PushButton(const QString &, QWidget *);
    void showEnabled();
    void showDisabled();
    void hide();

};

#endif // PUSHBUTTON_H
