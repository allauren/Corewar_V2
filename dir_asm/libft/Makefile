# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 23:45:03 by tcassier          #+#    #+#              #
#    Updated: 2018/03/21 13:49:58 by gsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_PATH)

SRC_PATH = ./src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRC = ft_atoi.c                \
	  ft_atoi_sec.c            \
	  ft_bzero.c               \
	  ft_count_word.c          \
	  ft_getfile.c             \
	  ft_imaxtoa_base.c        \
	  ft_isalnum.c             \
	  ft_isalpha.c             \
	  ft_isascii.c             \
	  ft_isdigit.c             \
	  ft_is_in.c               \
	  ft_islower.c             \
	  ft_isneg.c               \
	  ft_isprint.c             \
	  ft_isspace.c             \
	  ft_isupper.c             \
	  ft_itoa.c                \
	  ft_itoa_dst.c            \
	  ft_itoa_base.c           \
	  ft_lflen.c               \
	  ft_lfstrlen.c            \
	  ft_lftoa.c               \
	  ft_lstadd.c              \
	  ft_lstadd_back.c         \
	  ft_lstdel.c              \
	  ft_lstdelone.c           \
	  ft_lstiter.c             \
	  ft_lstmap.c              \
	  ft_lstnew.c              \
	  ft_lstsize.c             \
	  ft_memalloc.c            \
	  ft_memccpy.c             \
	  ft_memchr.c              \
	  ft_memcmp.c              \
	  ft_memcpy.c              \
	  ft_memdel.c              \
	  ft_memdel_bis.c          \
	  ft_memdup.c              \
	  ft_memjoin.c             \
	  ft_memjoin_free.c        \
	  ft_memmove.c             \
	  ft_memoverlap.c          \
	  ft_memset.c              \
	  ft_memset_sec.c          \
	  ft_nbrlen_base.c         \
	  ft_nbrlen_imax_base.c    \
	  ft_nbrlen_uimax_base.c   \
	  ft_perror.c              \
	  ft_pr_apply.c            \
	  ft_pr_convert.c          \
	  ft_pr_flag.c             \
	  ft_pr_process.c          \
	  ft_printf.c              \
	  ft_putchar.c             \
	  ft_putchar_fd.c          \
	  ft_putendl.c             \
	  ft_putendl_fd.c          \
	  ft_putnbr.c              \
	  ft_putnbr_fd.c           \
	  ft_putstr.c              \
	  ft_putstr_fd.c           \
	  ft_spacejump.c           \
	  ft_sqrt.c                \
	  ft_strappend.c           \
	  ft_strappend_sec.c       \
	  ft_strcat.c              \
	  ft_strchr.c              \
	  ft_strclr.c              \
	  ft_strcmp.c              \
	  ft_strcpy.c              \
	  ft_strdel.c              \
	  ft_strdup.c              \
	  ft_strequ.c              \
	  ft_strinsert.c           \
	  ft_striter.c             \
	  ft_striteri.c            \
	  ft_strjoin.c             \
	  ft_strlcat.c             \
	  ft_strlen.c              \
	  ft_strmap.c              \
	  ft_strmapi.c             \
	  ft_strnappend_s1.c       \
	  ft_strnappend_s2.c       \
	  ft_strncat.c             \
	  ft_strncmp.c             \
	  ft_strncpy.c             \
	  ft_strndup.c             \
	  ft_strndup_free.c        \
	  ft_strnequ.c             \
	  ft_strnew.c              \
	  ft_strnjoin_s1.c         \
	  ft_strnjoin_s2.c         \
	  ft_strnncat.c            \
	  ft_strnncpy.c            \
	  ft_strnstr.c             \
	  ft_strrchr.c             \
	  ft_strsplit.c            \
	  ft_strstr.c              \
	  ft_strsub.c              \
	  ft_strtolower.c          \
	  ft_strtoupper.c          \
	  ft_strtrim.c             \
	  ft_tolower.c             \
	  ft_toupper.c             \
	  ft_uimaxtoa_base.c       \
	  ft_wchar_byte.c          \
	  ft_wstrlen.c             \
	  get_next_line.c          \
	  gnl_free.c

OBJ_PATH = ./obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_PATH = ./includes/
INCS = $(addprefix $(INC_PATH), $(INC))
INC = libft.h

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
