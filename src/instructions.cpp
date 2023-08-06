/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** instructions
*/

#include "../include/core.hpp"

Instructions::Instructions()
{
    operators["push"] = &Instructions::push;
    operators["pop"] = &Instructions::pop;
    operators["dump"] = &Instructions::dump;
    operators["clear"] = &Instructions::clear;
    operators["dup"] = &Instructions::dup;
    operators["swap"] = &Instructions::swap;
    operators["assert"] = &Instructions::assertion;
    operators["add"] = &Instructions::add;
    operators["sub"] = &Instructions::sub;
    operators["mul"] = &Instructions::mul;
    operators["div"] = &Instructions::div;
    operators["mod"] = &Instructions::mod;
    operators["load"] = &Instructions::load;
    operators["store"] = &Instructions::store;
    operators["print"] = &Instructions::print;
    operators["exit"] = &Instructions::exit;
}

Instructions::~Instructions()
{

}

void Instructions::push(IOperand const *value)
{
    this->stack.push(value);
}

void Instructions::pop(IOperand const *value)
{
    if (this->stack.empty())
        throw error("Error: pop on empty stack");
    this->stack.pop();
}

void Instructions::dump(IOperand const *value)
{
    std::stack<IOperand const *> tmp = this->stack;

    while (!tmp.empty()) {
        std::cout << tmp.top()->toString() << std::endl;
        tmp.pop();
    }
}

void Instructions::clear(IOperand const *value)
{
    while (!this->stack.empty())
        this->stack.pop();
}

void Instructions::dup(IOperand const *value)
{
    if (this->stack.empty())
        throw error("Error: dup on empty stack");
    this->stack.push(this->stack.top());
}

void Instructions::swap(IOperand const *value)
{
    IOperand const *tmp1;
    IOperand const *tmp2;

    if (this->stack.size() < 2)
        throw error("Error: swap on stack with less than 2 values");
    tmp1 = this->stack.top();
    this->stack.pop();
    tmp2 = this->stack.top();
    this->stack.pop();
    this->stack.push(tmp1);
    this->stack.push(tmp2);
}

void Instructions::assertion(IOperand const *value)
{
    if (this->stack.empty())
        throw error("Error: assertion on empty stack");
    if (this->stack.top()->getType() != value->getType() || this->stack.top()->toString() != value->toString())
        throw error("Error: assertion failed");
}

void Instructions::add(IOperand const *value)
{
    IOperand const *tmp1;
    IOperand const *tmp2;
    IOperand const *result;

    if (this->stack.size() < 2)
        throw error("Error: add on stack with less than 2 values");
    tmp1 = this->stack.top();
    this->stack.pop();
    tmp2 = this->stack.top();
    this->stack.pop();
    result = *tmp2 + *tmp1;
    this->stack.push(result);
}

void Instructions::sub(IOperand const *value)
{
    IOperand const *tmp1;
    IOperand const *tmp2;
    IOperand const *result;

    if (this->stack.size() < 2)
        throw error("Error: sub on stack with less than 2 values");
    tmp1 = this->stack.top();
    this->stack.pop();
    tmp2 = this->stack.top();
    this->stack.pop();
    result = *tmp2 - *tmp1;
    this->stack.push(result);
}

void Instructions::mul(IOperand const *value)
{
    IOperand const *tmp1;
    IOperand const *tmp2;
    IOperand const *result;

    if (this->stack.size() < 2)
        throw error("Error: mul on stack with less than 2 values");
    tmp1 = this->stack.top();
    this->stack.pop();
    tmp2 = this->stack.top();
    this->stack.pop();
    result = *tmp2 * *tmp1;
    this->stack.push(result);
}

void Instructions::div(IOperand const *value)
{
    IOperand const *tmp1;
    IOperand const *tmp2;
    IOperand const *result;

    if (this->stack.size() < 2)
        throw error("Error: div on stack with less than 2 values");
    tmp1 = this->stack.top();
    this->stack.pop();
    tmp2 = this->stack.top();
    this->stack.pop();
    result = *tmp2 / *tmp1;
    this->stack.push(result);
}

void Instructions::mod(IOperand const *value)
{
    IOperand const *tmp1;
    IOperand const *tmp2;
    IOperand const *result;

    if (this->stack.size() < 2)
        throw error("Error: mod on stack with less than 2 values");
    tmp1 = this->stack.top();
    this->stack.pop();
    tmp2 = this->stack.top();
    this->stack.pop();
    result = *tmp2 % *tmp1;
    this->stack.push(result);
}

void Instructions::load(IOperand const *value)
{
    int index = std::stoi(value->toString());

    if (index < 0 || index > 15)
        throw error("Error: load on invalid index");
    if (this->registers[index] == nullptr)
        throw error("Error: load on empty register");
    this->stack.push(this->registers[index]);
}

void Instructions::store(IOperand const *value)
{
    if (this->stack.empty())
        throw error("Error: store on empty stack");

    int index = std::stoi(value->toString());

    if (index < 0 || index > 15)
        throw error("Error: store on invalid index");
    this->registers[index] = this->stack.top();
    this->stack.pop();
}

void Instructions::print(IOperand const *value)
{
    if (this->stack.empty())
        throw error("Error: print on empty stack");
    if (this->stack.top()->getType() != int8)
        throw error("Error: print on non int8 value");
    std::cout << static_cast<char>(std::stoi(this->stack.top()->toString())) << std::endl;
}

void Instructions::exit(IOperand const *value)
{
    (void)value;
    std::exit(0);
}

void Instructions::getInstructions(std::vector<std::pair<std::string, IOperand*>> instructionsTab)
{
    std::string instruction;
    IOperand* operand;

    for (auto it = instructionsTab.begin(); it != instructionsTab.end(); it++) {
        instruction = it->first;
        operand = it->second;
        Instructions::executeInstructions(instruction, operand);
    }
}

void Instructions::executeInstructions(std::string const &instruction, IOperand const *value)
{
    (this->*operators[instruction])(value);
}
