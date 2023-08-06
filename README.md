# Abstract-VM

## About The Project

`AbstractVM` is a Epitech second year project in C++ to develop a virtual machine that interprets programs written in a basic assembler language. It operates as a stack machine and performs arithmetic operations.

## Instructions

1. **comments**
    - Begin with a semicolon (;) and end at the end of a line.
    - May be indifferent at the beginning of a line or after an instruction.

2. **pushv**
    - Stack the `v` value at the top.
    - The `v` value can be one of: `int8(n)`, `int16(n)`, `int32(n)`, `float(z)`, or `double(z)`.

3. **pop**
    - Unstacks the value at the top of the stack.
    - Stops execution if the stack is empty.

4. **clear**
    - Clears the stack.

5. **dup**
    - Duplicates the top value on the stack.

6. **swap**
    - Swaps the top two values on the stack.

7. **dump**
    - Displays stack values from newest to oldest without modifying the stack.

8. **assertv**
    - Verifies the top stack value against the given parameter.
    - Stops execution if values are not equal.

9. **add**
    - Unstacks the top two values, adds them, and stacks the result.
    - Stops execution if less than two values on the stack.

10. **sub**
    - Unstacks the top two values, subtracts them, and stacks the result.
    - Stops execution if less than two values on the stack.

11. **mul**
    - Unstacks the top two values, multiplies them, and stacks the result.
    - Stops execution if less than two values on the stack.

12. **div**
    - Unstacks the top two values, divides them, and stacks the result.
    - Stops execution if less than two values on the stack or if divisor is 0.

13. **mod**
    - Unstacks the top two values, calculates modulo, and stacks the result.
    - Stops execution if less than two values on the stack or if divisor is 0.

14. **loadv**
    - Copies value from register `v` and stacks it.
    - Stops execution if register `v` is empty.

15. **storev**
    - Unstacks the top value and stores it in register `v`.

16. **print**
    - Ensures top stack value is an 8-bit integer and interprets it as an ASCII value.
    - Displays the corresponding character.

17. **exit**
    - Quits the current program execution.
    - Stops execution if this instruction is missing but all others are executed.

## Prerequisites

- Developed and tested primarily on x86-64/Linux.
- Standard C++ Libraries.

## Compilation

The program is written in `C++` and comes with a `Makefile` that includes the following rules:

- `make`: Compile the program.
- `make re`: Recompile the program.
- `make clean`: Clean object files.
- `make fclean`: Clean object files and the binary.

After compilation, the binary will be named `abstractVM`.

## Usage
To test the program use the test file in the repository, feel free to modify it.

Exemple :
```bash
make all

./abstractVM test.avm
