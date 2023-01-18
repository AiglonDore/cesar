/**
 * @file cesar.cpp
 * @author Thomas Roiseux
 * @brief Implements{@link cesar.h}.
 * @version 0.1
 * @date 2023-01-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../header/cesar.h"

#include <exception>
#include <stdexcept>

Caesar::Caesar(/* args */) : Code(), key(0)
{
}

Caesar::Caesar(int short key) : Code(), key(key % 26)
{
    if (key < 0)
    {
        throw std::invalid_argument("The key must be positive.");
    }
}

Caesar::~Caesar()
{
}

void Caesar::code(std::string &text) const
{
    for (char &c : text)
    {
        if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + key) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + key) % 26 + 'A';
        }
    }
}

void Caesar::decode(std::string &text) const
{
    for (char &c : text)
    {
        if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' - key + 26) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' - key + 26) % 26 + 'A';
        }
    }
}