#pragma once

#include <climits>

#include "graph.h"

/// file:dfs.h

void dfs_impl(graph&, int);

/**	@function	dfs 
 *	@param	graph& g
 */
void dfs(graph& g)
{
	for (auto& each : g.unord_map_id_pvtx) {
		each.second->color = enum_color::WHITE;
		each.second->pre = -1;
		each.second->dist = INT_MAX;
	}

	for (auto& each : g.unord_map_id_pvtx) {
		if (each.second->color == enum_color::WHITE) {
			dfs_impl(g, each.first);
		}
	}
}

/**	@function dfs_impl
 *	@param	graph& g
 *	@param	int sc
 *	@return void
 */
void dfs_impl(graph& g, int sc)
{
	g.unord_map_id_pvtx[sc]->color = enum_color::GRAY;

	for (const auto& each : g.unord_map_id_neibor[sc]) {
		if (g.unord_map_id_pvtx[each.first]->color == enum_color::WHITE) {
			dfs_impl(g, each.first);
		}
	}

	g.unord_map_id_pvtx[sc]->color = enum_color::BLACK;
}