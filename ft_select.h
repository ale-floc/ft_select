/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 17:35:21 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/19 00:25:41 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include "libft.h"
# define TOUCH_DOWN 	4348699
# define TOUCH_UP		4283163
# define TOUCH_SPACE 	32
# define TOUCH_ENTER	10
# define TOUCH_ECHAP	27
# define TOUCH_DELETE   127
# define TOUCH_CTRL_D	4

typedef struct		s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				select;
	int				focus;
	char			*str;
	int				size_str;
}					t_list;

typedef struct		s_select
{
	t_list			*begin;
	t_list			*end;
	int				fd;
	int				size;
	int				line;
	int				column;
	int				column_nb;
	int				stock;
	int				secu;
	int				final;
	int				size_long;
}					t_select;

void				ft_print_error(char *str, int fd);
void				init_list(char **argv, t_select *env);
t_list				*init_one_list(char *str, t_list *tmp);
t_list				*list_circulaire_init(t_list *list, t_select *env);
int					ft_listlen(t_list *list, t_list *temp);
t_list				*ft_listpush(char *str, t_list *list);
void				print_arg(t_select *env);
void				print_base(char *str);
void				print_surligne(char *str);
void				print_select(char *str);
void				print_select_surligne(char *str);
int					my_std(int c);
t_select			*get_select();
int					check_incrementation(int nb_line);
void				ft_signal();
t_list				*init_check_screen(int *nb_line);
void				init_screen_size(t_select *env, int access);
int					ft_size_str();
void				size_screen();
void				clear_term();
void				check_screen(t_select *env);
void				touch_key_echap();
int					sig_cont();
void				sig_stop();
void				init_list_term(t_select *env);
void				ft_error(char *str, int fd);
int					size_to_small(int size_long);
void				init_term(t_select *env);
void				touch_key_up(t_select *env);
void				touch_key_down(t_select *env);
void				touch_key_space(t_list *list);
t_list				*touch_key_delete(t_select *env);
t_list				*dlt_other_maillon(t_select *env);
t_list				*dlt_maillon(t_select *env);

#endif
