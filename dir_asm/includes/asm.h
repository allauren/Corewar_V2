/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:32:51 by tcassier          #+#    #+#             */
/*   Updated: 2018/03/25 16:49:49 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "limits.h"

# define IND_SIZE 2
# define REG_SIZE 4
# define DIR_SIZE REG_SIZE

# define MEM_SIZE (4*1024)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR ','

# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"

# define REG_NUMBER 16

# define T_REG 1
# define T_DIR 2
# define T_IND 4

# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define HEADER_LENGTH (PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
# define FILE_MAX_SIZE (HEADER_LENGTH + CHAMP_MAX_SIZE)
# define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct			s_lab_pos
{
	int					index;
	int					pc;
	int					size;
	struct s_lab_pos	*next;
}						t_lab_pos;

typedef struct			s_labs
{
	char				*name;
	int					define;
	int					index;
	t_lab_pos			*pos;
	struct s_labs		*next;
}						t_labs;

typedef struct			s_asm
{
	int					fd;
	char				*line;
	char				*file;
	int					size;
	int					pc;
	int					idx;
	int					error;
	t_labs				*labs;
}						t_asm;

typedef struct			s_op
{
	char				*name;
	int					nb_params;
	int					param_types[3];
	int					opcode;
	int					has_ocp;
	int					has_idx;
}						t_op;

extern t_op				g_op_tab[17];

void					asm_add_lab(t_asm *data, char *name);
void					asm_add_lab_pos(t_asm *data, char *tmp,
						int pc, int size);
void					asm_error_1(t_asm *data);
void					asm_error_2(t_asm *data);
void					asm_error_3(char *file);
void					asm_error_4(int fd, char *file, char *name_cor);
void					asm_error_5(t_asm *data, int check);
void					asm_error_6(t_asm *data);
void					asm_error_7(t_asm *data);
void					asm_error_8(t_asm *data);
void					asm_error_9(t_asm *data);
void					asm_error_10(t_asm *data, int check);
void					asm_error_11(t_asm *data);
void					asm_error_12(t_asm *data);
void					asm_get_comment(t_asm *data);
void					asm_get_name(t_asm *data);
void					asm_get_op(t_asm *data);
void					asm_lab_addback(t_labs *new, t_labs **labs);
void					asm_lab_addback(t_labs *new, t_labs **labs);
void					asm_lab_pos_addback(t_lab_pos *new, t_lab_pos **pos);
t_labs					*asm_lab_exists(t_labs *labs, char *name);
void					asm_labs_del(t_labs *labs);
void					asm_op_line(t_asm *data, char *tmp);
void					asm_op_process(t_asm *data, char *tmp);
int						asm_op_type_param(t_asm *data,
						int idx_param, char *tmp);
int						asm_process(int fd, char **file);
void					asm_put_hexa(char *str, unsigned int hexa, int size);
#endif
