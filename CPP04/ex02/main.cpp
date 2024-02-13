#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    int nb = 5;
    
    // Test setIdea and printIdeas
    // Animal uninstatiated;
    Animal* animals[nb];
    for (int i = 0; i < nb; i++)
    {
        if (i % 2 == 0)
        {
            animals[i] = new Dog();
            animals[i]->setIdea(0, "I am a dawg");
            animals[i]->setIdea(99, "I am a good dawg");
        }
        else
        {
            animals[i] = new Cat();
            animals[i]->setIdea(0, "I am a car");
            animals[i]->setIdea(1, "I am a good car");
            animals[i]->setIdea(2, "Purrrrrr");
        }
    }
    for (int i = 0; i < nb; i++)
    {
        animals[i]->makeSound();
        animals[i]->printIdeas();
        delete animals[i];
    }

    // Test copy constructor for unique brain array
    Cat* cat = new Cat();
    Cat* catty = new Cat(*cat);
    catty->setIdea(0, "Test deep copy");
    std::cout << "Cat: ";
    cat->printIdeas();
    std::cout << std::endl;
    std::cout << "Catty: ";
    catty->printIdeas();
    // Test assignation operator for unique brain array
    *cat = *catty;
    cat->printIdeas();
    catty->printIdeas();
    delete catty;
    delete cat;
    return 0;
}