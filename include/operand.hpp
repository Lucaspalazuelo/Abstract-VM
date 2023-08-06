/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** Operand
*/

#ifndef OPERAND_HPP_
    #define OPERAND_HPP_
    #include "IOperand.hpp"

template <typename T>
class Operand : public IOperand {
    public:
        Operand(const std::string & value, eOperandType type);
        ~Operand();

        virtual std::string toString() const override;

        virtual eOperandType getType() const override;

        virtual int getPrecision() const override;

        IOperand* operator+(const IOperand &rhs) const override;
        IOperand* operator-(const IOperand &rhs) const override;
        IOperand* operator*(const IOperand &rhs) const override;
        IOperand* operator/(const IOperand &rhs) const override;
        IOperand* operator%(const IOperand &rhs) const override;

        std::string getPrecisionValue(std::string value) const;

    private:
        std::string _value;
        eOperandType _type;
};

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;

#endif /* !OPERAND_HPP_ */
