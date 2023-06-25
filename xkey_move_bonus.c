/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xkey_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:31:51 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/13 18:00:16 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_exit(int x, int y, t_slb *l)
{
	if (l->carte[x][y] == 'C')
		l->c--;
	else if (l->carte[x][y] == 'E' && l->c != 0)
		return (1);
	else if (l->carte[x][y] == 'E' && l->c == 0)
	{
		write (1, ">> Well done! You have won the game <<\n", 40);
		exit (0);
	}
	else if (l->carte[x][y] == '3' ||
	(l->carte[x][y] == 'P' || l->carte[x][y] == 'L'))
	{
		write (1, ">> Game Over. Better luck next time! <<\n", 41);
		exit (0);
	}
	return (0);
}

void	key_move_rl(int keycode, t_slb *l)
{
	if ((keycode == 123 || keycode == 0) && l->carte[l->pl][l->pc - 1] != '1')
	{
		if (check_exit(l->pl, l->pc - 1, l) != 1)
		{
			l->carte[l->pl][l->pc - 1] = 'L';
			l->carte[l->pl][l->pc] = '0';
			l->pc -= 1;
			l->moves++;
		}
	}
	else if ((keycode == 124 || keycode == 2)
		&& l->carte[l->pl][l->pc + 1] != '1')
	{
		if (check_exit(l->pl, l->pc + 1, l) != 1)
		{
			l->carte[l->pl][l->pc + 1] = 'P';
			l->carte[l->pl][l->pc] = '0';
			l->pc += 1;
			l->moves++;
		}
	}
}

void	key_move_ud(int keycode, t_slb *l)
{
	if ((keycode == 125 || keycode == 1) && l->carte[l->pl + 1][l->pc] != '1')
	{
		if (check_exit(l->pl + 1, l->pc, l) != 1)
		{
			l->carte[l->pl + 1][l->pc] = 'P';
			l->carte[l->pl][l->pc] = '0';
			l->pl += 1;
			l->moves++;
		}
	}
	else if ((keycode == 126 || keycode == 13)
		&& l->carte[l->pl - 1][l->pc] != '1')
	{
		if (check_exit(l->pl - 1, l->pc, l) != 1)
		{
			l->carte[l->pl - 1][l->pc] = 'P';
			l->carte[l->pl][l->pc] = '0';
			l->pl -= 1;
			l->moves++;
		}
	}
}

void	player_pos(t_slb *l)
{
	int	i;
	int	j;

	i = 0;
	while (l->carte[i])
	{
		j = 0;
		while (l->carte[i][j])
		{
			if (l->carte[i][j] == 'P')
			{
				l->pl = i;
				l->pc = j;
			}
			j++;
		}
		i++;
	}
}

void	enemy_move(t_slb *l)
{
	l->i = 0;
	while (l->i < l->en)
	{
		l->x = l->p_enemy[l->i][0];
		l->y = l->p_enemy[l->i][1];
		if (l->carte[l->x][l->y + 1] == '0' && l->p_enemy[l->i][2] == 0)
		{
			l->carte[l->x][l->y + 1] = '3';
			l->carte[l->x][l->y] = '0';
			l->p_enemy[l->i][2] = 1;
		}
		else if (l->carte[l->x][l->y - 1] == '0' && l->p_enemy[l->i][2] == 1)
		{
			l->carte[l->x][l->y - 1] = '3';
			l->carte[l->x][l->y] = '0';
			l->p_enemy[l->i][2] = 0;
		}
		if (l->carte[l->x][l->y + 1] == 'P' || l->carte[l->x][l->y + 1] == 'L')
			check_exit(l->x, l->y + 1, l);
		if (l->carte[l->x][l->y - 1] == 'P' || l->carte[l->x][l->y - 1] == 'L')
			check_exit(l->x, l->y - 1, l);
		l->i++;
	}
}
