/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrunier <tbrunier@student.42perpignan.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:20:56 by tbrunier          #+#    #+#             */
/*   Updated: 2024/12/05 19:21:27 by tbrunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*create_token(char *value, t_token_type type)
{
	t_token	*result;

	result = malloc(sizeof(t_token));
	if (!result)
		return (NULL);
	result->value = value;
	result->type = type;
	result->next = NULL;
	return (result);
}

void	add_token(t_token **head, t_token **tail, t_token *new_token)
{
	if (!*head)
		*head = new_token;
	else
		(*tail)->next = new_token;
	*tail = new_token;
}

t_token	*ft_lexer(const char *input)
{
	t_token			*tokens;
	t_token			*tail;
	unsigned int	i;

	tokens = NULL;
	tail = NULL;
	i = 0;
	add_token(&tokens, &tail, create_token(NULL, TOKEN_EOF));
	return (tokens);
}
