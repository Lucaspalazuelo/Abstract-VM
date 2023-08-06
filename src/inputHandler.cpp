/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
** File description:
** InputHandler
*/

#include "../include/core.hpp"

InputHandler::InputHandler(const std::string &fileName)
{
    if (fileName != "cin") {
        this->_file.open(fileName);
        if (!this->_file.is_open())
            throw error("Failed to open file");
    }
}

InputHandler::~InputHandler()
{
    if (this->_file.is_open())
        this->_file.close();
}

void InputHandler::parseFile()
{
    std::regex validCommand("^\\s*(push|pop|dump|clear|dup|swap|assert|add|sub|mul|div|mod|load|store|print|exit)\\s*((int8|int16|int32|float|double)\\(([-]?[\\d]+[.]?[\\d]*)\\))?\\s*$");
    std::string line;
    std::string instruction;
    eOperandType type;
    Factory *factory = new Factory();
    IOperand *operand;
    std::string value;
    Instructions *instructions = new Instructions();
    std::vector<std::pair<std::string, IOperand*>> instructionsTab;
    bool isExit = false;

    for (int i = 0; std::getline(this->_file, line, '\n'); i++) {

        if (line[0] == ';')
            continue;
        if (line.empty() || line == "\n" || line == "\t" || line == "\r\n" || line == "\r" || line == ";")
            continue;

        std::smatch match;

        if (std::regex_search(line, match, validCommand)) {
            if (match[1].matched)
                instruction = match[1].str();
            if (match[1].matched != true)
                throw error("Error: invalid command in line");
            if (instruction == "exit")
                isExit = true;
            if (match[3].matched)
                type = getType(match[3].str());
            if (match[4].matched) {
                value = match[4].str();
                operand = factory->createOperand(type, value);
            }
            instructionsTab.push_back(std::make_pair(instruction, operand));
        } else
            throw error("Error: invalid command in line");
    }
    if (!isExit)
        throw error("Error: no exit instruction");
    instructions->getInstructions(instructionsTab);
}

void InputHandler::parseCin()
{
    std::regex validCommand("^(push|pop|dump|clear|dup|swap|assert|add|sub|mul|div|mod|load|store|print|exit)[\\s]*((int8|int16|int32|float|double)\\(([-]?[\\d]+[.]?[\\d]*)\\))?");
    std::string line;
    std::string instruction;
    eOperandType type;
    Factory *factory = new Factory();
    IOperand *operand;
    std::string value;
    Instructions *instructions = new Instructions();
    std::vector<std::pair<std::string, IOperand*>> instructionsTab;
    bool isExit = false;

    for (int i = 0; std::getline(std::cin, line, '\n'); i++) {

        if (line[0] == ';')
            continue;
        if (line.empty() || line == "\n" || line == "\t" || line == "\r\n" || line == "\r" || line == ";")
            continue;

        std::smatch match;

        if (line == ";;")
            break;
        if (std::regex_search(line, match, validCommand)) {
            if (match[1].str() != "" && match[1].matched)
                instruction = match[1].str();
            if (match[1].matched != true)
                throw error("Error 0: invalid command in line");
            if (instruction == "exit")
                isExit = true;
            if (match[3].str() != "" && match[3].matched)
                type = getType(match[3].str());
            if (match[4].str() != "" && match[4].matched) {
                value = match[4].str();
                operand = factory->createOperand(type, value);
            }
            instructionsTab.push_back(std::make_pair(instruction, operand));
        } else
            throw error("Error: invalid command in line");
    }
    if (!isExit)
        throw error("Error: no exit instruction");
    instructions->getInstructions(instructionsTab);
}

eOperandType InputHandler::getType(const std::string &type)
{
    if (type == "int8")
        return int8;
    else if (type == "int16")
        return int16;
    else if (type == "int32")
        return int32;
    else if (type == "float")
        return FLOAT;
    else if (type == "double")
        return DOUBLE;
    else
        throw error("Error: invalid type");
}
