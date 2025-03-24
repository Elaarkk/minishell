/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:43:21 by acolonne          #+#    #+#             */
/*   Updated: 2025/03/24 19:50:42 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

int	check_prompt(char *prompt)
{

	return (1);
}

int	main()
{
	char	*prompt;

	prompt = 0;
	logo();
	while (1)
	{
		prompt = readline("$> ");
		if (prompt)
			add_history(prompt);
		check_prompt(prompt);
		free(prompt);
	}
	return (0);
}