#include "animal.h"

Animal::Animal() :
    name("")
{

}

Animal::Animal(std::string _name) :
    name(_name)
{

}

Animal::~Animal() {}

std::string Animal::getName()
{
    return name;
}
