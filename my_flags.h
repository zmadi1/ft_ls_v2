#ifndef MY_FLAGS_H

# define MY_FLAGS_H

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

typedef struct  s_flags
{
	int        l;
	int        a;
	int        R;
	int        r;
	int        t;
	int        o;
	int        n;
	int        g;

}			t_flags;

#endif