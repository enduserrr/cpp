/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:06:24 by asalo             #+#    #+#             */
/*   Updated: 2024/12/31 13:06:28 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "------------------START-------------------" << std::endl;
    const Animal* meta = new Animal();
    const Animal* jake = new Dog();
    const Animal* felix = new Cat();
	std::cout << "------------------------------------------" << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << jake->getType() << " " << std::endl;
    std::cout << felix->getType() << " " << "\n\n";

    meta->makeSound();
    jake->makeSound();
    felix->makeSound();

    std::cout << "-------------------WRONG---------------------" << std::endl;
    const WrongAnimal* wMeta = new WrongAnimal();
    const WrongAnimal* wCat = new WrongCat();
    const WrongCat* lCat = new WrongCat();
    std::cout << "--------------------------------------------" << std::endl;
	std::cout << wMeta->getType() << " " << std::endl;
    std::cout << wCat->getType() << " " << std::endl;
	std::cout << lCat->getType() << " " << "\n\n";
    wCat->makeSound();
    wMeta->makeSound();
    lCat->makeSound();

    std::cout << "----------------DEEPCOPIES------------------" << std::endl;
    Animal* originalCat = new Cat();
    Animal* deepcopyCat = new Cat();

    *deepcopyCat = *originalCat;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "original addresss: " << std:: endl;
    originalCat->printAddress();
    std::cout << "deepcopy addresss: " << std:: endl;
    deepcopyCat->printAddress();
	std::cout << "---------------with copy----------------------" << std::endl;
    Animal* originalDog = new Dog();
    Animal* deepCopyDog = new Dog(*(Dog*)(originalDog));
	std::cout << "--------------------------------------------" << std::endl;
    std::cout << "original addresss: " << std:: endl;
    originalDog->printAddress();
    std::cout << "deepcopy addresss: " << std:: endl;
    deepCopyDog->printAddress();

    std::cout << "---------------------------------------------" << std::endl;

    delete meta;
    delete felix;
    delete jake;
    delete wCat;
    delete wMeta;
    delete lCat;
    delete originalCat;
    delete originalDog;
    delete deepcopyCat;
    delete deepCopyDog;

    return 0;
}
