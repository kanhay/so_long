/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:22:36 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/15 11:57:49 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_y(t_sl *l)
{
	char	*next;

	l->line = 0;
	next = get_next_line(l->fd);
	if (!next)
		ft_error("something is wrong with the file");
	while (next)
	{
		l->line++;
		free (next);
		next = get_next_line(l->fd);
	}
	free (next);
	if (l->line > 256)
		exit (1);
	close (l->fd);
	l->fd = open(l->av[1], O_RDONLY);
}

int	get_map(t_sl *l)
{
	char	*next;
	int		i;

	l->carte = malloc(sizeof(char *) * (l->line + 1));
	if (!l->carte)
		return (0);
	next = get_next_line(l->fd);
	l->col = 0;
	while (next[l->col] && next[l->col] != '\n')
			l->col++;
	if (l->col > 256)
		exit (1);
	i = 0;
	while (next)
	{
		l->carte[i] = next;
		next = get_next_line(l->fd);
		i++;
	}
	l->carte[i] = NULL;
	close (l->fd);
	l->fd = open(l->av[1], O_RDONLY);
	return (0);
}

void	check_map_shape(t_sl l)
{
	int		i;
	int		j;

	i = 1;
	l.line--;
	while (l.carte[i])
	{
		j = 0;
		while (l.carte[i][j] && l.carte[i][j] != '\n')
			j++;
		if (i == l.line && j == l.col && l.carte[i][l.col] == '\n')
			ft_error("La forme de la carte n'est pas rectangulaire");
		if (j != l.col)
			ft_error("La forme de la carte n'est pas rectangulaire");
		else
			i++;
	}
}

void	map_frame(t_sl l)
{
	int	i;

	i = 0;
	l.line--;
	while (i < l.col)
	{
		if (l.carte[0][i] != '1')
			ft_error("la 1ere line n'est pas identique");
		else if (l.carte[l.line][i] != '1')
			ft_error("la derniere line n'est pas identique");
		i++;
	}
	i = 1;
	l.col--;
	while (l.carte[i] && i < l.line)
	{
		if (l.carte[i][0] != '1')
			ft_error("les premiers char ne sont pas identique");
		if (l.carte[i][l.col] != '1')
			ft_error("les derniers char ne sont pas identique");
		i++;
	}
}

int	check_char_num(char c, t_sl *l)
{
	l->x = 0;
	l->i = 0;
	while (l->carte[l->i])
	{
		l->j = 0;
		while (l->carte[l->i][l->j])
		{
			if (l->carte[l->i][l->j] != 'C' && l->carte[l->i][l->j] != 'P'
				&& l->carte[l->i][l->j] != 'E' && l->carte[l->i][l->j] != '0'
				&& l->carte[l->i][l->j] != '1' && l->carte[l->i][l->j] != '\n')
				ft_error("there is a strange char");
			if (l->carte[l->i][l->j] == c)
				l->x++;
			l->j++;
		}
		l->i++;
	}
	if (c == 'C')
		l->c = l->x;
	if (l->x == 0)
		return (0);
	else if (l->x > 1)
		return (-1);
	return (1);
}
