/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:16:52 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/25 17:56:08 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_atoi(char *n)
{
	int	parity;
	int	i;
	int	nb;

	parity = 1;
	i = 0;
	nb = 0;
	while ((n[i] >= 9 && n[i] <= 13) || (n[i] == 32))
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			parity = -1;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		nb = nb * 10 + n[i] - '0';
		i++;
	}
	return (nb * parity);
}

int	ft_list_size(t_philo *list)
{
	int	i;

	if (!list)
		return (0);
	if (!list->next)
		return (1);
	i = 0;
	while (list->next)
	{
		i++;
		list = list->next;
	}
	return (i + 1);
}
