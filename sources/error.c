/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:40:22 by acolonne          #+#    #+#             */
/*   Updated: 2025/03/25 19:13:29 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

void	free_list(t_prompt **lst)
{
	t_prompt *tmp;
	int		i;

	i = 0;
	if (!(*lst))
		return ;
	while (*lst)
	{
		i++;
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
}

void	free_content(t_prompt **lst)
{
	t_prompt	*tmp;
	
	tmp = *lst;
	while (tmp)
	{
		if (tmp->text && tmp->token == NORMAL)
			free(tmp->text);
		tmp = tmp->next;
	}
}

void	free_all(t_prompt **lst)
{
	free_content(lst);
	free_list(lst);
}

void	exit_clean(int code, t_prompt *prompt)
{
	free_content(&prompt);
	free_list(&prompt);
	exit(code);
}