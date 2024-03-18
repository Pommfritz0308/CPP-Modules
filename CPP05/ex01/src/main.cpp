#include "Bureaucrat.hpp"
#include "Form.hpp"

static Bureaucrat* createAndPrintBureaucrat(const std::string& name, int grade) {
    try {
        Bureaucrat *b = new Bureaucrat(name, grade);
        std::cout << *b;
        return (b);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (NULL);
    }
}

static Form* createAndPrintForm(const std::string& name, int gradeToSign, int gradeToExecute) {
    try {
        Form *f = new Form (name, gradeToSign, gradeToExecute);
        std::cout << f->getName() << " form created with grade to sign: " << f->getGradeToSign() << " and grade to execute: " << f->getGradeToExecute() << std::endl;
        return (f);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (NULL);
    }
}

int main(void)
{
    //Test with good grade
    Bureaucrat *b0 = createAndPrintBureaucrat("b0", 1);
    Form *f0 = createAndPrintForm("f0", 1, 1);
    try{
        f0->beSigned(*b0);
        std::cout << *f0;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << *f0;
    }
    b0->signForm(*f0);

    //Test with bad grade
    Bureaucrat *b1 = createAndPrintBureaucrat("b1", 150);
    Form *f1 = createAndPrintForm("f1", 149, 149);
    try{
        f1->beSigned(*b1);
        std::cout << *f1;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << *f1;
    }
    b1->signForm(*f1);
    delete b0;
    delete f0;
    delete b1;
    delete f1;
    return 0;
}