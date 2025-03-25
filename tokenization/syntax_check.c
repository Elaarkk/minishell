/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:33:02 by acolonne          #+#    #+#             */
/*   Updated: 2025/03/25 19:27:13 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int SIGNAL;

int	check_operand (t_prompt *prompt)
{
	t_prompt	*tmp;

	tmp = prompt;
	if ((tmp->token == HEREDOC || tmp->token == APPEND || tmp->token == INPUT
		|| tmp->token == OUTPUT || tmp->token == PIPE) && ((tmp->next == 0) ||(tmp->next->token != NORMAL)))
	{
		print_error("bash: syntax error near unexpected token\n");
		SIGNAL = 2;
		return (1);
	}
	return (0);
}

int	check_prompt (t_prompt *prompt)
{
	if (check_operand(prompt) == 0)
		printf("no syntax error\n");
	else
		return (1);
}