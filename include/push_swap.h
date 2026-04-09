/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapo <rapo@rapo.rapo>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:48:36 by tle-pape          #+#    #+#             */
/*   Updated: 2024/12/16 10:18:33 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdbool.h>

int		only_digit(char *str);
int		check_duplicate(long *tab, int size);
int		sanity_check(int argc, char **argv, bool san);
int		instructions(long *tabA, long *tabB, char *flag);
int		is_sort(long *tab);
int		sort_three(long *tab, long *useless);
int		sort_five(long *tab_a, long *tab_b);
int		ft_rev_order(long *tab_a, long *tab_b, long min, long max);
int		tablen(long *tab);
int		sort_big(long *tab_a, long *tab_b);
int		get_fastest(int min, int max, int close_min, int close_max);
long	*fastest_pair(long *tab_a, long *tab_b);
long	*rev_int_tab(long *tab, int size);
long	*find_thrd(long *tab);
long	get_min(long *tab);
long	get_max(long *tab);
long	op_count(long target, long *tab);
long	closest_above(long target, long *tab);
long	biggest(long a, long b);
void	which_rotation(long *tab_a, long *tab_b, long top_a, long top_b);
void	free_array(char **strs);

#endif
