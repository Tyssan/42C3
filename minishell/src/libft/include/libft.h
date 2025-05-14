/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:06:46 by tbrunier          #+#    #+#             */
/*   Updated: 2024/12/03 15:31:20 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int						ft_isspace(int c);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					ft_putstr_fd(char *s, int fd);
char					**ft_split(char *str, char delimiter);
char					*ft_strndup(const char *s, size_t n);
char					*ft_strjoin(char const *s1, char const *s2);
int						ft_strlen(const char *c);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strdup(const char *s);

#endif
