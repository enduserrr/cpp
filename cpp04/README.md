# SUBTYPE POLYMORPHISM, ABSTRACT CLASSES & INTERFACES

## What is a Subtype?
Is a class derived from a base class that inherits its behaviour while also being able to extend or modify it.

### Subtype Polymorphism
Allows a pointer or reference to a base to call methods of a derived class (Dog, Cat).
Enables treating objects of different derived classes uniformly, using the same inteface.

## What is an Abstract Class?
A blueprint class for derived classes which can't be instantiated directly.
Usually contains at least one 'pure virtual' function.

### Un-Instantiable Class


### Pure Virtual Functions
A function declared in the base class with no implementation,
forcing the derived classes to implement the function to make it concrete.

### 'Virtual' Prefix
A keyword that allows derived classes to override a base class function.
When used for destructors, it ensures proper destruction of derived objects
(like mem resources) through a base class pointer. PREVENT LEAKS.

## Shallow Copy
Duplicates only the objects immediate values like pointers, without duplicating
the data they point to. Can lead to shared ownership and possible double deletion issues.
`Cat shallowCat = originalCat;`

## Deep Copy
Duplicates the object and all its dynamically allocated resources including the stored values.
Dynamically allocs memory if needed that has to be free'd (deleted).
`Cat deepCopyCat; deepCopyCat = originalCat;`
