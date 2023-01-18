/**
 * @file vigenere.h
 * @author Thomas Roiseux
 * @brief Provides a class to use the Vigènere code.
 * @version 0.1
 * @date 2023-01-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VIGENERE_H
#define VIGENERE_H

#include "code.h"
#include <string>

class Vigenere : public Code
{
private:
    std::string key;
public:
    /**
     * @brief Construct a new Vigenere object.
     * 
     * @param key Key to use.
     */
    Vigenere();

    /**
     * @brief Construct a new Vigenere object.
     * @throws std::invalid_argument If the key is empty or if it has other than litteral characters.
     * @param key Key to use.
     */
    Vigenere(const std::string& key);

    /**
     * @brief Destroy the Vigenere object.
     * 
     */
    virtual ~Vigenere();
    /**
     * @brief Get the Key object.
     * 
     * @return const std::string& Constant reference to the key.
     */
    const std::string& getKey() const { return key; };

    /**
     * @brief Codes the text.
     * 
     * @param text Text to be code. It will be modified.
     */
    virtual void code(std::string& text) const override final;

    /**
     * @brief Decodes the text.
     * 
     * @param text Text to be decode. It will be modified.
     */
    virtual void decode(std::string& text) const override final;
};

#endif // VIGENERE_H