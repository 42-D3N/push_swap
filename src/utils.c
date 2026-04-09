/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:21:10 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/07 14:30:20 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
}

static void	ft_swap(long *start, long *end)
{
	int	tmp;

	tmp = *start;
	*start = *end;
	*end = tmp;
}

long	*rev_int_tab(long *tab, int size)
{
	int	start;

	start = 0;
	size--;
	while (start < size)
	{
		ft_swap(tab + start, tab + size);
		start++;
		size--;
	}
	return (tab);
}

long	get_max(long *tab)
{
	int		i;
	long	max;

	i = 0;
	max = tab[i];
	while (tab[i] != 2147483648)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

long	get_min(long *tab)
{
	int		i;
	long	min;

	i = 0;
	min = tab[i];
	while (tab[i] != 2147483648)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}
