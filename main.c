/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:10:09 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/03/04 14:36:13 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int	**arr;
	int	n;

	if (argc < 2)
		return (printf("Not enough arguments"), 1);
	if (!parse_args(argc, argv, &arr, &n))
		return (printf("Error with args\n"), 2);
	if (!check_no_duplicates(arr, n))
	{
		free(arr);
		return (printf("Duplicates found"), 3);
	}
	// build stack from arr && n
	// run push_swap
	free(arr);
	return (0);
}
