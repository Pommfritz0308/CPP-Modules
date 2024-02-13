#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:

        Brain* brain;

    public:

        Cat();
        Cat(const Cat &old);
        Cat& operator= (const Cat &old);
        ~Cat();
        void makeSound() const;
        void setIdea(int i, std::string idea);
        void printIdeas() const;
};

#endif