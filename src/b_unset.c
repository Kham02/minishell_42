#include "../includes/minishell.h"

// char	*b_unset(char *str)
// {
// 	size_t	len;
// 	t_envp	*list;
// 	t_envp	*list2;

// 	list = info.envp;
// 	list2 = info.envp;
// 	while(list)
// 	{
// 		len = 0;
// 		len = ft_strlen(list->variable);
// 		if (!ft_strncmp(str, list->variable, len))
// 		{
// 			list2->next = list->next;
// 			free(list);
// 			printf("%s\n", "variable has been deleted");
// 			break;
// 		}
// 		list2 = list;
// 		list = list->next;
// 	}
// 	return (EXIT_SUCCESS);
// }

char	**b_unset(char *str, char **envp)
{
	size_t	i;
	char	**new_str;
	// char	**envp_2;

	i = 0;
	// envp_2 = NULL;
	// write(1, "ok\n", 3);
	new_str = ft_split(str, ' ');
	while (ft_strnstr(envp[i], new_str[1], ft_strlen(new_str[1])) == 0)
		i++;
	if (envp[i])
	{
		// if (!ft_strcmp(envp[i], new_str[1]))
		envp = del_var(str, envp);
		// i++;
		// write(1, "kO\n", 3);
	}
	// free_str(envp);
	return (envp);
}

char	**del_var(char *str, char **envp)
{
	// char	**envp_new;
	size_t	i;
	size_t	n;
	// char	**str2;

	i = 0;
	n = 0;
	write(1, "kkkkk\n", 6);
	// envp_new = NULL;
	str = (ft_split(str, ' '))[1];
	while(envp[i])
	{
		if ((ft_strnstr(envp[i], str, ft_strlen(str)) == 0))
			i++;
		else
			break;
	}
	if (!(envp[i + 1]))
		free(envp[i]);
	while (envp[i + 1])
	{
		free(envp[i]);
		envp[i] = ft_strdup(envp[i + 1]);
		i++;
	}
	// free_str(envp);
	return (envp);
}

void	b_env(char **envp)
{
	size_t	i;

	i = 0;
	while(envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}