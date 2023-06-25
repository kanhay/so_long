/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xso_long_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:49:19 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/13 18:06:54 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_path(t_slb *l, int pl, int pc)
{
	if (pl < 1 || pc < 1 || pl >= l->line || pc >= l->col
		|| (l->map[pl][pc] == 'p') || (l->map[pl][pc] == '1')
		|| (l->map[pl][pc] == 'E') || (l->map[pl][pc] == '3'))
		return ;
	l->map[pl][pc] = 'p';
	check_path(l, pl + 1, pc);
	check_path(l, pl - 1, pc);
	check_path(l, pl, pc + 1);
	check_path(l, pl, pc - 1);
}

void	check_ce(t_slb l)
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

void	parsing_call(t_slb	*l)
{
	int		i;
	char	*next;

	get_y(l);
	get_map(l);
	check_map_shape(*l);
	map_frame(*l);
	check_map("CPE3", l);
	player_pos(l);
	i = 0;
	l->map = malloc(sizeof(char *) * l->line + 1);
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

void	mlx_fun(t_slb *l)
{
	l->mlx = mlx_init();
	if (!l->mlx)
		exit(1);
	l->win = mlx_new_window(l->mlx, l->col * 64, l->line * 64, "so_long");
	if (!l->win)
		exit(1);
	file_to_img(l);
	file2img(l);
	enemies_tab(l);
}

int	main(int ac, char **argv)
{
	t_slb	l;

	if (ac != 2)
		ft_error("the number of arguments is not 2");
	if (ft_memcmp((ft_strrchr(argv[1], '.')), ".ber", 5))
		ft_error("the extension is not valid");
	l.fd = open(argv[1], O_RDONLY);
	if (l.fd < 0)
		ft_error("error openning file");
	l.av = argv;
	parsing_call(&l);
	mlx_fun(&l);
	l.moves = 0;
	push_images(&l);
	move(&l);
	mlx_loop_hook(l.mlx, donut_to_img, &l);
	mlx_loop(l.mlx);
	return (0);
}
