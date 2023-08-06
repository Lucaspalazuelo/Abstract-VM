/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
    #define DOUBLE_HPP_
    #include "../operand.hpp"

class Double : public Operand<double> {
    public:
        Double(const std::string &value);
        ~Double();

    private:
};

template<>
eOperandType Operand<double>::getType() const {
    return eOperandType::DOUBLE;
}

template<>
int Operand<double>::getPrecision() const {
    return 4;
}

#endif /* !DOUBLE_HPP_ */
