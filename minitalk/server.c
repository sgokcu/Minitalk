/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgokcu <sgokcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:42:54 by sgokcu            #+#    #+#             */
/*   Updated: 2023/12/21 15:53:34 by sgokcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_getbit(int signal)
{
	static char	c = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		ft_printf("pid %d\n", getpid());
		signal(SIGUSR1, ft_getbit);
		signal(SIGUSR2, ft_getbit);
		while (1)
		{
			pause();
		}
	}
}
