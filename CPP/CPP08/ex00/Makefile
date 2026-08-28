# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/28 05:36:04 by gbazin            #+#    #+#              #
#    Updated: 2026/08/28 06:01:27 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := easyfind

# COMPILATION #

CXX := c++

CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -std=c++98

# SOURCES #

SRCS += main.cpp

# HEADERS #

HDS += easyfind.hpp
HDS += easyfind.tpp

# OBJECTS #

OBJS := $(SRCS:.cpp=.o)

## RULES ##

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJS): $(HDS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re