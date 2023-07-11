# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 12:12:29 by harndt            #+#    #+#              #
#    Updated: 2023/07/11 11:38:54 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# VARIABLES
# ------------------------------------------------------------------------------

NAME		:=	zombie
CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98
HEADERS		:=	./Zombie.hpp
SRCS		:=	./main.cpp	./Zombie.cpp	./zombieHorde.cpp

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

%.o:	%.cpp $(HEADERS)
			@$(ECHO) Compiling $< $(EOC)
			@$(CC) $(CFLAGS) -c $< -o $@

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

test:		all
			./$(NAME) "humberto doisberto tresBERTO QUATROberto"

.PHONY:		all clean fclean re