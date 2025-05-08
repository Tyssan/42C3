/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:33:33 by tbrunier          #+#    #+#             */
/*   Updated: 2025/05/08 15:31:42 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	ft_args_check(char *arg)
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
	if (!(arg[i] >= '0' && arg[i] <= '9'))
		return (ft_error_exit("ERROR: given arg is not an integer", 1), 0);
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		j++;
		if (j > 10)
			return (ft_error_exit("ERROR: given arg value is too big", 1), 0);
		i++;
	}
	return (1);
}

long	ft_atol(char *n)
{
	unsigned int	i;
	long			nb;

	if (!ft_args_check(n))
		return (-1);
	i = 0;
	nb = 0;
	while ((n[i] >= 9 && n[i] <= 13) || (n[i] == 32))
		i++;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			return (ft_error_exit("ERROR: value cannot be negative", 1), -1);
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

long	ft_timestamp(long start)
{
	struct timeval	tv;
	long			now;

	gettimeofday(&tv, NULL);
	now = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (now - start);
}

void	ft_usleep(long duration, t_data *data)
{
	long	start;

	start = ft_timestamp(data->start_time);
	while (!data->simulation_stop && (
			ft_timestamp(data->start_time) - start) < duration)
		usleep(100);
}

void	ft_philoprint(t_philo *philo, char *str)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->mutex_print);
	if (!philo->data->simulation_stop)
	{
		timestamp = ft_timestamp(philo->data->start_time);
		printf("%ld %d %s\n", timestamp, philo->id, str);
	}
	pthread_mutex_unlock(&philo->data->mutex_print);
}
