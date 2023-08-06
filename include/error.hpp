/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_
    #include <exception>
    #include <string>

class error : public std::exception {

    public:
        error(const std::string &message);
        const char *what() const noexcept;
        ~error();
    private:
        std::string _message;
};

#endif /* !ERROR_HPP_ */
