/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:36:47 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/08 11:10:05 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_lt **lst, t_lt *new)
{
	t_lt	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}
