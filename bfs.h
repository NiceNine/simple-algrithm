#pragma once

#include <climits>
#include <queue>
#include "graph.h"


/*	@function:	bfs
 *	@desc:		
 *	@param:		graph& g
	@param:		int sc
 *	@return:	void		
 *
 */
void bfs(graph& g, int sc)
{
	for (auto& each : g.unord_map_id_pvtx) {
		each.second->color = enum_color::WHITE;
		each.second->pre = -1;
		each.second->dist = INT_MAX;
	}

	g.unord_map_id_pvtx[sc]->color = enum_color::GRAY;
	g.unord_map_id_pvtx[sc]->dist = 0;
	
	std::queue<int> que_id;
	que_id.push(sc);

	while (!que_id.empty()) {
		auto cur_id = que_id.front();
		for (const auto& each : g.unord_map_id_neibor[cur_id]) {
			if (g.unord_map_id_pvtx[each.first]->color == enum_color::WHITE) {
				g.unord_map_id_pvtx[each.first]->pre = cur_id;
				g.unord_map_id_pvtx[each.first]->dist = g.unord_map_id_pvtx[cur_id]->dist + 1;
				g.unord_map_id_pvtx[each.first]->color = enum_color::GRAY;
				que_id.push(each.first);
			}
		}

		que_id.pop();
		g.unord_map_id_pvtx[cur_id]->color = enum_color::BLACK;
	}
}
