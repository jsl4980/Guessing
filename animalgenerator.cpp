#include "animalgenerator.h"

AnimalGenerator::AnimalGenerator() :
    animalIndex(0)
{
    createList();
}

AnimalGenerator::~AnimalGenerator()
{

}

Animal AnimalGenerator::getNextAnimal()
{
    return Animal(animalNames.at(animalIndex++));
}

void AnimalGenerator::createList()
{
    animalNames = {"cat", "dog", "shark", "deer", "beaver", "mouse", "snake"};
}
