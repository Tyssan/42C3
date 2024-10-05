/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:23:46 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/04 21:09:40 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philolist;

	if (argc != 5 && argc != 6)//arg count check
		return(write(2, "ERROR: 4 or 5 inputs needed\n", 28), 1);
	if (!ft_data_init(&data, &philolist, argv))//if function fails to init data, ends program.
		return (1);
	ft_philo_init(&data, philolist);
	ft_philosophers(&data, philolist);
	ft_free(&data, philolist);
	return (0);
}
