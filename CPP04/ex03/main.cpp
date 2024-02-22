#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    Character *me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("false"); // should not be created
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure"); // should not be created
    me->equip(tmp);
    tmp = src->createMateria("cure"); // should not be created
    me->equip(tmp);
    delete tmp;
    ICharacter *copy = new Character(*me); // copy constructor
    Character *assigned = new Character("assigned");
    *assigned = *me; // assignation operator
    ICharacter* bob = new Character("bob");
    std::cout << "me (type:" << me->getName() << "): " << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob); // should not be used
    me->unequip(0);
    me->unequip(1);
    me->use(0, *bob); // should not be used
    me->use(1, *bob); // should not be used

    // Test copy constructor and assignation operator
    std::cout << std::endl << "copy (type:" << copy->getName() << "): " << std::endl;
    copy->use(0, *bob);
    copy->use(1, *bob);
    copy->use(2, *bob); // should not be used
    copy->unequip(0);
    copy->unequip(1);
    copy->use(0, *bob); // should not be used
    copy->use(1, *bob); // should not be used
    std::cout << std::endl << "assigned (type:" << assigned->getName() << "): " << std::endl;
    assigned->use(0, *bob);
    assigned->use(1, *bob);
    assigned->use(2, *bob);
    assigned->use(3, *bob);
    std::cout << std::endl;
    delete bob;
    delete me;
    delete copy;
    delete assigned;
    delete src;
    return 0;
}