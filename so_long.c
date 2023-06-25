/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:49:19 by khanhayf          #+#    #+#             */
/*   Updated: 2023/06/13 11:47:11 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char *s, t_sl *l)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (check_char_num(s[i], l) == 0)
		{
			if (s[i] == 'C')
				ft_error("La carte ne contient aucun item");
			else if (s[i] == 'P')
				ft_error("La carte ne contient aucune  position de départ");
			else if (s[i] == 'E')
				ft_error("La carte ne contient aucune sortie");
		}
		else if (check_char_num(s[i], l) == -1)
		{
			if (s[i] == 'P')
				ft_error("La carte doit contenir 1 seule position de départ");
			else if (s[i] == 'E')
				ft_error("La carte doit contenir 1 seule sortie");
		}
		i++;
	}
}

void	check_path(t_sl *l, int pl, int pc)
{
	if (pl < 1 || pc < 1 || pl >= l->line || pc >= l->col
		|| (l->map[pl][pc] == 'p') || (l->map[pl][pc] == '1')
		|| (l->map[pl][pc] == 'E'))
		return ;
	l->map[pl][pc] = 'p';
	check_path(l, pl + 1, pc);
	check_path(l, pl - 1, pc);
	check_path(l, pl, pc + 1);
	check_path(l, pl, pc - 1);
}

void	check_ce(t_sl l)
{
	int	c;
	int	e;

	c = 0;
	e = 0;
	l.i = 0;
	while (l.map[l.i])
	{
		l.j = 0;
		while (l.map[l.i][l.j])
		{
			if (l.map[l.i][l.j] == 'C')
				c++;
			else if (l.map[l.i][l.j] == 'E')
			{
				if ((l.map[l.i][l.j + 1] == 'p') || (l.map[l.i][l.j - 1] == 'p')
				|| (l.map[l.i + 1][l.j] == 'p') || (l.map[l.i - 1][l.j] == 'p'))
					e++;
			}
			l.j++;
		}
		l.i++;
	}
	if (c > 0 || e == 0)
		ft_error("invalid path");
}

void	parsing_call(t_sl	*l)
{
	int		i;
	char	*next;

	get_y(l);
	get_map(l);
	check_map_shape(*l);
	map_frame(*l);
	check_map("CPE", l);
	i = 0;
	player_pos(l);
	i = 0;
	l->map = malloc(sizeof(char *) * (l->line + 1));
	next = get_next_line(l->fd);
	while (next)
	{
		l->map[i] = next;
		next = get_next_line(l->fd);
		i++;
	}
	l->map[i] = NULL;
	check_path(l, l->pl, l->pc);
	check_ce(*l);
}

int	main(int ac, char **argv)
{
	t_sl	l;

	if (ac != 2)
		ft_error("the number of arguments is not 2");
	if (ft_memcmp((ft_strrchr(argv[1], '.')), ".ber", 5))
		ft_error("the extension is not valid");
	l.fd = open(argv[1], O_RDONLY);
	if (l.fd < 0)
		ft_error("error openning file");
	l.av = argv;
	parsing_call(&l);
	l.mlx = mlx_init();
	if (!l.mlx)
		exit(1);
	l.win = mlx_new_window(l.mlx, l.col * 64, l.line * 64, "so_long");
	if (!l.win)
		exit(1);
	file_to_img(&l);
	push_images(&l);
	l.moves = 0;
	move(&l);
	mlx_loop(l.mlx);
	return (0);
}
