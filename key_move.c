/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:31:51 by khanhayf          #+#    #+#             */
/*   Updated: 2023/06/14 11:35:33 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(int x, int y, t_sl *l)
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
	return (0);
}

void	write_moves(int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write (1, &c, 1);
	}
	else
	{
		write_moves(n / 10);
		write_moves(n % 10);
	}
}

void	key_move_rl(int keycode, t_sl *l)
{
	if ((keycode == 123 || keycode == 0) && l->carte[l->pl][l->pc - 1] != '1')
	{
		if (check_exit(l->pl, l->pc - 1, l) != 1)
		{
			l->carte[l->pl][l->pc - 1] = 'L';
			l->carte[l->pl][l->pc] = '0';
			l->pc -= 1;
			l->moves++;
			write_moves(l->moves);
			write (1, "\n", 1);
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
			write_moves(l->moves);
			write (1, "\n", 1);
		}
	}
}

void	key_move_ud(int keycode, t_sl *l)
{
	if ((keycode == 125 || keycode == 1) && l->carte[l->pl + 1][l->pc] != '1')
	{
		if (check_exit(l->pl + 1, l->pc, l) != 1)
		{
			l->carte[l->pl + 1][l->pc] = 'P';
			l->carte[l->pl][l->pc] = '0';
			l->pl += 1;
			l->moves++;
			write_moves(l->moves);
			write (1, "\n", 1);
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
			write_moves(l->moves);
			write (1, "\n", 1);
		}
	}
}

void	player_pos(t_sl *l)
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
