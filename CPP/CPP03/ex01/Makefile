# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 19:26:49 by gbazin            #+#    #+#              #
#    Updated: 2026/01/08 23:37:33 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := a.out

# COMPILATION #

CXX := c++

CXXFLAGS += -Wall 
CXXFLAGS += -Werror 
CXXFLAGS += -Wextra
CXXFLAGS += -std=c++98

# SOURCES #

SRCS += main.cpp
SRCS += ClapTrap.cpp
SRCS += ScavTrap.cpp

# OBJECTS #

OBJS := $(patsubst %.cpp, %.o, $(SRCS))

## RULES ##

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus