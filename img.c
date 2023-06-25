/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:05:16 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/13 14:47:06 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_img(t_sl *l)
{
	int	w;
	int	h;

	l->tree = mlx_xpm_file_to_image(l->mlx, "textures/tree.XPM", &w, &h);
	if (!l->tree)
		exit (1);
	l->bears_r = mlx_xpm_file_to_image(l->mlx, "textures/bear_r.XPM", &w, &h);
	if (!l->bears_r)
		exit (1);
	l->bears_l = mlx_xpm_file_to_image(l->mlx, "textures/bear_l.XPM", &w, &h);
	if (!l->bears_l)
		exit (1);
	l->door = mlx_xpm_file_to_image(l->mlx, "textures/door.XPM", &w, &h);
	if (!l->door)
		exit (1);
	l->road = mlx_xpm_file_to_image(l->mlx, "textures/road.XPM", &w, &h);
	if (!l->road)
		exit (1);
	l->donuts = mlx_xpm_file_to_image(l->mlx, "textures/donut.XPM", &w, &h);
	if (!l->donuts)
		exit (1);
}

void	push_img(char c, t_sl *l)
{
	if (c == '1')
		mlx_put_image_to_window(l->mlx, l->win, l->tree, l->y, l->x);
	else if (c == 'C')
		mlx_put_image_to_window(l->mlx, l->win, l->donuts, l->y, l->x);
	else if (c == '0')
		mlx_put_image_to_window(l->mlx, l->win, l->road, l->y, l->x);
	else if (c == 'P')
		mlx_put_image_to_window(l->mlx, l->win, l->bears_r, l->y, l->x);
	else if (c == 'L')
		mlx_put_image_to_window(l->mlx, l->win, l->bears_l, l->y, l->x);
	else if (c == 'E')
		mlx_put_image_to_window(l->mlx, l->win, l->door, l->y, l->x);
}

int	push_images(t_sl *l)
{
	int	i;
	int	j;

	i = 0;
	while (l->carte[i])
	{
		j = 0;
		while (l->carte[i][j])
		{
			l->x = i * 64;
			l->y = j * 64;
			push_img (l->carte[i][j], l);
			j++;
		}
		i++;
	}
	return (0);
}

int	key_move(int keycode, t_sl *l)
{
	if (keycode == 123 || keycode == 0 || keycode == 124 || keycode == 2)
		key_move_rl(keycode, l);
	else if (keycode == 125 || keycode == 1 || keycode == 126 || keycode == 13)
		key_move_ud(keycode, l);
	else if (keycode == 53)
		exit (0);
	mlx_clear_window(l->mlx, l->win);
	push_images(l);
	return (0);
}

void	move(t_sl *l)
{
	mlx_key_hook(l->win, key_move, l);
	mlx_hook(l->win, 17, 0, mouse, l);
}
