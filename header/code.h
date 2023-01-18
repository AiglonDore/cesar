/**
 * @file code.h
 * @author Thomas Roiseux
 * @brief Provides a global class to use codes.
 * @version 0.1
 * @date 2023-01-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CODE_H
#define CODE_H

#include <string>

class Code
{
public:
    /**
     * @brief Construct a new Code object.
     * 
     */
    Code() = default;

    /**
     * @brief Destroy the Code object.
     * 
     */
    virtual ~Code();

    /**
     * @brief Codes the text.
     * 
     * @param text Text to be code. It will be modified.
     */
    virtual void code(std::string &text) const = 0;
    /**
     * @brief Decodes the text.
     * 
     * @param text Text to be decode. It will be modified.
     */
    virtual void decode(std::string &text) const = 0;
};

#endif // CODE_H