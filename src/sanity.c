/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:06:42 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/16 10:28:04 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(long *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	str_check(char	*s, int argc)
{
	int		i;
	int		len;
	int		err;
	char	**tab;

	i = 0;
	len = 0;
	while (s[i] == ' ' && s[i])
		i++;
	if (i == (int)ft_strlen(s))
		return (-1);
	tab = ft_split(s, ' ');
	while (tab[len])
		len++;
	err = sanity_check(len, tab, true);
	free_array(tab);
	free(tab);
	if (err == -1)
		return (-1);
	return (argc);
}

int	sanity_check(int argc, char **argv, bool san)
{
	int	i;

	i = 1;
	if (san == true)
		i = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			argc = str_check(argv[i], argc);
		else if (argv[i][0] != '-' && ft_atoi(argv[i]) < 0)
			return (-1);
		else if (argv[i][0] == '-' && ft_atoi(argv[i]) > 0)
			return (-1);
		else if (only_digit(argv[i]) == 0)
			return (-1);
		i++;
	}
	if (argc == -1)
		return (-1);
	return (0);
}
