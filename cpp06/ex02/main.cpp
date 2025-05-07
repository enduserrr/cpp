#include "Base.hpp"
#define WB "\033[1;97m"
#define RES "\033[0m"

int main() {
    // Seed random number gen
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << WB << "Test with pointers:" << RES << std::endl;
    for (int i = 0; i < 4; i++) {
        Base* ptr = generate();
        std::cout << "Object " << i + 1 << ": ";
        identify(ptr);
        delete ptr;
    }

    std::cout << WB << "\nTest with references:" << RES << std::endl;
    for (int i = 0; i < 4; i++) {
        Base* ptr = generate();
        std::cout << "Object " << i + 1 << ": ";
        identify(*ptr);
        delete ptr;
    }

    // Comparison of pointer and reference
    std::cout << WB << "\nPointer vs Reference" << RES << std::endl;
    Base* testPtr = generate();
    std::cout << "Pointer identify: ";
    identify(testPtr);
    std::cout << "Reference identify: ";
    identify(*testPtr);

    // Known type verification
    std::cout << WB << "\nType verification" << RES << std::endl;
    A aObj;
    B bObj;
    C cObj;
    std::cout << "Known object A (ptr): ";
    identify(&aObj);
    std::cout << "Known object A (ref): ";
    identify(aObj);
    std::cout << "Known object B (ptr): ";
    identify(&bObj);
    std::cout << "Known object B (ref): ";
    identify(bObj);
    std::cout << "Known object C (ptr): ";
    identify(&cObj);
    std::cout << "Known object C (ref): ";
    identify(cObj);

    std::cout << WB << "\nNULL:" << RES << std::endl;
    Base* nullPtr = NULL;
    std::cout << "nullptr identify: ";
    identify(nullPtr);

    delete testPtr;

    return 0;
}
