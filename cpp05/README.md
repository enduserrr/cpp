# CPP05

## KEY CONCEPTS:
Inheritance:
* Allows creating a class that inherits from a base class, which then automatically gains the properties and methods of the base class. It's a "is-a" relationship promoting code reuse for shared attributes and behaviors.

Abstraction:
* Hiding complexity while exposing only essential features.

Polymorphism:
* Means literally "many forms." Allows treating derived classes (schrubbery, robotomy etc) uniformly through their base class interface.

### Ex00 (Bureaucrat)
Creation of Bureaucrat class. Its aim was implementing a class with specific constraints (grade 1-150), handling errors with custom exceptions (GradeTooHigh, GradeTooLow), while adhering to Orthodox Canonical Form.

### Ex01 (Form)
Addition of Form class, demonstrating class interaction. Its main addition was the signForm logic, where a Bureaucrat attempts to sign a Form based on grade requirements (beSigned).

### Ex02 (AForm & Concrete Forms)
The key here is introducing abstraction and polymorphism. Form became an abstract base class AForm with a pure virtual execute method. Concrete derived classes (shrubbery, robotomy, presidential...) implemented specific actions. The Bureaucrat gained an executeForm method (with a min grade to execute), showcasing polymorphic behavior.

### Ex03 (Intern)
Addition of Intern class (to try and work the forms). Its aim was creating different AForm objects dynamically based on string names while avoiding if/else chains (I used function pointers). This required dynamic memory allocation (new) and with that also deallocation (delete).



