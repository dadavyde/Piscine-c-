# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 14:43:45 by rnovodra          #+#    #+#              #
#    Updated: 2018/10/01 14:43:46 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	-s

NAME		=	ft_retro

SRC_DIR 	= sources/

SRCS		=	main.cpp		\
				GameZone.cpp	\
				GameEntity.cpp	\
				Player.cpp		\
				Bullet.cpp		\
				Enemy.cpp		\
				Stars.cpp		\
				EnemyElite.cpp	\
				EnemyBoss.cpp	\

INC			=	GameZone.hpp	\
				GameEntity.hpp	\
				Player.hpp		\
				Bullet.hpp		\
				Enemy.hpp		\
				Stars.hpp		\
				EnemyElite.hpp	\
				EnemyBoss.hpp	\

OBJ_FILES = $(SRCS:.cpp=.o)

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

HEADER_DIR = includes/

INCLUDES = -I includes

HEADER = $(addprefix $(HEADER_DIR), $(INC))

CXX			=	clang++

RM			=	rm -rf

FLAGS		=	-Wall -Werror -Wextra

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CXX) $(OBJ) -o $@ $(INCLUDES) -lcurses
	@echo ${BG}"[ ✓ ] $@"

$(OBJ_DIR):   
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER)
	$(CXX) $(FLAGS) -c $< -o $@ $(INCLUDES)
	@echo ${BG}"[ ✓ ] $@"


clean:
	$(RM) $(OBJ_DIR)
	@echo ${BR}"[ ✗ ] $(OBJS)"

fclean: clean
	$(RM) $(NAME)
	@echo ${BR}"[ ✗ ] $(NAME)"

re: fclean all

.PHONY: all fclean clean re
