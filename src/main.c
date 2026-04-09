/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:16:09 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/16 10:17:42 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	tab_len(char **argv)
{
	int		i;
	int		j;
	int		len;
	char	**s;

	i = 1;
	len = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			j = 0;
			s = ft_split(argv[i], ' ');
			while (s[j++])
				len++;
			free_array(s);
			free(s);
			len--;
		}
		len++;
		i++;
	}
	return (len);
}

long	*make_tab(long *tab, char **argv, int len)
{
	int		i;
	int		j;
	char	**s;

	i = 1;
	len--;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			j = 0;
			s = ft_split(argv[i], ' ');
			while (s[j])
			{
				tab[len--] = ft_atoi(s[j]);
				j++;
			}
			free_array(s);
			free(s);
		}
		else
			tab[len--] = ft_atoi(argv[i]);
		i++;
	}
	return (tab);
}

int	push_swap(long *tab, long *tab_b)
{
	if (tab[2] == 2147483648)
		return (instructions(tab, tab_b, "sa"));
	else if (tab[3] == 2147483648)
		return (sort_three(tab, tab_b));
	else if (tab[4] == 2147483648 || tab[5] == 2147483648)
		return (sort_five(tab, tab_b));
	return (sort_big(tab, tab_b));
}

int	main(int argc, char **argv)
{
	long	*tab;
	long	*tab_b;
	int		len;

	if (!argv[1])
		return (0);
	if (sanity_check(argc, argv, false) != 0)
		return (write(2, "Error\n", 6));
	len = tab_len(argv);
	tab = ft_calloc(sizeof(int *), len + 1);
	tab = rev_int_tab(make_tab(tab, argv, len), len);
	tab[len] = 2147483648;
	tab_b = ft_calloc(sizeof(int *), len);
	tab_b[0] = 2147483648;
	if (check_duplicate(tab, len) == -1)
		return (free(tab), free(tab_b), write(2, "Error\n", 6));
	if (is_sort(tab) == 1)
		return (free(tab), free(tab_b), 0);
	push_swap(tab, tab_b);
	free(tab);
	free(tab_b);
}
