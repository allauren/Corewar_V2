# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:39:52 by gsmith            #+#    #+#              #
#    Updated: 2018/03/21 13:51:00 by gsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
COMP=clang
FLAG=-Wall -Wextra -Werror
SRCS=ft_printf.c ft_error.c ft_format.c convert_c.c convert_s.c \
	 convert_percent.c convert_p.c read_digits1.c read_digits2.c \
	 read_udigits1.c read_udigits2.c convert_d.c convert_u.c convert_o.c \
	 convert_x.c
OBJS=$(SRCS:.c=.o)
LIBFT_DIR=../libft/
LIBFT_LIB=../libft/libft.a
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
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_LIB) $(NAME)
	@ar rsc $(NAME) $(OBJS)

%.o: %.c
	@$(COMP) $(FLAG) -I $(LIBFT_DIR) -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean:
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all
