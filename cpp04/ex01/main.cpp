#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define GC     "\033[3;90m"
#define WB     "\033[1;97m"
#define GB     "\033[1;92m"
#define RB     "\033[1;91m"
#define RES    "\033[0m"

#define GROUP 8

int main()
{

    std::cout << WB << "ANIMALS & WRONG ANIMALS" << RES GC << std::endl;
    {
        const Animal *a1 = new Animal();
        const Animal *musti = new Dog();
        const Cat *mirri = new Cat();
        std::cout << RES;
        std::cout << a1->getType() << " sounds:" << WB << std::endl;
        a1->makeSound();
        std::cout << RES << musti->getType() << " sounds:" << GB << std::endl;
        musti->makeSound();
        std::cout << RES << mirri->getType() << " sounds:" << GB << std::endl;
        mirri->makeSound();
        std::cout << RES GC;
        const WrongAnimal *w1 = new WrongAnimal();
        const WrongAnimal *w2 = new WrongCat();
        const WrongCat *w3 = new WrongCat();
        std::cout << RES;
        std::cout << w1->getType() << " sounds:" << RB << std::endl;
        w1->makeSound();
        std::cout << RES << w2->getType() << " sounds:" << RB << std::endl;
        w2->makeSound();
        std::cout << RES << w3->getType() << " sounds:" << RB << std::endl;
        w3->makeSound();
        std::cout << RES GC;
        delete a1;
        delete musti;
        delete mirri;
        delete w1;
        delete w2;
        delete w3;
    }

    std::cout << std::endl;
    std::cout << WB << "100 IDEAS:" << RES GC << std::endl;
    {
        Dog dog1;
        Cat cat1;
        for (int i = 0; i < 100; i++) {
            cat1.getBrain()->setIdeas("Evil master plan");
        }
        const std::string *newIdeas = cat1.getBrain()->getIdeas();
        for (int i = 0; i < 100; i++) {
            std::cout << RES << "cat1 " << i << ": " << newIdeas[i] << std::endl;
        }
        for (int i = 0; i < 100; i++) {
            dog1.getBrain()->setIdeas("Goofy stuff");
        }
        std::cout << std::endl;
        newIdeas = dog1.getBrain()->getIdeas();
        for (int i = 0; i < 100; i++) {
            std::cout << "dog1 " << i << ": " << newIdeas[i] << std::endl;
        }
        std::cout << GC;
    }

    std::cout << RES << std::endl;
    std::cout << WB "ANIMAL ARRAY" << std::endl;
    {
        Animal *animalGroup[GROUP];
        std::cout << GB << "CONSTRUCT:" << RES GC << std::endl;
        for (int i = 0; i < GROUP; i++) {
            if (i < GROUP / 2)
                animalGroup[i] = new Cat();
            else
                animalGroup[i] = new Dog();
        }
        std::cout << RB << "DESTRUCT:" << RES GC << std::endl;
        for (int i = 0; i < GROUP; i++) {
            delete animalGroup[i];
        }
    }

    std::cout << std::endl;
    std::cout << WB << "COPY & DEEPCOPY:" << RES GC << std::endl;
    {
        Cat ogCat;
        std::cout << RES;
        ogCat.getBrain()->setIdeas("Evil master plan.");
        std::cout << GC;
        Cat deepcopyCat = ogCat;
        std::cout << RES;
        std::cout << "Cat: Original idea: " << *ogCat.getBrain()->getIdeas() << std::endl;
        std::cout << "Cat: Deep Copy idea: " << *deepcopyCat.getBrain()->getIdeas() << std::endl;
        std::cout << GC;
        Dog ogDog;
        std::cout << RES;
        ogDog.getBrain()->setIdeas("Goofy stuff.");
        std::cout << GC;
        Dog deepcopyDog(ogDog);
        std::cout << RES << "Dog: Original idea: " << *ogDog.getBrain()->getIdeas() << std::endl;
        std::cout << "Dog: Deep Copy idea: " << *deepcopyDog.getBrain()->getIdeas() << std::endl;
        std::cout << std::endl;
        std::cout << WB << "BRAIN ADDRESS VALIDATION:" << RES << std::endl;
        const std::string* ideas = ogCat.getBrain()->getIdeas();
        for (int i = 0; i < 3; i++) {
            std::cout << "Cat: Original idea " << i << ": " << ideas[i] << " at " << &ideas[i] << std::endl;
        }
        ideas = deepcopyCat.getBrain()->getIdeas();
        for (int i = 0; i < 3; i++) {
            std::cout << "Cat: Deep Copy idea " << i << ": " << ideas[i] << " at " << &ideas[i] << std::endl;
        }
        std::cout << GC;
    }

    std::cout << RES << std::endl;
    std::cout << RES WB << "OBJECT ADDRESS VALIDATION:" << RES GC << std::endl;
    {
        Animal *ogAnimalDog = new Dog();
        Animal *deepcopyAnimalDog = new Dog(*(Dog*)ogAnimalDog);
        std::cout << RES << "Og dog address:" << std::endl;
        ogAnimalDog->printAddress();
        std::cout << "Deep copy dog address:" << std::endl;
        deepcopyAnimalDog->printAddress();
        std::cout << GC;
        delete ogAnimalDog;
        delete deepcopyAnimalDog;
    }
    std::cout << RES;
    return (0);
}
