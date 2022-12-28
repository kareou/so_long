/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairou <mkhairou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:49 by mkhairou          #+#    #+#             */
/*   Updated: 2022/12/26 14:49:08 by mkhairou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (n)
	{
		str[i] = '\0';
		i++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	int	*pt;

	pt = (void *)malloc(count * size);
	if (!pt)
		return (NULL);
	ft_bzero(pt, count * size);
	return (pt);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(void *content, int y, int x)
{
	t_list	*cont;

	cont = (t_list *)malloc(sizeof(t_list));
	if (!cont)
		return (NULL);
	cont->x = x;
	cont->y = y;
	cont->content = content;
	cont->next = NULL;
	return (cont);
}
