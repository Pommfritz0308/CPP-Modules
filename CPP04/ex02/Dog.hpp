#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:

        Brain* brain;

    public:

        Dog();
        Dog(const Dog &old);
        Dog& operator= (const Dog &old);
        ~Dog();
        void makeSound() const;
        void setIdea(int i, std::string idea);
        void printIdeas() const;
};

#endif