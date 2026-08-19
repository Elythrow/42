# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/19 21:43:04 by gbazin            #+#    #+#              #
#    Updated: 2026/08/19 21:44:03 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## VARIABLES ##

# TARGET #

NAME := ScalarConverter

# COMPILATION #

CXX := c++

CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -std=c++98

# SOURCES #

SRCS += main.cpp
SRCS += ScalarConverter.cpp

# HEADERS #

HDS += ScalarConverter.hpp

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