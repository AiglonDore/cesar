/**
 * @file main.cpp
 * @author Thomas Roiseux
 * @brief Main file.
 * @version 0.1
 * @date 2023-01-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <string>

#include "../header/vigenere.h"
#include "../header/cesar.h"

/**
 * @brief Main function.
 * 
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return int Exit code.
 */
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " [vigenere|cesar] [key]" << std::endl;
        return 1;
    }
    if (argc > 3)
    {
        std::cerr << "Too many arguments." << std::endl;
        return 1;
    }

    Code *code = nullptr;

    try
    {
        if (!strcmp(argv[1], "vigenere"))
        {
            code = new Vigenere(argv[2]);
        }
        else if (!strcmp(argv[1], "cesar"))
        {
            short int key = 0;
            if (sscanf(argv[2], "%hd", &key) != 1)
            {
                throw std::invalid_argument("The key must be a number.");
            }
            code = new Caesar(key);
        }
        else
        {
            throw std::invalid_argument("Unknown algorithm.");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::string text;
    std::cout << "Enter the text to code:" << std::endl;
    std::getline(std::cin, text);

    std:: cout << "The coded text is:" << std::endl;
    code->code(text);
    std::cout << text << std::endl;

    code->decode(text);
    std::cout << "The decoded text is:" << std::endl;
    std::cout << text << std::endl;

    delete code;
    code = nullptr;
    return 0;
}