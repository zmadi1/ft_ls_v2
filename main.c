/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <zmadi@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:52:53 by zmadi             #+#    #+#             */
/*   Updated: 2019/09/03 15:59:52 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <my_flags.h>

void init_flags(t_flags *flag) {
	flag->l = 0;
	flag->a = 0;
	flag->R = 0;
	flag->r = 0;
	flag->t = 0;
	flag->o = 0;
	flag->n = 0;
	flag->g = 0;
}

void	proccess_flag(char *s, t_flags *f)
{
	int i;

	i = 0;
	while (s[++i])
	{
		if (s[i] == 'l')
			f->l = 1;
		else if (s[i] == 'a')
			f->a = 1;
		else if (s[i] == 'R')
			f->R = 1;
		else if (s[i] == 'r')
			f->r = 1;
		else if (s[i] == 't')
			f->t = 1;
		else
		{
			ft_putendl("Sorry no such flag!!!");
			exit(EXIT_FAILURE);
		}
		
	}
}

void	handle_dir(char *path, t_flags *f)
{
	struct dirent	*pd;
	DIR			*d;
	
	if ((d = opendir(path)) == NULL){
		ft_putendl_fd("No such file of directory!", 2);
		return;
	}

	ft_putendl(path);
	while ((pd = readdir(d)) != NULL)
	{
		ft_putchar('\t');
		ft_putendl(pd->d_name);
	}
	
	
}

void proccess(t_flags *f, char **av, int ac)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		if (av[i][0] == '-' && ft_isalpha(av[i][1]))
			proccess_flag(av[i], &(*f));
	} else {
		handle_dir(".", &(*f));
		return;
	}
	i--;
	while (++i < ac)
		handle_dir(av[i], &(*f));
}


int main(int ac, char  **av)
{
	t_flags flags;

	init_flags(&flags);
	proccess(&flags, &(*av), ac);
	printf("a -> %d\n", flags.a);
	printf("R -> %d\n", flags.R);
	printf("r -> %d\n", flags.r);
	printf("t -> %d\n", flags.t);	
	printf("l -> %d\n", flags.l);	
	// while(1){}
	return 0;
}
