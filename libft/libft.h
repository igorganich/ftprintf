/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:43:45 by iganich           #+#    #+#             */
/*   Updated: 2018/04/01 03:12:52 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	char			*secondstr;
	struct s_list	*next;
}					t_list;

void				ft_putnwstr(const wchar_t *str, size_t len);
int					ft_max_of_two(int a, int b);
void				ft_putnstr_fd(char const *str, size_t str_len, int fd);
int					freenode(t_list **first, t_list *node);
int					ft_atoi(const char *str);
void				ft_bzero(void *memory, size_t size);
char				*ft_itoa(int n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *str, int d, size_t s);
int					ft_memcmp(const void *str1, const void *str2, size_t s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int d, size_t n);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
int					ft_strdel(char **as);
void				ft_strclr(char *s);
size_t				ft_strlen(const char *s);
char				*ft_strcat(char *destptr, const char *srcptr);
char				*ft_strncat(char *destptr, const char *srcptr, size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(t_list *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *destptr, const void *srcptr, size_t num);
char				*ft_strchr(const char *string, int symbol);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncpy(char *destination, const char *source,
					size_t num);
char				*ft_strnstr(char *big, const char *little, size_t len);
char				*ft_strrchr(const char *str, int character);
char				*ft_strstr(char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void
					*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *,
					size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *
					(*f)(t_list *elem));
void				ft_strclr(char *s);

#endif
