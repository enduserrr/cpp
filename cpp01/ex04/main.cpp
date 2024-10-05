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

static int	openFiles(std::string oldFileName, std::string newFileName,
					std::ifstream *inFile, std::ofstream *outFile)
{
    (*inFile).open(oldFileName, std::fstream::in);

    if (!(*inFile).is_open()) {
        std::cerr << "input file does not exist or cannot be opened" << std::endl;
        return (1);
    }

    (*outFile).open(newFileName, std::fstream::out);

	if (!(*outFile).is_open()) {
        std::cerr << "unable to create or open output file" << std::endl;
        (*inFile).close();
        return (1);
    }
    return (0);
}

static bool replaceLine(const std::string &line, const std::string &replace_this,
                        const std::string &replacement, std::string &newLine)
{
    std::string::size_type found = 0;
    std::string::size_type last_position = 0;
    bool replaced_flag = false;

    while ((found = line.find(replace_this, last_position)) != std::string::npos) {
        newLine.append(line, last_position, found - last_position);
        newLine += replacement;
        last_position = found + replace_this.length();
        replaced_flag = true;
    }
    newLine.append(line, last_position, line.length() - last_position);
    return (replaced_flag);
}

// Function to process the file, replacing lines and managing output
static void processFile(char **av, std::ifstream *inFile, std::ofstream *outFile)
{
    std::string replace_this = av[2];
    std::string replacement = av[3];
    std::string line;
    bool replaced_flag = false;

    while (std::getline(*inFile, line)) {
        std::string newLine;
        if (replaceLine(line, replace_this, replacement, newLine)) {
            replaced_flag = true;
        }
        *outFile << newLine << std::endl;
    }

    if (replaced_flag) {
        std::cout << "done" << std::endl;
    } else {
        std::cout << "nothing to replace" << std::endl;
        outFile->close();
        std::remove(av[1]);
    }
}

int main(int ac, char **av)
{
	std::string oldFileName;
	std::string newFileName;
	std::ifstream inFile;
	std::ofstream outFile;

	if (ac != 4)
		return (std::cout << "incorrect argument count" << std::endl, 0);
	if (!av[1][0] || !av[2][0])
		return (std::cout << "empty argument: unable to replace" << std::endl, 0);
	oldFileName = av[1];
	newFileName = newFileName + av[1] + ".replace";
	if (openFiles(oldFileName, newFileName, &inFile, &outFile))
		return (1);
	processFile(av, &inFile, &outFile);
	inFile.close();
	outFile.close();
	return (0);
}
