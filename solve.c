/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:37:08 by ctrouve           #+#    #+#             */
/*   Updated: 2022/02/02 12:07:12 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve(t_piece *piecelist, t_map *map, int x_offset, int y_offset)
{
	if (!piecelist)
		return (0);
	while (y_offset < map->map_size)
	{
		while (x_offset < map->map_size - piecelist->leader_coord[1])
		{
			if (placepiece(piecelist, map, x_offset, y_offset) == 1)
			{
				if (piecelist->next != NULL)
				{
					if (solve(piecelist->next, map, 0, 0) == 1)
						return (1);
					else
						cancelplacepiece(piecelist, map);
				}
				else
					return (1);
			}
			x_offset++;
		}
		x_offset = 0;
		y_offset++;
	}
	return (0);
}
