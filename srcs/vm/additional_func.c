/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergottli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:12:37 by ergottli          #+#    #+#             */
/*   Updated: 2020/01/26 21:12:38 by ergottli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void    standart_usage(void)
{
    ft_putstr("Usage: ./corewar [-a (-dump|-d) <num> (-shed|-s) <num> -l <num>] [-v] [-n <num>] <champion.cor> <...>\n");
    ft_putstr("    -a          : Print output from \"aff\" (Default is off)\n");
    ft_putstr("    -dump <num> : Dump memory (32 octets per line) after <num> cycles and exit\n");
    ft_putstr("    -d    <num> : Dump memory (64 octets per line) after <num> cycles and exit\n");
    ft_putstr("    -l    <num> : Log levels\n");
    ft_putstr("                   1  : Show lives\n");
    ft_putstr("                   2  : Show cycles\n");
    ft_putstr("                   4  : Show operations\n");
    ft_putstr("                   8  : Show deaths\n");
    ft_putstr("    -v          : Run visualizer\n");
    ft_putstr("    -n    <num> : Set <num> of the next player\n");


}