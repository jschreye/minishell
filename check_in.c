/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:22:41 by grubin            #+#    #+#             */
/*   Updated: 2022/06/24 15:17:37 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_file_in(char *file_name, t_fd *files)
{
	if (files->fd_in != -1)
		close(files->fd_in);
	files->fd_in = open(file_name, O_RDONLY);
	if (files->fd_in == -1)
	{
		printf("$ %s: no such file or directory\n", file_name);
		return (0);
	}
	if (files->heredocs == 1)
	{
		ft_free_tab(files->tab_in);
		files->heredocs = 0;
	}
	return (1);
}

char	**cpy_tab_heredocs(char **tab, int nb_lines, char *input)
{
	char	**copied_tab;
	int		j;

	j = 0;
	copied_tab = malloc(sizeof(char *) * (nb_lines + 1));
	while (tab[j])
	{
		copied_tab[j] = copy_new_line(tab[j]);
		j++;
	}
	if (input)
	{
		copied_tab[j] = copy_new_line(input);
		copied_tab[j + 1] = 0;
	}
	else
		copied_tab[j] = 0;
	return (copied_tab);
}

int	ft_check_input(t_her *her, t_fd *files)
{
	her->input = readline("> ");
	if (!her->input)
	{
		files->value = 1;
		return (0);
	}
	if (her->input[0] == '\0')
	{
		free(her->input);
		her->input = ft_strdup(" \0");
	}
	return (0);
}

int	ft_creat_tab_in(t_fd *files, int freed, t_her *her)
{
	if (freed == 1)
	{
		files->tab_in = malloc(sizeof(char *) * 2);
		files->tab_in[0] = copy_new_line(her->input);
		free(her->input);
		files->tab_in[1] = 0;
		freed = 0;
	}
	else
	{
		her->tmp = cpy_tab_heredocs(files->tab_in, her->nb_lines, her->input);
		ft_free_tab(files->tab_in);
		free(her->input);
		files->tab_in = cpy_tab_heredocs(her->tmp, her->nb_lines, NULL);
		ft_free_tab(her->tmp);
	}
	return (freed);
}

int	check_heredoc(char *key_word, t_fd *files)
{
	t_her		her;
	static int	freed;

	her.nb_lines = 1;
	freed = 1;
	if (files->heredocs == 1)
		ft_free_tab(files->tab_in);
	ft_check_input(&her, files);
	if (!her.input)
		return (0);
	while ((ft_strcmp(her.input, key_word) != 0))
	{
		freed = ft_creat_tab_in(files, freed, &her);
		ft_check_input(&her, files);
		if (!her.input)
			return (0);
		her.nb_lines++;
	}
	free(her.input);
	freed = 1;
	files->heredocs = 1;
	return (0);
}
