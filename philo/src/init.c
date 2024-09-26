/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:33:16 by tbrunier          #+#    #+#             */
/*   Updated: 2024/09/25 17:39:38 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	ft_data_init(t_data *data, t_philo **philolist, char **args)
{
	data->lst_size = ft_atoi(args[1]);
	return (1);
}

bool	ft_philo_init(t_data *data, t_philo **philolist)
{
	
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