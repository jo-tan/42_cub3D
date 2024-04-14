/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aauthier <aauthier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:23:54 by jo-tan            #+#    #+#             */
/*   Updated: 2024/02/07 20:48:11 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_node
{
	char			*content;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	struct s_node	*head;
}	t_list;

/*libft*/
int		ft_isspace(int c);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t i);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/*double-linked list*/
t_list	*ft_dlst_init(void);
int		ft_dlst_lstsize(t_list *list);
void	ft_dlst_addlast(t_list *list, char *line);
void	ft_dlst_deleteone(t_node *node);
t_node	*ft_dlst_tolastone(t_list *list);
void	ft_dlst_freelst(t_list *list);
void	ft_dlst_printlst(t_list *list);
/*Get Next Line*/
char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);

#endif
