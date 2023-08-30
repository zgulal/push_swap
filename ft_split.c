/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgulal <zgulal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:49:26 by zgulal            #+#    #+#             */
/*   Updated: 2023/08/13 19:49:29 by zgulal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	b(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*copy(char *array, const char *s, int i, int len)
{
	int	j;

	j = 0;
	while (len > 0)
	{
		array[j] = s[i - len];
		len--;
		j++;
	}
	array[j] = '\0';
	return (array);
}

static void	*splitit(char **array, char const *s, char c, int mallocnumber)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (j < mallocnumber)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			len++;
		}
		array[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!array[j])
			return (NULL);
		copy(array[j], s, i, len);
		j++;
		len = 0;
	}
	array[j] = NULL;
	return (array[j]);
}

char	**ft_split(char const *s, char c)
{
	int		mallocnumber;
	char	**array;

	if (s != NULL)
	{
		mallocnumber = b(s, c);
		array = (char **)malloc(sizeof(char *) * (mallocnumber + 1));
		if (!array)
			return (NULL);
		splitit(array, s, c, mallocnumber);
		return (array);
	}
	return (0);
}
