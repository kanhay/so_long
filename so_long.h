/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:25:42 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/13 17:51:56 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE    10
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_solong{
	int		i;
	int		j;
	int		x;
	int		y;
	int		fd;
	char	**av;
	char	**carte;
	char	**map;
	int		c;
	int		line;
	int		col;
	int		pl;
	int		pc;
	void	*mlx;
	void	*win;
	void	*tree;
	void	*bears_r;
	void	*bears_l;
	void	*door;
	void	*road;
	void	*donuts;
	int		moves;
}	t_sl;

int		ft_error(char *msg);
int		ft_memcmp(void *ptr1, void *ptr2, int s);
char	*ft_strrchr(char *str, int c);
void	get_y(t_sl *l);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		get_map(t_sl *l);
void	check_map_shape(t_sl l);
void	map_frame(t_sl l);
int		check_char_num(char c, t_sl *l);
void	player_pos(t_sl *l);
void	file_to_img(t_sl *l);
int		push_images(t_sl *l);
void	move(t_sl *l);
void	key_move_rl(int keycode, t_sl *l);
void	key_move_ud(int keycode, t_sl *l);
int		mouse(void);

#endif