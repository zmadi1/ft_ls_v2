/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:24:31 by zmadi             #+#    #+#             */
/*   Updated: 2019/08/17 10:28:39 by zmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static unsigned int	ft_countwords(char *s)
{
	int index = 0;
	int wordcount = 0;
	
	if (s == NULL)
		return (0);
	while (s[index])
	{
		while (ft_isspace(s[index]) && (s[index]))
			index++;
		if ((!(ft_isspace(s[index]))) && (s[index]))
			wordcount++;
		while ((!(ft_isspace(s[index]))) && (s[index]))
			index++;			
	}
	return (wordcount);
}

static char	*ft_strndup(char *str, unsigned int n)
{
	unsigned int index = 0;
	char *s;

	if (str == NULL)
		return (NULL);
	s = (char *)malloc((sizeof(char)) * n + 1);
	if (s == NULL)
	   return (NULL);
	while (n)
	{
		s[index] = str[index];
		index++;
		n--;
	}
	s[index] = '\0';
	return (s);
}

char    **ft_split(char *str)
{
	int index = 0;
	int word = 0;
	int start = 0;
	char	**s;

	if (str == NULL)
		return (NULL);
	s = (char **)malloc((sizeof(char *)) * ft_countwords(str) + 1);
	if (s == NULL)
		return (NULL);
	while (str[index])
	{
		while ((ft_isspace(str[index])) && (str[index]))
			index++;
		start = index;
		while ((!(ft_isspace(str[index]))) && (str[index]))
			index++;
		if (index > start)
			s[word++] = ft_strndup(str + start, index - start);			
	}
	s[word] = NULL;
	return (s);
}

