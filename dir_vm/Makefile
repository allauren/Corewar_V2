# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:39:52 by gsmith            #+#    #+#              #
#    Updated: 2018/03/25 18:06:22 by allauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re dclean

NAME = corewar
CC = clang
LIBFT = ft
LIBFT_NAME = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/
HEADER_PATH = includes
OBJS_PATH = objs
SRCS_PATH = srcs
DPDS_PATH = depend
INCL = -I $(HEADER_PATH) -I $(LIBFT_DIR)
CFLAGS = -Wall -Wextra -Werror $(INCL)
SRCS = $(addprefix $(SRCS_PATH)/,  \
		main.c                     \
		parser_options_functions.c \
		parse_options.c            \
		ft_atoi_base.c             \
		ft_print_memory.c          \
		map_init.c                 \
		map_utils.c                \
		parse_utils.c              \
		parser_fill_map.c          \
		parser_pointer_functions.c \
		process_init.c             \
		cycles.c                   \
		process.c                  \
		op.c                       \
		op_1.c                     \
		op_2.c                     \
		op_3.c                     \
		op_4.c                     \
		op_utils.c                 \
		op_arg.c)
OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
DPDS = $(SRCS:$(SRCS_PATH)/%.c=$(DPDS_PATH)/%.d)
ERASE_LINE = '\r\033[K'
NC = '\033[0m'
RED = '\033[0;31m'
LRED = '\033[1;31m'
LBLUE = '\033[1;34m'
GREEN = '\033[0;32m'
LGREEN = '\033[1;32m'
ORANGE = '\033[0;33m'
YELLOW = '\033[1;33m'

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(CC)  $(CFLAGS) -o $(NAME) $(OBJS) -L./$(LIBFT_DIR) -l$(LIBFT)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(OBJS_PATH)/%.o:
	$(CC) $(CFLAGS) -o $@ -c $(@:$(OBJS_PATH)/%.o=$(SRCS_PATH)/%.c)

$(DPDS_PATH)/%.d: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -MM $^ | sed -e '1s/^/$(OBJS_PATH)\//' > $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

dclean:
	rm -f $(DPDS)

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS)
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

-include $(DPDS)
