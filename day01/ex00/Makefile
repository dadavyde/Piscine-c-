# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 16:27:45 by dadavyde          #+#    #+#              #
#    Updated: 2018/10/03 16:27:48 by dadavyde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLANG = clang++

C_FLAGS = -Wall -Wextra -Werror

SOURCES = main.cpp Pony.cpp 

HEADERS = Pony.hpp

NAME = pony

all: $(NAME)

$(NAME): $(HEADERS) $(SOURCES)
	$(CLANG) $(C_FLAGS) $(SOURCES) -o $@

clean:

fclean:
	rm -f $(NAME)

re: fclean all
