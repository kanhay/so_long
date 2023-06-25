/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:25:42 by khanhayf          #+#    #+#             */
/*   Updated: 2023/04/13 17:53:18 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*enemy;
	void	*a;
	void	*b;
	void	*cc;
	void	*d;
	void	*e;
	void	*f;
	void	*p;
	int		moves;
	void	*bar;
	int		**p_enemy;
	int		en;
}	t_slb;

int		ft_error(char *msg);
int		ft_memcmp(void *ptr1, void *ptr2, int s);
char	*ft_strrchr(char *str, int c);
void	get_y(t_slb *l);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		get_map(t_slb *l);
void	check_map_shape(t_slb l);
void	map_frame(t_slb l);
int		check_char_num(char c, t_slb *l);
void	player_pos(t_slb *l);
void	file_to_img(t_slb *l);
int		push_images(t_slb *l);
void	move(t_slb *l);
void	key_move_rl(int keycode, t_slb *l);
void	key_move_ud(int keycode, t_slb *l);
int		donut_to_img(t_slb *l);
int		mouse(void);
void	file2img(t_slb *l);
char	*ft_itoa(int n);
void	enemy_move(t_slb *l);
void	enemy_pos(t_slb *l);
void	enemies_tab(t_slb *l);
void	check_map(char *s, t_slb *l);
void	drawing(t_slb *l, void *p);
int		push_donuts(t_slb *l, void *str);
#endif