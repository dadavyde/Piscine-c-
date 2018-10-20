# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 12:42:45 by dadavyde          #+#    #+#              #
#    Updated: 2018/10/01 12:42:46 by dadavyde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLANG = clang++

CPP_FLAGS = -Wall -Wextra -Werror

SOURCES = Contact.cpp PhoneBook.cpp main.cpp 

HEADERS = Contact.hpp PhoneBook.hpp

NAME = PhoneBook

all: $(NAME)

$(NAME): $(HEADERS) $(SOURCES)
	$(CLANG) $(CPP_FLAGS) $(SOURCES) -o $@

clean:

fclean:
	rm -f $(NAME)

re: fclean all
