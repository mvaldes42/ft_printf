/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:13:17 by mvaldes           #+#    #+#             */
/*   Updated: 2020/05/07 18:00:06 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_digit_len(long long n);
int		ft_find_index(const char *s1, const char *set);
int		ft_get_index(const char *s1, const char c);
int		ft_is_on_set(const char *set, int c);

int		ft_is_preci(char c);
int		ft_is_type(char p);
int		ft_is_nbr(char c);
int		ft_is_nbr_dgt(char c);

char	*ft_itoa(long long n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar(char c);
void	ft_putnbr_base(unsigned long nbr, char *base, int out_arg);
void	ft_putstr(char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_strremove(char *str, const char *to_remove);
void	ft_putstr(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

#endif
