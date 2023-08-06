/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
    #define IOPERAND_HPP_
    #include <string>
    #include <cmath>
    #include <limits>
    #include <stack>
    #include "error.hpp"

enum eOperandType {
    int8,
    int16,
    int32,
    FLOAT,
    DOUBLE
};

class IOperand {
    public:
        virtual std::string toString() const = 0;

        virtual eOperandType getType() const = 0;

        virtual int getPrecision() const = 0;

        virtual IOperand* operator+(const IOperand &rhs) const = 0;
        virtual IOperand* operator-(const IOperand &rhs) const = 0;
        virtual IOperand* operator*(const IOperand &rhs) const = 0;
        virtual IOperand* operator/(const IOperand &rhs) const = 0;
        virtual IOperand* operator%(const IOperand &rhs) const = 0;

        virtual ~IOperand() {}
    private:
};

#endif /* !IOPERAND_HPP_ */
