/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:51:44 by mbari             #+#    #+#             */
/*   Updated: 2021/06/02 17:02:58 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void				*ft_memset(void *ptr, int x, size_t len);
void				ft_bzero(void *ptr, size_t l);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
int					ft_intsize(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
long long			ft_atoi(const char *str);
long long			my_atoi(const char *str);
int					ft_isalnum(int a);
int					ft_isalpha(int c);
int					ft_isascii(int asci);
int					ft_isdigit(int d);
int					ft_isprint(int p);
char				*ft_strchr(const char *str, int c);
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *str, int c);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strrchr(const char *s, int r);
int					ft_tolower(int c);
int					ft_toupper(int i);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strcmp(char *s1, char *s2);
char				**my_split(char *str);
#endif
