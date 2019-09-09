#ifndef MY_FLAGS_H

#define MY_FLAGS_H

#include <unistd.h>
#include <stdio.h>
#include <libft.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

typedef struct s_flags
{
	int l;
	int a;
	int R;
	int r;
	int t;
	int o;
	int n;
	int g;

} t_flags;

typedef struct s_ls
{
	char *name;
	struct s_ls *next;
} t_ls;

void list_add(t_ls **list, char *name);
void list_swap(t_ls **n1);
void sort_by_ascii(t_ls **list);
void sort_by_ascii_r(t_ls **list);
void sort_by_time(t_ls **list, char *);
#endif