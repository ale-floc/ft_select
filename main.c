/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-floc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 23:21:10 by ale-floc          #+#    #+#             */
/*   Updated: 2016/04/18 23:27:46 by ale-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				end_term_enter(void)
{
	struct termios	term;

	tgetent(NULL, getenv("TERM"));
	tcgetattr(get_select()->fd, &term);
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	tputs(tgetstr("ve", NULL), 0, my_std);
	tcsetattr(get_select()->fd, TCSADRAIN, &term);
	close(get_select()->fd);
	exit(0);
}

void				touch_key_enter(t_select *env)
{
	int				i;
	int				nb;

	i = 0;
	nb = 0;
	clear_term();
	while (i++ != env->size)
	{
		if (env->begin->select == 1)
		{
			if (nb == 0)
			{
				ft_putstr(env->begin->str);
				nb++;
			}
			else
			{
				ft_putstr(" ");
				ft_putstr(env->begin->str);
			}
		}
		env->begin = env->begin->next;
	}
	end_term_enter();
}

t_list				*read_touch(int buffer, t_select *env)
{
	if (buffer == TOUCH_UP)
		touch_key_up(env);
	else if (buffer == TOUCH_DOWN)
		touch_key_down(env);
	else if (buffer == TOUCH_SPACE)
		touch_key_space(env->begin);
	else if (buffer == TOUCH_ECHAP)
		touch_key_echap();
	else if (buffer == TOUCH_DELETE)
		env->begin = touch_key_delete(env);
	else if (buffer == TOUCH_ENTER)
		touch_key_enter(env);
	else if (buffer == TOUCH_CTRL_D)
		touch_key_echap();
	return (env->begin);
}

void				begin_select(t_select *env)
{
	int				buffer;

	check_screen(get_select());
	init_screen_size(get_select(), 1);
	while (42)
	{
		read(0, &buffer, 3);
		if (!size_to_small(get_select()->size_long))
		{
			get_select()->begin = read_touch(buffer, get_select());
			clear_term();
			check_screen(get_select());
		}
		else
		{
			size_to_small(get_select()->size_long);
			if (buffer == TOUCH_ECHAP)
				touch_key_echap();
			else if (buffer == TOUCH_CTRL_D)
				touch_key_echap();
		}
		ft_bzero(&buffer, 3);
	}
}

int					main(int argc, char **argv, char **env)
{
	init_list_term(get_select());
	if (argc == 1)
		return (-1);
	if (!env[0])
		ft_error("Environnement not set", 2);
	ft_signal();
	init_term(get_select());
	init_list(argv, get_select());
	init_screen_size(get_select(), 0);
	begin_select(get_select());
	return (0);
}
