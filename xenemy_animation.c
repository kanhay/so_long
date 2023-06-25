/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:43:00 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/10 21:41:49 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_pos(t_slb *l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (l->carte[i])
	{
		while (l->carte[i][j])
		{
			if (l->carte[i][j] == '3')
			{
				l->p_enemy[k][0] = i;
				l->p_enemy[k][1] = j;
				l->p_enemy[k][2] = '\0';
				k++;
			}
			j++;
		}
		i++;
	}
	l->p_enemy[k] = 0;
}
