/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:47:10 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/04 20:37:29 by tbrunier         ###   ########.fr       */
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

void	ft_error_exit(char *error)
{
	unsigned int	i;
	static bool		print_usage = 0;//allows USAGE writing only once

	i = 0;
	while (error[i])
		i++;
	write(2, &error, i);
	if (print_usage == 0)
	{
		write(2, "\nUSAGE: ./philo [+number_of_philosophers] [+time_to_die] \
			[+time_to_eat] [+time_to_sleep]\n", 92);
		print_usage = 1;
	}
	write(1, "\n", 1);
}
