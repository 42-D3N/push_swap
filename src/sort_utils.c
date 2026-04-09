/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:47:52 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/12 10:19:20 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rot_way(long *tab, long target)
{
	int	i;
	int	len;

	i = 0;
	len = tablen(tab);
	while (tab[i] != target)
		i++;
	if (i > len / 2)
		return (1);
	return (0);
}

long	closest_above(long target, long *tab)
{
	int		i;
	long	max;

	i = 0;
	max = get_max(tab);
	if (target > max)
		return (target);
	while (tab[i] != 2147483648)
	{
		if (tab[i] > target && tab[i] < max)
			max = tab[i];
		i++;
	}
	return (max);
}

static void	which_rot_all(long *tab_a, long *tab_b, long top_a, long top_b)
{
	if (rot_way(tab_b, top_b) && rot_way(tab_a, top_a))
	{
		while (tab_b[0] != top_b && tab_a[0] != top_a)
			instructions(tab_a, tab_b, "rrr");
	}
	else if (!rot_way(tab_b, top_b) && !rot_way(tab_a, top_a))
	{
		while (tab_b[0] != top_b && tab_a[0] != top_a)
			instructions(tab_a, tab_b, "rr");
	}
}

void	which_rotation(long *tab_a, long *tab_b, long top_a, long top_b)
{
	which_rot_all(tab_a, tab_b, top_a, top_b);
	if (tab_b[0] != top_b && rot_way(tab_b, top_b))
	{
		while (tab_b[0] != top_b)
			instructions(tab_a, tab_b, "rrb");
	}
	else if (tab_b[0] != top_b)
	{
		while (tab_b[0] != top_b)
			instructions(tab_a, tab_b, "rb");
	}
	if (tab_a[0] != top_a && rot_way(tab_a, top_a))
	{
		while (tab_a[0] != top_a)
			instructions(tab_a, tab_b, "rra");
	}
	else if (tab_a[0] != top_a)
	{
		while (tab_a[0] != top_a)
			instructions(tab_a, tab_b, "ra");
	}
}

int	is_sort(long *tab)
{
	int	i;

	i = 0;
	while (tab[i + 1] != 2147483648)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
