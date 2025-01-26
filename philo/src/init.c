/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:33:16 by tbrunier          #+#    #+#             */
/*   Updated: 2025/01/26 15:20:42 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	ft_data_init(t_data *data, char **args)
{
	struct timeval	tv;

	data->lst_size = ft_atol(args[1]);//uses custom atol to check arg, returns value if input correct
	if (data->lst_size == -1)//atol fails if value exceeds INT_MAX, if negative, and if incorrect nbr
		return (ft_error_exit("| error cause: argv[1]", 1), 0);//if -1, it means ft_atol detected an input error
	data->ttdie = ft_atol(args[2]);
	if (data->ttdie == -1)
		return (ft_error_exit("| error cause: argv[2]", 1), 0);
	data->tteat = ft_atol(args[3]);
	if (data->tteat == -1)
		return (ft_error_exit("| error cause: argv[3]", 1), 0);
	data->ttsleep = ft_atol(args[4]);
	if (data->ttsleep == -1)
		return (ft_error_exit("| error cause: argv[4]", 1), 0);
	data->food_goal = -2;
	if (args[5])
		data->food_goal = ft_atol(args[5]);
	if (args[5] && (data->food_goal == 0 || data->food_goal == -1))
		return (ft_error_exit("| error cause: argv[5]", 1), 0);
	if (!args[5])
		data->food_goal = -1;
	if (gettimeofday(&tv, NULL) != 0)
		return (ft_error_exit("| error cause: gettimeofday failed", 0), 0);
	data->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (1);
}

bool	ft_clear_philolist(t_philo *philolist, unsigned int count)
{
	unsigned int	i;

	if (!philolist)
		return (0);
	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&(philolist[i].mutex_fork));
		pthread_mutex_destroy(&(philolist[i].eat.mutex_eat));
		i++;
	}
	free(philolist);
	return (0);
}

bool	ft_philo_init(t_data *data, t_philo **philolist)
{
	unsigned int	i;
	t_philo			*current;

	*philolist = malloc(sizeof(t_philo) * data->lst_size);
	if (!*philolist)
		return (ft_error_exit("ERROR: malloc failed", 0), 0);
	current = *philolist;
	i = 0;
	while (i < data->lst_size)
	{
		current[i].philo_id = i + 1;
		current[i].alive = 1;
		current[i].data = data;
		current[i].eat.lastmeal = data->start_time;
		if (pthread_mutex_init(&(current[i].mutex_fork), NULL) != 0)
			return (ft_error_exit("ERROR: mutex init failed (fork)", 0), ft_clear(*philolist, i));
		if (pthread_mutex_init(&(current[i].eat.mutex_eat), NULL) != 0)
			return (ft_error_exit("ERROR: mutex init failed (eat)", 0), ft_clear(*philolist, i));
		if (i == data->lst_size - 1)
			current[i].next = *philolist;//last points to first (circle table)
		else
			current[i].next = &current[i + 1];
		i++;
	}
	return (1);
}

/*
typedef struct s_data
{
	int				lst_size;
	int				ttdie;
	int				ttsleep;
	int				tteat;
	t_state			state;
}					t_data;

typedef struct s_philo
{
	int				philo_id;
	int				alive;
	pthread_t		thread;
	pthread_mutex_t	mutex_fork;
	t_eat			eat;
	t_data			*data;
	struct s_philo	*next;
}					t_philo;*/