/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:54:22 by ctrouve           #+#    #+#             */
/*   Updated: 2022/02/03 14:50:56 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	allblocksinmap(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	if (x + x_offset >= map->map_size || y + y_offset >= map->map_size)
		return (0);
	j = 0;
	i = 1;
	while (j <= 4)
	{
		y = piece->leader_coord[0] + piece->friends_coord[j];
		x = piece->leader_coord[1] + piece->friends_coord[i];
		if (x + x_offset >= map->map_size || y + y_offset >= map->map_size)
			return (0);
		else
		{
			i = i + 2;
			j = j + 2;
		}
	}
	return (1);
}

int	cancelplacepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	y;
	int	x;
	int	i;

	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	i = 0;
	if (piece->cancel >= 2)
		map->map_array[y + y_offset][x + x_offset] = '.';
	y = piece->leader_coord[0] + piece->friends_coord[i];
	x = piece->leader_coord[1] + piece->friends_coord[i + 1];
	i = i + 2;
	if (piece->cancel >= 4)
		map->map_array[y + y_offset][x + x_offset] = '.';
	y = piece->leader_coord[0] + piece->friends_coord[i];
	x = piece->leader_coord[1] + piece->friends_coord[i + 1];
	i = i + 2;
	if (piece->cancel >= 6)
		map->map_array[y + y_offset][x + x_offset] = '.';
	y = piece->leader_coord[0] + piece->friends_coord[i];
	x = piece->leader_coord[1] + piece->friends_coord[i + 1];
	i = i + 2;
	if (piece->cancel == 8)
		map->map_array[y + y_offset][x + x_offset] = '.';
	return (0);
}

int	placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	j;

	if (allblocksinmap(piece, map, x_offset, y_offset) == 0)
		return (0);
	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	j = 0;
	while (j < 7)
	{
		if (map->map_array[y + y_offset][x + x_offset] == '.')
		{
			map->map_array[y + y_offset][x + x_offset] = piece->letter;
			y = piece->leader_coord[0] + piece->friends_coord[j];
			x = piece->leader_coord[1] + piece->friends_coord[j + 1];
			j = j + 2;
		}
		else
			break ;
	}
	piece->cancel = j;
	if (piece->cancel != 8)
		return (cancelplacepiece(piece, map, x_offset, y_offset));
	return (1);
}
