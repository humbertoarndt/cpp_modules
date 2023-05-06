# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 09:42:37 by harndt            #+#    #+#              #
#    Updated: 2023/05/06 11:37:22 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# VARIABLES
# ------------------------------------------------------------------------------

NAME		:=	DiamondTrap
CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98
HEADERS		:=	./includes/
SRCS		:=	./sources/main.cpp	./sources/ClapTrap.cpp		\
				./sources/ScavTrap.cpp	./sources/FragTrap.cpp	\
				./sources/DiamondTrap.cpp

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

%.o:	%.cpp 
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
			@echo "$(WHT)Compiling DIAMONDTRAP...$(EOC)"
			@$(CC) $(OBJS) -o $@
			@echo "$(GREEN)DIAMONDTRAP build completed.$(EOC)"

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -rf $(OBJS)
			@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME)
			@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

.PHONY:		all clean fclean re