#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "round.h"
#include "animalgenerator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_goButton_clicked();

    void on_gameOverBtn_clicked();

    void on_clueBtn_clicked();

    void on_questionButton_clicked();

    void on_startOverBtn_clicked();

private:
    void setupRound();
    void finishRound();
    void setQuestions(int q);
    void setGuesses(int g);
    void setClues(int c);

    Ui::MainWindow *ui;
    Round *round;
};
#endif // MAINWINDOW_H
