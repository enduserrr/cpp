#include <iostream>
#define WB "\033[1;97m"
#define RES   "\033[0m"

/**
 * @brief   strPtr: pointing to the str.
 *          strRef: referencing the str.
 *          REF is an alias for a given var (like a static pointer) and
 *          unlike pointer it can't be re-assigned.
 */

int main()
{
    std::string str;
    str = "HI THIS IS BRAIN";

    std::string *strPtr;
    strPtr = &str;
    std::string& strRef = str;
    std::cout << WB << "ADDRESS:" << RES << std::endl;
    std::cout << "str: " << &str << std::endl;
    std::cout << "ptr: " << &strPtr << std::endl;
    std::cout << "ref: " << &strRef << std::endl;
    std::cout << WB << "VALUE:" << RES << std::endl;
    std:: cout << "str: " << str << std::endl;
    std:: cout << "ptr: " << *strPtr << std::endl;
    std:: cout << "ref: " << strRef << std::endl;
}
