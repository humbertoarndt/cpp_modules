# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 15:38:13 by harndt            #+#    #+#              #
#    Updated: 2023/04/18 15:38:34 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------------------------------------------------------------------------
# VARIABLES
# ------------------------------------------------------------------------------

NAME		:=	harl
CC			:=	c++
CFLAGS		:=	-Wall -Werror -Wextra -std=c++98
HEADERS		:=	./Harl.hpp
SRCS		:=	./main.cpp	./Harl.cpp

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
			@echo "$(WHT)Compiling HARL...$(EOC)"
			@$(CC) $(OBJS) -o $@
			@echo "$(GREEN)HARL build completed.$(EOC)"

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