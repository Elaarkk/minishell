/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:27:18 by acolonne          #+#    #+#             */
/*   Updated: 2025/03/25 19:06:33 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*token_operand(int token)
{
	char	*text;
	
	if (token == HEREDOC)
		text = "<<";
	if (token == APPEND)
		text = ">>";
	if (token == INPUT)
		text = "<";
	if (token == OUTPUT)
		text = ">";
	if (token == PIPE)
		text = "|";
	return (text);
}

char	*token_normal(char *content)
{
	int		i;
	int		j;
	char 	*text;

	i = 0;
	j = 0;
	text = 0;
	while (content && content[i] && content[i] != ' ' && content[i] != '\t' && content[i] != '<' 
			&& content[i] != '>' && content[i] != '|')
		i++;
	text = malloc(i + 1);
	while (j < i)
	{
		text[j] = content[j];
		j++;
	}
	text[j] = '\0';
	return (text);
}

int identify_token(char *prompt)
{
     if (ft_strncmp(prompt, "<<", 2) == 0)
        return (HEREDOC);
    if (ft_strncmp(prompt, ">>", 2) == 0)
        return (APPEND);
    if (ft_strncmp(prompt, "<", 1) == 0)
        return (INPUT);
    if (ft_strncmp(prompt, ">", 1) == 0)
        return (OUTPUT);
    if (ft_strncmp(prompt, "|", 1) == 0)
        return (PIPE);
    else
        return (NORMAL);
}

t_prompt	*cut_prompt(char *content)
{
    int         i;
    int         token;
	char		*text;
    t_prompt    *prompt;

    i = 0;
    prompt = 0;
    while (content && content[i])
    {
		i += skip_spaces(&content[i]);
        token = identify_token(&content[i]);
		if (token == NORMAL)
			text = token_normal(&content[i]);
		else
			text = token_operand(token);
        if (!prompt)
            prompt = create_prompt(text, token);
		else
			ft_lstadd_back(&prompt, create_prompt(text, token));
		i += ft_strlen(text);
    }
	return (prompt);
	
	// t_prompt *tmp;
	// tmp = prompt;
	
	// while (tmp)
	// {
	// 	if (tmp->text)
	// 		printf("%s\n", tmp->text);
	// 	tmp = tmp->next;
	// }
}