# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <agouby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 02:38:12 by agouby            #+#    #+#              #
#    Updated: 2017/11/25 23:04:59 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_select

CC			= gcc
FLA			= -g -fsanitize=address -Wall -Werror -Wextra

LIB_NAME	= libft
LIB_PATH	= -L./libft -lftprintf
LIB_INC		= -I./libft/includes

INC			= -I./includes
SRCS_PATH	= ./srcs/

SRCS_FILES	= main.c \
			  init.c \
			  restore.c \
			  infos.c \
			  list.c \
			  print.c \
			  exit.c \
			  utils.c \
			  inputs.c \
			  delete.c

SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@/usr/bin/make -C $(LIB_NAME)
	@$(CC) $(FLA) -o $(NAME) $(OBJS) $(LIB_PATH) -l termcap

%.o: %.c
	@$(CC) $(FLA) $(INC) $(LIB_INC) -c $< -o $@

clean:
	@/usr/bin/make clean -C $(LIB_NAME)
	@/bin/rm -f $(OBJS)

fclean: clean
	@/usr/bin/make fclean -C $(LIB_NAME)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
