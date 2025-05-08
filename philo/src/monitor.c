/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:40:39 by tbrunier          #+#    #+#             */
/*   Updated: 2025/05/08 15:33:31 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	ft_monitor_famine(int i, t_data *data)
{
	if ((ft_timestamp(data->start_time)
			- data->philos[i].last_meal) > data->ttdie)
	{
		ft_philoprint(&data->philos[i], "died");
		pthread_mutex_lock(&data->mutex_stop);
		data->simulation_stop = 1;
		pthread_mutex_unlock(&data->mutex_stop);
		return (1);
	}
	return (0);
}

bool	ft_monitor_goal(t_data *data)
{
	int	i;
	int	total_finished;

	total_finished = 0;
	i = -1;
	while (++i < data->nb_philos)
	{
		if (data->philos[i].meal_count >= data->food_goal)
			total_finished++;
	}
	if (total_finished == data->nb_philos)
	{
		pthread_mutex_lock(&data->mutex_stop);
		data->simulation_stop = 1;
		pthread_mutex_unlock(&data->mutex_stop);
		return (1);
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = -1;
		while (++i < data->nb_philos && !data->simulation_stop)
		{
			if (ft_monitor_famine(i, data))
				return (NULL);
		}
		if (data->food_goal > 0)
			if (ft_monitor_goal(data))
				return (NULL);
		usleep(1000);
	}
	return (NULL);
}
