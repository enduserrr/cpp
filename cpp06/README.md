# CPP06 - CASTS

## Ex00 - Scalar Converter

### Scalar Data Types
Scalar types are data types representing a single value instead of multiple (like composite or aggregate types).
Takes an input and tries to represent it in different scalar types unless it would be unprintable or NaN alue

#### Examples:
1. Integers (e.g., int, long)
2. Floating points (e.g., float, double)
3. Characters (e.g., char)
4. Boolean (e.g., bool)


### Pseudo-Literals
Special values that represent infinity and not-a-number (NaN) for float and double types, like for example -inff, +inff, nanf, -inf, +inf, and nan.
1. -inff: negative infnity for float type.
2. +inff: positive infinity for float type.
3. nanf: not-a-number for float type.
4. -inf: negative infinity for double.
5. +inf: positive infinity double type.
6. nan: not-a-number (Nan) for double type'

## Ex01
Demonstrates a way to treat memory address as a plain numerical value and convert it back to memory address.

## Ex02
Dynamic type identification using polymorphism and dynamic_cast. t shows how you can have a pointer or reference to a base class (Base)
but still determine the actual derived class (A, B, or C) of the object at runtime.

Identifies type during runtime and using dynamic cast and function pointers.

### Polymorphism = multiple ways through one interface
