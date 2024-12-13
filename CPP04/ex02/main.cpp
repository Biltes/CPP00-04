/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:18:13 by migupere          #+#    #+#             */
/*   Updated: 2024/12/13 14:11:27 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

    delete dog;
    delete cat;

	// const Animal* animal = new Animal();

	// delete animal;

    // std::cout << "---- Array of Animals ----" << std::endl;

    // // Array de animais
    // const Animal* animals[4];
    // for (int i = 0; i < 2; ++i) {
    //     animals[i] = new Dog();
    // }
    // for (int i = 2; i < 4; ++i) {
    //     animals[i] = new Cat();
    // }

    // for (int i = 0; i < 4; ++i) {
    //     delete animals[i];
    // }

    // std::cout << "---- Deep Copy Test ----" << std::endl;

    // Dog dog1;
    // dog1.getBrain()->setIdea(0, "Chase the ball!");

	// dog1.getBrain()->setIdea(1, "Bark at the mailman!");

    // Dog dog2 = dog1;
    // dog2.getBrain()->setIdea(0, "Eat the food!");

	// Cat cat1;
	// cat1.getBrain()->setIdea(0, "Chase the mouse!");

	// Cat cat2 = cat1;
	// cat2.getBrain()->setIdea(0, "Eat the fish!");

    // std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	// std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(1) << std::endl;
    // std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	// std::cout << "Cat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	// std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;

    return 0;
}
