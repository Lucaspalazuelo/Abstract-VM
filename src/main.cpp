/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** main
*/

#include "../include/core.hpp"

int main(int ac, char **av)
{
    if (ac > 2)
        return 84;
    if (ac == 2) {
        InputHandler *inputVM = new InputHandler(av[1]);

        try {
            inputVM->parseFile();
        } catch(error& e) {
            std::cerr << e.what() << '\n';
            return 84;
        }
    }
    if (ac == 1) {
        InputHandler *inputVM = new InputHandler("cin");

        try {
            inputVM->parseCin();
        } catch(error& e) {
            std::cerr << e.what() << '\n';
            return 84;
        }
    }
    return 0;
}
