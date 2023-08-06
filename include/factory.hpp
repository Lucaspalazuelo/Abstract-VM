/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_
    #include "IOperand.hpp"
    #include "type/int8.hpp"
    #include "type/int16.hpp"
    #include "type/int32.hpp"
    #include "type/float.hpp"
    #include "type/double.hpp"
    #include <map>

class Factory {
    public:
        Factory();
        ~Factory();
        static IOperand* createOperand(eOperandType type, const std::string& value);

    private:
        IOperand* createInt8(const std::string& value);
        IOperand* createInt16(const std::string& value);
        IOperand* createInt32(const std::string& value);
        IOperand* createFloat(const std::string& value);
        IOperand* createDouble(const std::string& value);

        const Factory& operator=(const Factory&);

};

#endif /* !FACTORY_HPP_ */
