/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xanimation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:29:24 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/11 13:05:03 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_num(t_slb *l)
{
	l->en = 0;
	l->i = 0;
	while (l->carte[l->i])
	{
		l->j = 0;
		while (l->carte[l->i][l->j])
		{
			if (l->carte[l->i][l->j] == '3')
				l->en++;
			l->j++;
		}
		l->i++;
	}
}

void	enemies_tab(t_slb *l)
{
	enemy_num(l);
	l->p_enemy = malloc(sizeof(int *) * l->en + 1);
	if (!l->p_enemy)
		return ;
	l->i = 0;
	while (l->i < l->en)
	{
		l->p_enemy[l->i] = malloc(sizeof(int) * 3);
		if (!l->p_enemy[l->i])
			return ;
		l->p_enemy[l->i][2] = 0;
		l->i++;
	}
	l->p_enemy[l->en] = NULL;
}

int	push_donuts(t_slb *l, void *str)
{
	int	i;
	int	j;

	l->p = str;
	i = 0;
	while (l->carte[i])
	{
		j = 0;
		while (l->carte[i][j])
		{
			if (l->carte[i][j] == 'C')
				mlx_put_image_to_window(l->mlx, l->win, str, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

void	file2img(t_slb *l)
{
	int	w;
	int	h;

	l->a = mlx_xpm_file_to_image(l->mlx, "textures/a.XPM", &w, &h);
	if (!l->a)
		exit (1);
	l->b = mlx_xpm_file_to_image(l->mlx, "textures/b.XPM", &w, &h);
	if (!l->b)
		exit (1);
	l->cc = mlx_xpm_file_to_image(l->mlx, "textures/c.XPM", &w, &h);
	if (!l->c)
		exit (1);
	l->d = mlx_xpm_file_to_image(l->mlx, "textures/d.XPM", &w, &h);
	if (!l->d)
		exit (1);
	l->e = mlx_xpm_file_to_image(l->mlx, "textures/e.XPM", &w, &h);
	if (!l->e)
		exit (1);
	l->f = mlx_xpm_file_to_image(l->mlx, "textures/f.XPM", &w, &h);
	if (!l->f)
		exit (1);
	l->bar = mlx_xpm_file_to_image(l->mlx, "textures/bar.xpm", &w, &h);
	if (!l->bar)
		exit (1);
	l->p = l->a;
}

int	donut_to_img(t_slb *l)
{
	static int	n;

	if (n == 0)
		push_donuts(l, l->b);
	else if (n == 1000)
		push_donuts(l, l->cc);
	else if (n == 2500)
		push_donuts(l, l->d);
	else if (n == 4000)
		push_donuts(l, l->e);
	else if (n == 5500)
		push_donuts(l, l->f);
	else if (n == 7000)
		push_donuts(l, l->e);
	else if (n == 8500)
		push_donuts(l, l->d);
	else if (n == 10000)
		push_donuts(l, l->cc);
	else if (n == 11500)
	{
		drawing(l, l->b);
		n = -1;
	}
	n++;
	return (0);
}
