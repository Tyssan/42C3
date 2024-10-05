/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:05:32 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/04 20:24:24 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
/*printf, ...*/
# include <unistd.h>
/*write, ...*/
# include <stdlib.h>
/*malloc, free, ...*/
# include <pthread.h>
/*pthread, mutex*/
# include <sys/time.h>
/*gettimeofday*/
# include <limits.h>
/*INT_MIN, INT_MAX*/
# include <stdbool.h>
/*bool variable*/

typedef struct s_eat
{
	pthread_mutex_t	mutex_eat;
	long			lastmeal;
}					t_eat;

typedef struct s_state
{
	pthread_mutex_t	mutex_state;
	int				state;
}					t_state;

typedef struct s_data
{
	long			lst_size;
	long			ttdie;
	long			ttsleep;
	long			tteat;
	long			food_goal;
	t_state			state;
}					t_data;

typedef struct s_philo
{
	long			philo_id;
	int				alive;
	pthread_t		thread;
	pthread_mutex_t	mutex_fork;
	t_eat			eat;
	t_data			*data;
	struct s_philo	*next;
}					t_philo;

/*init.c*/
bool			ft_philo_init(t_data *data, t_philo **philolist);
bool			ft_data_init(t_data *data, t_philo **philolist, char **args);

/*stop.c*/
void			ft_free(t_data *data, t_philo *philolist);
void			ft_error_exit(char *error);

/*utils.c*/
long			ft_atol(char *n);
int				ft_list_size(t_philo *list);

#endif
