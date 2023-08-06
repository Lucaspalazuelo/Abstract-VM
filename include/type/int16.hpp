/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** Int16
*/

#ifndef INT16_HPP_
    #define INT16_HPP_
    #include "../operand.hpp"

class Int16 : public Operand<int16_t> {
    public:
        Int16(const std::string &value);
        ~Int16();

    private:
};

template<>
eOperandType Operand<int16_t>::getType() const {
    return eOperandType::int16;
}

template<>
int Operand<int16_t>::getPrecision() const {
    return 1;
}

#endif /* !INT16_HPP_ */
