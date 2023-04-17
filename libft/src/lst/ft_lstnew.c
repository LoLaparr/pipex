/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:37:20 by lolaparr          #+#    #+#             */
/*   Updated: 2023/02/08 16:17:25 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lt	*ft_lstnew(void *content)
{
	t_lt	*new;

	new = malloc(sizeof(t_lt));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
