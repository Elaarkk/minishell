/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:43:21 by acolonne          #+#    #+#             */
/*   Updated: 2025/03/25 19:38:24 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int SIGNAL = 0;

void	logo()
{
	printf("                            ___\n");
    printf("                          /~   ~\\\n");
    printf("                         |_      |\n");
    printf("                         |/     __-__\n");
    printf("                          \\   /~     ~~-_\n");
    printf("                           ~~ -~~\\       ~\\\n");
    printf("                            /     |        \\\n");
    printf("               ,           /     /          \\\n");
    printf("             //   _ _---~~~    //-_          \\\n");
    printf("           /  (/~~ )    _____/-__  ~-_       _-\\             _________\n");
    printf("         /  _-~\\\\0) ~~~~         ~~-_ \\__--~~   `\\  ___---~~~        /'\n");
    printf("        /_-~                       _-/'          )~/               /'\n");
    printf("        (___________/           _-~/'         _-~~/             _-~\n");
    printf("     _ ----- _~-_\\\\        _-~ /'      __--~   (_ ______---~~~--_\n");
    printf("  _-~         ~-_~\\\\      (   (     -_~          ~-_  |          ~-_\n");
    printf(" /~~~~\\          \\ \\~~       ~-_ ~-_    ~\\            ~~--__-----_    \\\n");
    printf(";    / \\ ______-----\\           ~-__~-~~~~~~--_             ~~--_ \\    .\n");
    printf("|   | \\((*)~~~~~~~~~~|      __--~~             ~-_               ) |   |\n");
    printf("|    \\  |~|~---------)__--~~                      \\_____________/ /    ,\n");
    printf(" \\    ~-----~    /  /~                             )  \\    ~-----~    /\n");
    printf("  ~-_         _-~ /_______________________________/    `-_         _-~\n");
    printf("     ~ ----- ~                                            ~ ----- ~  -MINISHELL\n");
}

int	main()
{
	char	    *content;
    t_prompt    *prompt;

	prompt = 0;
    content = 0;
	logo();
	while (1)
	{
		content = readline("$> ");
		if (content)
			add_history(content);
        prompt = cut_prompt(content);
        check_prompt(prompt);
		if (strncmp(content, "exit", 4) == 0)
        {
            rl_clear_history();
            exit_clean(0, prompt);
        }
        free_all(&prompt);
        free(content);
	}
	return (0);
}