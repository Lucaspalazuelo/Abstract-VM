/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_HPP_
    #define INSTRUCTIONS_HPP_
    #include "core.hpp"

class Instructions {
    public:
        Instructions();
        ~Instructions();
        void getInstructions(std::vector<std::pair<std::string, IOperand*>> instructionsTab);

    private:
        std::map<std::string, void (Instructions::*)(IOperand const *)> operators;
        std::stack<IOperand const *> stack;
        std::map<int, IOperand const *> registers;
        std::vector<std::pair<std::string, IOperand*>> instructionsTab;

        void executeInstructions(std::string const &instruction, IOperand const *value);
        
        void push(IOperand const *value);
        void pop(IOperand const *value);
        void dump(IOperand const *value);
        void clear(IOperand const *value);
        void dup(IOperand const *value);
        void swap(IOperand const *value);
        void assertion(IOperand const *value);
        void add(IOperand const *value);
        void sub(IOperand const *value);
        void mul(IOperand const *value);
        void div(IOperand const *value);
        void mod(IOperand const *value);
        void load(IOperand const *value);
        void store(IOperand const *value);
        void print(IOperand const *value);
        void exit(IOperand const *value);
};

#endif /* !INSTRUCTIONS_HPP_ */
