# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:39:52 by gsmith            #+#    #+#              #
#    Updated: 2018/03/21 13:47:37 by gsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
COMP=clang
FLAG=-Wall -Wextra -Werror
SRCS=$(GNL_DIR)get_next_line.c
OBJS=$(SRCS:.c=.o)
GNL_DIR=get_next_line/
PRINTF_DIR=ft_printf/
PRINTF_LIB=ft_printf/libftprintf.a
LIBFT_DIR=libft/
ERASE_LINE='\r\033[K'
NC='\033[0m'
RED='\033[0;31m'
LRED='\033[1;31m'
LBLUE='\033[1;34m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(PRINTF_DIR)
	@cp $(PRINTF_LIB) $(NAME)
	@ar rsc $(NAME) $(OBJS)

%.o: %.c
	@$(COMP) $(FLAG) -I $(GNL_DIR) -I $(LIBFT_DIR) -o $@ -c $<

clean:
	@make -C $(PRINTF_DIR) clean
	@rm -f $(OBJS)

fclean:
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all
