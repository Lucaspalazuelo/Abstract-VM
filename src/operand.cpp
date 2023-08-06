/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** operand
*/

#include "../include/operand.hpp"
#include "../include/factory.hpp"

template<typename T>
Operand<T>::Operand(const std::string &value, eOperandType type)
{
    this->_value = value;
    this->_type = type;
}

template<typename T>
std::string Operand<T>::toString() const
{
    return this->_value;
}

template<typename T>
eOperandType Operand<T>::getType() const
{
    return this->_type;
}

template<typename T>
Operand<T>::~Operand()
{

}

template<typename T>
IOperand *Operand<T>::operator+(const IOperand &rhs) const
{
    double thisValue = std::stod(this->_value);
    double rhsValue = std::stod(rhs.toString());
    double resultValue;
    std::string resultStr;

    resultValue = thisValue + rhsValue;
    resultStr = getPrecisionValue(std::to_string(resultValue));
    if (this->getPrecision() < rhs.getPrecision())
        return Factory::createOperand(rhs.getType(), resultStr);
    return Factory::createOperand(this->getType(), resultStr);
}

template<typename T>
IOperand *Operand<T>::operator-(const IOperand &rhs) const
{
    double thisValue = std::stod(this->_value);
    double rhsValue = std::stod(rhs.toString());
    double resultValue;
    std::string resultStr;

    resultValue = thisValue - rhsValue;
    resultStr = getPrecisionValue(std::to_string(resultValue));
    if (this->getPrecision() < rhs.getPrecision())
        return Factory::createOperand(rhs.getType(), resultStr);
    return Factory::createOperand(this->getType(), resultStr);
}

template<typename T>
IOperand *Operand<T>::operator*(const IOperand &rhs) const
{
    double thisValue = std::stod(this->_value);
    double rhsValue = std::stod(rhs.toString());
    double resultValue;
    std::string resultStr;

    resultValue = thisValue * rhsValue;
    resultStr = getPrecisionValue(std::to_string(resultValue));
    if (this->getPrecision() < rhs.getPrecision())
        return Factory::createOperand(rhs.getType(), resultStr);
    return Factory::createOperand(this->getType(), resultStr);
}

template<typename T>
IOperand *Operand<T>::operator/(const IOperand &rhs) const
{
    double thisValue = std::stod(this->_value);
    double rhsValue = std::stod(rhs.toString());
    double resultValue;
    std::string resultStr;

    if (rhsValue == 0)
        throw error("Error : modulo by zero");
    resultValue = thisValue / rhsValue;
    resultStr = getPrecisionValue(std::to_string(resultValue));
    if (this->getPrecision() < rhs.getPrecision())
        return Factory::createOperand(rhs.getType(), resultStr);
    return Factory::createOperand(this->getType(), resultStr);
}

template<typename T>
IOperand *Operand<T>::operator%(const IOperand &rhs) const
{
    double thisValue = std::stod(this->_value);
    double rhsValue = std::stod(rhs.toString());
    double resultValue;
    std::string resultStr;

    if (rhsValue == 0)
        throw error("Error : modulo by zero");
    if constexpr (std::is_floating_point<T>::value) {
        resultValue = std::fmod(thisValue, rhsValue);
    } else if constexpr (std::is_integral<T>::value) {
        int intThisValue = std::stoi(this->_value);
        int intRhsValue = std::stoi(rhs.toString());
        resultValue = intThisValue % intRhsValue;
    }
    resultStr = getPrecisionValue(std::to_string(resultValue));
    if (this->getPrecision() < rhs.getPrecision())
        return Factory::createOperand(rhs.getType(), resultStr);
    return Factory::createOperand(this->getType(), resultStr);
}

template<typename T>
std::string Operand<T>::getPrecisionValue(std::string value) const
{
    value.erase(value.find_last_not_of('0') + 1, std::string::npos);
    if (value.back() == '.')
        value.pop_back();
    return value;
}
