/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** Int32
*/

#ifndef INT32_HPP_
    #define INT32_HPP_
    #include "../operand.hpp"

class Int32 : public Operand<int32_t> {
    public:
        Int32(const std::string &value);
        ~Int32();

    private:
};

template<>
eOperandType Operand<int32_t>::getType() const {
    return eOperandType::int32;
}

template<>
int Operand<int32_t>::getPrecision() const {
    return 2;
}

#endif /* !INT32_HPP_ */
