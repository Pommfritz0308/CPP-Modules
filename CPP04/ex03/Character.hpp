#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"
class Character : public ICharacter
{
    private:

        std::string _name;
        AMateria* _materias[4];
        AMateria* _floor[4];

    public:
    
        Character();
        Character(std::string name);
        Character(const Character &old);
        Character& operator= (const Character &old);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif