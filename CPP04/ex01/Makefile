# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:05:46 by fbohling          #+#    #+#              #
#    Updated: 2024/01/31 16:56:36 by fbohling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SCRS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS = $(SCRS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[32m[✔] \033[0m\033[1;32mCreated:\033[0m $(NAME)"

%.o: %.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
