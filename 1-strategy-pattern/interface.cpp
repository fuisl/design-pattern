#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal
{
public:
    void makeSound() {bark();}
    void bark() { cout << "Woof! Woof!" << endl; }
};

class Cat : public Animal
{
public:
    void makeSound() {meow();}
    void meow() { cout << "Meow! Meow!" << endl; }
};

int main()
{
    Animal *animal = new Cat;
    animal->makeSound();
    return 0;
}