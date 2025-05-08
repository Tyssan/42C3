/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:14:17 by tbrunier          #+#    #+#             */
/*   Updated: 2025/05/08 15:29:56 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_cantina(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->left_fork);
	ft_philoprint(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	ft_philoprint(philo, "has taken a fork");
	ft_philoprint(philo, "is eating");
	philo->last_meal = ft_timestamp(data->start_time);
	philo->meal_count++;
	ft_usleep(data->tteat, data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&data->mutex_stop);
		if (data->simulation_stop)
		{
			pthread_mutex_unlock(&data->mutex_stop);
			break ;
		}
		pthread_mutex_unlock(&data->mutex_stop);
		ft_cantina(philo, data);
		if (data->food_goal != -1 && philo->meal_count >= data->food_goal)
			break ;
		ft_philoprint(philo, "is sleeping");
		ft_usleep(data->ttsleep, data);
		ft_philoprint(philo, "is thinking");
	}
	return (NULL);
}

void	ft_philosophers(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->nb_philos)
	{
		philo = &data->philos[i];
		if (pthread_create(&philo->thread, NULL, ft_routine, philo) != 0)
		{
			ft_error_exit("thread creation error", 0);
			if (i > 0)
				data->clean.clean_threads = 1;
			return ;
		}
		data->clean.threads_made++;
	}
	data->clean.clean_threads = 1;
	if (pthread_create(&data->monitor_thread, NULL, ft_monitor, data) != 0)
		ft_error_exit("monitor thread creation error", 0);
	data->clean.clean_monitor_thread = 1;
}

void	ft_pov_dev(t_data *data)
{
	data->simulation_stop = 0;
	printf("0 1 has taken a fork\n");
	ft_usleep(data->ttdie, data);
	printf("%d 1 died\n", data->ttdie);
}
