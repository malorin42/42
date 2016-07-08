/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aempisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:51:49 by aempisse          #+#    #+#             */
/*   Updated: 2014/11/09 19:52:20 by aempisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (i < (ft_strlen(s)))
	{
		(*f)(&s[i]);
		i++;
	}
}
