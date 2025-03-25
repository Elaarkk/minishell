/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:32:33 by acolonne          #+#    #+#             */
/*   Updated: 2025/03/25 19:13:40 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h> 
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <sys/time.h>
# include <readline/readline.h>
# include <readline/history.h>

# define HEREDOC 0
# define APPEND 1
# define INPUT 2
# define OUTPUT 3
# define PIPE 4
# define NORMAL 5

typedef	struct	s_prompt
{
	char			*text;
	int				token;
	struct s_prompt	*next;
}				t_prompt;

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*token_operand(int token);

char		*token_normal(char *content);

t_prompt	*create_prompt(char *content, int token);

void		ft_lstadd_back(t_prompt **lst, t_prompt *new);

t_prompt	*cut_prompt(char *content);

size_t		ft_strlen(const char *s);

int			skip_spaces(char *content);

void		print_error(char *s);

void		exit_clean(int code, t_prompt *prompt);

int			check_prompt (t_prompt *prompt);

void		free_all(t_prompt **lst);

#endif