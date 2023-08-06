##
## EPITECH PROJECT, 2023
## B-SYN-400-LYN-4-1-abstractVM-lucas.palazuelo
## File description:
## Makefile
##

SRC	=	src/main.cpp \
		src/factory.cpp \
		src/operand.cpp \
		src/type/int8.cpp \
		src/type/int16.cpp \
		src/type/int32.cpp \
		src/type/float.cpp \
		src/type/double.cpp \
		src/error.cpp \
		src/inputHandler.cpp \
		src/instructions.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	abstractVM

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -std=gnu++17
	make clean

clean:
	rm -f src/*.o src/type/*.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
