/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:50:09 by acolonne          #+#    #+#             */
/*   Updated: 2025/03/25 18:28:56 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	skip_spaces(char *content)
{
	int	i;

	i = 0;
	while (content && content[i] && (content[i] == ' ' || content[i] == '\t'))
		i++;
	return (i);
}

t_prompt	*create_prompt(char *content, int token)
{
	t_prompt	*prompt;

	prompt = 0;
	prompt = malloc(sizeof(t_prompt));
	if (!prompt)
		return (0);
	prompt->next = NULL;
	prompt->text = content;
	prompt->token = token;
	return (prompt);
}

void	ft_lstadd_back(t_prompt **lst, t_prompt *new)
{
	t_prompt	*p;

	p = *lst;
	if (!new)
		return ;
	if (*lst)
	{
		while (p->next)
			p = p->next;
		p->next = new;
		p = new;
	}
	else
		*lst = new;
	return ;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	i = 0;
	while ((s1_cpy[i] || s2_cpy[i]) && (i < n))
	{
		if (s1_cpy[i] > s2_cpy[i])
			return (1);
		if (s1_cpy[i] < s2_cpy[i])
			return (-1);
		i++;
	}
	return (0);
}