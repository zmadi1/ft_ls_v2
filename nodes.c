#include <my_flags.h>

void list_add(t_ls **list, char *name)
{
    t_ls *tmp;

    tmp = *list;
    if (!*list)
    {
        *list = (t_ls *)malloc(sizeof(t_ls));
        (*list)->name = ft_strdup(name);
        (*list)->next = NULL;
    }
    else
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = (t_ls *)malloc(sizeof(t_ls));
        tmp->next->name = ft_strdup(name);
        tmp->next->next = NULL;
    }
}

void sort_by_ascii(t_ls **list)
{
    t_ls *l_ls;
    char *tmp;

    l_ls = *list;
    while (l_ls->next != NULL)
    {
        if (ft_strcmp(l_ls->name, l_ls->next->name) > 0)
        {
            tmp = l_ls->name;
            l_ls->name = l_ls->next->name;
            l_ls->next->name = tmp;
            break;
        }
        l_ls = l_ls->next;
    }
    if (l_ls->next == NULL)
        return;
    else
        sort_by_ascii(&(*list));
}

void sort_by_ascii_r(t_ls **list)
{
    t_ls *l_ls;
    char *tmp;

    l_ls = *list;
    while (l_ls->next != NULL)
    {
        if (ft_strcmp(l_ls->name, l_ls->next->name) < 0)
        {
            tmp = l_ls->name;
            l_ls->name = l_ls->next->name;
            l_ls->next->name = tmp;
            break;
        }
        l_ls = l_ls->next;
    }
    if (l_ls->next == NULL)
        return;
    else
        sort_by_ascii_r(&(*list));
}

void sort_by_time(t_ls **list, char *s)
{
    t_ls *l_ls;
    char *tmp;
    struct stat st;
    struct stat st2;

    l_ls = *list;
    while (l_ls->next != NULL)
    {
        tmp = ft_strjoin(s, l_ls->name);
        lstat(tmp, &st);
        tmp = ft_strjoin(s, l_ls->next->name);
        lstat(tmp, &st2);
        printf("%ld**%ld\n", st.st_mtimespec.tv_sec, st2.st_mtimespec.tv_sec);
        if (st.st_mtimespec.tv_sec < st2.st_mtimespec.tv_sec)
        {
            tmp = l_ls->name;
            l_ls->name = l_ls->next->name;
            l_ls->next->name = tmp;
            break;
        }
        l_ls = l_ls->next;
    }
    if (l_ls->next == NULL)
        return;
    else
        sort_by_time(&(*list), s);
}