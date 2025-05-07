#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

#define GC     "\033[3;90m"
#define WB     "\033[1;97m"
#define GB     "\033[1;92m"
#define RB     "\033[1;91m"
#define RES    "\033[0m"

int main()
{
    std::cout << WB << "ANIMALS & WRONG ANIMALS" << RES GC << std::endl;
    {
        const Animal *meta = new Animal();
        const Animal *musti = new Dog();
        const Cat *mirri = new Cat();
        std::cout << RES;
        std::cout << meta->getType() << " sounds:" << WB << std::endl;
        meta->makeSound();
        std::cout << RES << musti->getType() << " sounds:" << GB << std::endl;
        musti->makeSound();
        std::cout << RES << mirri->getType() << " sounds:" << GB << std::endl;
        mirri->makeSound();
        std::cout << RES GC;
        const WrongAnimal *wMeta = new WrongAnimal();
        const WrongAnimal *w2 = new WrongCat();
        const WrongCat *w3 = new WrongCat();
        std::cout << RES;
        std::cout << wMeta->getType() << " sounds:" << RB << std::endl;
        wMeta->makeSound();
        std::cout << RES << w2->getType() << " sounds:" << RB << std::endl;
        w2->makeSound();
        std::cout << RES << w3->getType() << " sounds:" << RB << std::endl;
        w3->makeSound();
        std::cout << RES GC;
        delete meta;
        delete musti;
        delete mirri;
        delete wMeta;
        delete w2;
        delete w3;
    }
    std::cout << RES;
    return (0);
}
