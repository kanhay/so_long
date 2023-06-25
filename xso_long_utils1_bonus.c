/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xso_long_utils1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:52:05 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/10 21:47:58 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mouse(void)
{
	write (1, ">> Game session ended || you quit the game <<\n", 47);
	exit (0);
}

char	*ft_itoa(int n)
{	
	int		l;
	char	*s;
	long	nb;

	nb = n;
	l = 0;
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (s == NULL)
		return (NULL);
	s[l] = '\0';
	if (nb == 0)
		s[0] = '0';
	while (nb > 0 && l-- > 0)
	{
		s[l] = (nb % 10) + 48;
		nb /= 10;
	}
	return (s);
}

void	check_map(char *s, t_slb *l)
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
			else if (s[i] == '3')
				ft_error("La carte ne contient aucun ennemie");
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

void	enemy_pos(t_slb *l)
{
	int	m;

	l->i = 0;
	m = 0;
	while (l->carte[l->i])
	{
		l->j = 0;
		while (l->carte[l->i][l->j])
		{
			if (l->carte[l->i][l->j] == '3' && m < l->en)
			{
				l->p_enemy[m][0] = l->i;
				l->p_enemy[m][1] = l->j;
				m++;
			}
			l->j++;
		}
		l->i++;
	}
}

void	drawing(t_slb *l, void *p)
{
	enemy_pos(l);
	enemy_move(l);
	push_donuts(l, p);
	mlx_clear_window(l->mlx, l->win);
	push_images(l);
}
