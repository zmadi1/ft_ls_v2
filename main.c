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
#include <string.h>

void init_flags(t_flags *flag)
{
	flag->l = 0;
	flag->a = 0;
	flag->R = 0;
	flag->r = 0;
	flag->t = 0;
	flag->o = 0;
	flag->n = 0;
	flag->g = 0;
}

void proccess_flag(char *s, t_flags *f)
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

void handle_dir(char *path, t_flags *f)
{
	struct dirent *pd;
	DIR *d;
	t_ls *l_ls;
	struct stat st;

	lstat("libft", &st);
	printf("********** %ld\n", st.st_atimespec.tv_sec);
	l_ls = NULL;
	if ((d = opendir(path)) == NULL)
	{
		ft_putendl_fd("No such file of directory!", 2);
		return;
	}

	while ((pd = readdir(d)) != NULL)
	{
		if (!ft_strncmp(pd->d_name, ".", 1) && !f->a)
			continue;
		list_add(&l_ls, pd->d_name);
	}

	sort_by_ascii(&l_ls);
	if (f->r)
		sort_by_ascii_r(&l_ls);
	if (f->t)
		sort_by_time(&l_ls);
	while (l_ls)
	{
		printf("---> %s\n", l_ls->name);
		l_ls = l_ls->next;
	}
}

void proccess(t_flags *f, char **av, int ac)
{
	int i;
	int count;

	i = 1;
	count = 0;
	if (ac > 1)
	{
		if (av[i][0] == '-' && ft_isalpha(av[i][1]))
			proccess_flag(av[i], &(*f));
	}
	else
	{
		handle_dir(".", &(*f));
		return;
	}
	i--;
	while (++i < ac)
	{
		if (!(av[i][0] == '-' && ft_isalpha(av[i][1])))
		{
			handle_dir(av[i], &(*f));
			count++;
		}
	}
	if (!count)
		handle_dir(".", &(*f));
}

int main(int ac, char **av)
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
