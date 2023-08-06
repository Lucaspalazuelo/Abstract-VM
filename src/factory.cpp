/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** factory
*/

#include "../include/factory.hpp"

Factory::Factory()
{

}

IOperand *Factory::createOperand(eOperandType type, const std::string &value)
{
	IOperand* (Factory::*f)(const std::string&);

    switch (type) {
        case eOperandType::int8:
            f = &Factory::createInt8;
            break;
        case eOperandType::int16:
            f = &Factory::createInt16;
            break;
        case eOperandType::int32:
            f = &Factory::createInt32;
            break;
        case eOperandType::FLOAT:
            f = &Factory::createFloat;
            break;
        case eOperandType::DOUBLE:
            f = &Factory::createDouble;
            break;
        default:
            throw error("Error: invalid type");
    }
    Factory factory;
    return (factory.*f)(value);
}

IOperand *Factory::createInt8(const std::string &value)
{
    if (std::stod(value) < std::numeric_limits<int8_t>::min() || std::stod(value) > std::numeric_limits<int8_t>::max())
        throw error("Error: underflow or overflow");

    return (new Int8(value));
}

IOperand *Factory::createInt16(const std::string &value)
{
    if (std::stod(value) < std::numeric_limits<int16_t>::min() || std::stod(value) > std::numeric_limits<int16_t>::max())
        throw error("Error: underflow or overflow");

    return (new Int16(value));
}

IOperand *Factory::createInt32(const std::string &value)
{
    if (std::stod(value) < std::numeric_limits<int32_t>::min() || std::stod(value) > std::numeric_limits<int32_t>::max())
        throw error("Error: underflow or overflow");

    return (new Int32(value));
}

IOperand *Factory::createFloat(const std::string &value)
{
    if (std::stod(value) == 0)
        return (new Float(value));

    if (std::stod(value) < std::numeric_limits<float>::min() || std::stod(value) > std::numeric_limits<float>::max())
        throw error("Error: underflow or overflow");

    return (new Float(value));
}

IOperand *Factory::createDouble(const std::string &value)
{
    if (std::stod(value) == 0)
        return (new Double(value));

    if (std::stod(value) > std::numeric_limits<double>::max())
        throw error("Error: underflow or overflow");

    return (new Double(value));
}

Factory::~Factory()
{

}
