# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 12:28:06 by harndt            #+#    #+#              #
#    Updated: 2023/05/01 15:17:22 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# VARIABLES
# ------------------------------------------------------------------------------

NAME		:=	violence
CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98
HEADERS		:=	./HumanA.hpp	./HumanB.hpp	./Weapon.hpp
SRCS		:=	./main.cpp	./HumanA.cpp	./HumanB.cpp	./Weapon.cpp

OBJS		:=	$(SRCS:.cpp=.o)

# ==============================================================================
# COLORS
# ==============================================================================

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHT			:=	\033[1;37m
EOC			:=	\033[1;0m

# ==============================================================================
# RECIPES
# ==============================================================================

all:		$(NAME)
			clear

%.o:		%.cpp $(HEADERS)
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@echo "$(WHT)Compiling HUMAN...$(EOC)"
			@$(CC) $(OBJS) -o $@
			@echo "$(GREEN)HUMAN build completed.$(EOC)"

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS)
			@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME)
			@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

test:		all
			./$(NAME) "humberto doisberto tresBERTO QUATROberto"

.PHONY:		all clean fclean re