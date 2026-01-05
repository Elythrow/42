# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 15:38:43 by gbazin            #+#    #+#              #
#    Updated: 2026/01/05 15:39:12 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := horde

# COMPILATION #

CC := c++

CFLAGS += -Wall 
CFLAGS += -Werror 
CFLAGS += -Wextra
CFLAGS += -std=c++98

# SOURCES #

SRCS += main.cpp

# OBJECTS #

OBJS := $(patsubst %.cpp, %.o, $(SRCS))

## RULES ##

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus