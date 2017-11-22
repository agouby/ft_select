# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouby <agouby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 02:38:12 by agouby            #+#    #+#              #
#    Updated: 2017/11/22 03:10:29 by agouby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_select

CC			= gcc
FLA			= -Wall -Werror -Wextra

LIB_NAME	= libft
LIB_PATH	= -L./libft -lftprintf
LIB_INC		= -I./libft/includes

INC			= -I./includes
SRCS_PATH	= ./srcs/
SRCS_FILES	= ft_select.c
SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@/usr/bin/make -C $(LIB_NAME)
	@$(CC) $(FLA) -o $(NAME) $(OBJS) $(LIB_PATH)

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
