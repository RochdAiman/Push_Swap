#include "../../includes/push_swap.h"

char *ft_strjoin_free(char *s1, char *s2)
{
    char *result = ft_strjoin(s1, s2);
    free(s1);
    return (result);
}

char **collect_args(int ac, char **av, int *counter, int *to_free)
{
    char    **args;
    char    *joined;
    int     i;
    
    *to_free = 1;
    if (ac == 2)
        args = ft_split(av[1], ' ');
    else
    {
        joined = ft_strdup(av[1]);
        i = 2;
        while (i < ac)
        {
            joined = ft_strjoin_free(joined, " ");
            joined = ft_strjoin_free(joined, av[i++]);
        }
        args = ft_split(joined, ' ');
        free(joined);
    }
    i = 0;
    while (args && args[i])
        i++;
    *counter = i;
    return (args);
}

void free_args(char **args, int to_free)
{
    int     i;
    if (!args || !to_free)
        return ;
    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

int valide_nbrs(char **args)
{
    int     i;
    int     j;

    i = 0;
    while (args[i])
    {
        j = 0;
        if (args[i][j] == '-' || args[i][j] == '+')
            j++;
        if (!args[i][j])
            return (0);
        while (args[i][j])
        {
            if (!(args[i][j] >= '0' && args[i][j] <= '9'))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int dupchecks(char **args)
{
    int     i;
    int     j;
    long    nb1;
    long    nb2;

    i = 0;
    while (args[i])
    {
        nb1 = ft_atoi(args[i]);
        if (nb1 > 2147483647 || nb1 < -2147483648)
            return (0);
            
        j = i + 1;
        while (args[j])
        {
            nb2 = ft_atoi(args[j]);
            if (nb2 > 2147483647 || nb2 < -2147483648)
                return (0);
            if (nb2 == nb1)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
