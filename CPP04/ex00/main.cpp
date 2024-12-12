/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:52:43 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 15:50:17 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " cachorro" << std::endl;
    std::cout << cat->getType() << " gatinho" << std::endl;
	
    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "---- WrongAnimal Test ----" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;

    wrongAnimal->makeSound();
    wrongCat->makeSound();

    delete wrongAnimal;
    delete wrongCat;

    return 0;
}