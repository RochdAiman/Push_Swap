/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:51:13 by arochd            #+#    #+#             */
/*   Updated: 2025/12/10 17:24:51 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char	**collect_arguments(int ac, char **av, int *count)
{
	char	**arguments;
	char	*temp;
	int		i;

	// if (ac < 2 || !av || !count) // to chcek
	// 	return (*count = 0, NULL);
	// if (ac == 2) // no need for condition maybe
	// 	arguments = ft_split(av[1], ' ');
	// else
	// {
		temp = ft_strdup(av[1]);
		i = 2;
		while (i < ac)
		{
			temp = join_and_free(temp, " ");
			temp = join_and_free(temp, av[i++]);
		}
		arguments = ft_split(temp, ' ');
		free(temp);
	// }
	i = 0;
	while (arguments && arguments[i])
		i++;
	*count = i;
	return (arguments);
}

void	clear_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	numeric_checker(char **args)
{
	int		i;
	int		pos;
	long	num;

	i = 0;
	while (args[i])
	{
		pos = 0;
		// if (!args[i][pos]) // no need (already handled in the count != 0) check previous call 
		// 	return (0);
		if (args[i][pos] == '-' || args[i][pos] == '+')
			pos++;
		if (!args[i][pos])
			return (0);
		while (args[i][pos])
		{
			if (args[i][pos] < '0' || args[i][pos] > '9')
				return (0);
			pos++;
		}
		num = ft_atoi(args[i++]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
	}
	return (1);
}

int	dups_spotter(char **args)
{
	int		i;
	int		k;
	long	num1;
	long	num2;

	i = 0;
	while (args[i])
	{
		num1 = ft_atoi(args[i]);
		// if (num1 > 2147483647 || num1 < -2147483648) // no need
		// 	return (0);
		k = i + 1;
		while (args[k])
		{
			num2 = ft_atoi(args[k]);
			// if (num2 > 2147483647 || num2 < -2147483648) // no need
			// 	return (0);
			if (num2 == num1)
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
