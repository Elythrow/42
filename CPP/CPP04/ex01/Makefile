# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 12:32:45 by gbazin            #+#    #+#              #
#    Updated: 2026/01/09 17:44:45 by gbazin           ###   ########.fr        #
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
SRCS += Animal.cpp
SRCS += Dog.cpp
SRCS += Cat.cpp
SRCS += Brain.cpp

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