#ifndef BRAIN_HPP
#define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
    protected:

        std::string ideas[100];

    public:
    
        Brain();
        Brain(const Brain &old);
        Brain& operator= (const Brain &old);
        ~Brain();
        void setIdea(int i, std::string idea);
        void printIdeas() const;
};

#endif

