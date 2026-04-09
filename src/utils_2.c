/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:20:28 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/12 09:20:30 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_rev_order(long *tab_a, long *tab_b, long min, long max)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (tab_a[i] != 2147483648)
	{
		if (tab_b[0] == max && tab_a[i] == min)
			tmp = i;
		else if (tab_a[i] > tab_b[0] && tab_a[i] < tab_a[tmp])
			tmp = i;
		else if (tab_a[i] == min && tab_b[0] == 2147483648)
			tmp = i;
		i++;
	}
	if (tmp <= i / 2)
		return (0);
	return (1);
}

long	*fastest_pair(long *tab_a, long *tab_b)
{
	int		op_clos_max;
	int		op_clos_min;
	int		op_min;
	int		op_max;
	long	*ret;

	ret = ft_calloc(sizeof(long), 2);
	op_min = op_count(get_min(tab_b), tab_b);
	op_max = op_count(get_max(tab_b), tab_b);
	op_clos_max = op_count(closest_above(get_max(tab_b), tab_a), tab_a);
	op_clos_min = op_count(closest_above(get_min(tab_b), tab_a), tab_a);
	if (get_fastest(op_min, op_max, op_clos_min, op_clos_max))
		ret[0] = get_min(tab_b);
	else
		ret[0] = get_max(tab_b);
	ret[1] = closest_above(ret[0], tab_a);
	return (ret);
}

static int	process_fastest(int extrem, int close_extrem)
{
	int	op_extrem;

	if ((extrem < 0 && close_extrem < 0) || (extrem > 0 && close_extrem > 0))
		op_extrem = biggest(extrem, close_extrem);
	else
	{
		if (extrem < 0)
			extrem = -extrem;
		if (close_extrem < 0)
			close_extrem = -close_extrem;
		op_extrem = extrem + close_extrem;
	}
	return (op_extrem);
}

int	get_fastest(int min, int max, int close_min, int close_max)
{
	int	op_min;
	int	op_max;

	op_min = process_fastest(min, close_min);
	op_max = process_fastest(max, close_max);
	if (op_min < op_max)
		return (1);
	return (0);
}

long	op_count(long target, long *tab)
{
	int	i;

	i = 0;
	while (tab[i] != target && tab[i] != 2147483648)
		i++;
	if (i > tablen(tab) / 2)
	{
		i = tablen(tab) - i;
		i = -i;
	}
	return (i);
}
