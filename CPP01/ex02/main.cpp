/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:46:35 by migupere          #+#    #+#             */
/*   Updated: 2024/12/04 17:53:40 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(){
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Address of the string variable: " << &str << std::endl;
	std::cout << "Address of the string pointer: " << ptr << std::endl;
	std::cout << "Address of the string reference: " << &ref << std::endl;

	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value of the string pointer: " << *ptr << std::endl;
	std::cout << "Value of the string reference: " << ref << std::endl;
	return 0;
}
