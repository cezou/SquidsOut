/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cviegas <cviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:33:49 by cviegas           #+#    #+#             */
/*   Updated: 2024/02/02 19:02:26 by cviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRST_LIBFT_H
# define FIRST_LIBFT_H
# include <unistd.h>

// PREMIERE PARTIE
// easy
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);

// mem
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

// str
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);

// malloc
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);

// DEUXIEME PARTIE
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				**ft_split_charset(const char *str, char *charset);
char				*str_whitespaces(void);
void				free_s(char **s);

char				*ft_itoa(int n);

// fd
void				ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);

// BONUS
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

// split_charset utils
int					is_sep(const char c, char *charset);
int					lenbsep(const char *s, char *charset, int indice_s);
int					ft_nb_mots(const char *str, char *charset);
char				**if_str_null(const char *str);

// Linked list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif