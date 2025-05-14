/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:18:58 by tbrunier          #+#    #+#             */
/*   Updated: 2024/12/05 17:21:04 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_main_parsing(t_data *data)
{
	t_token	*tokens;

	if (!data->input || *(data->input) == '\0')
		return ;
	tokens = ft_lexer(data->input);
	if (!tokens)
	{
		data->exit_status = -2;
		return ;
	}
	ft_handle_commands(tokens, data);
	ft_free_tokens(tokens);
}
