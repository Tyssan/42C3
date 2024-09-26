/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:23:46 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/25 18:05:19 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_free(t_data *data, t_philo *philolist)
{
	t_philo	*temp;
	int		lstsize;

	lstsize = ft_list_size(philolist);
	temp = philolist;
	while (lstsize > 0)
	{
		temp = philolist->next;
		pthread_mutex_destroy(&philolist->eat.mutex_eat);
		pthread_mutex_destroy(&philolist->mutex_fork);
		free(philolist);
		philolist == NULL;
		philolist == temp;
		lstsize--;
	}
	if (data)
		pthread_mutex_destroy(&data->state.mutex_state);
}

void	ft_args_error()
{
	write(1, "ERROR: invalid args input.\n", 27);
	write(1, "USAGE: ./philo [number_of_philosophers] [time_to_die] \
			[time_to_eat] [time_to_sleep]\n", 87);
}

int main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philolist;

	if (args_check(argc, argv) == 1)
	{
		if (!ft_data_init(&data, &philolist, argv))
			return(write(1, "ERROR: data init error.\n", 24), 1);
		if (!ft_philo_init(&data, philolist))
			return(write(1, "ERROR: philo init error.\n", 25), 1);
		ft_philosophers(&data, philolist);
		ft_free(&data, philolist);
	}
	else
		return (ft_args_error(), 1);
	return (0);
}
