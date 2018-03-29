/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:49:35 by allauren          #+#    #+#             */
/*   Updated: 2018/03/25 17:59:41 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# define HEX "0123456789abcdef"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft_adv.h"
# include "vm.h"

# define TOO_LONG "Invalid size of champ"

typedef struct			s_chmp
{
	int					fd;
	t_bool				param;
	unsigned int		num_player;
	t_header			head;
}						t_chmp;

typedef struct			s_memory
{
	t_uc				memory[MEM_SIZE];
	char				memoryp[MEM_SIZE * 4];
	char				magic[9];
	char				size[17];
	t_chmp				chp[4];
	int					nb_champ;
	t_chmp				*last_live;
}						t_memory;

typedef struct			s_options
{
	int		visu;
	int		param;
	int		sp;
	int		d;
	int		s;
}						t_options;

typedef struct			s_param
{
	t_chmp			nchamp[4];
	int				fd[4];
	int				ret;
	unsigned int	dmp;
	int				nb_champ;
	t_uc			buf[SIZE_CHAMP + 1];
	int				test;
	int				param;
	int				dump;
	int				periodic;
	t_options		opt;
}						t_param;

typedef struct			s_atoi
{
	long	i;
	long	jack;
	int		neg;
	int		j;
	int		fin;
}						t_atoi;

/*
** Utils to display
*/
void					ft_fill_memory(t_uc *me,
		t_uc *b, int strt, int stop);
int						ft_atoi_base(const char *l, int base);
void					print_memory(const void *addr, size_t size);
/*
** Parsing functions
*/
void					ft_parse_options(int argc,
		char **argv, t_param *p, t_memory *m);
void					ft_set_fd(char *str, t_param *p, t_options *s);
void					ft_set_option(char *str, t_param *p, t_options *s);
void					ft_set_optionparam(char *str, t_param *p, t_options *s);
void					ft_error(char *str, t_param *p, t_options *s);
void					ft_set_memory(t_memory *m, t_param *p);
void					ft_isactive(int i, int *j, int value);
void					corewar_usage(void);
/*
** options functions
*/
void					ft_select_player(char *str, t_param *p, t_options *s);
void					ft_select_dump(char *str, t_param *p, t_options *s);
void					ft_select_periodic(char *str, t_param *p, t_options *s);
int						ft_ispresentchamp(t_param *p, unsigned int value);
/*
** map init functions
*/
void					ft_isolatebuf(t_uc *buf, t_uc *cpy, int start, int end);
void					ft_check_magic(t_memory *m, t_param *p, int i);
void					ft_check_prog_size(t_memory *m, t_param *p, int i);

#endif
