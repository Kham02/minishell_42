/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:50:38 by estrong           #+#    #+#             */
/*   Updated: 2022/06/04 18:19:21 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	size_list(void)
{
	t_envp	*lst;
	size_t	count;

	count = 0;
	lst = info.envp;
	while (lst->next)
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