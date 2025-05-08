/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:32:56 by tbrunier          #+#    #+#             */
/*   Updated: 2025/05/08 16:02:33 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_warn(void)
{
	printf("WARN: high amount of philosophers, program might break !\n\n");
	printf("Starting simulation in..\n");
	printf("3\n");
	usleep(1000000);
	printf("2\n");
	usleep(1000000);
	printf("1\n\n");
	usleep(1000000);
}

bool	ft_parser(char **args, t_data *data)
{
	struct timeval	tv;

	data->nb_philos = ft_atol(args[1]);
	if (data->nb_philos <= 0)
		return (ft_error_exit("| error cause: invalid 1st argument", 0), 0);
	data->ttdie = ft_atol(args[2]);
	if (data->ttdie == -1)
		return (ft_error_exit("| error cause: invalid 2nd argument", 0), 0);
	data->tteat = ft_atol(args[3]);
	if (data->tteat == -1)
		return (ft_error_exit("| error cause: invalid 3rd argument", 0), 0);
	data->ttsleep = ft_atol(args[4]);
	if (data->ttsleep == -1)
		return (ft_error_exit("| error cause: invalid 4th argument", 0), 0);
	data->food_goal = -2;
	if (args[5])
		data->food_goal = ft_atol(args[5]);
	if (args[5] && (data->food_goal == 0 || data->food_goal == -1))
		return (ft_error_exit("| error cause: invalid 5th argument", 0), 0);
	if (!args[5])
		data->food_goal = -1;
	if (gettimeofday(&tv, NULL) != 0)
		return (ft_error_exit("| error cause: gettimeofday failed", 0), 0);
	data->start_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (1);
}

bool	ft_init(t_data *data)
{
	ft_default_init(data);
	if (!ft_malloc_init(data))
		return (0);
	if (!ft_mutex_init(data))
		return (0);
	ft_philos_init(data);
	return (1);
}

void	ft_clean(t_data *data)
{
	ft_thread_clean(data);
	ft_mutex_clean(data);
	ft_malloc_clean(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	if (!ft_parser(argv, &data))
		return (1);
	if (data.nb_philos == 1)
		return (ft_pov_dev(&data), 0);
	if (data.nb_philos >= 200)
		ft_warn();
	if (!ft_init(&data))
	{
		ft_clean(&data);
		return (1);
	}
	ft_philosophers(&data);
	ft_clean(&data);
	return (0);
}
