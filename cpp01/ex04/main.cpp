/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:24:12 by asalo             #+#    #+#             */
/*   Updated: 2024/09/16 10:24:18 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
/**
 * @brief	ifstream:	Input file stream allows reading the file contents.
 *			ofstream:	Output file stream allows writing to a file.
 *			fstrean:	File stream allows both read and write as default but
 *						can behave like ifstream or ofstream with flags.
 */

static int openFiles(std::string nameInputFile, std::string nameOutputfile,
					std::ifstream *inputFile, std::ofstream *outputFile) {
	(*inputFile).open(nameInputFile, std::fstream::in);
	(*outputFile).open(nameOutputfile, std::fstream::out);
	if (!inputFile || !outputFile) {
        std::cerr << "Failed to open files!" << std::endl;
		(*inputFile).close();
		(*outputFile).close();
        return (1);
    }
	return (0);
}

static void replaceLine(char **argv, std::ifstream *inputFile, std::ofstream *outputFile) {
	std::string 			to_find;
	std::string 			to_replace;
	std::string 			line;
	std::string::size_type	found;
	size_t					end_last_found;
	std::string				replaced_line;

	to_find = *(argv + 2);
	to_replace = *(argv + 3);
	end_last_found = 0;

	while(std::getline(*inputFile, line)) {

		replaced_line.clear();
		end_last_found = 0;
		found = line.find(to_find);
		if (found != std::string::npos) {
			while (found != std::string::npos) {
				replaced_line.append(line,end_last_found,found - end_last_found);
				replaced_line += to_replace;
				end_last_found = found + to_find.length();
				found = line.find(to_find, end_last_found);
				if (found == std::string::npos)
					replaced_line.append(line, end_last_found,line.length());
			}
		}
		else
			replaced_line = line;
		if (!(*inputFile).eof())
			*outputFile << replaced_line << std::endl;
		else
			*outputFile << replaced_line;
	}
}

int main(int argc, char **argv) {
	std::string nameInputFile;
	std::string nameOutputfile;
	std::ifstream inputFile;
	std::ofstream outputFile;

	if (argc != 4)
		return (std::cout << "incorrect argument count" << std::endl, 0);
	nameInputFile = argv[1];
	nameOutputfile = nameOutputfile + argv[1] + ".replace";
	if (openFiles(nameInputFile, nameOutputfile, &inputFile, &outputFile))
		return (1);
	replaceLine(argv, &inputFile, &outputFile);
	inputFile.close();
	outputFile.close();
	return (0);
}
