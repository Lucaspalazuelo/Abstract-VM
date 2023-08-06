/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** InputHandler
*/

#ifndef InputHandler_HPP_
    #define InputHandler_HPP_
    #include "core.hpp"

class InputHandler {

    public:
        InputHandler(const std::string &file);
        ~InputHandler();
        void parseFile();
        void parseCin();
        eOperandType getType(const std::string &type);

    private:
        std::ifstream _file;
};

#endif /* !InputHandler_HPP_ */
