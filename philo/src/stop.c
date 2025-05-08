/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:34:49 by tbrunier          #+#    #+#             */
/*   Updated: 2025/05/08 15:29:56 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_error_exit(char *error, bool usage)
{
	unsigned int	i;

	i = 0;
	while (error[i])
	{
		write(2, &error[i], 1);
		i++;
	}
	if (usage == 1)
	{
		write(2, "\nUSAGE: ./philo [+number_of_philosophers] [+time_to_die] \
			[+time_to_eat] [+time_to_sleep]\n", 92);
	}
	write(1, "\n", 1);
}

void	ft_thread_clean(t_data *data)
{
	int	i;

	i = -1;
	if (data->clean.threads_made)
		while (++i < data->clean.threads_made)
			pthread_join(data->philos[i].thread, NULL);
	if (data->clean.clean_monitor_thread)
		pthread_join(data->monitor_thread, NULL);
}

void	ft_mutex_clean(t_data *data)
{
	if (data->clean.clean_mutex_forks)
		while (0 < data->clean.forks_made--)
			pthread_mutex_destroy(&data->forks[data->clean.forks_made]);
	if (data->clean.clean_mutex_print)
		pthread_mutex_destroy(&data->mutex_print);
	if (data->clean.clean_mutex_stop)
		pthread_mutex_destroy(&data->mutex_stop);
}

void	ft_malloc_clean(t_data *data)
{
	if (data->clean.clean_malloc_forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
	if (data->clean.clean_malloc_philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}
