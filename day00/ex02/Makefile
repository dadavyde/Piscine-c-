# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 18:11:47 by dadavyde          #+#    #+#              #
#    Updated: 2018/06/24 18:11:49 by dadavyde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLANG = clang++

C_FLAGS = -Wall -Wextra -Werror

SOURCES = tests.cpp Account.class.cpp 

HEADERS = Account.class.hpp

NAME = PhoneBook

all: $(NAME)

$(NAME): $(HEADERS) $(SOURCES)
	$(CLANG) $(C_FLAGS) $(SOURCES) -o $@

fclean:
	rm -f $(NAME)

re: fclean all
