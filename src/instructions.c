/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:35:17 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/16 08:59:43 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ins_s(long *tab, char *flag)
{
	long	tmp;

	if (tab[1] == 2147483648 || tab[0] == 2147483648)
		return (0);
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	if (flag)
		ft_printf("%s\n", flag);
	return (1);
}

static int	ins_p(long *tabA, long *tabB, char *flag)
{
	int	tmp;
	int	i;

	i = 0;
	if (tabA[0] == 2147483648)
		return (0);
	while (tabB[i] != 2147483648)
		i++;
	while (i + 1 > 0)
	{
		tabB[i + 1] = tabB[i];
		i--;
	}
	i++;
	tmp = tabB[0];
	tabB[0] = tabA[0];
	tabA[0] = tmp;
	while (tabA[i + 1] != 2147483648)
	{
		tabA[i] = tabA[i + 1];
		i++;
	}
	tabA[i] = 2147483648;
	ft_printf("%s\n", flag);
	return (1);
}

static int	ins_r(long *tab, char *flag)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = tab[0];
	if (tab[1] == 2147483648 || tab[0] == 2147483648)
		return (0);
	while (tab[i + 1] != 2147483648)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = tmp;
	if (flag)
		ft_printf("%s\n", flag);
	return (1);
}

static int	ins_rr(long *tab, char *flag)
{
	int	i;
	int	tmp;

	i = 0;
	if (tab[1] == 2147483648 || tab[0] == 2147483648)
		return (0);
	while (tab[i + 1] != 2147483648)
		i++;
	tmp = tab[i];
	i--;
	while (i + 1 > 0)
	{
		tab[i + 1] = tab[i];
		i--;
	}
	tab[0] = tmp;
	if (flag)
		ft_printf("%s\n", flag);
	return (1);
}

int	instructions(long *tabA, long *tabB, char *flag)
{
	int	i;

	if (ft_strncmp(flag, "sa", 2) == 0)
		i = ins_s(tabA, flag);
	else if (ft_strncmp(flag, "sb", 2) == 0)
		i = ins_s(tabB, flag);
	else if (ft_strncmp(flag, "ss", 2) == 0)
		i = ins_s(tabA, flag) + ins_s(tabB, NULL);
	else if (ft_strncmp(flag, "pa", 2) == 0)
		i = ins_p(tabB, tabA, flag);
	else if (ft_strncmp(flag, "pb", 2) == 0)
		i = ins_p(tabA, tabB, flag);
	else if (ft_strncmp(flag, "rra", 3) == 0)
		i = ins_rr(tabA, flag);
	else if (ft_strncmp(flag, "rrb", 3) == 0)
		i = ins_rr(tabB, flag);
	else if (ft_strncmp(flag, "rrr", 3) == 0)
		i = ins_rr(tabA, "rrr") + ins_rr(tabB, NULL);
	else if (ft_strncmp(flag, "ra", 2) == 0)
		i = ins_r(tabA, flag);
	else if (ft_strncmp(flag, "rb", 2) == 0)
		i = ins_r(tabB, flag);
	else if (ft_strncmp(flag, "rr", 2) == 0)
		i = ins_r(tabA, "rr") + ins_r(tabB, NULL);
	return (i = 0);
}
