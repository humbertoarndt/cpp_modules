# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 12:12:29 by harndt            #+#    #+#              #
#    Updated: 2023/04/10 12:14:54 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# VARIABLES
# ------------------------------------------------------------------------------

NAME		:=	accounts
CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98
HEADERS		:=	./Account.hpp
SRCS		:=	./Account.cpp ./tests.cpp

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

%.o:		%.cpp
			@$(CC) $(CFLAGS) -l $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
			@echo "$(WHT)Compiling ACCOUNTS...$(EOC)"
			@$(CC) $(OBJS) -o $@
			@echo "$(GREEN)ACCOUNTS build completed.$(EOC)"

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