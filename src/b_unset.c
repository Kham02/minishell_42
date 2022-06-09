#include "../includes/minishell.h"

char	*b_unset(char *str)
{
	size_t	len;
	t_envp	*list;
	t_envp	*list2;

	list = info.envp;
	list2 = info.envp;
	while(list)
	{
		len = 0;
		len = ft_strlen(list->variable);
		if (!ft_strncmp(str, list->variable, len))
		{
			list2->next = list->next;
			free(list);
			break;
		}
		list2 = list;
		list = list->next;
	}
	return (EXIT_SUCCESS);
}
