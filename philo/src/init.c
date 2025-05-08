/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:43:13 by tbrunier          #+#    #+#             */
/*   Updated: 2025/05/08 15:29:56 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_default_init(t_data *data)
{
	data->simulation_stop = 0;
	data->forks = NULL;
	data->philos = NULL;
	data->clean.clean_mutex_forks = 0;
	data->clean.clean_mutex_philos = 0;
	data->clean.clean_mutex_print = 0;
	data->clean.clean_mutex_stop = 0;
	data->clean.clean_malloc_forks = 0;
	data->clean.clean_malloc_philos = 0;
	data->clean.clean_threads = 0;
	data->clean.clean_monitor_thread = 0;
	data->clean.forks_made = -1;
	data->clean.threads_made = 0;
}

bool	ft_malloc_init(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (ft_error_exit("malloc failed: forks", 0), 0);
	data->clean.clean_malloc_forks = 1;
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		return (ft_error_exit("malloc failed: philos", 0), 0);
	data->clean.clean_malloc_philos = 1;
	return (1);
}

bool	ft_mutex_init(t_data *data)
{
	if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
		return (ft_error_exit("print mutex init failed", 0), 0);
	data->clean.clean_mutex_print = 1;
	if (pthread_mutex_init(&data->mutex_stop, NULL) != 0)
		return (ft_error_exit("stop mutex init failed", 0), 0);
	data->clean.clean_mutex_stop = 1;
	while (++data->clean.forks_made < data->nb_philos)
		if (pthread_mutex_init(&data->forks[data->clean.forks_made], NULL) != 0)
			return (ft_error_exit("fork mutex init failed", 0), 0);
	data->clean.clean_mutex_forks = 1;
	return (1);
}

void	ft_philos_init(t_data *data)
{
	int		i;
	long	start_time;

	i = 0;
	start_time = data->start_time;
	while (i < data->nb_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meal_count = 0;
		data->philos[i].last_meal = start_time;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philos];
		data->philos[i].data = data;
		i++;
	}
	data->clean.clean_mutex_philos = 1;
}
