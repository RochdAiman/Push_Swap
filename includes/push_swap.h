#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

// Parsing functions
char	**collect_args(int argc, char **argv, int *count, int *need_free);
int		validate_numbers(char **args);
int		check_duplicates(char **args);
void	free_args(char **args, int need_free);

#endif