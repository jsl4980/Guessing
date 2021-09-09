#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "round.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    // Switch pages to second page
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_goButton_clicked()
{
    // Switch to the game page
    setupRound();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_questionButton_clicked()
{
    setQuestions(round->questionAsked());
}

void MainWindow::on_gameOverBtn_clicked()
{
    round->guessRight();
    if(round->isGameOver()) {
        finishRound();
    }
}

void MainWindow::on_clueBtn_clicked()
{
    setClues(round->giveClue());
}


void MainWindow::on_startOverBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::setupRound()
{
    round = new Round();
    setClues(round->getClues());
    setQuestions(round->getQuestions());
    ui->animalLabel->setText(QString::fromStdString(round->getAnimalName()));
    QPixmap pic(":/images/resources/cat_cropped.jpeg");
    ui->animalPicture->setPixmap(pic);
}

void MainWindow::finishRound()
{
    // Change to finish window
    ui->stackedWidget->setCurrentIndex(3);
    // Print results
    if(round->isGameWon()) {
        ui->resultLabel->setText("Congratulations!");
        ui->detailLabel->setText(QString("You guessed %1 in %2 questions!")
                                 .arg(QString::fromStdString(round->getAnimalName()))
                                 .arg(round->getQuestions()));
    } else {
        // Ran out of questions, todo later
    }
    // Delete the round
    delete round;
}

void MainWindow::setQuestions(int q)
{
    ui->questionLabel->setText(QString("Question Count: %1").arg(q));
}

void MainWindow::setClues(int c)
{
    ui->clueCount->setText(QString("Clue Count: %1").arg(c));
}

