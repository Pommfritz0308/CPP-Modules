#include "MutantStack.hpp"

int main (void)
{
    std::cout << BOLD("Testing MutantStack") << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop(); // removes top element
    std::cout << "Stack size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "---------------------\nElements:\n";
    std::cout << "Top\n\t^\n";
    while (ite != it)
    {
        ite--;
        std::cout << "\t| " << *ite << std::endl;
    }
    std::cout << "\tv\nBottom\n";
    std::cout << std::endl;

    std::cout << BOLD("Comparing with std::list behaviour") << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << "Top element: " << list.back() << std::endl;
    list.pop_back();
    std::cout << "Stack size: " << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator it2 = list.begin();
    std::list<int>::iterator ite2 = list.end();
    ++it2;
    --it2;
    std::cout << "---------------------\nElements:\n";
    std::cout << "Top\n\t^\n";
    while (ite2 != it2)
    {
        ite2--;
        std::cout << "\t| " << *ite2 << std::endl;
    }
    std::cout << "\tv\nBottom\n";
    std::cout << std::endl;

    std::stack<int> s(mstack); // Check if stack has copy constructor for MutantStack reference
    
    std::cout << BOLD("Copy of MutantStack") << std::endl;
    MutantStack<int> cpy(mstack);
    it = cpy.begin();
    ite = cpy.end();
    
    std::cout << "Top element: " << cpy.top() << std::endl;
    std::cout << "Stack size: " << cpy.size() << std::endl;
    std::cout << "---------------------\nElements:\n";
    std::cout << "Top\n\t^\n";
    while (ite != it)
    {
        ite--;
        std::cout << "\t| " << *ite << std::endl;
    }
    std::cout << "\tv\nBottom\n\n";

    std::cout << BOLD("Assignment of MutantStack") << std::endl;
    MutantStack<int> assigned;
    assigned = mstack;
    it = assigned.begin();
    ite = assigned.end();

    std::cout << "Top element: " << assigned.top() << std::endl;
    std::cout << "Stack size: " << assigned.size() << std::endl;
    std::cout << "---------------------\nElements:\n";
    std::cout << "Top\n\t^\n";
    while (ite != it)
    {
        ite--;
        std::cout << "\t| " << *ite << std::endl;
    }
    std::cout << "\tv\nBottom\n";
    std::cout << "Address of original stack: " << &mstack << std::endl; // Address of original stack
    std::cout << "Address of copy stack: " << &cpy << std::endl; // Address of copy stack
    std::cout << "Address of assigned stack: " << &assigned << std::endl; // Address of assigned stack
    return 0;
}