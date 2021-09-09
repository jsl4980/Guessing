#include "round.h"

Round::Round() :
    questionCount(0),
    clueCount(0),
    animalName("Cat"),
    gameOver(false),
    gameWon(false)
{
}

Round::~Round()
{
}

std::string Round::getAnimalName()
{
    return animalName;
}

int Round::getClues()
{
    return clueCount;
}

int Round::getQuestions()
{
    return questionCount;
}

bool Round::isGameOver()
{
    return gameOver;
}

bool Round::isGameWon()
{
    return gameWon;
}

int Round::guessRight()
{
    gameOver = true;
    gameWon = true;
    return ++questionCount;
}

int Round::giveClue()
{
    return ++clueCount;
}

int Round::questionAsked()
{
    return ++questionCount;
}


