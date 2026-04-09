/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:10:35 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/16 14:54:31 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	biggest(long a, long b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

static void	sort_part(long *tab_a, long *tab_b)
{
	long	*best_pair;

	while (tab_b[0] != 2147483648)
	{
		best_pair = fastest_pair(tab_a, tab_b);
		if (best_pair[1] == best_pair[0])
			best_pair[1] = get_min(tab_a);
		which_rotation(tab_a, tab_b, best_pair[1], best_pair[0]);
		instructions(tab_a, tab_b, "pa");
		free(best_pair);
	}
}

static void	push_sort(long *tab_a, long *tab_b, long f_sec, long s_sec)
{
	int	i;
	int	len;

	i = 0;
	len = tablen(tab_a);
	while (i < len && tab_a[0] < s_sec)
	{
		if (f_sec <= tab_a[0] && tab_a[0] < s_sec)
			instructions(tab_a, tab_b, "pb");
		else
			instructions(tab_a, tab_b, "ra");
		i++;
	}
	sort_part(tab_a, tab_b);
	if (f_sec != -2147483649)
	{
		if (op_count(get_max(tab_a), tab_a) < 0)
			while (tab_a[len - 1] != get_max(tab_a))
				instructions(tab_a, tab_b, "rra");
		else
			while (tab_a[0] >= f_sec)
				instructions(tab_a, tab_b, "ra");
	}
}

static void	finalize(long *tab_a, long *tab_b)
{
	if (op_count(get_min(tab_a), tab_a) < 0)
		while (-op_count(get_min(tab_a), tab_a))
			instructions(tab_a, tab_b, "rra");
	else
		while (op_count(get_min(tab_a), tab_a))
			instructions(tab_a, tab_b, "ra");
}

int	sort_big(long *tab_a, long *tab_b)
{
	long	*thrd;
	int		len;

	thrd = find_thrd(tab_a);
	len = tablen(tab_a);
	if (len < 250)
	{
		push_sort(tab_a, tab_b, thrd[1], 2147483648);
		push_sort(tab_a, tab_b, thrd[0], thrd[1]);
		push_sort(tab_a, tab_b, -2147483649, thrd[0]);
	}
	else
	{
		push_sort(tab_a, tab_b, thrd[4], 2147483648);
		push_sort(tab_a, tab_b, thrd[3], thrd[4]);
		push_sort(tab_a, tab_b, thrd[2], thrd[3]);
		push_sort(tab_a, tab_b, -2147483649, thrd[2]);
	}
	finalize(tab_a, tab_b);
	free(thrd);
	return (0);
}
