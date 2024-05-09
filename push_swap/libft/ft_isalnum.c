/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:53:23 by oallan            #+#    #+#             */
/*   Updated: 2023/12/30 17:13:54 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}
