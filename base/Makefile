##
## Makefile for YOLO in /Users/sabs231/Downloads/front/lexer/YOLO
##
## Made by sergioandres baezserrano
## Login   <baezse_s@epitech.net>
##
## Started on  Mon Apr 22 22:42:31 2013 sergioandres baezserrano
## Last update Tue Apr 23 01:50:21 2013 sergioandres baezserrano
##

SRC 		= 	lexer/Token.cpp \
			lexer/Word.cpp  \
			lexer/Real.cpp  \
			lexer/Num.cpp   \
			lexer/Lexer.cpp \
			inter/Node.cpp  \
			inter/Stmt.cpp  \
			inter/Seq.cpp  \
			inter/Expr.cpp  \
			inter/Id.cpp  \
			inter/While.cpp  \
			inter/If.cpp  \
			inter/Else.cpp  \
			inter/Temp.cpp  \
			inter/Op.cpp  \
			inter/Unary.cpp  \
			inter/Set.cpp  \
			inter/Or.cpp \
			inter/Constant.cpp \
			inter/And.cpp \
			inter/Logical.cpp \
			inter/Rel.cpp \
			inter/Arith.cpp \
			symbols/Type.cpp  \
			symbols/Env.cpp  \
			parser/Parser.cpp \
			main.cpp

OBJS 		= 	$(SRC:.cpp=.o)

CPP		= 	g++

CPPFLAGS 	= -ggdb -W -Wall -Wextra -I./include

NAME 		= 	C_Compiler

all: 			$(NAME)

$(NAME): 		$(OBJS)
			$(CPP) $(CPPFLAGS) -o $@ $^

clean:
			rm -f $(OBJS)

fclean: 		clean
			rm -f $(NAME)

re: 			clean all
