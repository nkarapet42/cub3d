/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:35:27 by nkarapet          #+#    #+#             */
/*   Updated: 2024/06/15 19:09:07 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_lstclear(t_map **lst)
{
	t_map	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->r != NULL)
			free((*lst)->r);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_map	*ft_lstnew(int len, char *row, int index)
{
	t_map	*res;

	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	res->len = len;
	res->r = row;
	res->index = index;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	ft_addstack(t_map	**stack, char **res)
{
	size_t	i;
	t_map	*tmp;

	i = 6;
	tmp = *stack;
	while (res[i])
	{
		(*stack)->next = ft_lstnew(ft_strlen(res[i]), res[i], i - 6);
		if (!(*stack)->next)
		{
			ft_lstclear(&tmp->next);
			free_and_error(res, 1, "Malloc error");
		}
		(*stack)->next->prev = (*stack);
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = NULL;
	(*stack) = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
}
