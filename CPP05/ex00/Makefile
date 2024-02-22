NAME = ex00
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SCRS = main.cpp Bureaucrat.cpp
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
