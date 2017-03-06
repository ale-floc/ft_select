/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 23:36:55 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/18 23:40:29 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list					*init_check_screen(int *nb_line)
{
	*nb_line = 0;
	get_select()->final = 0;
	get_select()->secu = 0;
	get_select()->size_long = 0;
	return (get_select()->begin);
}

void					init_list_term(t_select *env)
{
	env->fd = 1;
	env->size = 0;
	env->column = 0;
	env->line = 0;
	env->stock = 0;
	env->secu = 0;
}

void					init_screen_size(t_select *env, int access)
{
	struct winsize		w;

	ioctl(get_select()->fd, TIOCGWINSZ, &w);
	get_select()->column = w.ws_col;
	get_select()->line = w.ws_row;
	clear_term();
	if (access)
		check_screen(get_select());
}

void					init_term(t_select *env)
{
	struct termios		term;
	char				*str;

	if (tgetent(NULL, getenv("TERM")) < 1)
		ft_error("term error", 2);
	if ((get_select()->fd = open(ttyname(STDIN_FILENO), O_RDWR)) == -1)
		ft_error("tty error", 2);
	if (get_select()->fd == -1)
		ft_error("Error tty", 2);
	if (tcgetattr(get_select()->fd, &term) == -1)
		ft_error("term error", 2);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag |= ISIG;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tputs(tgetstr("vi", NULL), 0, my_std);
	if (tcsetattr(get_select()->fd, TCSADRAIN, &term) == -1)
		ft_error("Error", 2);
}

t_select				*get_select(void)
{
	static t_select		env;

	return (&env);
}
