/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:16:33 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/15 12:09:07 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *msg)
{
	write(1, "error\n", 6);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	exit (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_memcmp(void *ptr1, void *ptr2, int s)
{
	char	*p1;
	char	*p2;

	p1 = (char *)ptr1;
	p2 = (char *)ptr2;
	if (s == 0)
		return (0);
	while (s > 1)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		s--;
	}
	return (*p1 - *p2);
}

char	*ft_strrchr(char *str, int c)
{
	int		l;

	if (str[0] == '\0' || str[0] == ' ')
		ft_error("no such file");
	l = ft_strlen(str);
	while (l >= 0)
	{
		if (str[l] == (char)c)
			return (&str[l]);
		l--;
	}
	ft_error ("wrong file");
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
