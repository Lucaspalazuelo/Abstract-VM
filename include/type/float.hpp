/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** Float
*/

#ifndef FLOAT_HPP_
    #define FLOAT_HPP_
    #include "../operand.hpp"

class Float : public Operand<float> {
    public:
        Float(const std::string &value);
        ~Float();

    private:
};

template<>
eOperandType Operand<float>::getType() const {
    return eOperandType::FLOAT;
}

template<>
int Operand<float>::getPrecision() const {
    return 3;
}

#endif /* !FLOAT_HPP_ */
