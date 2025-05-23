#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void); // Generate random instance of A, B, or C
void identify(Base* p); // Identify type using pointer (dynamic_cast)
void identify(Base& p); // Identify type using reference (dynamic_cast)

#endif
