/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:13:09 by raguillo          #+#    #+#             */
/*   Updated: 2019/04/03 19:28:19 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 600
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct		s_tetro
{
	char			*map;
	struct s_tetro	*next;
}					t_tetro;

typedef struct		s_var
{
	int		len;
	int		diff;
	int		j;
	int		k;
	int		count;
	int		lim;
}					t_var;

/*
** Validité du fichier
*/

char				*read_file(int fd);

int					count_maps(char *buff);

int					checking(char *buff);

int					check_blocs(char *buff);

int					check_maps(char *buff);

int					check_maps_next(char *buff, int *i, int *x, int *y);

int					split_maps(char *buff);

int					check_tetro(char *buff);

void				check_tetro_next(char **tab, int x, int y, int *count);

/*
** Stockage des maps
*/

char				*split_and_move(char *buff, int start);

void				lstadd_tetro(t_tetro **alst, t_tetro *new);

t_tetro				*lstnew_tetro(char *buff, int len);

t_tetro				*create_tetro(char *buff);

void				free_lst(t_tetro *t);

void				tetrodel(t_tetro **alst);

void				tetrodelone(t_tetro **alst);

/*
** Fonctions du backtracking
*/

void				tetro_shift(char *piece, size_t n);

void				tetro_shift_left(char *piece);

void				tetro_shift_top(char *piece);

char				*grow_and_solve(t_tetro *t);

int					can_place(char *map, char *tab, int i);

int					can_place_2(char *map, char *tab, int *i, t_var *var);

int					can_place_sup(char *map, char *tab, int i);

int					can_place_sup_2(char *map, char *tab, int *i, t_var *var);

void				place(char *map, char *tab, char c, int i);

void				place_sup(char *map, char *tab, char c, int i);

void				delete_block(char *map, char *tab, char c, int i);

void				delete_block_sup(char *map, char *tab, char c, int i);

int					backtracking(t_tetro *t, char c, char *tab);

/*
** Création du tableau
*/

char				*create_final_tab(int *count);

char				*delete_nl(char *map);

size_t				tab_len(char *tab);

void				print_tab(char *tab, size_t len);

/*
** Test
*/

void				ft_print_put_map_in_str(char *map);

void				ft_print_create_tetro(t_tetro *t);
#endif
