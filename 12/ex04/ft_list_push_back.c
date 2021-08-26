/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:33:54 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/26 18:44:43 by apigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list) * 1);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*cur_list;

	cur_list = *begin_list;
	while (cur_list->next)
		cur_list = cur_list->next;
	cur_list->next = ft_create_elem(data);
}
