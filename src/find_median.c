/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:22:21 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/12 09:41:37 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	tablen(long *tab)
{
	int	i;

	i = 0;
	while (tab[i] != 2147483648)
		i++;
	return (i);
}

static void	sort_array(long *tab, int len)
{
	int	tmp;
	int	i;

	while (len >= 0)
	{
		i = 0;
		while (i < len - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab [i];
				tab[i] = tab [i + 1];
				tab [i + 1] = tmp;
			}
			i++;
		}
		len--;
	}
}

long	*find_thrd(long *tab)
{
	int		i;
	int		len;
	long	*sortab;
	long	*thrd;

	i = 0;
	len = tablen(tab);
	sortab = ft_calloc(sizeof(long), len);
	thrd = ft_calloc(sizeof(long), 5);
	while (tab[i] != 2147483648)
	{
		sortab[i] = tab[i];
		i++;
	}
	sort_array(sortab, len);
	thrd[0] = sortab[len / 3];
	thrd[1] = sortab[len / 3 * 2];
	thrd[2] = sortab[len / 4];
	thrd[3] = sortab[len / 2];
	thrd[4] = sortab[len / 4 * 3];
	free(sortab);
	return (thrd);
}
