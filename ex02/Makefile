# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 15:22:43 by jkovacev          #+#    #+#              #
#    Updated: 2026/02/05 22:00:50 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp

OBJDIR = objects
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

DEPS = Account.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(DEPS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re