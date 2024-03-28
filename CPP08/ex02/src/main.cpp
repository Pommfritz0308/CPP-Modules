#include "MutantStack.hpp"

int main (void)
{
    std::cout << BOLD("Testing MutantStack") << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop(); // removes top element
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "---------------------\nElements:\n";
    std::cout << "Bottom\n\t^\n";
    while (it != ite)
    {
        std::cout << "\t| " << *it << std::endl;
        ++it;
    }
    std::cout << "\tv\nTop\n";
    std::cout << std::endl;

    std::cout << BOLD("Comparing with std::list behaviour") << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator it2 = list.begin();
    std::list<int>::iterator ite2 = list.end();
    ++it2;
    --it2;
    std::cout << "---------------------\nElements:\n";
    std::cout << "Bottom\n\t^\n";
    while (it2 != ite2)
    {
        std::cout << "\t| " << *it2 << std::endl;
        ++it2;
    }
    std::cout << "\tv\nTop\n";
    std::cout << std::endl;

    std::stack<int> s(mstack); // Check if stack has copy constructor for MutantStack reference
    
    std::cout << BOLD("Copy of MutantStack") << std::endl;
    MutantStack<int> cpy(mstack);
    it = cpy.begin();
    ite = cpy.end();
    
    std::cout << cpy.top() << std::endl;
    std::cout << cpy.size() << std::endl;
    std::cout << "---------------------\nElements:\n";
    std::cout << "Bottom\n\t^\n";
    while (it != ite)
    {
        std::cout << "\t| " << *it << std::endl;
        ++it;
    }
    std::cout << "\tv\nTop\n\n";

    std::cout << BOLD("Assignment of MutantStack") << std::endl;
    MutantStack<int> assigned;
    assigned = mstack;
    it = assigned.begin();
    ite = assigned.end();

    std::cout << assigned.top() << std::endl;
    std::cout << assigned.size() << std::endl;
    std::cout << "---------------------\nElements:\n";
    std::cout << "Bottom\n\t^\n";
    while (it != ite)
    {
        std::cout << "\t| " << *it << std::endl;
        ++it;
    }
    std::cout << "\tv\nTop\n";
    std::cout << "Address of original stack: " << &mstack << std::endl; // Address of original stack
    std::cout << "Address of copy stack: " << &cpy << std::endl; // Address of copy stack
    std::cout << "Address of assigned stack: " << &assigned << std::endl; // Address of assigned stack
    return 0;
}