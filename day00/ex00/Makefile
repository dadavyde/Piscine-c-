# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 12:03:48 by dadavyde          #+#    #+#              #
#    Updated: 2018/10/01 12:03:51 by dadavyde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLANG = clang++

CPP_FLAGS = -Wall -Wextra -Werror

SOURCES = megaphone.cpp

NAME = megaphone

all: $(NAME)

$(NAME): $(SOURCES)
	$(CLANG) $(CPP_FLAGS) $(SOURCES) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all
