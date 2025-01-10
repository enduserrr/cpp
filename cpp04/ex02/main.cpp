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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define GC     "\033[3;90m"
#define WB     "\033[1;97m"
#define GB     "\033[1;92m"
#define RB     "\033[1;91m"
#define RES    "\033[0m"

#define SIZE_GROUP 6

int main()
{
    Animal* animalGroup[SIZE_GROUP];

    std::cout << GB << "CONSTRUCT:" << RES GC << std::endl;
    for (int i = 0; i < SIZE_GROUP; i++) {
        if (i < SIZE_GROUP / 2)
            animalGroup[i] = new Cat();
        else
            animalGroup[i] = new Dog();
    }
    std::cout << RB << "DESTRUCT:" << RES GC << std::endl;
    for (int i = 0; i < SIZE_GROUP; i++) {
        delete animalGroup[i];
    }

	std::cout << std::endl;
    std::cout << WB << "COPY & DEEPCOPY:" << RES GC << std::endl;
    Cat originalCat;
	std::cout << RES;
    originalCat.getBrain()->setIdeas("I love tuna!");
	std::cout << GC;
    Cat deepcopyCat = originalCat;
	std::cout << RES;
    std::cout << "Original Cat's idea: " << *originalCat.getBrain()->getIdeas() << std::endl;
    std::cout << "Deep Copy Cat's idea: " << *deepcopyCat.getBrain()->getIdeas() << std::endl;
	std::cout << GC << std::endl;
    Dog originalDog;
	std::cout << RES;
    originalDog.getBrain()->setIdeas("Let’s go to the park!");
	std::cout << GC;
    Dog deepcopyDog(originalDog);
    std::cout << RES << "Original Dog's idea: " << *originalDog.getBrain()->getIdeas() << std::endl;
    std::cout << "Deep Copy Dog's idea: " << *deepcopyDog.getBrain()->getIdeas() << std::endl;

	std::cout << std::endl;
    std::cout << WB << "BRAIN ADDRESS VALIDATION:" << RES << std::endl;
    const std::string* ideas = originalCat.getBrain()->getIdeas();
    for (int i = 0; i < 3; i++) {
        std::cout << "Original Cat Idea " << i << ": " << ideas[i] << " at " << &ideas[i] << std::endl;
    }
	std::cout << std::endl;
    ideas = deepcopyCat.getBrain()->getIdeas();
    for (int i = 0; i < 3; i++) {
        std::cout << "Deep Copy Cat Idea " << i << ": " << ideas[i] << " at " << &ideas[i] << std::endl;
    }
	std::cout << std::endl;
    std::cout << WB << "OBJECT ADDRESS VALIDATION:" << RES GC << std::endl;
    Animal* originalAnimalDog = new Dog();
    Animal* deepCopyAnimalDog = new Dog(*(Dog*)originalAnimalDog);
	std::cout << std::endl;
    std::cout << RES << "Original Dog Address:" << std::endl;
    originalAnimalDog->printAddress();
    std::cout << "Deep Copy Dog Address:" << std::endl;
    deepCopyAnimalDog->printAddress();
	std::cout << GC << std::endl;
    delete originalAnimalDog;
    delete deepCopyAnimalDog;
	std::cout << GC << std::endl;
    return 0;
}
