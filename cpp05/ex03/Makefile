# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:39:56 by harndt            #+#    #+#              #
#    Updated: 2023/06/27 14:45:57 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# VARIABLES
# ------------------------------------------------------------------------------

NAME		:=	intern
CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -g
HEADERS		:=	./includes/
SRCS		:=	./sources/main.cpp	./sources/Bureaucrat.cpp			\
				./sources/AForm.cpp ./sources/ShrubberyCreationForm.cpp	\
				./sources/RobotomyRequestForm.cpp						\
				./sources/PresidentialPardonForm.cpp					\
				./sources/Intern.cpp

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
			@echo "$(WHT)Compiling INTERN...$(EOC)"
			@$(CC) $(OBJS) $(CFLAGS) -o $@
			@echo "$(GREEN)INTERN build completed.$(EOC)"

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -rf $(OBJS)
			@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME)
			@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

display:	re
			clear
			@echo ">Executing ./$(NAME)"
			./$(NAME)

v:			all
			valgrind ./$(NAME)

.PHONY:		all clean fclean re v