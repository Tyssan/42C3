/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:02:56 by tbrunier          #+#    #+#             */
/*   Updated: 2024/10/03 19:36:30 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_print_arg(void *arg)
{
	char	*str;

	str = (char *)arg;
	printf("Thread %s starting\n", str);
	sleep(5);
	printf("Thread %s finished\n\n", str);
	return NULL;
}

int	main(int ac, char **av)
{ 
	pthread_t	newthread[ac - 1];
	int			i;

	i = 0;
	printf("Process started..\n");
	while (i < (ac - 1))`
	{
		pthread_create(&newthread[i], NULL, ft_print_arg, av[i + 1]);
		i++;
	}
	i = 0;
	sleep(1);
	printf("Threads created, waiting..\n");
	while (i < (ac - 1))
	{
		pthread_join(newthread[i], NULL);
		i++;
	}
	printf("Process ended..\n");
	return (0);
}
