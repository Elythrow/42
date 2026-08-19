# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/18 14:02:25 by gbazin            #+#    #+#              #
#    Updated: 2026/08/19 16:37:18 by gbazin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## VARIABLES ##

# TARGET #

NAME := forms

# COMPILATION #

CXX := c++

CXXFLAGS += -Wall
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -std=c++98

# SOURCES #

SRCS += main.cpp
SRCS += Bureaucrat.cpp
SRCS += AForm.cpp
SRCS += PresidentialPardonForm.cpp
SRCS += RobotomyRequestForm.cpp
SRCS += ShrubberyCreationForm.cpp
SRCS += Intern.cpp

# HEADERS #

HDS += Bureaucrat.hpp
HDS += AForm.hpp
HDS += PresidentialPardonForm.hpp
HDS += RobotomyRequestForm.hpp
HDS += ShrubberyCreationForm.hpp
HDS += Intern.hpp

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
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re