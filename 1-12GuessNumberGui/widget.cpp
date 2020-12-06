#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);

    // Initialize rand number generator
    srand(time(NULL));

    // Stylize UI widget components
    ui->spinBox->setStyleSheet("QSpinBox { background-color:#fcf8ec; }");

    // Add programmatic buttons
    guessButton = new PushButton("Guess", this);
    guessButton->setGeometry(QRect(160, 130, 113, 32));

    startOverButton = new PushButton("Start Over", this);
    startOverButton->setGeometry(QRect(300, 130, 113, 32));

    // Handle button signals
    connect(guessButton, SIGNAL (released()), this, SLOT (on_guessButton_clicked()));
    connect(startOverButton, SIGNAL (released()), this, SLOT (on_startOverButton_clicked()));

    // Restart new game
    restartGame();
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_guessButton_clicked() {

    guessNumber = ui->spinBox->value();
    qDebug() << "Guess Number : " << QString::number(guessNumber);

    if(guessNumber == secretNumber) {

        endGame();
    } else {
        if(guessNumber > secretNumber) {

            ui->messageLabel->setText("Number is lower than that");

        } else if (guessNumber < secretNumber) {

            ui->messageLabel->setText("Number is higher than that");
        }
    }
}

void Widget::on_startOverButton_clicked() {

    restartGame();
}

void Widget::restartGame() {

    qDebug() << "Start new game";

    // Enable guess button
    guessButton->showEnabled();

    // Disable the start over button
    startOverButton->showDisabled();

    // Put the spinbox back to 1
    ui->spinBox->setValue(1);

    // Clear message label
    ui->messageLabel->setText("");

    // Generate (1-10)
    secretNumber = rand()%10 + 1;
    qDebug() << "Secret Number generated : " << QString::number(secretNumber);
}

void Widget::endGame() {

    qDebug() << "Game Over";

    ui->messageLabel->setText("Congrats, number is : "+QString::number(secretNumber) + " !");

    guessButton->showDisabled();
    startOverButton->showEnabled();
}
