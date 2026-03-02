/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:41:52 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/02 15:58:35 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//returns:
//	1 = success (valid int)
//	0 = error (invalid format or out of range)
//	write parsed value on success

int	parse_int_strict(const char *s, int *out)
{
	if (!s)
		return (errno);
