/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:47:10 by tbrunier          #+#    #+#             */
/*   Updated: 2025/01/26 16:53:19 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_free(t_data *data, t_philo *philolist)
{
	unsigned int	i;

	if (philolist)
	{
		i = 0;
		while (i < data->lst_size)
		{
			pthread_mutex_destroy(&philolist[i].eat.mutex_eat);
			pthread_mutex_destroy(&philolist[i].mutex_fork);
			i++;
		}
		free(philolist);
		philolist == NULL;
	}
	if (data)
		pthread_mutex_destroy(&data->state.mutex_state);
}

void	ft_error_exit(char *error, bool usage)
{
	unsigned int	i;

	i = 0;
	while (error[i])
		i++;
	write(2, &error, i);
	if (usage == 1)
	{
		write(2, "\nUSAGE: ./philo [+number_of_philosophers] [+time_to_die] \
			[+time_to_eat] [+time_to_sleep]\n", 92);
	}
	write(1, "\n", 1);
}
