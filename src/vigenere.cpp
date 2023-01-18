/**
 * @file vigenere.cpp
 * @author Thomas Roiseux
 * @brief Implements {@link vigenere.h}.
 * @version 0.1
 * @date 2023-01-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../header/vigenere.h"
#include <cctype>
#include <stdexcept>
#include <exception>

Vigenere::Vigenere() : Code(), key("a")
{
}

Vigenere::Vigenere(const std::string &key) : Code(), key(key)
{
    if (key.empty())
    {
        throw std::invalid_argument("The key cannot be empty.");
    }
    for (const char& c : key)
    {
        if (!isalpha(c))
        {
            throw std::invalid_argument("The key must only contain litteral characters.");
        }
    }
}

Vigenere::~Vigenere()
{
}

void Vigenere::code(std::string &text) const
{
    for (size_t i = 0; i < text.size(); i++)
    {
        char c = text[i];
        if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + key[i % key.size()] - 'a') % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + key[i % key.size()] - 'A') % 26 + 'A';
        }
        text[i] = c;
    }
}

void Vigenere::decode(std::string &text) const
{
    for (size_t i = 0; i < text.size(); i++)
    {
        char c = text[i];
        if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' - key[i % key.size()] + 'a' + 26) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' - key[i % key.size()] + 'A' + 26) % 26 + 'A';
        }
        text[i] = c;
    }
}