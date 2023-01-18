/**
 * @file cesar.h
 * @author Thomas Roiseux
 * @brief Provides a class to use the Caesar cipher.
 * @version 0.1
 * @date 2023-01-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CESAR_H
#define CESAR_H

#include "code.h"

class Caesar : public Code
{
private:
    unsigned int short key;
public:
    /**
     * @brief Construct a new Caesar object.
     * 
     */
    Caesar();

    /**
     * @brief Construct a new Caesar object.
     * 
     * @param key Value for the key.
     * @throws std::invalid_argument If the key is strictly negative.
     */
    explicit Caesar(int short key);
    /**
     * @brief Destroy the Caesar object.
     * 
     */
    virtual ~Caesar();

    /**
     * @brief Get the Key object.
     * 
     * @return unsigned int short The key.
     */
    unsigned int short getKey() const { return key; };

    /**
     * @brief Codes the text.
     * 
     * @param text Text to be code. It will be modified.
     */
    virtual void code(std::string &text) const override final;

    /**
     * @brief Decodes the text.
     * 
     * @param text Text to be decode. It will be modified.
     */
    virtual void decode(std::string &text) const override final;
};


#endif // CESAR_H