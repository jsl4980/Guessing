#ifndef ROUND_H
#define ROUND_H

#include <string>

class Round
{
public:
    Round();
    virtual ~Round();

    std::string getAnimalName();
    int guessRight();
    int guessWrong();
    int giveClue();
    int questionAsked();

    int getGuesses();
    int getClues();
    int getQuestions();
    bool isGameOver();
    bool isGameWon();

private:
    int guessCount;
    int questionCount;
    int clueCount;
    std::string animalName;
    bool gameOver;
    bool gameWon;
};

#endif // ROUND_H
