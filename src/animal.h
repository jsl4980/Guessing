#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
public:
    Animal();
    Animal(std::string _name);
    virtual ~Animal();

    std::string getName();

private:
    std::string name;
};

#endif // ANIMAL_H
