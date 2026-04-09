/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapo <rapo@rapo.rapo>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:36:14 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/13 18:04:40 by rapo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	pre_sort(long *tab_a, long *tab_b, long min, long max)
{
	long	med;

	sort_three(tab_a, tab_b);
	med = tab_a[1];
	if (tab_b[0] == max || tab_b[0] == min)
	{
		instructions(tab_a, tab_b, "pa");
		if (tab_b[0] == max)
			instructions(tab_a, tab_b, "ra");
	}
	else
	{
		if (tab_b[0] > med)
		{
			if (tab_a[2] > tab_b[0])
				instructions(tab_a, tab_b, "rra");
		}
		else
		{
			if (tab_a[0] < tab_b[0])
				instructions(tab_a, tab_b, "ra");
		}
		instructions(tab_a, tab_b, "pa");
	}
}

static void	five_rot(long *tab_a, long *tab_b, long min, long max)
{
	int	rev_order;

	rev_order = ft_rev_order(tab_a, tab_b, min, max);
	if (tab_b[0] == max || tab_b[0] == min)
	{
		while (!(tab_a[0] == min || tab_a[3] == max))
		{
			if (rev_order)
				instructions(tab_a, tab_b, "rra");
			else
				instructions(tab_a, tab_b, "ra");
		}
	}
	else
	{
		while (!(tab_b[0] < tab_a[0] && tab_b[0] > tab_a[3]))
		{
			if (rev_order)
				instructions(tab_a, tab_b, "rra");
			else
				instructions(tab_a, tab_b, "ra");
		}
	}
}

int	sort_five(long *tab_a, long *tab_b)
{
	long	max;
	long	min;
	int		rev_order;

	max = get_max(tab_a);
	min = get_min(tab_a);
	instructions(tab_a, tab_b, "pb");
	if (tab_a[3] != 2147483648)
		instructions(tab_a, tab_b, "pb");
	pre_sort(tab_a, tab_b, min, max);
	if (tab_b[0] != 2147483648)
	{
		five_rot(tab_a, tab_b, min, max);
		instructions(tab_a, tab_b, "pa");
	}
	rev_order = ft_rev_order(tab_a, tab_b, min, max);
	while (tab_a[0] != min)
	{
		if (rev_order)
			instructions(tab_a, tab_b, "rra");
		else
			instructions(tab_a, tab_b, "ra");
	}
	return (0);
}

int	sort_three(long *tab, long *useless)
{
	if (tab[1] > tab[0] && tab[1] > tab[2])
		instructions(tab, useless, "rra");
	else if (tab[0] > tab[1] && tab[0] > tab[2])
		instructions(tab, useless, "ra");
	if (tab[1] < tab[0] && tab[1] < tab[2])
		instructions(tab, useless, "sa");
	return (0);
}
