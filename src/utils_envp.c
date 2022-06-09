/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:50:38 by estrong           #+#    #+#             */
/*   Updated: 2022/06/09 22:03:00 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	size_list(void)
{
	t_envp	*lst;
	size_t	count;

	count = 0;
	lst = info.envp;
		write(1, "fu\n", 3);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_envp	*list_new_envp(char *envp)
{
	t_envp	*list;

	list = malloc(sizeof(t_envp));
	if (!list)
		return (NULL);
	list->order = size_list() + 1;
	list->variable = get_var_envp(envp);
	if (ft_strcmp(list->variable, "SHLVL") == 0)
		list->val = get_val_shlvl(envp);
	else
		list->val = get_val_envp(envp);
	list->next = NULL;
	return (list);
}

void	list_add_back_envp(t_envp *envp, t_envp *new)
{
	t_envp	*list;

	list = envp;
	if (!new)
		return ;
	while (list)
		list = list->next;
	list->next = new;
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}