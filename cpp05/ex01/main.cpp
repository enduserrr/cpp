#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat sir("Sir", 50);
        Form form1("Application", 60, 70); // Grade to sign: 60
        Form form2("Promotion", 40, 50);  // Grade to sign: 40

        std::cout << sir << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << std::endl;
        sir.signForm(form1); // 50 is not high enough to sign
        sir.signForm(form2); // 50 is high enough to sign
        std::cout << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        Bureaucrat bobby("Bobby", 30);
        std::cout << bobby << std::endl;
        bobby.signForm(form1); // 30 is high enough (60 is lower)
        std::cout << form1 << std::endl;
        std::cout << std::endl;
        //Test grade too high
        Form form3("Invalid Form", 0, 50);
        std::cout << form3 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat dummy("Dummy", 150);
        Form form4("Impossible Form", 149, 50);
        dummy.signForm(form4);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
