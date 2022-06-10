/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:50:48 by estrong           #+#    #+#             */
/*   Updated: 2022/06/10 22:55:35 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_val_shlvl(char *envp)
{
	int		shlvl;
	char	*str;

	str = get_val_envp(envp);
	shlvl = ft_atoi(str) + 1;
	free(str);
	str = ft_itoa(shlvl);
	return (str);
}

char	*get_val_envp(char *envp)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	while (envp[i] != '=')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(envp) - i) + 1);
	if (!str)
		return (NULL);
	i++;
	while (envp[i])
	{
		str[j] = envp[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*get_var_envp(char *envp)
{
	size_t	i;
	char	*str;

	i = 0;
	while (envp[i] != '=')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (envp[i] != '=')
	{
		str[i] = envp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	envp_to_lst(char **envp)
{
	size_t	i;
	t_envp	*lst;

	if (!envp)
		return (1);
	i = 0;
	info.envp = NULL;
	lst = info.envp;
	while (envp[i] && lst)
	{
		// write(1, "fu\n", 3);
		list_add_back_envp(lst, list_new_envp(envp[i]));
		i++;
		lst = lst->next;
		// write(1, "de\n", 3);
	}
	return (0);
}