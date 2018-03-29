/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 20:02:47 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/27 11:58:40 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFF_SIZE 4096
# define CONV "sSpbdDioOuUxXcCfF"
# define FLAG "1234567890#-+ .lhjz*"

enum { HASH, PLUS, MINUS, SPACE, ZERO, WIDTH, PREC, PREFIX };

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_print
{
	char			*format;
	char			conv;
	size_t			size;
	size_t			last;
	size_t			idx;
	size_t			len;
	int				error;
	int				option[8];
}					t_print;

int					ft_atoi(const char *str);
int					ft_atoi_sec(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_count_word(const char *s, int c);
t_list				*ft_getfile(char *file);
char				*ft_imaxtoa_base(intmax_t n, int base);
int					ft_dprintf(const int fd, const char *format, ...);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_is_in(const char *s, int c);
int					ft_islower(int c);
int					ft_isneg(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
int					ft_itoa_dst(char *dst, intmax_t n);
char				*ft_itoa_base(int n, int base);
size_t				ft_lflen(double n);
int					ft_lfstrlen(char *str);
char				*ft_lftoa(double n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list *alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_lstsize(t_list *begin_list);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				ft_memdel_bis(void *ap, size_t n);
void				*ft_memdup(const void *s, size_t n);
void				*ft_memjoin(void *s1, size_t len1, void *s2, size_t len2);
void				*ft_memjoin_free(void *s1, size_t len1, void *s2,
					size_t len2);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memoverlap(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t n);
void				*ft_memset_sec(void *b, int c, size_t n);
int					ft_nbrlen_base(int n, int base);
int					ft_nbrlen_imax_base(intmax_t n, int base);
int					ft_nbrlen_uimax_base(uintmax_t n, int base);
void				ft_perror(const char *s);
void				*ft_pr_apply(void *ret, t_print *data, t_list *chunk);
void				*ft_pr_convert(t_print *data, t_list *chunk, va_list ap);
void				ft_pr_flag(t_print *data, t_list *chunk, va_list ap);
void				ft_pr_getsize(t_print *data, t_list *chunk);
void				ft_pr_process(t_list *lst, t_print *data, va_list ap);
void				ft_pr_unicode(char str[5], int byte, wchar_t c);
int					ft_printf(const char *format, ...);
int					ft_putchar(char c);
int					ft_putchar_fd(char c, int fd);
int					ft_putendl(char const *s);
int					ft_putendl_fd(char const *s, int fd);
char				*ft_strinsert(char **ad, char **str, size_t where, char c);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char const *s);
int					ft_putstr_fd(char const *s, int fd);
char				*ft_spacejump(char *str);
int					ft_sprintf(char **str, const char *format, ...);
int					ft_sqrt(int n);
char				*ft_strappend(char **s1, char **s2, char c);
char				*ft_strappend_sec(char **s1, char **s2, char c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnappend_s1(char **s1, char **s2, int n, char c);
char				*ft_strnappend_s2(char **s1, char **s2, int n, char c);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strndup_free(char **s1, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnjoin_s1(char const *s1, char const *s2, int n);
char				*ft_strnjoin_s2(char const *s1, char const *s2, int n);
char				*ft_strnncat(char *s1, const char *s2, size_t n);
char				*ft_strnncpy(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strtolower(char *str);
void				ft_strtoupper(char *str);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_uimaxtoa_base(uintmax_t n, int base);
int					ft_wchar_byte(wchar_t c);
size_t				ft_wstrlen(wchar_t *wstr);
int					get_next_line(const int fd, char **line);
int					gnl_free(char **line, t_list **begin_list, int check);
#endif
