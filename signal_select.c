/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 22:57:00 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/18 23:01:10 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_signal(void)
{
	signal(SIGINT, touch_key_echap);
	signal(SIGTSTP, (void *)sig_stop);
	signal(SIGCONT, (void *)sig_cont);
	signal(SIGWINCH, (void *)size_screen);
	signal(SIGKILL, touch_key_echap);
	signal(SIGQUIT, touch_key_echap);
}

void		size_screen(void)
{
	init_screen_size(get_select(), 1);
}

void		sig_stop(void)
{
	struct termios	term;
	char			tmp[2];

	if (isatty(1))
	{
		if (tcgetattr(get_select()->fd, &term) == -1)
			ft_error("Error Term", 2);
		tmp[0] = term.c_cc[VSUSP];
		tmp[1] = 0;
		signal(SIGTSTP, SIG_DFL);
		clear_term();
		init_term(get_select());
		tputs(tgetstr("ve", NULL), 0, my_std);
		if (tcsetattr(0, 0, &term) == -1)
			ft_error("Error", 2);
		ioctl(get_select()->fd, TIOCSTI, tmp);
	}
}

int			sig_cont(void)
{
	struct winsize		w;

	ioctl(get_select()->fd, TIOCGWINSZ, &w);
	get_select()->column = w.ws_col;
	get_select()->line = w.ws_row;
	init_term(get_select());
	clear_term();
	signal(SIGTSTP, (void *)sig_stop);
	check_screen(get_select());
	size_to_small(get_select()->size_long);
	return (1);
}
