/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** Int8
*/

#ifndef INT8_HPP_
    #define INT8_HPP_
    #include "../operand.hpp"

class Int8 : public Operand<int8_t> {
    public:
        Int8(const std::string &value);
        ~Int8();

    private:
};

template<>
eOperandType Operand<int8_t>::getType() const {
    return eOperandType::int8;
}

template<>
int Operand<int8_t>::getPrecision() const {
    return 0;
}

#endif /* !INT8_HPP_ */
