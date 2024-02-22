# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:23:52 by fbohling          #+#    #+#              #
#    Updated: 2024/01/24 11:33:53 by fbohling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex04
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SCRS = main.cpp
OBJS = $(SCRS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[32m[✔] \033[0m\033[1;32mCreated:\033[0m $(NAME)"

%.o: %.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f *.replace

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
