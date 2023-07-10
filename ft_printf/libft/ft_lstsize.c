/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:24:17 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/09 14:29:48 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	if (!lst)
		return (0);
	i = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
