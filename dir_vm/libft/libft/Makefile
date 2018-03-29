# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:39:52 by gsmith            #+#    #+#              #
#    Updated: 2018/03/21 13:51:33 by gsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
COMP=gcc
FLAG=-Wall -Wextra -Werror
SRCS=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	 ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	 ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	 ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	 ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	 ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	 ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	 ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	 ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
	 ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	 ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	 ft_lstmap.c ft_isspace.c ft_islower.c ft_isupper.c ft_strrev.c \
	 ft_lstaddend.c ft_pow.c ft_sqrt.c ft_fact.c ft_itoa_b.c ft_iswap.c \
	 ft_cswap.c ft_itowchar.c ft_perror.c ft_lsttail.c ft_lstlen.c ft_atol.c \
	 ft_trimint.c
OBJS=$(SRCS:.c=.o)
NC='\033[0m'
RED='\033[0;31m'
LRED='\033[1;31m'
LBLUE='\033[1;34m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(COMP) $(FLAG) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
