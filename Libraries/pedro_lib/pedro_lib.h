/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pedro_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:39:42 by pgrellie          #+#    #+#             */
/*   Updated: 2023/11/24 16:23:44 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************/
/* E1 :     #ifndef MONFICHIER_H                     */
/*          # define MONFICHIER_H                    */
/*          INCLUDE THE NEEDED LIBRARIES             */
/*          #define BUFF_SIZE XXX                    */
/*                                                   */
/*****************************************************/
#ifndef PEDRO_LIB_H
# define PEDRO_LIB_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "get_next_line.h"
//# include <string.h>
//# include <strings.h>

/*****************************************************/
/* E2 :          STRUCT DECLARATIONS                 */
/*          typedef struct      Mastructure          */
/*          {                                        */
/*              void/int/char/etc...(*)NAME;         */
/*              ^^  ^^  ^^  ^^  ^^  ^^  ^^ ;         */
/*            //struct Mastructure  (*)next;         */
/*          } Mastructure;                           */
/*         (      SI           BESOIN      )         */
/*****************************************************/

// Linked_list struct

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

// Garbage collector

/*****************************************************/
/* E3 :           FUNCTION PROTOTYPE                 */
/*                                                   */
/*****************************************************/

int		ft_isascii(int x);
int		ft_isprint(int x);
int		ft_isalpha(int x);
int		ft_isdigit(char x);
int		ft_isalnum(int x);
int		ft_tolower(int x);
int		ft_toupper(int x);
int		ft_isspace(char x);
int		ft_issigns(char x);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	*ft_itoa(int nbr);

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *str, int chr, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int chr);
char	*ft_strrchr(const char *str, int chr);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strcat(char *dest, const char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strcpy(char *dest, const char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_equal(char const *s1, char const *s2);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
void	*ft_free_tab(char **strs);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	ft_putchar_fd(char x, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Bonus

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *blst);
t_list	*ft_lstlast(t_list *blst);
void	ft_lstadd_back(t_list **flst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif //Fin des gardes d'en-tete
