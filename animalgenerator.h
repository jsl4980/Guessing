#ifndef ANIMALGENERATOR_H
#define ANIMALGENERATOR_H

#include "animal.h"
#include <vector>
#include <string>

class AnimalGenerator
{
public:
    AnimalGenerator();
    ~AnimalGenerator();

    Animal getNextAnimal();

private:
    void createList();

    std::vector<std::string> animalNames;
    int animalIndex;

};

#endif // ANIMALGENERATOR_H
