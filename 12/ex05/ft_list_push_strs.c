/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:14:23 by apigeon           #+#    #+#             */
/*   Updated: 2021/08/26 19:25:39 by apigeon          ###   ########.fr       */
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*first;
	t_list	*current;
	
	if (size == 0)
		return (NULL);
	first = ft_create_elem(strs[size--]);
	current = first;
	while (size >= 0)
	{
		current->next = ft_create_elem(strs[size]);
		current = current->next;
		size--;
	}
	return (first);	
}
