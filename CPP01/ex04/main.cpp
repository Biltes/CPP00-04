/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:30:09 by migupere          #+#    #+#             */
/*   Updated: 2024/12/05 14:30:14 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	replaceStringInFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
	if (s1.empty()){
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return;
	}

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()){
		std::cerr << "Error: Could not open file." << std::endl;
		return;
	}

	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()){
		std::cerr << "Error: Could not create ouput file." << std::endl;
		return;
	}

	std::string line;
	while(std::getline(inputFile, line)){
		size_t pos = 0;
		while((pos = line.find(s1, pos)) != std::string::npos){
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	replaceStringInFile(filename, s1, s2);

	return 0;
}
