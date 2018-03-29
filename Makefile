# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 23:19:18 by tcassier          #+#    #+#              #
#    Updated: 2018/03/25 20:47:10 by tcassier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean all re fclean

NAME_1 = corewar
NAME_2 = asm

PATH_1 = ./dir_vm/
SRCS_1_PATH = $(PATH_1)srcs/
SRCS_1 = $(addprefix $(SRCS_1_PATH), \
		 main.c                      \
		 parser_options_functions.c  \
		 parse_options.c             \
		 ft_atoi_base.c              \
		 ft_print_memory.c           \
		 map_init.c                  \
		 map_utils.c                 \
		 parse_utils.c               \
		 parser_fill_map.c           \
		 parser_pointer_functions.c  \
		 process_init.c              \
		 cycles.c                    \
		 process.c                   \
		 op.c                        \
		 op_1.c                      \
		 op_2.c                      \
		 op_3.c                      \
		 op_4.c                      \
		 op_utils.c                  \
		 op_arg.c)

PATH_2 = ./dir_asm/
SRCS_2_PATH = $(PATH_2)src/
SRCS_2 = $(addprefix $(SRCS_2_PATH), \
		 asm.c                       \
		 asm_add_lab.c               \
		 asm_add_lab_pos.c           \
		 asm_error.c                 \
		 asm_error_bis.c             \
		 asm_error_ter.c             \
		 asm_get_comment.c           \
		 asm_get_name.c              \
		 asm_get_op.c                \
		 asm_labs_tools.c            \
		 asm_op.c                    \
		 asm_op_line.c               \
		 asm_op_process.c            \
		 asm_op_type_param.c         \
		 asm_process.c               \
		 asm_put_hexa.c)

INC_1_PATH = $(PATH_1)includes/
INC_2_PATH = $(PATH_2)includes/
INCS_1 = $(addprefix $(INC_1_PATH), \
		cycles.h                    \
		memory.h                    \
		op.h                        \
		op_utils.h                  \
		process.h                   \
		vm.h)
INCS_2 = $(addprefix $(INC_2_PATH), asm.h)

NC = '\033[0m'
LBLUE = '\033[1;34m'
LGREEN = '\033[1;32m'

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(SRCS_1) $(INCS_1)
	@printf $(LBLUE)"Compiling Corewar\n"$(NC)
	@make -C $(PATH_1) all
	mv $(PATH_1)$(NAME_1) ./
	@printf $(LGREEN)"Corewar Ready\n"$(NC)

$(NAME_2): $(SRCS_2) $(INCS_2)
	@printf $(LBLUE)"Compiling Asm\n"$(NC)
	@make -C $(PATH_2) all
	mv $(PATH_2)$(NAME_2) ./
	@printf $(LGREEN)"Asm Ready\n"$(NC)

clean:
	@make -C $(PATH_1) clean
	@make -C $(PATH_2) clean

fclean:
	@make -C $(PATH_1) fclean
	@make -C $(PATH_2) fclean
	rm -f $(NAME_1)
	rm -f $(NAME_2)

re: fclean all
