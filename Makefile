# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <agouby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 02:38:12 by agouby            #+#    #+#              #
#    Updated: 2018/01/03 19:47:10 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPIL_LIB	= n

NAME		= ft_select

CC			= gcc
FLA			= -Wall -Werror -Wextra

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
			  find.c \
			  delete.c \
			  signal.c \
			  fetch.c

SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
ifeq ($(COMPIL_LIB), y)
	@/usr/bin/make -C $(LIB_NAME)
endif
	@$(CC) $(FLA) -o $(NAME) $(OBJS) $(LIB_PATH) -l termcap

%.o: %.c
	@$(CC) $(FLA) $(INC) $(LIB_INC) -c $< -o $@

clean:
ifeq ($(COMPIL_LIB), y)
	@/usr/bin/make clean -C $(LIB_NAME)
endif
	@/bin/rm -f $(OBJS)

fclean: clean
ifeq ($(COMPIL_LIB), y)
	@/usr/bin/make fclean -C $(LIB_NAME)
endif
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
