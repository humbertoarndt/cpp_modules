# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:39:56 by harndt            #+#    #+#              #
#    Updated: 2023/07/11 11:47:43 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# VARIABLES
# ------------------------------------------------------------------------------

NAME		:=	form
CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -g
HEADERS		:=	./includes/
SRCS		:=	./sources/main.cpp	./sources/Bureaucrat.cpp			\
				./sources/AForm.cpp ./sources/ShrubberyCreationForm.cpp	\
				./sources/RobotomyRequestForm.cpp	./sources/PresidentialPardonForm.cpp

OBJS		:=	$(SRCS:.cpp=.o)

# ==============================================================================
# COLORS
# ==============================================================================

EOC				:=	"\e[0m"
ITALIC_GRAY		:=	"\e[3;37m"
ITALIC_MAGENTA	:=	"\e[1;3;35m"

# ==============================================================================
# BUILD PERCENTAGE
# ==============================================================================

ifndef ECHO
	T := $(shell $(MAKE) $(MAKECMDGOALS) -n ECHO="counter" | grep -c "counter")
endif

ifeq ($(firstword $(MAKECMDGOALS)), $(shell echo re))
	T := $(shell expr $(words $(OBJS)) + 1)
endif

PRINT	:=	$(shell which echo) -e
N := x
C = $(words $(N))$(eval N := x $(N))
P = "`expr $(C) '*' 100 / $(T)`"
ECHO = $(PRINT) $(ITALIC_GRAY)"[$(P)%]\t"

# ==============================================================================
# RECIPES
# ==============================================================================

all:		$(NAME)

%.o:	%.cpp
			@$(ECHO) Compiling $< $(EOC)
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
			@$(ECHO) $(NAME) created! $(EOC)
			@$(CC) $(OBJS) $(CFLAGS) -o $@

clean:
			@rm -rf $(OBJS)
			@$(PRINT) $(ITALIC_MAGENTA)"Objects deleted"$(EOC)

fclean:		clean
			@rm -f $(NAME)
			@$(PRINT) $(ITALIC_MAGENTA)$(NAME)" deleted"$(EOC)

re:			fclean all

display:	re
			clear
			@echo ">Executing ./$(NAME)"
			./$(NAME)

v:			all
			valgrind ./$(NAME)

.PHONY:		all clean fclean re v