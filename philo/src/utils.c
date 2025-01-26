/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:16:52 by tbrunier          #+#    #+#             */
/*   Updated: 2025/01/26 16:53:06 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static bool	ft_args_check(char *arg)
{
	unsigned int	i;
	unsigned int	j;

	if (!arg || !arg[0])
		return (ft_error_exit("ERROR: NULL arg given", 1), 0);
	i = 0;
	j = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || (arg[i] == 32))
		i++;
	if (arg[i] == '+')
		i++;
	if (!(arg[i] >= '0' && arg[i] <= 9))
		return (ft_error_exit("ERROR: given arg is not an integer", 1), 0);
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		j++;
		if (j > 10)
			return (ft_error_exit("ERROR: given arg value exceeds INT_MAX", 1), 0);
		i++;
	}
	return (1);
}

long	ft_atol(char *n)
{
	unsigned int	i;
	long			nb;

	if (!ft_args_check(n))//checks if given value can be processed by atol
		return (-1);
	i = 0;
	nb = 0;
	while ((n[i] >= 9 && n[i] <= 13) || (n[i] == 32))
		i++;
	if (n[i] == '+' || n[i] == '-')//skip '+' and returns error if '-', value cant be < 0
	{
		if (n[i] == '-')
			return (ft_error_exit("ERROR: given arg value cant be negative", 1), -1);
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		nb = nb * 10 + n[i] - '0';
		i++;
	}
	if (nb > INT_MAX)
		return (ft_error_exit("ERROR: given arg value exceeds INT_MAX", 1), -1);
	return (nb);
}
