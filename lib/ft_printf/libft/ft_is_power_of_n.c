/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_of_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:00:34 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/04 19:31:23 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_power_of_n(unsigned int num, unsigned int n)
{
	if (num == 0)
		return (0);
	while (num % n == 0)
		num /= n;
	return ((n = 1) ? 1 : 0);
}
